#include "GLRendererContext.h"
#include "../util/LogUtil.h"
#include "../sample/TriangleSample.h"

GLRendererContext* GLRendererContext::mGLRendererContextInstance = nullptr;

GLRendererContext::GLRendererContext() {
    mCurrentBaseSample = new TriangleSample();
}

GLRendererContext::~GLRendererContext() {
    if (mCurrentBaseSample){
        delete mCurrentBaseSample;
        mCurrentBaseSample = nullptr;
    }
}

GLRendererContext *GLRendererContext::GetInstance() {
    LOGD("GLRendererContext::GetInstance");
    if (mGLRendererContextInstance == nullptr){
        mGLRendererContextInstance = new GLRendererContext();
    }
    return mGLRendererContextInstance;
}


void GLRendererContext::DestroyInstance() {
    LOGD("GLRendererContext::DestroyInstance");
    if (mGLRendererContextInstance){
        delete mGLRendererContextInstance;
        mGLRendererContextInstance = nullptr;
    }
}

void GLRendererContext::OnSurfaceCreated() {
    LOGD("GLRendererContext::OnSurfaceCreated");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    if (mCurrentBaseSample){
        mCurrentBaseSample->Init();
    }
}

void GLRendererContext::OnSurfaceChanged(int width, int height) {
    LOGD("GLRendererContext::OnSurfaceChanged [width, height] = [%d, %d]", width, height);
    glViewport(0, 0, width, height);
    mScreenWidth = width;
    mScreenHeight = height;
}

void GLRendererContext::OnDrawFrame() {
    LOGD("GLRendererContext::OnDrawFrame");
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    if (mCurrentBaseSample){
        mCurrentBaseSample->Draw(mScreenWidth, mScreenHeight);
    }
}

