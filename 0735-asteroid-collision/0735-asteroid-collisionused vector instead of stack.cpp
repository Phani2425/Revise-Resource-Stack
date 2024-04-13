class Solution {
public:

 /*INTUTION:- WHY WE WILL USE STACK HERE?????\
 WE CAN NOTICE HERE ONE THING THAT IN EXAMPLE 3 OR SIMILAR EXAMPLE TO THAT WHEN -5 ASTEROID IS MOVING OPPOSITE TO BOTH 10 AND 2 THEN FIRST IT GOT COLLIDE DWITH 2 THEN 2 GOT DESTROYED AND THEN IT GOT COLLIDED WITH 10 
 MEANS IF A ASTEROID HAVE LARGER SIZE THAN OTHERS THEN IT CAN GET COLLIDED WITH MULTILE ASTEROIDS WHO ARE MOVING OPPOSITE TO IT 
 SO DOESN'T IT INDIACTE US USE STACK STORE THE ASTEROIDS WHO ARE MOVING IN SINGLE DIRECTION AND WHEN ANY ASTEROID COMES WHICH IS MOVING OPPOSITE TO THEM THEN IT CAN COLIDE WITH ALL THE ASTEROIDS STORED IN THE STACK IF THAT HAS LARGER SIZE THAN ALL OF THEM 
 */

//........MEANS STACK IS ALSO USED IN THeSE TYPE OF QUESTION WHERE WE NEED TO STORE SOMETHING WHIICH IS NOT NECESSARILY REQUIRED NOW BUT NECESSARY FOR FUTURE OPERATIONS .............//

    vector<int> asteroidCollision(vector<int>& asteroids) {
        //I CAN ALSO USE VECTOR IN PLACE  OF STACK
        //in vector we will use back() function instead of top()
        vector<int> st;

        for(int &it : asteroids){
            //when collison will happen ?????
            while(!st.empty() && st.back()>0 && it<0){
                int sum=st.back()+it;

                if(sum<0){
                   st.pop_back();
                }
                else if(sum>0){
                    it=0; //current asteroid got destroyed
                    break;
                }
                else if(sum==0){
                    st.pop_back();
                    it=0;
                    break;
                }
            }

//this will handle all the cases when "it" asteroid destroyed all others, or like in example 2 both asteroid got destroyed, or when stackk is empty
//, or when both have same direction or, when asteroid at top of stack is -ve and asteroid on which we are on is +ve 
            if(it != 0){//means if "it" is not destroyed yet
                st.push_back(it);
            }
        }

        return st;
    }
};