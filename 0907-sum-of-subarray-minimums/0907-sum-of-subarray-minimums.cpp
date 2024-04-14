class Solution {
public:
/*IN THE BRUTE FORCE APPROACH WE WERE EXPLAORING ALL THE POSSIBLE SUBARRAYS AND THEN ADDING THEIR MINIMUMS WHICH WAS GIVING US TLE
BUT IN THIS OPTIMISE APPROACH WE WILL SOLVE IT A TIME COMPLEXITY OF O(N)*/

/*MU NOTICE KALI KI ARRAY RA SABU ELEMENT KOU NA KOU SUBARRAY RE MINIMUM HEBE FOR SURE TAHELE MU SABU SIBARRAY EXPLORE NA KARIKI JADI GOTE GOTE ELEMENT KU DHARIKI PACHARIBI
KI TU KOU RANGE JAE MINIMUM (MEANS I WILL TRY TO FIND NEXT SAMMLER RIGHT AND NEXT SMALLER LEFT) AU SE ARNGE JANILA PARE JADDI MU EITA CALCULATE KARIPARIBI JE SEI MINIMUM ELEMENT KU NEIKI SE RANGE RE KETETA SUBARRAY POSSIBLE TAHELE SUM RE MU SE ELEMENT KU SETETHARA ADD KARIDEBI
JEMEITI 1ST EXAMPLE RE JEBE 1 KU CHECK KALI MU JANILI JE SIE PURA ARRAY RE MINIMMUM AU MU ETE BAHARA KALI KI TAKU INCLUDE KARIKI TOTAL 6 SUBARRAY POSSIBLE SO ME SUM+=1*6 KARIDEBI BAS
*/

/*EBE QUESTION ASIBA MU JANIBI KEMITI SE ELEMENT KU INCLUDE KARIKI KETETA SUBARRAY  POSSIBLE ??????
NO OF SUBARRAYS POSSIBLE IN A GIVEN RANGE AND INCLUDING AN ELEMENT = (NO OF ELEMENT PRESENT IN RIGHT OF THAT ELEMENT IN THE RANGE+1) * (NO OF ELEMENT PRESENT IN LEFT OF THAT ELEMENT IN THE RANGE+1) OR (INDEX OF NSR - INDEX OF ELEMENT)*(INDEX OF ELEMENT - INDEX OF NSL)*/

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        long long totalsum=0;
        int M=1e9+7;
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                int index=st.top();
                st.pop();
                if(st.empty()){ //if there is no  next smaller left of any one then INDEX OF NSL will be -1 for that
                   totalsum+= arr[index]*((i-index)*(index-(-1))); //formula to find no of subarrays including the element whose nsr we found recently
                }
                else{
                    totalsum+= arr[index]*(i-index)*(index-st.top());
                }
            }
            st.push(i);
        }

        //stil some element will be there whose NSR couldn't be found like 1,2 and 4 in example 1 so now they will be in stack and we will handle them
        while(!st.empty()){
            int index=st.top();
            st.pop();
            if(st.empty()){//nsl will be -1 and nsr will be n
              totalsum+= arr[index]*(n-index)*(index-(-1));
            }
            else{
                totalsum+= (long long)arr[index]*(n-index)*(index-st.top());
            }
        }

        return (totalsum)%M;
    }
};