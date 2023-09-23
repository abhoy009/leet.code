class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        int left = 0;
        int maxprofit = 0;
        
        for(int right = 1;right<n;right++){
            if(prices[right] > prices[left]){
                int profit = prices[right] - prices[left];
                maxprofit = max(maxprofit , profit);
            }
            else{
                left = right;
            }
        }
        return maxprofit;
    }
};