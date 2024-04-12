#include<bits/stdc++.h>
using namespace std;

/*BRUTE FORCE APPROACH TO SOLVE THE QUESTION OF FINDING THE MINIMUM OF MAXIMUM FOR EVERY WINDOW SIZE IN AN ARRAY
TIME COMP=  O(N^3)
SPACE COMP=O(1)*/

vector<int> MinOfMax(vector<int>arr,int n){
    vector<int> ans(n,INT_MAX);

    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-i-1;j++){
            int num=INT_MIN;
            for(int k=j;k<=j+i;k++){
                num=max(num,arr[k]);
            }
            ans[i]=min(ans[i],num);
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
