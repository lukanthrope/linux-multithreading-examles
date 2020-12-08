#include <iostream> 
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

const int MAX_THREAD_COUNT = 8;
int N, threadCount;
int *arr;
pthread_t Threads[MAX_THREAD_COUNT];

void randomArray();
void bubbleSortDown();
void swap(int *xp, int *yp);
void printArray();

void *threadFunction(void *param) {
  bubbleSortDown();
  int id = *static_cast<int*>(param);
  std::cout << "\nThread #" << id << " is done";
  return 0;
}


int main() {

  randomArray();
  printArray();
  
  std::cout << "Input number of threads " << std::endl;
  std::cin >> threadCount;

  int threadNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8};

  for (int i = 0; i < threadCount; i++) {
    pthread_create(&Threads[i], NULL, &threadFunction, &threadNumbers[i]); 
  }
  for (int i = 0; i < threadCount; ++i) {
    pthread_join(Threads[i], NULL);
  }


  printArray();
}

void randomArray() {
  std::cout << "Input number of elements " << std::endl;
  std::cin >> N;

  arr = new int[N];

  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    arr[i] = rand() % 1000000;
  }
}

void printArray() {
  std::cout << std::endl;
  for (int i = 0; i < N; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
   
void bubbleSortDown()  
{  
    int i, j;  
    for (i = 0; i < N - 1; i++)      
 
    for (j = 0; j < N - i - 1; j++)  
        if (arr[j] < arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
