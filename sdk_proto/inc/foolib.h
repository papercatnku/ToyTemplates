#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if defined(DLL_EXPORTS)
#if defined(_WINDOWS) || defined(__CYGWIN__)
#define FOO_DLL __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#define FOO_DLL __attribute__((visibility("default")))
#else
#define FOO_DLL
#endif
#else
#define FOO_DLL
#endif

typedef struct {
  int iW;
  float fX;
  char chY[100];
  void *pZ;
} FooInitParam;

typedef void *FooHandle;

FOO_DLL long FooInit(FooHandle *pHandle, const FooInitParam *pInit);

FOO_DLL long FooDoSomething(FooHandle handle);

FOO_DLL long FooUninit(FooHandle *pHandle);

#ifdef __cplusplus
}
#endif