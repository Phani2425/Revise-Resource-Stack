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