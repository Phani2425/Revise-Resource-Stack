class Solution {
public:
        //copied the whole solution from the leetcode-56 merge intervals
        vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < ans.back()[1]) {
                // Merge intervals by updating the end time
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hor; //vector for checking that if three line possible in horizontal direction

        vector<vector<int>> ver;//for vertical direction

        for(auto & rect : rectangles){
            int x1=rect[0];
            int x2=rect[2];
            int y1=rect[1];
            int y2=rect[3];
            hor.push_back({x1,x2});
            ver.push_back({y1,y2});
        }

        return (merge(hor).size() >= 3) || (merge(ver).size() >= 3);

    }
};