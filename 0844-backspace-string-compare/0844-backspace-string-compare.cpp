class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>sstk;
        stack<char>tstk;
        //copying elements of string s to a stack named sstk
        for(int i=0;i<s.length();i++){
            if(s[i] != '#'){
               sstk.push(s[i]);
            }
            else if(s[i]=='#' && !sstk.empty()){
                sstk.pop();
            }
            else{
                continue;
            }
        }

        //copying elements of string t to a stack named tstk
        for(int i=0;i<t.length();i++){
            if(t[i] != '#'){
               tstk.push(t[i]);
            }
            else if(t[i]=='#' && !tstk.empty()){
                tstk.pop();
            }
            else{
                continue;
            }
        }

        //now we will compare both stack
        //handling case where size of both  stack is not same
        if(sstk.size() != tstk.size()){
            return false;
        }
         bool flag=1;
         while(!sstk.empty()){//here i can use tstk also
            if(sstk.top()==tstk.top()){
                sstk.pop();
                tstk.pop();
            }
            else{
                flag=0;
                break;
            }
         }

         return flag;
    }
};