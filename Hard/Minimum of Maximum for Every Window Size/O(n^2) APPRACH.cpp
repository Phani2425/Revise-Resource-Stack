#include<bits/stdc++.h>
using namespace std;

/*BRUTE FORCE APPROACH TO SOLVE THE QUESTION OF FINDING THE MINIMUM OF MAXIMUM FOR EVERY WINDOW SIZE IN AN ARRAY
TIME COMP=  O(N^2)
SPACE COMP=O(1)*/

vector<int> MinOfMax(vector<int>arr,int n){
    vector<int> ans(n,INT_MAX);

    for(int i=0;i<n;i++){
        int index=0;
        int maxm=INT_MIN;
        for(int j=i;j<n;j++){
           maxm=max(maxm,arr[j]);
           ans[index]=min(ans[index],maxm);
           index++;
        }
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