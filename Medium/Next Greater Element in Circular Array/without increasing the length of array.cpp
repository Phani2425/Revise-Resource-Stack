//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> ans(n,-1);
       stack<int> st;
       
       //WAY 2 :- WITHOUT INCREASING THE LENGTH OF THE GIVEN ARRAY
       int index=0;
       int iteration=2*n;
       while(iteration--){
           while(!st.empty() && arr[index]>arr[st.top()]){
               ans[st.top()]=arr[index];
               st.pop();
           }
           st.push(index);
           
           //INCREMENTING THE INDEX SUCH THAT IT WILL FOLLOW THE CIRCULAR PROPERTY OF ARRAY
           index=(index+1)%n;
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends
