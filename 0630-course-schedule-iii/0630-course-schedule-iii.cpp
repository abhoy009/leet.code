class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];  // Sort by end time
        });
        
        priority_queue<int> pq;  // Max heap to store course durations
        
        int currentTime = 0;
        for (const vector<int>& course : courses) {
            currentTime += course[0];  // Add course duration to current time
            pq.push(course[0]);  // Add course duration to the heap
            
            if (currentTime > course[1]) {
                currentTime -= pq.top();  // Remove the longest course
                pq.pop();
            }
        }
        
        return pq.size();  // Number of courses that can be taken
    }
};
