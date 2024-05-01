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

int main() {
    long long i = 0;
    while (i >= 0) {
        cout << i << ": " << catalanDP(i) << endl;
        i++;
    }
    return 0;
}