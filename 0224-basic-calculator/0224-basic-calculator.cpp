class Solution {
public:
    int calculate(string s) {
        int number=0;
        int result=0;
        int sign=1;//default sign +ve so value will be +1...only when -ve sign will come it will be -1
        stack<int> st;

        for(char ch:s){
            if(ch==' '){
                continue;
            }
            else if(ch=='+' || ch=='-'){
                result += (sign*number);
                number=0;
                if(ch=='-'){
                    sign=-1;
                }
                else{
                    sign=1;
                }
            }
            else if(ch=='('){
                st.push(result);
                st.push(sign);
                //setting all to default
                number=0;
                result=0;
                sign=1;
            }
            else if(ch==')'){
                //finalising the ans of exression inside the bracket
                result += (sign*number);
                number=0;
                //using sign and previous result which was stored in stack
                //multiplying the sign which was present previous to the starting of bracket to result of expression inside the bracket
                result *= st.top();
                st.pop();
                //now combining the result of bracketed expression and  previous expression
                result += st.top();
                st.pop();
            }
            else{  //if not all these the character must be diigit so lets handle that
                int digit=ch-'0';
                number=number*10+digit;
            }
        }

        //if there is a digit at end index of string the we have to handle that at end of loop ass inside the loop  it couldn't be handled
        //becuse before adding the number to the result our loop will end
        result +=(sign*number);

        return result;
    }
};

/*STORY OF CODE

-----------ONE THING TO KNOW THAT QUESTION OF SOLVING MATHEMATICAL EXPRESSION S SHOULD ALWAYS BE SOLVED USINNG STACK-------
INITIALISE NUMBER=0,RESULT=0,SIGN=1 VARIABLES AND A STACK.

1.IF CHARACTER IS ' ' THEN -> CONTINUE THE LOOP
2.IF CHARACTER IS DIGIT THEN -> BUILD THE NUMBER BY DOING NUMBER=NUMBER*10+DIGIT (THIS IS IMPORTANT IN CASES WHERE MULTI DIGIT NUMBERS ARE REPRESENTED BY CHARACTERS) ONCE WE BUILD THAT NUMBER THEN ONLY WE CAN PERFORM ANY OPERATION WITH THEM
3.IF CHARACTER IS A SYMBOL (+ OR -) -> 
           1.THIS MEANS BEFOR THIS SYMBOL THERE  MUST  BE NUMBER. AND THAT NUMBER WE MUST HAVE BUILD IN THE NUMBER VARIABLE BY USING PREVIOUS STEP  
           2.SO LETS ADD THAT NUMBER TO RESULT BUT WE WILL ADD THAT NUMBER BY MULTIPLYING IT WITH SIGN VARIABLE BECAUSE CURRENTLY SIGN IS STORING (+1 OR -1) ON THE BASIS OF SYMBOL WHICH WAS PRESENT BEFORE THE NUMBER
           SO WE WILL DO (RESULT += SIGN*NUMBER)
           3.NOW NUMBER IS USED SO WE WILL DO - NUMBER=0  AND THIS WILL HELP US FOR FUTURE NUMBER BUILDING
           4.NOW WE WILL STORE THE CURRENT SIGN -1 FOR -VE SIGN AND 1 FOR OTHERS
4.IF CHARACTER IS '(' THEN ->
            1.HERE A NEW STORY MUST GET STARTED AS THIS CALCULLATION WILL DONE FIRST AND THEN WE CAN ADD IT WITH OUR PREVIOUS CALCULATIONS
            SO WE WILL STORE THE PREVIOUS RESULT AND THE SIGN PRESENT BEFORE THE '(' IN STACK AND REINITIALISE ALL THE VARIABLES BY THEIR DEFAULT VALUES
5.IF CHARACTER IS ')' THEN ->
            1.RESULT KO UPDATE KARKE BRACKET KE ANDAR KE ANSWER KO FINALISE KARENGE
            RESULT+=SIGN*NUMBER;
            NUMBER=0;
            2.AB JO  RVIOUS RESULT AUR SIGN HAM STACK ME STORE KIYE THE USE USE KARNE KA TIME AGAYA
            RESULT=RESULT*ST.TOP(); //PEHLE SIGN MULTIPLY HUA JO SIGN BRACKET KE PEHLE THA
            ST.POP();//STORE HEITHIBA SIGN POP HEIGALA 
            //EBE TOP RE PREVIOUS EXPRESSION RA RESULT THIBA
            //NOW WE WILL COMBINE THE RESIULT INSIDE BRACKET AND THE PREVIOUS RESULT
            RESULT+=ST.TOP();
            ST.POP(); //STORE HEITHIBA RESULT POP HEIGALA 

6.LAST RE RESULT RETURN KARIDABA */