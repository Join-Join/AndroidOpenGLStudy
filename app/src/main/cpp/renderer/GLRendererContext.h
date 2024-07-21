//
// Created by ZSP on 2024-07-21.
//

#ifndef OPENGLNDKSTUDY_GLRENDERERCONTEXT_H
#define OPENGLNDKSTUDY_GLRENDERERCONTEXT_H

#include "../sample/BaseSample.h"

class GLRendererContext {
    GLRendererContext();
    ~GLRendererContext();

public:
    static GLRendererContext* GetInstance();
    static void DestroyInstance();

    void OnSurfaceCreated();
    void OnSurfaceChanged(int width, int height);
    void OnDrawFrame();

//    void SetImageData(int format, int width, int height, uint8_t *pData);

private:
    static GLRendererContext* mGLRendererContextInstance;
    BaseSample *mCurrentBaseSample;
    BaseSample *mLastBaseSample;
    int mScreenWidth;
    int mScreenHeight;
};


#endif //OPENGLNDKSTUDY_GLRENDERERCONTEXT_H
