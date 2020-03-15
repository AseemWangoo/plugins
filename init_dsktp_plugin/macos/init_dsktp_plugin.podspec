#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint init_dsktp_plugin.podspec' to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'init_dsktp_plugin'
  s.version          = '0.0.1'
  s.summary          = 'Hands on with Flutter Desktop Plugins'
  s.description      = <<-DESC
How to create desktop plugins.
                       DESC
  s.homepage         = 'https://flatteredwithflutter.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Aseem Wangoo' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files     = 'Classes/**/*'
  s.dependency 'FlutterMacOS'

  s.platform = :osx, '10.11'
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES' }
  s.swift_version = '5.0'
end
