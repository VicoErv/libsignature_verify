package com.tencent.wemusic.business.core

import com.tencent.wemusic.business.user.UserManager

class AppCore {
    var userManager_: UserManager = UserManager()

    object AppCoreHolder {
        val INSTANCE = AppCore()
    }

    companion object {
        @JvmStatic
        fun getUserManager (): UserManager {
            return getInstance().userManager_
        }

        @JvmStatic
        private fun getInstance (): AppCore {
            return AppCoreHolder.INSTANCE
        }
    }

    fun getOpenUdid(): String {
        return "ffffffffd7228adb00000186df707fdc"
    }
}