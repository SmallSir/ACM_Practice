class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[100005];
        //dp[0] = 1;
        for(int i = 1;i <= amount;i++)
            dp[i] = INT_MAX-5;
        dp[0] = 0;
        for(int i = 0;i < coins.size();i++)
        {
            for(int j = coins[i];j <= amount;j++)
            {
                dp[j] = min(dp[j],dp[j-coins[i]] + 1);
            }
        }
        if(dp[amount] == INT_MAX-5)
            return -1;
        else
            return dp[amount];
    }
};