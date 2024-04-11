//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
    //HERE I WILL USE THE CONCEPT OF STORING TWO  ELEMENT AT  ONE PLACE SUCH THA I CAN RETRIVE ONE OF THEM BY MODULUS OPERATOR AND ANOTHER ONE BY DIVISION OPERATION
    //HERE I AM RETRIVING THE PUSHED NUMBER BY DIVIDING THE STORED  NUMBER BY 101 AND RETRIVING THE MINIMUM VALUE BY DOING MODULUS OF THE STORED NUMBER WITH 101
       
       /*returns min element from stack*/
       int getMin(){
           
           if(s.empty()){
               return -1;
           }
           else{
               return s.top()%101;
           }
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           if(s.empty()){
               return -1;
           }
           else{
               int ans=s.top()/101;
               s.pop();
               return ans;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
         if(s.empty()){
             s.push(x*101+x);
         } 
         else{
             int minimum=min(x,s.top()%101);
             s.push(x*101+minimum);
         }
         
           
       }

             //here space complexity = o(1)
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
