#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    //TLE when dealing with large inputs
    int curr_profit = 0, max_profit = 0;

    for(int left = 0; left < prices.size(); left++) {
        for(int right = left + 1; right < prices.size(); right++) {
            if(prices[right] < prices[left]) continue;
            curr_profit = prices[right] - prices[left];
            max_profit = max(max_profit, curr_profit);
        }
        curr_profit = 0;
    }

    return max_profit;
}

int maxProfit1(vector<int>& prices) {
    //still kinda slow but easy to explain
    int buy = INT_MAX, profit = 0;
    int n = prices.size();
    for(int i = 0; i < n; i++) {
        buy = min(buy, prices[i]);
        profit = max(profit, prices[i] - buy);
    }
    return profit;
}

int maxProfit2(vector<int>& prices) {
    int profit = 0, n = prices.size(), buy = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(buy > prices[i]) buy = prices[i];
        profit = max(profit, prices[i] - buy);
    }
    return profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    cout << maxProfit2(prices);

    return 0;
}