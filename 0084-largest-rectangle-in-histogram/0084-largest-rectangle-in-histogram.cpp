class Solution {

/*THIS IS THE MOST OPTIMISED APPROACH OF THIS PROBLEM WHERE WE CAN  SOLVE THIS ONLY IN ONE PASS AND WE WILL NOT  BE NEEDING ANY EXTRA SPACE TO STORE NSR AND NSL
AS IN THAT LOOP WHEN WE WILL GET NSR AND NSL OF A ELEMENT "X" INSTANTLY WE WILL CALLCULATE THE AREA OF RECTANGLE HAVING HEIGHT OF "X" AND ALSO UPDATE THE "MAX_AREA" VARIABLE
SO THERE IS NO NEED TO STORE THEM.......

THIS SOLUTION INCLUDES A GREAT TRICK FOR FINDING  NSR AND  NSL FOR A ELEMENT AT ONCE SO THIS IS VERY VERY IMPORTANT */

public:
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();
        stack<int> st;
        int max_area=INT_MIN;

        for(int i=0;i<size;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int index=st.top();
                st.pop();
                if(st.empty()){
                    max_area=max(max_area,heights[index]*(i));
                }
                else{
                    max_area=max(max_area,(heights[index] * (i-st.top()-1)));
                }
            }

            st.push(i);
        }

        //HERE WE WILL HANDLE A CASE WHERE EVEN AFTER TRAVERSING THE WHOLE ARRAY WE COULDN'T FIND NSR OF SOME ELEMENTS
        //MEANS THOSE ELEMENT ARE STILL IN THE STACK 
        //FOR THEM INDEX OF THEIR NSR WILL BE "SIZE" OF THE INPUT ARRAY AS CONSIDERING THIS WE CAN FIND THE WIDTH OF THE RECTANGLE
        while(!st.empty()){
            int index=st.top();
            st.pop();
            if(st.empty()){
                max_area=max(max_area, heights[index]*size);
            }
            else{
                max_area=max(max_area, (heights[index]*(size-st.top()-1)));
            }
        }

        return max_area;
    }
};

//

