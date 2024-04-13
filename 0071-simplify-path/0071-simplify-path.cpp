class Solution {
public:
 
//BEFORE MOVING AHEAD UNDERSTAND THE INTUITION BEHIND WHY STACK WILL BE USED HERE.....DO WE HAVE TO TRAVERSE BACK AGAIN AND AGAIN IN THE STRING IN ANY CASE ?????

//AND ALSO THINK THAT DOES ONLY BY USING SIMPLE STACK WE CAN SOLVE THIS EASILY ??????? WE CAN DO THAT BUT THAT WILL BE VERY  VERY  COMPLEX
//SO IF WE OBSERVE THEN WE CAN NOTICE THAT WE HAVE ONLY WORK WITH DIRECTORIES AND WE HAVE  NOTHING  TO DO WITH SLASHES AND WE CAN ADD THEM EVEN LATER BY FINDING THE ANSWER
//SO SHOULLD WE REVOMVE THESE SLASHES FROM THE STRING DIRECTLY ?????
//IF WE TRY DOING IT WITH EXAMPLE 3 THEN AFTER THAT WE WILL  NOT ABLE TO IDENTIFY INDIVIDUAL DIRECTORIES IN THAT QUESTION

//SO WHAT WILL WE DO ???? I OBSERVED THAT IF I CAN SEPARATE THE DIRECTORY NAMES,SINGLE DOT,DOUBLE DOTS FROM EACH  OTHER THEN I CAN USE THEM 
//FOR THIS  I WILL USE "CONCEPT OF TOKENISING" where we can separate a string into multiple indivisual string on the basis of some delimeters or symbol such as :- . , : and al type of symbols

    string simplifyPath(string path) {
        stack<string> st;
        
        //TOKENISING THE STRING
        stringstream ss(path); //here ss is the variable name and here we have stored our path string
        string token=" ";//separate token will be stored in this

        while(getline(ss,token, '/')){ //getline function will tokenise the ss variable on the basis of '/' and store individual string into "token" (store one individual strin in token at a time until all tokens end) so we used while loop
             if(token=="." || token==""){
                continue;
             }
             else if(token==".."){
                if(!st.empty()){
                    st.pop();
                }
             }
             else{
                st.push(token);
             }
        }

        if(st.empty()){
            return "/";
        }
        string result="";
        while(!st.empty()){
            result="/"+st.top()+result;
            st.pop();
        }

        return result;
    }
};