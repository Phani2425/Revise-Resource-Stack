class Solution {
public:
    int minAddToMakeValid(string s) {
      int opencount=0;
      int addition=0;
      for(char ch:s){
        if(ch=='('){
            opencount++;
        }
        else{
            if(opencount>0){
                opencount--;
            }
            else{
                addition++;
            }
        }
      }

      addition += opencount;
      return addition;
    }
};