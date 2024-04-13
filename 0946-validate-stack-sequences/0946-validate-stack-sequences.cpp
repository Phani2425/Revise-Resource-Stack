class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int> st;
        while(i != pushed.size()){
           if(st.empty() || popped[j] != st.top()){
            st.push(pushed[i]);
            i++;
           }
           else if(popped[j] == st.top()){
            st.pop();
            j++;
           }
        }

        while(j != popped.size()){
            if(popped[j]==st.top()){
                st.pop();
                j++;
            }
            else{
                return false;
            }
        }

        return true;
    }
};