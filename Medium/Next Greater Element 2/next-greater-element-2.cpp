//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
       vector<int> ans(N,-1);
       stack<int> st;
       
       //representing the circular array into straight array
       for(int i=0;i<N;i++){
           arr.push_back(arr[i]);
       }
       
       //main code
       for(int i=0;i<2*N;i++){
           while(!st.empty() && arr[i]>arr[st.top()]){
               ans[st.top()]=arr[i];
               st.pop();
           }
           
           st.push(i%N);
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