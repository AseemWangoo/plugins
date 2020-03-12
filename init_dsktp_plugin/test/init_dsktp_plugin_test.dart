import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:init_dsktp_plugin/init_dsktp_plugin.dart';

void main() {
  const MethodChannel channel = MethodChannel('init_dsktp_plugin');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await InitDsktpPlugin.platformVersion, '42');
  });
}
