g++ -ggdb main.cpp headerfunction.cpp -o maintest `pkg-config --cflags --libs opencv`
                        or
g++ -o maintest -ggdb main.cpp headerfunction.cpp `pkg-config --cflags --libs opencv`

////

clang++ -ggdb main.cpp headerfunction.cpp -o maintest `pkg-config --cflags --libs opencv`

                        or

clang++ -o maintest -ggdb main.cpp headerfunction.cpp `pkg-config --cflags --libs opencv`




