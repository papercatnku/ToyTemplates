#include "foolib.h"

int main(int argc, char *argv[]) {
  FooHandle handle = nullptr;
  FooInitParam param = {1, 2.0f, "hello", nullptr};
  FooInit(&handle, &param);
  FooDoSomething(handle);
  FooUninit(&handle);

  char testKey[] = "bar1";
  param.pZ = (void *)testKey;
  FooInit(&handle, &param);
  FooDoSomething(handle);
  FooUninit(&handle);

  char testKey_ne[] = "bar_not_exist";
  param.pZ = (void *)testKey_ne;
  FooInit(&handle, &param);
  FooDoSomething(handle);
  FooUninit(&handle);
  return 0;
}