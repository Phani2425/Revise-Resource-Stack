//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);

void _getMinAtPop(stack<int>s);

// } Driver Code Ends
//User function Template for C++

//function to find out current minimum in the array from s.size()-1 index to 0th index
int min(stack<int>s,int index){
    vector<int>arr;
    while(!s.empty()){
        arr.push_back(s.top());
        s.pop();
    }
    int minimum=INT_MAX;
    for(int i=index;i>=0;i--){
        minimum=min(minimum,arr[i]);
    }
    return minimum;
}

//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
    stack<int> stk;
   for(int i=0;i<n;i++){
       stk.push(arr[i]);
   }
   return stk;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    
    while(!s.empty()){
        cout<<min(s,s.size()-1)<<" ";
        s.pop();
    }
}

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    
	    cout<<endl;
	    
	}
	return 0;
}


// } Driver Code Ends