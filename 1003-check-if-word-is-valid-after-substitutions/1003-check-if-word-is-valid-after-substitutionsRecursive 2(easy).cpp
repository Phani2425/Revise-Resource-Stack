class Solution {
public:
//RECURSIVE APPROACH
//yaha pe basically ham s se abc ko bar bar hatakar t form karne ki kosis karrahe hai
    bool isValid(string s) {
     //BASE CASE
     if(s.length()==0){//agar string s khali hogaya matalab wo t me convert ho gaya
        return true;
     }

     //RECURSIVE CASE
     else{
        int fnd=s.find("abc");
        if(fnd == string::npos){  
           return false;
        }
        else{  //agar abc milgaya to fnd uska index store karega then ham wo abc ko remove karke s ko phirse recursively funnction ko pass kardenge
            s.erase(fnd,3);
            return isValid(s);
        }

     }
    }
};