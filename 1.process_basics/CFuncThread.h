#ifndef CFuncThreadH
#define CFuncThreadH

#include "CThread.h"

#include <math.h>
#include <vector>

class CFuncThread : public CThread {
public:

  CFuncThread(float setA = 0,
              float setB = 1,
              float setEps = 0.01,
              float setStep = 0.01) :
              a(setA),
              b(setB),
              eps(fabs(setEps)),
              step(setStep) {
    if(a > b) {
      float tmp = a;
      a = b;
      b = tmp;
    } 
  }

  void Execute(void) {
    for(float x = a; x < b; x += step) {
      int   n = 2;
      float iter = 0,
            y = 1;
      do {
        iter = pow(x, n - 1) * pow(-1, n + 1);
        for(int i = 2; i <= n; ++i)
          iter *= (((2. * i) - 3.) / ((2. * i) - 2.));
        y += iter;
        ++n;
      }
      while(fabs(iter) >= eps && n < 1000);

      float yy = 1 / pow(1 + x, 0.5);
      std::cout << "x = " << x << ";   y = " << y << ";   F_teylor = " << yy << ";" << endl;
    }
  }

private:
  float a, b, eps, step;

};

#endif
 