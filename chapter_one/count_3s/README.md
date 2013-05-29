# Count threes

Given a random sequence of _n_ values:


![x1, x2, x3, ..., xn](http://latex.codecogs.com/svg.latex?\%20x_1,x_2,x_3,...,x_{n%20-%201} "Sequence")

Where 0 < _x_ < 10.

Sum the total occurrences of '_3_'


All perf tests are running on a Mac OS X 10.7.5 with an Intel i7 3520M 2.9 GHz (http://ark.intel.com/products/64893/)

## Iterative

`make iterative && ./iterative`

The iterative version does not use any threads,  it is simply a method that iterates over every element in the sequence, for each element it checks the value of `Xn == 3` and increments a local count variable.

Averages: **1.039s** where `_n_ = 100000000`

## Thread V1

`make threadv1 && ./threadv1`

The version one of the threaded implementation attempts to demonstrate performance degradation due to lock contention.  Although we've parallelised the algorithm, due to lock contention when incrementing the count, we see a huge performance degradation.

**1** Threads:  Averages **1.153s** where `_n_ = 100000000`

**2** Threads:  Averages **6.585s** where `_n_ = 100000000`

**4** Threads:  Averages **7.403s** where `_n_ = 100000000`

As expected a single thread is comparable to the iterative solution.  However, increasing the number of threads degrades performance.  This is due to the fact that a thread blocks while waiting to update the count.  If all threads are consistently waiting for the lock to be freed, we can expect threads to be waiting for each other rather than working.

## Thread V2

`make threadv2 && ./threadv2`

This version is almost identical to the Thread V1 implementation however it is capable of being more performant than the iterative implementation.  To avoid lock contention every time the thread finds a _3_ we simply keep a local count of threes (local from the thread and the code's point of view) and update the outer value once the loop has completed.

**1** Threads: Averages **1.144s** where `n = 100000000`

**2** Threads: Averages **1.024s** where `n = 100000000`

**4** Threads: Averages **0.990s** where `n = 100000000`
