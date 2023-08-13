#define ll long long 
class Solution {
public:
    int mySqrt(ll x) {
        ll s = 0;
        ll e = x;
        ll mid = s + (e-s)/2;
        ll target = x;
        ll ans = -1;
            
        while(s<=e)
        {
            if(mid*mid == target){
                return mid;
            }
            else if(mid*mid > target){
                e = mid -1;
            }
            else{
                ans = mid;
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};