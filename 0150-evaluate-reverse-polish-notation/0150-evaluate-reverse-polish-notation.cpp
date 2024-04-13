class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a,b; //a=first operand, b=second operand
        stack<int> st;
        string add="+";
        string sub="-";
        string mul="*";
        string div="/";

        for(string s:tokens){
            if(s==add){
                b=st.top();st.pop();
                a=st.top();st.pop();
                st.push(a+b);
            }
            else if(s==sub){
                b=st.top();st.pop();
                a=st.top();st.pop();
                st.push(a-b); 
            }
             else if(s==mul){
                b=st.top();st.pop();
                a=st.top();st.pop();
                st.push(a*b); 
            }
             else if(s==div){
                b=st.top();st.pop();
                a=st.top();st.pop();
                st.push(a/b); 
            }
            else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};