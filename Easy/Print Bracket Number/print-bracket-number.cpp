//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> bracketNumbers(string S)
	{
	    vector<int> ans;
	    int count=0;
	    stack<int> stk;
	    for(char ch: S){
	        if(ch != ')' && ch != '('){
	            continue;
	        }
	        else{
	            if(ch=='('){
	                count++;
	                ans.push_back(count);
	                stk.push(count);
	            }
	            else{
	                ans.push_back(stk.top());
	                stk.pop();
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.bracketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends