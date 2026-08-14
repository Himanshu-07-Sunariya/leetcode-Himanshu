class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // array method
        // all possible combo
        int mini=prices[0];
        // minimum till now
        int profit=0;
        int n=prices.size();

        for(int i=1; i<n; i++){
            mini=min(mini,prices[i]);
            profit=max(profit,prices[i]-mini);
        }

        return profit;
    }
};