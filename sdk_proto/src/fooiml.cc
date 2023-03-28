#include "bar.hpp"
#include "fooimp.hpp"
#include "pocket_paramgen.hpp"
#include <iostream>
#include <memory>

using namespace PocketToyTemplates;
using namespace std;

FooImpl::FooImpl(const FooInitParam &param)
    : initParam_(param), pBar_(nullptr) {
  if (nullptr == initParam_.pZ) {
    pBar_ = PocketParamGen<Bar>::Instance().Get("DefaultBAR");
  } else {
    std::string strKey = std::string(reinterpret_cast<char *>(initParam_.pZ));
    pBar_ = PocketParamGen<Bar>::Instance().Get(strKey);
  }
  return;
}

FooImpl::~FooImpl() {}

long FooImpl::DoSomething() {
  cout << "=======start FooImpl::DoSomething()========" << endl;
  cout << "initParam_.iW: " << initParam_.iW << endl;
  cout << "initParam_.fX: " << initParam_.fX << endl;
  cout << "initParam_.chY: " << initParam_.chY << endl;
  cout << "initParam_.pZ: " << initParam_.pZ << endl;
  printBAR(pBar_);
  cout << "=======end FooImpl::DoSomething()========" << endl;
  return 0;
}