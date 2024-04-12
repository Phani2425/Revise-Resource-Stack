//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        //BRUTE FORCE APPROACH THAT WILL GIVE TLE FOR MOST OF CASE AS IT'S T.C IS O(N^3) 
        //SPACE COMPLEXITY = O(N)
        
        vector<int> ans(n,0); //in this index=0 represent 1 window size i.e here each index i represent i+1 window size and value in index i represent the maximum of the minimum of i+1 window size in the array 
        
        for(int i=0;i<=n-1;i++){ //using this loop i will fill the ans array having size n i.e 0 to n-1 index
        //in this i=0 represent 1 window size i.e here each index i represent i+1 window size and value in index i represent the maximum of the minimum of i+1 window size in the array 
            for(int j=0;j<=n-i-1;j++){ //shows starting index of a window
                int num=INT_MAX;
                for(int k=j;k<=j+i;k++){ //this traverses a window from its starting index to end index of that window
                    num=min(num,arr[k]);
                }
                //updating the ith index of ans
                ans[i]=max(ans[i],num);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
