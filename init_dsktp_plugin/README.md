# init_dsktp_plugin

How to create a Flutter Desktop Plugin

## Installation

`pubspec.yaml`

```pubspec.yaml
...
dependencies:
  init_dsktp_plugin:
    git:
      url: https://github.com/AseemWangoo/plugins.git
      path: ./init_dsktp_plugin
...
```

## Usage

```dart
import 'package:init_dsktp_plugin/init_dsktp_plugin.dart';

InitDsktpPlugin.platformVersion
```

### Generic Steps for Windows (For using this plugin, you don't need this)

- Change `sample` in all the filenames to your plugin's name.
- Change the `ProjectName` in `plugin.vcxproj` to your plugin's name.
- Change the `ProjectGuid` in `plugin.vcxproj` to a randomly-generated v4
  UUID. You can use any UUID generator,
    - (Gen. online here) https://www.uuidgenerator.net/
- Change the `FlutterPluginName` in `PluginInfo.props` to your plugin's name.
- Search for comments containing `***` in the `.h` and `.cpp` file, and update
  the code as described in the comment.