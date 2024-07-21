package com.example.openglndkstudy

import android.opengl.GLSurfaceView
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class GLRenderer(): GLSurfaceView.Renderer {

    private var mNativeRenderer: NativeRenderer? = null

    init {
        mNativeRenderer = NativeRenderer()
    }

    override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
        mNativeRenderer?.native_OnSurfaceCreated()
    }

    override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
        mNativeRenderer?.native_OnSurfaceChanged(width,height)
    }

    override fun onDrawFrame(gl: GL10?) {
        mNativeRenderer?.native_OnDrawFrame()
    }

    fun init(){
        mNativeRenderer?.native_OnInit()
    }

    fun unInit(){
        mNativeRenderer?.native_OnUnInit()
    }
}