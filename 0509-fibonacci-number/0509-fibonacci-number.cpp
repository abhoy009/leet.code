class Solution {
public:
    int recSolve(int n) {
        if(n==0 || n==1){
            return n;
        }
        int ans = recSolve(n-1) + recSolve(n-2);
        return ans;
    }
    
    int topDown(int n,vector<int>& dp){
        if(n==0 || n==1){
            return n;
        }
        //step3: check if ans already exists
        if(dp[n] != -1){
            return dp[n];
        }
        //step2: replace ans with dp[n]
        dp[n] = topDown(n-1,dp) + topDown(n-2,dp);
        return dp[n];
    }
    
    int fib(int n){
        // int ans = recSolve(n);
        // return ans;
        
        //step1: create dp array
        vector<int> dp(n+1, -1);
        int ans = topDown(n,dp);
        return ans;
    }
};