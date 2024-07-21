
#ifndef OPENGLNDKSTUDY_GLUTILS_H
#define OPENGLNDKSTUDY_GLUTILS_H

#include <GLES3/gl3.h>
#include "LogUtil.h"

class GLUtils {

public:
    static GLuint LoadShader(GLenum shaderType, const char *shaderCode);

    static void DeleteProgram(GLuint &program);

    static void CheckGLError(const char *glOperation);

    static GLuint CreateProgram(char *vertexShaderCode, char *fragmentShaderCode, GLuint &vertexShaderHandle, GLuint &fragmentShaderHandle);
};

#endif //OPENGLNDKSTUDY_GLUTILS_H
