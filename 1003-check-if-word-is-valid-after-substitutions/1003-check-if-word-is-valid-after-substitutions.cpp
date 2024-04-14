class Solution {
public:
//ITERATIVE APPROACH
//yaha pe basically ham string s se abc ko bar bar hatakar t form karne ki kosis karrahe hai
    bool isValid(string s) {
      while(s.length()>0 && s.find("abc") != string::npos){
          s.erase( s.find("abc") , 3 );
      }

      if(s.length()==0){
        return true;
      }
      return false;
    }
};