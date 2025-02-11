#include <iostream>
#include <vector>

// In the example here the Table is local in the function, in general with dynamic programming it may be a good idea to cache the table by either making it global or static.
// Depends on a case-to-case basis

// Tabulation (bottom-up) iterative approach using array, O(n) space complexity
long long FibonacciTab(int n)
{   
    if (n == 0) return 1;
    if (n == 1) return 1;

    std::vector<long long> fibMem(n+1);

    fibMem[0] = 1;
    fibMem[1] = 1;

    for(int i = 2; i <= n; i++)
        fibMem[i] = fibMem[i-1] + fibMem[i-2];

    return fibMem[n];
}

// Tabulation approach using three variables, O(1) space complexity
long long FibonacciTabOpt(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;

    // previousVal would be fibonacci(i-1)
    // previousPreviousVal would be fibonacci(i-2)
    // curVal is previousVal + previousPreviousVal
    long long previousVal = 1, previousPreviousVal = 1, curVal;

    for(int i = 2; i <= n; i++)
    {
        curVal = previousVal + previousPreviousVal;
        previousPreviousVal = previousVal;
        previousVal = curVal;
    }

    return curVal;
}

int main()
{
    long long fibNum = FibonacciTab(50);
    long long fibNum2 = FibonacciTabOpt(50);

    std::cout << "Fibonacci(50) = " << fibNum << " | " << fibNum2 << std::endl;
}
