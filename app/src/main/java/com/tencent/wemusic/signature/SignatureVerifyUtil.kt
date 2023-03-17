package com.tencent.wemusic.signature

import android.content.Context

class SignatureVerifyUtil {
    companion object {
        init {
            System.loadLibrary("signature_verify")
        }

        @JvmStatic
        external fun getSignature(context: Context): String
    }
}