#include <iostream>
#include <vector>

const long long MAX_VAL = 500; 
std::vector<long long> fibMem(MAX_VAL, 0);

// Recursive (top-down) approach with Memoization
long long FibonacciMem(int n)
{
    if(fibMem[n] != 0)
        return fibMem[n];

    if (n == 0 || n == 1)
        fibMem[n] = 1;
    else
        fibMem[n] = FibonacciMem(n-1) + FibonacciMem(n-2);

    return fibMem[n];
}

int main()
{
    long long fibNum = FibonacciMem(50);
    std::cout << "Fibonacci(50): " << fibNum << std::endl;
}
