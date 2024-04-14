class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //THIS STACK WILL STORE THE BRACKETS TO CHECK WHEATHER THEY ARE VALID OR NOT
        stack<char> bracket;
        //THIS STACK WILL STORE THE INDEX VALUES OF THOSE BRACKETS WHO ARE MAKING THE PARENTHESIS INVALID
        //AT LAST WE WILL ERASE THOSE BRACKETS WHOSE INDEX IS STORED IN THIS STACK AND MAKE THE GIVEN PARENTHESES VALID
        stack<int> index;

        int len=s.length();
        for(int i=0;i<len;i++){
            if(isalpha(s[i])){
                continue;
            }
            else{
                if(bracket.empty() || s[i]=='('){ //if anyone condition is true then this will run
                    bracket.push(s[i]);
                    index.push(i);
                }
                else{ //means bracket is closing
                    if(bracket.top()=='('){
                       bracket.pop();
                       index.pop();
                    }
                    else{
                        bracket.push(')');
                        index.push(i);
                    }
                }
            }
        }

       if(bracket.empty()){
          //means parentheses is already valid
          return s;
       } 
       else{
          while(!index.empty()){
               //we will erase these indexes 
               s.erase(index.top(),1);
               index.pop();
          }
       }

       return s;
    }
};