#include "bar.hpp"
#include "pocket_paramgen.hpp"
#include <iostream>

using namespace std;

using namespace PocketToyTemplates;
void printBAR(const Bar *pBar) {
  if (pBar) {
    cout << "pBar:[x: " << pBar->x << "\ty: " << pBar->y << "\tz: " << pBar->z
         << "]\n";
  } else {
    cout << "pBar:[nullptr]" << endl;
  }
  return;
}

static Bar DefualtBAR = {3, 2.0f, "hello"};
static Bar BAR1 = {1, 2.0f, "bar1"};
PPG_REGISTER(Bar, DefualtBAR, "DefaultBAR");
PPG_REGISTER(Bar, BAR1, "bar1");