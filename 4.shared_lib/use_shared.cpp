#include <dlfcn.h>
#include <iostream>
#include "mutex.h"

int main(int argc,char *argv[])
{
  void* handle = dlopen("./shared_lib.so", RTLD_LAZY);
  Worker* (*create)();

     create = (Worker* (*)())dlsym(handle, "prestart");
     create();
}