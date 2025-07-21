
#include <bits/stdc++.h>
using namespace std;

int fibonacciUtil(int n, vector<int>& kutumia) {
    if (n <= 1) {
        return n;
    }

    if (kutumia[n] != -1) {
        return kutumia[n];
    }

    kutumia[n] = fibonacciUtil(n - 1, kutumia) + fibonacciUtil(n - 2, kutumia);

    return kutumia[n];
}

int fibonacci(int n) {
    vector<int> kutumia(n + 1, -1);
    return fibonacciUtil(n, kutumia);
}

int main() {
    int n = 5;
    int result = fibonacci(n);
    cout << result << endl;
    return 0;
}
