//
// Created by ZSP on 2024-07-21.
//

#include <malloc.h>
#include "GLUtils.h"

GLuint GLUtils::LoadShader(GLenum shaderType, const char *shaderCode) {
    GLuint shaderHandle = glCreateShader(shaderType);
    GLuint compileStatus = 0;
    if (shaderHandle == 0){
        LOGD("Create Shader Failed");
    }
    glShaderSource(shaderHandle, 1, &shaderCode, NULL);
    glCompileShader(shaderHandle);
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, reinterpret_cast<GLint *>(&compileStatus));
    if (!compileStatus){
        LOGD("Compile Shader Failed");
        GLint infoLen = 0;
        glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &infoLen);
        if (infoLen){
            char* buf = (char*) malloc((size_t)infoLen);
            if (buf){
                glGetShaderInfoLog(shaderHandle, infoLen, NULL, buf);
                LOGD("GLUtils::LoadShader Could not compile shader %d:\n%s\n", shaderType, buf);
                free(buf);
            }
            glDeleteShader(shaderHandle);
            shaderHandle = 0;
        }
    }
    return shaderHandle;
}

GLuint GLUtils::CreateProgram(char *vertexShaderCode, char *fragmentShaderCode, GLuint &vertexShaderHandle,
                       GLuint &fragmentShaderHandle) {
    GLuint programHandle = 0;
    vertexShaderHandle = LoadShader(GL_VERTEX_SHADER, vertexShaderCode);
    if (!vertexShaderHandle){
        LOGD("Create Vertex Shader Failed");
        return programHandle;
    }
    fragmentShaderHandle = LoadShader(GL_FRAGMENT_SHADER, fragmentShaderCode);
    if (!fragmentShaderHandle){
        LOGD("Create Fragment Shader Failed");
        return programHandle;
    }

    programHandle = glCreateProgram();
    if (!programHandle){
        LOGD("Create Program Failed");
        return programHandle;
    }

    glAttachShader(programHandle, vertexShaderHandle);
    CheckGLError("glAttachShader");
    glAttachShader(programHandle, fragmentShaderHandle);
    CheckGLError("glAttachShader");

    glLinkProgram(programHandle);
    GLint linkStatus = GL_FALSE;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &linkStatus);

    glDeleteShader(vertexShaderHandle);
    vertexShaderHandle = 0;
    glDeleteShader(fragmentShaderHandle);
    fragmentShaderHandle = 0;

    if (linkStatus != GL_TRUE){
        GLint bufLength = 0;
        glGetProgramiv(programHandle, GL_INFO_LOG_LENGTH, &bufLength);
        if (bufLength){
            char* buf = (char*) malloc((size_t)bufLength);
            if (buf){
                glGetProgramInfoLog(programHandle, bufLength, NULL, buf);
                LOGD("Could not link program:\n%s\n", buf);
                free(buf);
            }
            glDeleteProgram(programHandle);
            programHandle = 0;
        }
        return programHandle;
    }

    LOGD("Create Program Success programHandle = %d", programHandle);
    return programHandle;
}

void GLUtils::DeleteProgram(GLuint &program) {
    LOGD("Delete Program programHandle = %d", program);
    if (program){
        glUseProgram(0);
        glDeleteProgram(program);
        program = 0;
    }
}

void GLUtils::CheckGLError(const char *glOperation) {
    for (GLint error = glGetError(); error; error = glGetError()){
        LOGD("GLUtils::CheckGLError GL Operation %s() glError (0x%x)\n", glOperation, error);
    }

}




