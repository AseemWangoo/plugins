import 'package:flutter/services.dart' show MethodChannel;

class InitDsktpPlugin {
  static const MethodChannel _channel =
      const MethodChannel('init_dsktp_plugin');

  static Future<String> get platformVersion async {
    final String version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}