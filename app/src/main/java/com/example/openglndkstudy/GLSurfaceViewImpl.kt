package com.example.openglndkstudy

import android.content.Context
import android.opengl.GLSurfaceView
import android.util.AttributeSet

class GLSurfaceViewImpl(context: Context, attrs: AttributeSet?): GLSurfaceView(context, attrs) {

    init {
        setEGLContextClientVersion(3)
        setRenderer(GLRenderer())
        renderMode = RENDERMODE_CONTINUOUSLY
    }

    constructor(context: Context, glRenderer: GLRenderer): this(context, null) {
        setEGLContextClientVersion(3)
        setRenderer(glRenderer)
        renderMode = RENDERMODE_CONTINUOUSLY
    }


    constructor(context: Context, glRenderer: GLRenderer, attrs: AttributeSet): this(context, attrs) {
        setEGLContextClientVersion(3)
        setRenderer(glRenderer)
        renderMode = RENDERMODE_CONTINUOUSLY
    }


}