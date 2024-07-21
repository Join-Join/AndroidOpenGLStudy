//
// Created by ZSP on 2024-07-21.
//

#include "TriangleSample.h"

TriangleSample::~TriangleSample()  {

}

TriangleSample::TriangleSample() {

}

void TriangleSample::Init() {
    char vertexShaderCode[] =
            "#version 300 es                          \n"
            "layout(location = 0) in vec4 vPosition;  \n"
            "void main()                              \n"
            "{                                        \n"
            "   gl_Position = vPosition;              \n"
            "}                                        \n";

    char fragmentShaderCode[] =
            "#version 300 es                              \n"
            "precision mediump float;                     \n"
            "out vec4 fragColor;                          \n"
            "void main()                                  \n"
            "{                                            \n"
            "   fragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );  \n"
            "}                                            \n";

    mProgramHandle = GLUtils::CreateProgram(vertexShaderCode, fragmentShaderCode, mVertexShaderHandle, mFragmentShaderHandle);
}

void TriangleSample::Draw(int screenWidth, int screenHeight) {
    LOGD("TriangleSample::Draw");
    if (mProgramHandle == 0){
        return;
    }

    GLfloat vVertices[] = {
            0.0f,  0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
    };

    glUseProgram(mProgramHandle);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void TriangleSample::Destroy() {

}