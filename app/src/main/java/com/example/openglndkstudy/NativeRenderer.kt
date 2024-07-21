package com.example.openglndkstudy

class NativeRenderer {
    companion object {
        init {
            System.loadLibrary("OpenGLNDKStudy")
        }
    }

    external fun native_OnInit(): Unit

    external fun native_OnUnInit(): Unit

    external fun native_SetImageData(format: Int, width: Int, height: Int, bytes: ByteArray): Unit

    external fun native_OnSurfaceCreated(): Unit

    external fun native_OnSurfaceChanged(width: Int, height: Int): Unit

    external fun native_OnDrawFrame(): Unit

    external fun stringFromJni(): String
}