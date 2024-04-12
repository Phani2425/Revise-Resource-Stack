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
        //CREATING ANS VECTOR
        vector<int> ans (n,0);//it will be of size n and each index will represent a window size
        //means 0th index represent 1 window size,1stindex->2 window size,2nd index-> 3 window size etc
        //value in each index will represent the maximum of the minimum of respective window size
        //it is initialised with 0 because in future we will do comparisions so we have to initialise it with something smaller than possiblke values
        
        stack<int> st;//stack is required for finding the NSR(next smaller right) and NSL(next smaller left) of elements in the array
        //why it is required???
        //kain na ethi mu array  ra gote gote element ku utheiki pacharibi  ki tu kete window size jae minimum element or to minimum element habara range kete
        //au ei range amaku miliba from formula:- (NSR INDEX - NSL INDEX - 1) ru
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int index=st.top();
                st.pop();
                int range;
                if(st.empty()){
                    range=i; //( i is equal to {i-(-1)-1} )
                }
                else{
                   range=i-st.top()-1;
                }
                ans[range-1]=max(ans[range-1],arr[index]);
            }
            
            st.push(i);
        }
        
        //now if we couldn't find NSR for any element then that will still be in the stack
        while(!st.empty()){
            int index=st.top();
            st.pop();
            int range;
            if(st.empty()){
                range=n;
            }
            else{
                range=n-st.top()-1;
            }
            
             ans[range-1]=max(ans[range-1],arr[index]);
        }
        
        //last step
        //FILLING THE UNFILLED VALUES IN ANS VECTOR OR THE INDEXES WHICH HAVE STILL 0 IN THEM
    //VERY IMP:- THIS LOOP WILL ALWAYS RUN FROM RIGHT  TO LEFT THINK WHY???????? IF WE TRY TO RUN IT FROM LEFT TO RIGHT THEN ANS WILL BE WRONG.....
    //BECAUSE THE ELEMENT AT N-1 INDEX IS EVALUATED TO BE MINIMUM FOR N WINDOW SIZE SO THAT IS ALSO MINIMUM FOR 1,2,3,4,5....N-1 WINDOW SIZE
    //THIS MEANS THAT CAN BE A POSSIBLE CONTAINDER FOR THE PREVIOUS INDEXES OF N-1 SO THAT IS WHY WE COMPARE THAT ELEMENT TO ITS PREVIOUS ONES TO FILL THE UNFILLED VALUE
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
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
