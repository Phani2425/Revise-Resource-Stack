class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*THERE WILL BE TWO CASES WHERE A PRENTTHESIS WILL BE INVALID:- 
        CASE 1:- WHEN AT A POINT NO OF CLOSING PARENTHESIS IS MORE THAN THE NO OF OPENING PARENTHESES
        ->we will handle this with a loop which will traverse the string from left towards right and whenever at any point no of closing par becomes more than no of opening
        we will erase that extra closing par from the string

        CASE 2:- WHEN THE NO OF OPENING PARENTHESIS IS MORE THAN THE NO OF CLOSING PARENTHESE 
        ->we will handle this with a loop which will traverse the string from right towards left and whenever at any point no of opening par becomes more than no of closing
        we will erase that extra opening par from the string*/
        stack<int> index;
         
        // CASE 1
        int len=s.length();
        int open=0;
        string result="";
        for(char ch:s){
            if(isalpha(ch)){
                result.push_back(ch);
            }
            else{
               if(ch=='('){
                result.push_back(ch);
                open++;
               }
               else{
                if(open==0){
                    continue;
                }
                else{
                    open--;
                    result.push_back(ch);
                }
               }
            }
        }
        

        //CASE 2
        int r_len=result.length();
        int close=0;
        string final_result="";
        for(int i=r_len-1;i>=0;i--){
            if(isalpha(result[i])){
                final_result.push_back(result[i]);
            }
            else{
               if(result[i]==')'){
                final_result.push_back(result[i]);
                close++;
               }
               else{
                if(close==0){
                    continue;
                }
                else{
                    close--;
                    final_result.push_back(result[i]);
                }
               }
            }
        }

    reverse(final_result.begin(),final_result.end());
       return final_result;
    }
};