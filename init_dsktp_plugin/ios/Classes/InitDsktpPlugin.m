#import "InitDsktpPlugin.h"
#if __has_include(<init_dsktp_plugin/init_dsktp_plugin-Swift.h>)
#import <init_dsktp_plugin/init_dsktp_plugin-Swift.h>
#else
// Support project import fallback if the generated compatibility header
// is not copied when this plugin is created as a library.
// https://forums.swift.org/t/swift-static-libraries-dont-copy-generated-objective-c-header/19816
#import "init_dsktp_plugin-Swift.h"
#endif

@implementation InitDsktpPlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftInitDsktpPlugin registerWithRegistrar:registrar];
}
@end
