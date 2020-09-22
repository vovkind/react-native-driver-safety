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
            /**
            * Default Setting constructor
            * IsSensorFull - true
            * Stop tracking time is 5 minute.
            * Parking radius is 100 meters.
            * Auto start tracking is true.
            * hfOn - true if HIGH FREQUENCY data record from sensors (acc, gyro) is ON and false if is OFF.
            * isElmOn - true if data record from ELM327 devices is ON and false if is OFF.
            */
            val settings = Settings(true, Settings.stopTrackingTimeHigh, Settings.accuracyHigh, true, true, false)
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
        val api = TrackingApi.getInstance()
        
        api.setEnableSdk(false)
        api.clearDeviceID();
    }
}
