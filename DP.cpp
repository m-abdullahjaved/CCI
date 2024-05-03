#include "Headers.h"

int MemoizedCatalan(int n, vector<int>& Cs) {
    if (Cs[n] != -1)
        return Cs[n];

    int Sum = 0;
    for (int i = 0; i < n; i++)
        Sum += MemoizedCatalan(i, Cs) * MemoizedCatalan(n - 1 - i, Cs);

    Cs[n] = Sum;

    return Sum;
}
int catalan(int n) {
    if (n == 0)
        return 1;
    vector<int> Cs(n + 1, { -1 });
    Cs[0] = 1;
    return MemoizedCatalan(n, Cs);
}

long long catalanDP(int n) {
    vector<long long> Cs(n + 1, { 0 });
    Cs[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            Cs[i] += Cs[j] * Cs[i - 1 - j];

    return Cs[n];
}

long long climbStairs(int n) {
    vector<long long> Steps(n + 1, { 0 });
    Steps[0] = 1;
    Steps[1] = 2;

    for (int i = 2; i < n; i++)
        Steps[i] = Steps[i - 1] + Steps[i - 2];

    return Steps[n - 1];
}

int memoized_tribonacci(int n, vector<int>& Ts) {
    if (Ts[n] != -1)
        return Ts[n];

    Ts[n] = memoized_tribonacci(n - 1, Ts) + memoized_tribonacci(n - 2, Ts) + memoized_tribonacci(n - 3, Ts);
    return Ts[n];
}
int tribonacci(int n) {
    if (n == 0)
        return 0;
    else if (n <= 2)
        return 1;
    vector<int> Ts(n + 1, { -1 });
    Ts[0] = 0;
    Ts[1] = 1;
    Ts[2] = 1;
    return memoized_tribonacci(n, Ts);
}

int tribonacciDP(int n) {
    if (n == 0)
        return 0;
    else if (n <= 2)
        return 1;
    vector<int> Ts(n + 1, { -1 });
    Ts[0] = 0;
    Ts[1] = 1;
    Ts[2] = 1;

    for (int i = 3; i <= n; i++)
        Ts[i] = Ts[i - 1] + Ts[i - 2] + Ts[i - 3];

    return Ts[n];
}
