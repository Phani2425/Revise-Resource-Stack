class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        stack<int> k;
        int num=0;
        for(char ch : s){
           if(isdigit(ch)){
            num=num*10+(ch-'0');
           }
           else if (ch == '[') {
                k.push(num);
                st.push(ch);
                num = 0;//reseting value of num for further numbers
            }
           else if(ch == ']'){
            string s="";
            while(st.top()!='['){
                s.push_back(st.top());
                st.pop();
            }
            //poping the opening bracket
            st.pop();
            reverse(s.begin(),s.end());

            int repeat=k.top(); k.pop();
            string result="";
            while(repeat--){
                result += s;
            }
            for(char ch: result){
                st.push(ch);
            }
           }

           else{
            st.push(ch);
           }
        }

        string final_result="";
        while(!st.empty()){
            final_result.push_back(st.top());
            st.pop();
        }

        reverse(final_result.begin(),final_result.end());

        return final_result;
    }
};