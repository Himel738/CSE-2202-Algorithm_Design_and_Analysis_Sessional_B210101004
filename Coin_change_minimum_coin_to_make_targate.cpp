
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int inf = 1e9;
        vector<vector<int>> kutumia(coins.size() + 1, vector<int>(amount + 1, inf));

        for (int i = 0; i <= coins.size(); i++) {
            kutumia[i][0] = 0;
        }

        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] > j) {
                    kutumia[i][j] = kutumia[i - 1][j];
                } else {
                    kutumia[i][j] = min(kutumia[i - 1][j], 1 + kutumia[i][j - coins[i - 1]]);
                }
            }
        }

        return (kutumia[coins.size()][amount] == inf) ? -1 : kutumia[coins.size()][amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = sol.coinChange(coins, amount);
    if (result != -1)
        cout << "Minimum coins required: " << result << endl;
    else
        cout << "Amount cannot be formed with given coins." << endl;

    return 0;
}
