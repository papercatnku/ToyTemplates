#include "foolib.h"
#include "fooimp.hpp"
long FooInit(FooHandle *pHandle, const FooInitParam *pInit) {

  FooImpl *pFoo = new FooImpl(*pInit);
  *pHandle = pFoo;
  return 0;
}

long FooDoSomething(FooHandle handle) {
  FooImpl *pFoo = (FooImpl *)handle;
  pFoo->DoSomething();
  return 0;
}

long FooUninit(FooHandle *pHandle) {
  FooImpl *pFoo = (FooImpl *)*pHandle;
  delete pFoo;
  *pHandle = nullptr;
  return 0;
}