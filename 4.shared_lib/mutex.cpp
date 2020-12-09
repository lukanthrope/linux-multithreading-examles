#include "mutex.h"

extern "C" void prestart() {
  Worker().start();
}