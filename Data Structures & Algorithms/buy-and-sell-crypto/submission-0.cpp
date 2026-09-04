class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_profit=0;
        int profit=0;
        int sell_day=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>sell_day){
                sell_day=prices[i];
            }
            else{
                profit = sell_day-prices[i];
                if(profit>max_profit){
                    max_profit = profit;
                }
            }
        }
        return max_profit;
        
    }
};
