class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;

        for(int i =0;i<stones.size();i++){
            maxh.push(stones[i]);
        }
        while(maxh.size()>1){
            int x = maxh.top();
            maxh.pop();
            int y = maxh.top();
            maxh.pop();
            if (x != y) {
                maxh.push(x - y);
            }

        }
        maxh.push(0);
        return maxh.top();
    }
};
