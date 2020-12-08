#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>

#include "CFuncThread.h"

std::vector<CThread*> threads;

int main() {
  int prior = 0;
  int count = 1;
  float eps = 0.00001;

  std::cout << "Пріорітет процесу: ";
  std::cin >> prior;
  char cmd[256];
  sprintf(cmd, "renice %d %d", prior, (int)getpid());
  cout << cmd << endl;
  system(cmd);

  std::cout <<"Кількість потоків: ";
  std::cin >> count;

  float a = -1.0;
  float h = 2.0 / count;
  
  clock_t t = clock();
  for(int i = 0; i < count; ++i) {
    float x1 = a + (h * i);
    float x2 = a + (h * (i + 1));
    threads.push_back(new CFuncThread(x1, x2, eps, eps));
    threads[i]->Start();
    threads[i]->SetPriority(prior);
  }

  for(int i = 0; i < count; ++i)
    threads[i]->Wait();


  t = clock() - t;
  cout << "Час виконання процесу = " << float(t) / CLOCKS_PER_SEC << "s" << endl;

  for(int i = 0; i < threads.size(); ++i)
    delete threads[i];
    return 0;
}
