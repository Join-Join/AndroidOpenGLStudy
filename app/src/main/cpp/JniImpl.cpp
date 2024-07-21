#include "jni.h"
#include <string>
#include<android/log.h>
#include "util/LogUtil.h"
#include "renderer/GLRendererContext.h"


#define NATIVE_RENDERER_CLASS_NAME "com/example/openglndkstudy/NativeRenderer"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL native_OnInit(JNIEnv *env, jobject thiz) {
    GLRendererContext::GetInstance();
}

JNIEXPORT void JNICALL native_OnUnInit(JNIEnv *env, jobject thiz) {
    GLRendererContext::GetInstance()->DestroyInstance();
}

JNIEXPORT void JNICALL native_SetImageData(JNIEnv *env, jobject thiz,
                                           jint format, jint width,
                                           jint height, jbyteArray bytes) {

}

JNIEXPORT void JNICALL native_OnSurfaceCreated(JNIEnv *env,jobject thiz) {
    GLRendererContext::GetInstance()->OnSurfaceCreated();
}

JNIEXPORT void JNICALL native_OnSurfaceChanged(JNIEnv *env, jobject thiz,
                                               jint width, jint height) {
    GLRendererContext::GetInstance()->OnSurfaceChanged(width, height);
}

JNIEXPORT void JNICALL native_OnDrawFrame(JNIEnv *env, jobject thiz) {
    GLRendererContext::GetInstance()->OnDrawFrame();
}

JNIEXPORT jstring JNICALL stringFromJni(JNIEnv *env, jobject thiz) {
    std::string hello = "你好 OpenGL! (动态注册2)";
    return env->NewStringUTF(hello.c_str());
}

#ifdef __cplusplus
}
#endif

/*
typedef struct {
    const char* name;       // Java 中函数的名字
    const char* signature;  // 描述 Java 中函数的参数和返回值的字符串
    void*       fnPtr;      // 指向本地函数的函数指针
} JNINativeMethod;
 */
static JNINativeMethod gMethods[] = {
        {"native_OnInit",           "()V",                      (void *)(native_OnInit)},
        {"native_OnUnInit",         "()V",                      (void *)(native_OnUnInit)},
        {"native_SetImageData",     "(III[B)V",                 (void *)(native_SetImageData)},
        {"native_OnSurfaceCreated", "()V",                      (void *)(native_OnSurfaceCreated)},
        {"native_OnSurfaceChanged", "(II)V",                    (void *)(native_OnSurfaceChanged)},
        {"native_OnDrawFrame",      "()V",                      (void *)(native_OnDrawFrame)},
        {"stringFromJni",           "()Ljava/lang/String;",     (void *)(stringFromJni)},
};

/**
 * 注册native方法。
 * 本函数用于在Java虚拟机中注册指定类的native方法。它首先尝试查找指定类，如果找到，则尝试注册提供的native方法。
 *
 * @param env                Java环境指针，用于执行JNI操作。
 * @param className          要注册native方法的类的全限定名。
 * @param gMethods           一个JNINativeMethod数组，包含要注册的native方法的详细信息。
 * @param methodCount        gMethods数组中native方法的数量。
 * @return                  如果注册成功，返回JNI_TRUE；如果失败，返回JNI_FALSE。
 */
static int RegisterNativeMethods (JNIEnv *env, const char *className, JNINativeMethod *gMethods, int methodCount) {
    // 输出日志，标记注册native方法的开始
    LOGD("RegisterNativeMethods");

    // 尝试查找指定的Java类
    jclass clazz = env->FindClass(className);
    // 如果类未找到，输出错误日志并返回失败标志
    if (clazz == NULL) {
        LOGD("Native registration unable to find class '%s'", className);
        return JNI_FALSE;
    }

    // 尝试为找到的类注册native方法，如果注册失败，输出错误日志并返回失败标志
    if (env->RegisterNatives(clazz, gMethods, methodCount) < 0) {
        LOGD("RegisterNatives failed for '%s'", className);
        return JNI_FALSE;
    }
    // 如果一切顺利，返回成功标志
    return JNI_TRUE;
}

static void UnregisterNativeMethods (JNIEnv *env, const char *className) {
    // 输出日志，标记注销native方法的开始
    LOGD("UnregisterNativeMethods");

    // 尝试查找指定的Java类
    jclass clazz = env->FindClass(className);
    // 如果类未找到，输出错误日志并返回
    if (clazz == NULL) {
        LOGD("Native registration unable to find class '%s'", className);
        return;
    }
    if (env != NULL){
        env->UnregisterNatives(clazz);
    }
}

extern "C" jint JNI_OnLoad(JavaVM *jvm, void *reserved) {
    LOGD("JNI_OnLoad");
    JNIEnv *env = NULL;
    if (jvm->GetEnv((void **)(&env), JNI_VERSION_1_6) != JNI_OK){
        return JNI_ERR;
    }
    jint regRet = RegisterNativeMethods(env, NATIVE_RENDERER_CLASS_NAME, gMethods,
                                        sizeof(gMethods) / sizeof(gMethods[0]));
    if (regRet != JNI_TRUE){
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}

extern "C" void JNI_OnUnload(JavaVM *jvm, void *reserved) {
    LOGD("JNI_OnUnload");
    JNIEnv *env = NULL;
    if (jvm->GetEnv((void **)(&env), JNI_VERSION_1_6) != JNI_OK){
        return;
    }
    UnregisterNativeMethods(env,NATIVE_RENDERER_CLASS_NAME);
}
