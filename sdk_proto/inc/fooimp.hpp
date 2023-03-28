#pragma once
#include "bar.hpp"
#include "foolib.h"

class FooImpl {
public:
  FooImpl(const FooInitParam &param);
  ~FooImpl();
  long DoSomething();

protected:
  void print();

  FooInitParam initParam_;
  Bar *pBar_;
};