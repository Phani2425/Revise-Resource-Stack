class Solution {
public:

    //FUNCTION FOR FINDING AREA OF LARGEST RECTANGLE IN A HISTOGRAM BY TAKING A VECTOR AS INPUT WHICH HAVE HEIGHT OF HISTOGRAM BARS IN IT
    int largestRectangle(vector<int>height){
        int size=height.size();//we can also pass col to function to get the size
        stack<int> st;
        int maxArea=0;

        for(int i=0;i<size;i++){
            while(!st.empty() && height[i]<height[st.top()]){
                 int index=st.top();
                 st.pop();
                 if(st.empty()){
                   maxArea=max(maxArea,height[index]*i);
                 }
                 else{
                    maxArea=max(maxArea,(height[index] * (i-st.top()-1)));
                 }
            }
            st.push(i);
        }
        
         /*HERE WE WILL HANDLE A CASE WHERE EVEN AFTER TRAVERSING THE WHOLE ARRAY WE COULDN'T FIND NSR OF SOME ELEMENTS
        MEANS THOSE ELEMENT ARE STILL IN THE STACK 
        FOR THEM INDEX OF THEIR NSR WILL BE "SIZE" OF THE INPUT ARRAY AS CONSIDERING THIS WE CAN FIND THE WIDTH OF THE RECTANGLE */
        while(!st.empty()){
            int index=st.top();
            st.pop();
            if(st.empty()){
                maxArea=max(maxArea,height[index]*size);
            }
            else{
                maxArea=max(maxArea, (height[index] * (size-st.top()-1)));
            }
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        /*The solution approach capitalizes on a pattern that can be observed by examining the matrix row by row. By treating each row as the base,
         we can convert the problem into a series of "largest rectangle in histogram" problems.*/
         /*SO FIRST  WE WILL CONVERT EACH OF THE ROW INTO A HISTOGRAM AND FIND THE LARGEST POSSIBLE RECTANGLE ON THAT(THAT WILL BE DONE BY A SEPARATE FUNCTION)*/

         int row=matrix.size();
         int col=matrix[0].size();
         vector<int> histogram(col,0); //i forgot to initialise this so it gave me error becuase if i donoot initialise it or declare its size then
         //i can not add 1 to its index further and aslo i can't access any of its index
         int max_area=0;

         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1'){
                    histogram[j] += 1;
                }
                else{
                    histogram[j]=0;
                }
            }
            /*now we have histogram vector taking ith row as base so we will pass that to "largestRectangle()" function which will return the area of largest rectangle 
            possible by  taking ith row as base .......again that will get compared with max_area and max_area will get upadated */
            max_area=max(max_area, largestRectangle(histogram));
            /*in this way by comparing largest area when each row is considered as base of histoogram we will get the area of maximal rectangle in the whole  matrix */
         }

         return max_area;
  
    }
};