# linux-multithreading-examlpes

## to run
```
g++ -pthread -o output main.cpp
./output
```
## to run the fouth example

```
g++ -fPIC -shared mutex.cpp -o shared_lib.so
g++ use_shared.cpp -ldl -pthread  -o shared_build
./shared_build
```