$ clang++ -std=c++20 -fpic -c dash.cpp fci.cpp
$ clang++ -std=c++20 -shared dash.o -o libdash.so
$ clang++ -std=c++20 main.cpp fci.o -L. -ldash
$ LD_LIBRARY_PATH=. ./a.out
