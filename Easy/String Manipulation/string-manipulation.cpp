//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removeConsecutiveSame(vector <string > v) 
    {
        stack <string> stk;
        for(int i=0;i<v.size();i++){
            if(stk.empty()){
                stk.push(v[i]);
            }
            else{
                if(v[i]==stk.top()){
                    stk.pop();
                }
                else{
                    stk.push(v[i]);
                }
            }
        }
        
        return stk.size();
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
         string s;
         vector<string> v;
         for(int i=0;i<n;i++)
         {
             cin>>s;
             v.push_back(s);
         }
         Solution ob;
         cout<< ob.removeConsecutiveSame(v) <<endl;
     }
	
	
	
	
	return 0;
}
// } Driver Code Ends