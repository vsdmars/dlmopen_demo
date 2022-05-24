#pragma once

#include <iostream>

using std::cout;
using std::endl;
struct FCI;

struct DASH {
  void draw();
  void draw(int data);
  FCI *fci_;
};

extern "C" DASH *createDash(int);
