class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1;
        long long r = *max_element(piles.begin(), piles.end());
        
        while(l < r){
            long long k = l + (r-l)/2;
            long long time = 0;
            for(int p: piles){
                time += (p + k - 1) / k;  // Equivalent to ceil(p / k)
            }
            if(time <= h){
                r = k;
            }else{
                l = k + 1;
            }
        }
        return l;
    }
};