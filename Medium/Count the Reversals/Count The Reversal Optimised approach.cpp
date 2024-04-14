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
        return -1;//we can check this validity from starting by cheking the length of the input string in this same way
    }
    //if nothing returns then they can become valid 

    int reversal=0;//this will store the no of reversals
    
    /* one thing i noticed that the brackets who remained in the stack can,t form pairsbecause of some reasons:
    1.every two adjacent brackets may in the form of:- ")(" or "((" or "))" ...i.e either same character or different character
    so to make ")(" valid we need 2 reversal i.e "()" , to make "((" or "))" reversal we need only one reversal i.e "()"*/
    //so according to ths we will calculate the no of reversals
    
    while(!st.empty()){
        char ch=st.top();//mene ek adjacent ko bahar nikala
        st.pop();
        if(ch==st.top()){
            reversal+=1;
        }
        else{
            reversal+=2;
        }
        st.pop();//mene unka kaam khatam karke matlab kuch reversal karke dono ko cancel out kardia to 2nd one ko pop  kardia
    }
    
    return reversal;
}
