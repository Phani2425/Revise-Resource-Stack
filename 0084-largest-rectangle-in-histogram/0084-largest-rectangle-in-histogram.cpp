class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();

        vector<int>NSR(size,size); //NSR=NEXT SMALLER RIGHT
        vector<int>NSL(size,-1); //NSL=NEXT SMALLER LEFT
        //for finding and filling NSR and NSL for each  element we need a stack
        stack<int> st;

        //FILLING NSR FOR EACH  ELEMENT
        for(int i=0;i<size;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                NSR[st.top()] = i; 
                //unlike normal next greater and next smaller element we will store index here (in those questions we were storing element in vector)
                //we will do this because storing index will help us to find out width of rectangle in future
                st.pop();
            }

            st.push(i);
        }

        //before filling NSL we will clear the stack if incase there is something left in stack(if NSR of some index couldn't be founded)
        //we are clearing the stack in intention that those remaining index might affect the result while filling NSL
        while(!st.empty()){
            st.pop();
        }
        
        //FILLING NSl FOR EACH  ELEMENT
        for(int i=size-1;i>=0;i--){
            while(!st.empty() && heights[i] < heights[st.top()]){
                NSL[st.top()] = i; 
                //unlike normal next greater and next smaller element we will store index here (in those questions we were storing element in vector)
                //we will do this because storing index will help us to find out width of rectangle in future
                st.pop();
            }

            st.push(i);
        }

        //NOW WE WILL CALUCLATE THE MAXIMUM AREA RECTANGLE POSSIBLE IN THE HISTOGRAM
        //HERE WE WILL TRAVERSE THE "heights" ARRAY AND FOR EACH INDEX i THE NSR INDEX OF THAT ELEMENT IS PRESENT IN ith INDEX OF NSR ARRAY AND THE NSL INDEX OF THAT ELEMENT IS PRESENT IN ith INDEX OF NSL ARRAY
        //from these NSR and NSL indexes of an element we will get the width of rectangle if consider that element as minimum height of rectangle
        //width of rectangle having minimum height of height[i] will be:- NSR[i]-NSL[i]-1
        //and area will be :-width*height = { (NSR[i]-NSL[i]-1) * height[i] }

        int maxArea=INT_MIN;
        for(int i=0;i<size;i++){
            int area=(NSR[i]-NSL[i]-1) * heights[i];
            maxArea=max(maxArea,area);
        }

        return maxArea;
    }
};

/*THIS APPROACH WILL TAKE ATIME COPMLEXITY OF O(N) BUT HERE  WE NNEED TO TRAVERSE THE ARRAY 3 TIMES 
AND THE SPACE COMPLEXITY OF THE SOLUTION IS O(2N) AS HERE WE ARE TAKING 2 EXTRA VECTORS FOR STORING NSR AND NSL FOR EACH ELEMENT

BUT THE THING IS THIS IS NOT THE MOST OPTIMISIED APPROACH AND RECRUITER MAY ASK TO OPTIMISE THIS MORE 

SO WHAT IF I TELL THAT WE CAN SOLVE THIS  ONLY IN ONE PASS OR IN ONE LOOP AND ALSO WE WILL NOT BE NEEDING ANY EXTRA SPACE MEANS CONSTANT SPACE COMPLEXITY
LET'S UNDERSTAAND THAT IN NEXT SOLUTION*/