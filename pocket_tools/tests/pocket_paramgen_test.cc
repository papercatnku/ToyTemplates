#include "pocket_paramgen.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using namespace PocketToyTemplates;

struct A {
  int x = 3;
  float y = 2.0f;
  char z[100] = "hello";
};

struct B {
  vector<int> vecX = {1, 2, 3};
  vector<float> vecY = {1.0f, 2.0f, 3.0f};
  void *pA = nullptr;
};

static A a({2, 1.0f, "abc"});
static A aa({4, 5.0f, "efg hijk"});

static B b({{1, 2, 3}, {1.0f, 2.0f, 3.0f}, (void *)(&a)});
static B bb({{}, {1.0f}, nullptr});

PPG_REGISTER(A, a, std::string("a"));
PPG_REGISTER(A, aa, "aa");

PPG_REGISTER(B, b, "b");
PPG_REGISTER(B, bb, "bb");

void printA(const A *pa) {
  if (pa) {
    cout << "x: " << pa->x << "\ty: " << pa->y << "\tz: " << pa->z << endl;
  } else {
    cout << "nullptr of A" << endl;
  }
  return;
}

void printB(const B *pB) {
  if (pB) {
    cout << "vecX: ";
    for (auto &x : pB->vecX) {
      cout << x << " ";
    }
    cout << endl;
    cout << "vecY: ";
    for (auto &y : pB->vecY) {
      cout << y << " ";
    }
    cout << endl;
    printA(reinterpret_cast<A *>(pB->pA));
  } else {
    cout << "nullptr of B" << endl;
  }
}

#define SPLITLINE_BEGIN(T)                                                     \
  cout << "======================" << T << "-start"                            \
       << "======================\n"

#define SPLITLINE_END(T)                                                       \
  cout << "======================" << T << " -end "                            \
       << "======================\n"

#define PRETTY_WRAPPER(STATEMENTS, TAG)                                        \
  SPLITLINE_BEGIN((TAG));                                                      \
  { (STATEMENTS); }                                                            \
  SPLITLINE_END(TAG)

int main(int argc, char **argv) {

  PRETTY_WRAPPER(printA(PocketParamGen<A>::Instance().Get("a")), "A");
  PRETTY_WRAPPER(printA(PocketParamGen<A>::Instance().Get("aa")), "A");
  PRETTY_WRAPPER(printA(PocketParamGen<A>::Instance().Get("aaa")), "A");
  PRETTY_WRAPPER(printB(PocketParamGen<B>::Instance().Get("b")), "B");
  PRETTY_WRAPPER(printB(PocketParamGen<B>::Instance().Get("bb")), "B");
  PRETTY_WRAPPER(printB(PocketParamGen<B>::Instance().Get("bbb")), "B");

  return 0;
}