package com.tencent.wemusic.jooxsignernative

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.tencent.wemusic.business.core.AppCore
import com.tencent.wemusic.jooxsignernative.databinding.ActivityMainBinding
import com.tencent.wemusic.signature.SignatureVerifyUtil

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method

        binding.sampleText.text = SignatureVerifyUtil.getSignature(application.applicationContext).toString()
    }
}