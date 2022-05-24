#include "dash.hpp"
#include "fci.hpp"

#include <dlfcn.h>

struct DASH;

int main() {
  // init. FCI
  FCI f{42, nullptr};

  DASH d{&f};
  d.draw();

  // declare FUNC
  using FUNC = DASH *(*)(int);
  FUNC create;

  auto handle = dlopen("./libdash.so", RTLD_NOLOAD);

  if (handle == nullptr) {
    cout << "libdash.so is loaded through DT_NEEDED in default linking domain."
         << endl;
  }

  handle = dlmopen(LM_ID_NEWLM, "./libdash.so", RTLD_LAZY);
  *(void **)(&create) = dlsym(handle, "createDash");
  auto dash = create(44);
  printf("Address of DASH instance is %p\n", (void *)dash); // 0x7f7ba4b24098
  dash->draw();

  handle = dlmopen(LM_ID_NEWLM, "./libdash.so", RTLD_LAZY);
  *(void **)(&create) = dlsym(handle, "createDash");
  dash = create(47);
  printf("Address of DASH instance is %p\n", (void *)dash); // 0x7f7ba4b1f098
  dash->draw(42);
}
