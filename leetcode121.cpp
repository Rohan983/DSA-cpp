#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    // Brute Force
    // int max_profit = 0;
    // for(int i = 0; i<prices.size()-1 ; i++){
    //     for(int j = i + 1; j < prices.size(); j++){
    //         max_profit = max(prices[j] - prices[i], max_profit);
    //     }
    // }
    // return max_profit;

    int max_profit = 0;
    int best_buy = prices[0];

    for(int i = 1; i < prices.size(); i++){
        max_profit = max(prices[i]-best_buy, max_profit);
        best_buy = min(prices[i], best_buy);
    }

    return max_profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices)<<endl;
    return 0;
}