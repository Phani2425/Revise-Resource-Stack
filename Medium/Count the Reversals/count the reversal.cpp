//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    stack<char> st;
    int open=0;
    
    //first i will try to remove the brackets which get cancelled out by each other and keep only only those brackets which make the whoole parenthesis invalid
    for(char ch: s){
        if(st.empty() || ch=='{'){
            st.push(ch);
        }
        else{
            if(st.top()=='{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    
    //checking if the string is alredy valid
    if(st.empty()){
        return 0;
    }
    
    //now in the stack there are those brcakets who make the whole  parenthesis invalid 
    //so our work is to check if can they be valid and if yes then we will do that by reversals after which the whole string will be valid
    
    //checking wheather they can be valid (if they are odd in count then they can never be valid as only even count brackets have chance of becoming valid)
    if(st.size()%2 != 0){
        return -1;
    }
    //if nothing returns then they can become valid 
    //transfering them to a string for traversing on them and count the no of reversal we can make to make them valid
    s.clear();
    while(!st.empty()){
        s.push_back(st.top());
        st.pop();
    }
    
    reverse(s.begin(),s.end());
    
    int reversal=0;//this will store the no of reversals
    int opencount=0;
    for(char ch:s){
        if(ch=='}'){
          if(opencount==0){//agar ch '}' hai au  to aur iske piche koi opening bracket bhi  nehi thi (opencount==0) to hame ise '{' me convert karna hi padega
          //warna ye kese valid hoga 
          //so ise ham open bracket me convert kardenge aur opencount ko badhaenge aur revesal ko bhi ek se badhayenge
            reversal++;
            opencount++;
            }
          else{ //agar opencount==0 nehi hai matlab is close bracket keliye piche ek open bracket hai to opencount-- kardo
            opencount--;
            }
        }
        else{//agar character '{' ho to kuch mat karo bas opencount badaha do
            opencount++;
        }
    }
    
    if(opencount != 0){//agar loop khatam hone ke baad bhi opencount 0 na hua matlab ab wo invalid part me open brackets close one se jyada hai 
    //to phir ab wo bacha hua open brackets ko cancel kese karenge :--- unmese adha ko close me convert karke
        reversal+=opencount/2;
    }
    
    return reversal;
}
