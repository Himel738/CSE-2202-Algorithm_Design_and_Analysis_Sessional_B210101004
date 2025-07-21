
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
        vector<vector<int>> kutumia(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    kutumia[i][w] = max(kutumia[i - 1][w], val[i - 1] + kutumia[i - 1][w - wt[i - 1]]);
                } else {
                    kutumia[i][w] = kutumia[i - 1][w];
                }
            }
        }

        return kutumia[n][W];
    }
};

int main() {
    Solution sol;

    vector<int> weights = {1, 3, 4, 5};
    vector<int> values  = {1, 4, 5, 7};
    int capacity = 7;
    int n = weights.size();

    int result = sol.knapsack(capacity, weights, values, n);
    cout << "Maximum value in Knapsack: " << result << endl;

    return 0;
}
