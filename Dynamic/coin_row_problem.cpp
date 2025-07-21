#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinRow(vector<int>& coins) {
        int n = coins.size();
        if (n == 0) return 0;
        if (n == 1) return coins[0];

        vector<int> kutumia(n + 1, 0);
        kutumia[0] = 0;
        kutumia[1] = coins[0];

        for (int i = 2; i <= n; i++) {
            kutumia[i] = max(kutumia[i - 1], kutumia[i - 2] + coins[i - 1]);
        }

        return kutumia[n];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {5, 1, 2, 10, 6, 2};

    int result = sol.coinRow(coins);
    cout << "Maximum value without adjacent coins: " << result << endl;

    return 0;
}

