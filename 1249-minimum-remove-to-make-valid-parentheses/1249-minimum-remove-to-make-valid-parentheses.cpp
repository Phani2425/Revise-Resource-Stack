class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //here i noticed i can solve this by using onne stack only where ii will store index of brackkets

        //HERE ONE SINGLE STACK WILL STORE THE INDEX OF BRACKETS TO CHECK WHEATHER THEY ARE VALID OR NOT
        //AT END OF THE LOOP THIS STACK WILL STORE THE INDEX VALUES OF THOSE BRACKETS WHO ARE MAKING THE PARENTHESIS INVALID
        //AT LAST WE WILL ERASE THOSE BRACKETS WHOSE INDEX IS REAMINED IN THIS STACK AND NOT GOT CANCELLED WITH ANYONE AND BY ERASING THEM WE WILL MAKE THE GIVEN PARENTHESES VALID
        stack<int> index;

        int len=s.length();
        for(int i=0;i<len;i++){
            if(isalpha(s[i])){
                continue;
            }
            else{
                if(index.empty() || s[i]=='('){ //if anyone condition is true then this will run
                    index.push(i);
                }
                else{ //means bracket is closing
                    if(s[index.top()]=='('){
                       index.pop();
                    }
                    else{
                        index.push(i);
                    }
                }
            }
        }

       if(index.empty()){
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