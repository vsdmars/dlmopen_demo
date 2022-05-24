#include "dash.hpp"
#include "fci.hpp"

void DASH::draw() {
  cout << "DASH - FCI draw with no input data: " << fci_->draw() << endl;
}
void DASH::draw(int data) {
  cout << "DASH - FCI draw: " << fci_->draw() << endl;
  cout << "DASH - FCI draw with input data: " << fci_->draw(data) << endl;
}

extern "C" DASH *createDash(int fci_init) {
  static DASH d{new FCI{fci_init}};
  return &d;
};
