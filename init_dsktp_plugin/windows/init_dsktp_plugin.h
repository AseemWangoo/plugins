// *** Replace SAMPLE with your plugin's name here.
#ifndef FLUTTER_PLUGIN_INIT_DSKTP_PLUGIN_H_
#define FLUTTER_PLUGIN_INIT_DSKTP_PLUGIN_H_

#include <flutter_plugin_registrar.h>

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FLUTTER_PLUGIN_EXPORT __declspec(dllimport)
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

    // *** Replace SAMPLE with your plugin's name here.
    FLUTTER_PLUGIN_EXPORT void InitDsktpPluginRegisterWithRegistrar(
        FlutterDesktopPluginRegistrarRef registrar);

#if defined(__cplusplus)
} // extern "C"
#endif

#endif // FLUTTER_PLUGIN_INIT_DSKTP_PLUGIN_H_