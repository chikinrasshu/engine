#pragma once

// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
#define CHK_HELPER_DLL_IMPORT __declspec(dllimport)
#define CHK_HELPER_DLL_EXPORT __declspec(dllexport)
#define CHK_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define CHK_HELPER_DLL_IMPORT __attribute__((visibility("default")))
#define CHK_HELPER_DLL_EXPORT __attribute__((visibility("default")))
#define CHK_HELPER_DLL_LOCAL  __attribute__((visibility("hidden")))
#else
#define CHK_HELPER_DLL_IMPORT
#define CHK_HELPER_DLL_EXPORT
#define CHK_HELPER_DLL_LOCAL
#endif
#endif
