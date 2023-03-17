#include <jni.h>
#include <string>

extern "C"
{
#include "aes.h"
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_tencent_wemusic_signature_SignatureVerifyUtil_getSignature(
        JNIEnv* env, jclass clazz, jobject context) {
    std::string signature = "0E:FB:2E:93:82:33:CF:0B:EA:46:17:64:4C:E8:3F:D8:65:1D:53:B8:FC:D2:B6:DC:7F:8C:BC:02:DD:7B:3E:26";

    jclass AppCore = env->FindClass("com/tencent/wemusic/business/core/AppCore");
    jmethodID getUserManager = env->GetStaticMethodID(AppCore, "getUserManager",
                                                      "()Lcom/tencent/wemusic/business/user/UserManager;");
    jobject UserManagerObj = env->CallStaticObjectMethod(AppCore, getUserManager);
    jclass UserManager = env->GetObjectClass(UserManagerObj);
    jmethodID getWmid = env->GetMethodID(UserManager, "getWmid", "()J");
    jlong Wmid = env->CallLongMethod(UserManagerObj, getWmid);

    jmethodID getInstance = env->GetStaticMethodID(AppCore, "getInstance", "()Lcom/tencent/wemusic/business/core/AppCore;");
    jobject AppCoreObj = env->CallStaticObjectMethod(AppCore, getInstance);
    jclass AppCoreClass = env->GetObjectClass(AppCoreObj);
    jmethodID getOpenUdid = env->GetMethodID(AppCoreClass, "getOpenUdid", "()Ljava/lang/String;");
    auto OpenUdid = (jstring) env->CallObjectMethod(AppCoreObj, getOpenUdid);

    time_t seconds = time(nullptr);
    std::string timestamp = std::to_string(seconds);

    std::string result =
            "signature=" + signature +
            "&wmid=" + std::to_string(Wmid) +
            "&OpenUDID=" + env->GetStringUTFChars(OpenUdid, nullptr) +
            "&timestamp=" + timestamp +
            "&cv=655163395";

    const auto *key = reinterpret_cast<const uint8_t *>("SYba<=I7@fb+xsao");
    char* encrypted = AES_128_ECB_PKCS5Padding_Encrypt(result.c_str(), key);
    LOGE("%s", result.c_str());
    LOGE("encrypted: %s", encrypted);

    return env->NewStringUTF(encrypted);
}