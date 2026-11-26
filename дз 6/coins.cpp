//leetocode https://leetcode.com/problems/coin-change/description/

#include <limits.h>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> v(amount + 1, INT_MAX - 1);
        v[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if (coin <= i)
                    v[i] = std::min(v[i], v[i - coin] + 1);
            }
        }

        if (v[amount] == INT_MAX - 1)
            return -1;

        return v[amount];
    }
};
