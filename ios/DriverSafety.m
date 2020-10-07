#import "DriverSafety.h"
#import "Pods/RaxelPulse/RaxelPulse.framework/Headers/RaxelPulse.h"

@implementation DriverSafety

RCT_EXPORT_MODULE(DriverSafety)

RCT_EXPORT_METHOD(enable:(NSString *)token) {
  dispatch_async(dispatch_get_main_queue(), ^{
    [RPEntry instance].virtualDeviceToken = token;
    [RPEntry instance].disableTracking = NO;
  });
}

RCT_EXPORT_METHOD(disable) {
  dispatch_async(dispatch_get_main_queue(), ^{
    [RPEntry instance].disableTracking = YES;
    [[RPEntry instance] removeVirtualDeviceToken];
  });
}

@end
