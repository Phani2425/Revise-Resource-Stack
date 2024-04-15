class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        vector<double> ans(n,-1);//VECTOR THAT WILL STORE COLLISON TIME OF CARS IN THEIR RESPECTIVE INDEX
        /*ETHI PURA VECTOR -1 RE ETHIPAIN INITIALISE HABA KARANA AME AMA PROGRAM RE KEBELA SEI CAR RA COLLISON TIME BAHARA KARIBA JAHAR AGARE KICHI CAR ACHI AU SE CAR RA SPEED AMA CURRENT CAR THU SLOW ACHI
        TAHELE SE SABU CAR JOUGUDA KEBE COLIDE KARIBENI(MAY BE LAST CAR OR ANY CAR WHICH DO NOT HAVE ANY CAR AHEAD OF IT WHICH IS SLOWER THAT IT) SEMANANKARA COLISON TIME -1 HABA....SETHIPAIN JEHETU TANKARA AME CALCULATE KARUNE
        SO BY DEFAULT TANKA COLLISON TIME -1 RE INITIALISE HEIJAITHIBA */

        stack<int> st;
        /*stack bhitare kebala se car sabu rahibbe jie current collison ra part thibe */

        for(int i=n-1;i>=0;i--){
            /* one question arise here ki kn pain ame array ku backward ru traverse karuche??? dekh jadi ame forward traverse kariba au sabuthu pacha car ku dekhiki kahiba ki tara collison time x haba au ame pare janiba ki sie jaha saha colide karithanta
            se car already x time purbaru au kaha saha colide heiki nija speed decrease karideichi au jehetu ta speed decrease heijaichi so 1st car au x time re kemiti colide kariba ????? ame x setebele  calculate karithile jetebele ta aga car colide heinathila 
            au original speed re chaluthila ........so ebe ama calculation bhul heigala because jehetu se aga car  ra speed decrease heijaichi so 1st car x ru kam time re ta saha colide karijiba */
            /*aku hni avoid karibaku ame pacharu traverse kariki ans vector re value put kariba */

            while(!st.empty() && cars[i][1]<=cars[st.top()][1]){
                st.pop();
            }
            /*ei loop 2 ta reason pain break haba
            1.jadi pop heiki stack empty heijiba
            2.jadi emiti kichi car stack re milila jahara speed current car thu adhika*/
            /*au only in 2nd case  collison possible haba
            ....so we will try to check for which reason loop breaked 
            ->acha jadi mu 2nd condition direct check karidebi tahele sethire mate stack ra top ku acces karibaku padiba au  jadi bhul re bi stack empty heijaithiba then amaku runtime error deidaba
            -> so mu 1st condition check karibi*/

            while(!st.empty()){ //jadi stack empty heini mane loop 2nd condition fail habaru break heichi
                //mane ebe collison haba
                double colTime=(double)(cars[st.top()][0]-cars[i][0]) / (cars[i][1]-cars[st.top()][1]);   //(pos of car at stack top - pos of current car ) / (speed of current car - speed of car at stack top)

                if(colTime <= ans[st.top()] || ans[st.top()]== -1){ 
                    /*ans[st.top()]==-1 mane top re thiba car jadi kebe colide na kariba......au ei top ra car  may be last carof array heipare may be other car heipare jahara agare thiba sabu car ra speed tha thhu adhika thiba
                    then also that car will never colide nad colTime will be -1 for that */
                    ans[i]=colTime;
                    break;
                }
                else{
                    st.pop();
                }
            }

            st.push(i);
        }

        return ans;
    }
};

/*

1. **Initialization**: 
    - The vector `ans` is initialized to store the collision times of the cars. Each index `i` in the `ans` vector corresponds to the `i-th` car in the `cars` array.
    - We initialize all elements of `ans` to `-1` to indicate that initially, no car collides with any other car.

2. **Iteration Backwards through the Cars**:
    - We iterate through the cars array backwards. This approach helps us calculate the collision time of each car with the car ahead of it more efficiently.
    - Starting from the last car allows us to consider each car in the context of the cars ahead of it, simulating the real-world scenario where cars can only collide with those in front of them.

3. **Updating the Stack**:
    - We use a stack `st` to keep track of the cars that are ahead of the current car and potentially collide with it.
    - By iterating backwards and updating the stack, we ensure that we only consider cars ahead of the current car when calculating collision times.
    - If the speed of the current car is less than or equal to the speed of the car at the top of the stack, it indicates that the current car will not collide with the car at the top of the stack. Hence, we pop cars from the stack until the condition is no longer satisfied.

4. **Calculating Collision Time**:
    - For each car remaining in the stack after updating, we calculate the collision time between the current car and the car at the top of the stack.
    - We use the formula `(position of car at stack top - position of current car) / (speed of current car - speed of car at stack top)` to calculate the collision time.
    - If the collision time is less than or equal to the collision time stored for the car at the top of the stack, or if the collision time for the car at the top of the stack is `-1`, we update the collision time for the current car and break the loop.
    - This process ensures that we only update the collision time for the current car if it collides with the car at the top of the stack before colliding with any other car ahead of it.

5. **Updating the Stack and Returning the Answer**:
    - After calculating the collision time for the current car, we push its index onto the stack.
    - Once we have processed all cars, we return the `ans` vector containing the collision times.

**Reasons for Using a Stack**:
- **Efficiently Track Potential Collisions**: By using a stack, we efficiently keep track of the cars that are ahead of the current car and potentially collide with it.
- **Optimize Collision Time Calculation**: Iterating backwards and updating the stack allows us to consider only the relevant cars for collision time calculation, avoiding unnecessary calculations for cars that are not potential collision candidates.
- **Simplify Collision Time Updates**: The stack helps simplify the process of updating collision times for each car by considering only the cars ahead of it in the calculation.

Overall, using a stack in this manner optimizes the collision time calculation process and efficiently solves the problem by considering each car in the context of the cars ahead of it.*/
