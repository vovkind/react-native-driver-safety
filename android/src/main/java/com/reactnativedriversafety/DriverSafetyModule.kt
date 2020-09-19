package com.reactnativedriversafety

import android.content.Context
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContextBaseJavaModule
import com.facebook.react.bridge.ReactMethod
import com.facebook.react.bridge.Promise
import com.raxeltelematics.v2.sdk.Settings
import com.raxeltelematics.v2.sdk.TrackingApi

class DriverSafetyModule(reactContext: ReactApplicationContext) : ReactContextBaseJavaModule(reactContext) {

    override fun getName(): String {
        return "DriverSafety"
    }

    companion object {
        @JvmStatic
        fun init(context: Context){
            val settings = Settings(
                isSensorFull = true,
                stopTrackingTimeout = Settings.stopTrackingTimeHigh,
                accuracy = Settings.accuracyHigh,
                autoStartOn = true
            )
            val api = TrackingApi.getInstance()

            api.initialize(context, settings)
        }
    }

    @ReactMethod
    fun enable(deviceId: String) {
        enableSDK(deviceId)
    }

    @ReactMethod
    fun disable() {
        disableSDK()
    }

    fun enableSDK(deviceId: String) {
        val api = TrackingApi.getInstance()
        
        api.setDeviceID(deviceId)
        api.setEnableSdk(true)
    }

    fun disableSDK() {
        TrackingApi.getInstance().setEnableSdk(false)
    }
}
