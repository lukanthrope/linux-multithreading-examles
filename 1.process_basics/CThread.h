#ifndef CThreadH
#define CThreadH

#include <pthread.h>
#include <iostream>
#include <time.h>

using namespace std;

class CThread {
public:

  CThread() : started(false) {}

  virtual ~CThread() {
    if(started)
      pthread_join(thread, NULL);
  }

  int Start() {
    if(started) pthread_join(thread, NULL);

    int err = pthread_create(&thread, NULL, &ThreadMethod, this);
    if(err) cout << "Error (" << err << ") thread creating!" << endl;

    return err;
  }

  void SetPriority(int set) {
    if(started)
      pthread_setschedprio(thread, set);
  }

  void Wait() {
    if(started)
      pthread_join(thread, NULL);
  }

  void PrintExecuteTime() const {
    printf("%ld s %ld ns", execute_time.tv_sec, execute_time.tv_nsec / 1000000);
  }

protected:

  virtual void Execute(void) {}

private:

  pthread_t thread;

  bool started;

  struct timespec execute_time;

  static void *ThreadMethod(void *ob) {
    CThread* ptr = (CThread*)(ob);
    ptr->started = true;
    ptr->Execute();
    clockid_t cid;
    pthread_getcpuclockid(ptr->thread, &cid);
    clock_gettime(cid, &ptr->execute_time);
    ptr->started = false;
    return 0;
  }

};

#endif
