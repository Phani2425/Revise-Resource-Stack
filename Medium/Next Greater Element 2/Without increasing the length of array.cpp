//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
       vector<int> ans(N,-1);
       stack<int> st;
       
       //WAY 2 :- WITHOUT INCREASING THE LENGTH OF THE GIVEN ARRAY
       int index=0;
       int iteration=2*N;
       while(iteration--){
           while(!st.empty() && arr[index]>arr[st.top()]){
               ans[st.top()]=arr[index];
               st.pop();
           }
           st.push(index);
           
           //INCREMENTING THE INDEX SUCH THAT IT WILL FOLLOW THE CIRCULAR PROPERTY OF ARRAY
           index=(index+1)%N;
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
