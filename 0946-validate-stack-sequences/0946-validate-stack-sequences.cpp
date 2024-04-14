class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int> st;

        //WITH THE HELP OF THIS LOOP WE WILL REMOVE THOSE ELEMNT WHICH WERE POPED BETWEEN PUSING WAS GOING ON
        //AFTER REMOVING THEM IN THE NEXT LOOP WE WILL HANDLE THE CONTINUOUS POP STATEMENTS
        while(i != pushed.size()){
            //ye loop ek baar khatam ho gaya means ekbaar sab element push hogaye to iska natlab hai ki jo push ke bich bich me jo elements pop hone bale the wo pop ho chuke hain
        //abhi bas elements pop honge agar wo sab popped array me same sequence me hain like in stack  to phir ye valid hai nehi to nehi hai
           if(st.empty() || popped[j] != st.top()){
            st.push(pushed[i]);
            i++;
           }
           else if(popped[j] == st.top()){
            st.pop();
            j++;
           }
        }

        //ONCE ALL THE NON CONTINUOUS POP STATEMENT ARE COMMPLETED WE WILL HANDLE CONTINUOUS POP STATEMENTS HERE
        while(j != popped.size()){
            if(popped[j]==st.top()){
                st.pop();
                j++;
            }
            else{
                return false;
            }
        }

        return true;
    }
};
