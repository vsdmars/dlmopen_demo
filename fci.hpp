#pragma once
#include <iostream>

using std::cout;
using std::endl;
struct DASH;

struct FCI {
  int draw();
  int draw(int data);
  int data_;
  DASH *dash_;
};
