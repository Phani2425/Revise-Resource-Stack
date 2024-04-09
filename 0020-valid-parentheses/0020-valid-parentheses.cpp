class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        for(char ch:s){
           if(stk.empty() || ch=='(' ||ch=='{' || ch=='['){
            stk.push(ch);
           }
           else{
            if(ch==')'){
                if(stk.top()=='('){
                    stk.pop();
                }
                else{
                    stk.push(ch);
                }
            }
              if(ch=='}'){
                if(stk.top()=='{'){
                    stk.pop();
                }
                else{
                    stk.push(ch);
                }
            }
              if(ch==']'){
                if(stk.top()=='['){
                    stk.pop();
                }
                else{
                    stk.push(ch);
                }
            }
           }
        }

        if(stk.empty()){
            return true;
        }
        return false;
    }
};