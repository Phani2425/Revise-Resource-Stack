class Solution {
public:
    int minAddToMakeValid(string s) {
       //edge case  where  string is empty
       if(s.length()==0){
        return 0;
       } 

       //creating stack
       stack<char> stk;
       for(char ch:s){
        if(stk.empty() || ch=='('){
            stk.push(ch);
        }
        else{
            if(stk.top()=='('){
                stk.pop();
            }
            else{
                stk.push(ch);
            }
        }
       }

       return stk.size();
       
    }
};