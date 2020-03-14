#include "init_dsktp_plugin.h"

// This must be included before VersionHelpers.h.
#include <windows.h>

#include <VersionHelpers.h>
#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <map>
#include <memory>
#include <sstream>

namespace
{

// *** Rename this class to match the windows pluginClass in your pubspec.yaml.
class InitDsktpPlugin : public flutter::Plugin
{
public:
    static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

    SamplePlugin();

    virtual ~SamplePlugin();

private:
    // Called when a method is called on this plugin's channel from Dart.
    void HandleMethodCall(
        const flutter::MethodCall<flutter::EncodableValue> &method_call,
        std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

// static
void SamplePlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar)
{
    // *** Replace "sample_plugin" with your plugin's channel name in this call.
    auto channel =
        std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
            registrar->messenger(), "init_dsktp_plugin",
            &flutter::StandardMethodCodec::GetInstance());

    auto plugin = std::make_unique<SamplePlugin>();

    channel->SetMethodCallHandler(
        [plugin_pointer = plugin.get()](const auto &call, auto result) {
            plugin_pointer->HandleMethodCall(call, std::move(result));
        });

    registrar->AddPlugin(std::move(plugin));
}

SamplePlugin::SamplePlugin() {}

SamplePlugin::~SamplePlugin() {}

void SamplePlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result)
{
    // *** Replace the "getPlatformVersion" check with your plugin's method names.
    // See:
    // https://github.com/flutter/engine/tree/master/shell/platform/common/cpp/client_wrapper/include/flutter
    // and
    // https://github.com/flutter/engine/tree/master/shell/platform/windows/client_wrapper/include/flutter
    // for the relevant Flutter APIs.
    if (method_call.method_name().compare("getPlatformVersion") == 0)
    {
        std::ostringstream version_stream;
        version_stream << "Windows ";
        // The result returned here will depend on the app manifest of the runner.
        if (IsWindows10OrGreater())
        {
            version_stream << "10+";
        }
        else if (IsWindows8OrGreater())
        {
            version_stream << "8";
        }
        else if (IsWindows7OrGreater())
        {
            version_stream << "7";
        }
        flutter::EncodableValue response(version_stream.str());
        result->Success(&response);
    }
    else
    {
        result->NotImplemented();
    }
}

} // namespace

void SamplePluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar)
{
    // The plugin registrar wrappers owns the plugins, registered callbacks, etc.,
    // so must remain valid for the life of the application.
    static auto *plugin_registrars =
        new std::map<FlutterDesktopPluginRegistrarRef,
                     std::unique_ptr<flutter::PluginRegistrarWindows>>;
    auto insert_result = plugin_registrars->emplace(
        registrar, std::make_unique<flutter::PluginRegistrarWindows>(registrar));

    SamplePlugin::RegisterWithRegistrar(insert_result.first->second.get());
}