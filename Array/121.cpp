#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_cost = prices[0], profit = 0;

        for (int i = 1; i < n; ++i)
        {
            profit = max(max_profit, prices[i] - min_cost);
            min_cost = min(min_cost, prices[i]);
        }
        return profit;

    }
};