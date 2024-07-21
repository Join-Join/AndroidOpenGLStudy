//
// Created by ZSP on 2024-07-21.
//

#ifndef OPENGLNDKSTUDY_BASESAMPLE_H
#define OPENGLNDKSTUDY_BASESAMPLE_H


#include "stdint.h"
#include <GLES3/gl3.h>

class BaseSample {

public:
    BaseSample(){
        mVertexShaderHandle = 0;
        mFragmentShaderHandle = 0;
        mProgramHandle = 0;
        mSurfaceWidth = 0;
        mSurfaceHeight = 0;
    }

    virtual ~BaseSample(){

    }

    virtual void Init() = 0;
    virtual void Draw(int screenWidth, int screenHeight) = 0;
    virtual void Destroy() = 0;

protected:
    GLuint mVertexShaderHandle;
    GLuint mFragmentShaderHandle;
    GLuint mProgramHandle;
    int mSurfaceWidth;
    int mSurfaceHeight;
};



#endif //OPENGLNDKSTUDY_BASESAMPLE_H
