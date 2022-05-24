#include "fci.hpp"
#include "dash.hpp"

using std::cout;
using std::endl;

int FCI::draw() {
  if (dash_) {
    dash_->draw(data_);
  }
  return data_;
};

int FCI::draw(int data) {
  if (dash_) {
    dash_->draw(data);
  }
  return data;
};
