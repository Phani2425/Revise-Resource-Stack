#include<bits/stdc++.h>
using namespace std;

/*OPTIMISED APPROACH TO SOLVE THE QUESTION OF FINDING THE MINIMUM OF MAXIMUM FOR EVERY WINDOW SIZE IN AN ARRAY
TIME COMP=  O(N)
SPACE COMP=O(N) {FOR EXTRA SPACE OF STACK}*/

vector<int> MinOfMax(vector<int>arr,int n){
    vector<int> ans(n,INT_MAX);
    stack<int> st;

    //FINDING NEXT GREATER RIGHT AND NEXT GREATER LEFT OF EACH ELEMENT IN THE ARRAY FROM WHICH WE CAN GATE THE RANGE OR MAXIMUM WINDOW SIZE UPTO WHICH THAT ELEMENT WILL BE MAXIMUM
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            int index=st.top();
            st.pop();
            int range;
            if(st.empty()){
                range=i;
            }
            else{
                range=i-st.top()-1;
            }

            ans[range-1]=min(ans[range-1],arr[index]);
        }
        st.push(i);
    }

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

         ans[range-1]=min(ans[range-1],arr[index]);    
    }

   // Filling unfilled values of ans
    //VERY IMP:- THIS LOOP WILL ALWAYS RUN FROM RIGHT  TO LEFT THINK WHY???????? IF WE TRY TO RUN IT FROM LEFT TO RIGHT THEN ANS WILL BE WRONG.....
    //BECAUSE THE ELEMENT AT N-1 INDEX IS EVALUATED TO BE MAXIMUM FOR N WINDOW SIZE SO THAT CAN BE MAXIMUM FOR 1,2,3,4,5....N-1 WINDOW SIZE
    //THIS MEANS THAT CAN BE A POSSIBLE CONTAINDER FOR THE PREVIOUS INDEXES OF N-1 SO THAT IS WHY WE COMPARE THAT ELEMENT TO ITS PREVIOUS ONES TO FILL THE UNFILLED VALUE
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = min(ans[i], ans[i + 1]);
    }

    return ans;
}

int main(){
vector<int> arr{10,20,15,50,10,70,30};
int n=arr.size();
vector<int> ans=MinOfMax(arr,n);
//printing the ans vector
for(int in:ans){
    cout<<in<<" ";
}
    return 0;
}
