class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        stack<pair<int, int>> s;
        int pseudoIleft = -1;

        for (int i = 0; i < heights.size(); i++) {
            if (s.empty())
                left.push_back(pseudoIleft);
            else if (!s.empty() && s.top().first < heights[i]) {
                left.push_back(s.top().second);
            } else if (!s.empty() && s.top().first >= heights[i]) {
                while (!s.empty() && s.top().first >= heights[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    left.push_back(pseudoIleft);
                } else {
                    left.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }

        vector<int> right;
        stack<pair<int,int>> sr;
        int pseudoIright = heights.size();

        for (int i = heights.size() - 1; i >= 0; i--) {
            if (sr.empty())
                right.push_back(pseudoIright);
            else if (!sr.empty() && sr.top().first < heights[i]) {
                right.push_back(sr.top().second);
            } else if (!sr.empty() && sr.top().first >= heights[i]) {
                while (!sr.empty() && sr.top().first >= heights[i]) {
                    sr.pop();
                }
                if (sr.empty()) {
                    right.push_back(pseudoIright);
                } else {
                    right.push_back(sr.top().second);
                }
            }
            sr.push({heights[i], i});
        }
        reverse(right.begin(), right.end());

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};