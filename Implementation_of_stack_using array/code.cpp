#include<bits/stdc++.h>
using namespace std;

class Stack
{
   int * arr;//pointer to integer array
   int size;
   int top;
   public:
   //constructor
   Stack(int s){
    arr=new int[s];
    size=s;
    top=-1;
   }

   //PUSH FUNCTION
   void PUSH(int num){
    if(top==size-1){
        cout<<"stack is overflowed"<<endl;
        return;
    }
    else{
        top++;
        arr[top]=num;
        cout<<"pushed "<<num<<" into the stack\n";
    }
   }
   //POP FUNCTION
   void POP(){
    if(top==-1){
        cout<<"stack is underflowed"<<endl;
        return;
    }
    else{
        cout<<"poped "<<arr[top]<<" from the stack\n";
        top--;
    }
   }
   //PEEK FUNCTION
   int PEEK(){
        if(top==-1){
        cout<<"stack is underflowed"<<endl;
    }
    else{
        return arr[top];
    }
   }
   //ISEMPTY FUNCTION
   bool ISEMPTY(){
            if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
   }
   //ISSIZE FUNCTION
   int ISSIZE(){
    return (top+1);
   }
};

int main(){

    Stack stc(5);
    cout<<stc.ISEMPTY()<<endl;
    stc.PUSH(4);
    stc.PUSH(8);
    stc.PUSH(9);
    cout<<stc.ISEMPTY()<<endl;
    stc.POP();
    stc.PEEK();
    stc.POP();
    stc.POP();
    stc.PEEK();
    cout<<stc.ISEMPTY()<<endl;

    return 0;
}
