class Solution {
public:
    int minAddToMakeValid(string s) {
      int opencount=0;//YE INDIRECTLY BATAYEGA KI MUJHE PARENTHESIS KO VALID BANANE KELIYE RIGHT SIDE ME KITNE CLOSING BRACKETS LAGANA PADEGA

      int addition=0;//YE INDIRECTLY BATAYEGA KI MUJHE PARENTHESIS KO VALID BANANE KELIYE LEFT SIDE ME KITNE OPENING BRACKETS LAGANA PADEGA

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

//NO OF LEFT BRACKET I HAVE TO PUT + NO OF RIGHT BRACKET I HAVE TO PUT = NO OF STEPS I HAVE TO TAKE TO MAKE PARENTHESIS VALID. 

      addition += opencount;
      return addition;
    }
};