class Solution {
public:
    int minAddToMakeValid(string s) {
       //edge case  where  string has only one element
       if(s.length()==1){
        return 1;
       } 

       //solving with constant space complexity
       int i=0,j=1;
       while(s.length() && j<s.length()){
        if(s[i]=='(' && s[j]==')'){
            s.erase(i,2);
            i=0;j=1;
        }
        else{
            i++;
            j++;
        }

       }
       return s.length();

    }
};