class Solution {
public:
    bool isValid(string s) {
        //EDGE CASE
        if(s.length()<3){
            return false;
        }

        vector<char> v;//WE CAN USE STACK IN PLACE OF VECTOR

        for(char ch : s){
            if(ch=='c' && v.size()>1 && v[v.size()-1]=='b' && v[v.size()-2]=='a'){
                v.pop_back();
                v.pop_back();
            }
            else{
                v.push_back(ch);
            }
        }

        if(v.size()>0){
            return false;
        }
        return true;
    }
};
