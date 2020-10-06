#import "DriverSafety.h"
#import <RaxelPulse/RPEntry.h>

@implementation DriverSafety

RCT_EXPORT_MODULE()

// Example method
// See // https://facebook.github.io/react-native/docs/native-modules-ios
RCT_REMAP_METHOD(multiply,
                 multiplyWithA:(nonnull NSNumber*)a withB:(nonnull NSNumber*)b
                 withResolver:(RCTPromiseResolveBlock)resolve
                 withRejecter:(RCTPromiseRejectBlock)reject)
{
  NSNumber *result = @([a floatValue] * [b floatValue]);

  resolve(result);
}

RCT_EXPORT_METHOD(enable:(NSString *)token) {
  dispatch_async(dispatch_get_main_queue(), ^{
    [RPEntry instance].virtualDeviceToken = @"DeviceToken";
    [RPEntry instance].disableTracking = NO;
  });
}

@end
