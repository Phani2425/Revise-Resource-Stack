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
        if(fnd != string::npos){  //agar abc milgaya to fnd uska index store karega then ham baki string ko abc ke left aur right me todenge aur recursion ko call karenge
            string left=s.substr(0,fnd);
            string right=s.substr(fnd+3,s.size());
            return isValid(left+right);
        }
        
        //agar kisi point pe string s me "abc" nehi mila to else ke andar wala if nehi chalega to phir recursive call nehi hoga aur end me controll ayega aur false return hoga
        return false;
     }
    }
};