class Solution {
public:
    int recSolve(int n) {
        if(n==0 || n==1){
            return n;
        }
        int ans = recSolve(n-1) + recSolve(n-2);
        return ans;
    }
    int fib(int n){
        int ans = recSolve(n);
        return ans;
    }
};