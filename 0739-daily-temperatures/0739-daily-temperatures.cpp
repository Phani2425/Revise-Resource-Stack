class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size=temperatures.size();
        vector<int> ans(size,0);
        stack<int> st;

        for(int i=0;i<size;i++){

            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;

    }
};