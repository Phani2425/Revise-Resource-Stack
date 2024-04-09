#include<bits/stdc++.h>
using namespace std;

//declaring user defined variable for linkedlist
class Node
{
    public:
    int data;
    Node * next;
    //constructor
    Node(int value){
        data=value;
        next=NULL;
    }
};

class Stack
{
    Node * top;
    int size;
    public:
    //constructor
    Stack(){
        size=0;
        top=NULL;
    }

    //methods
    //push
    void push(int value){
        Node * temp=new Node(value);
        if(temp==NULL){
            cout<<"the stack is overflowed\n";
            return;
        }
        cout<<"pushed "<<value<<" into the stack\n";
        temp->next=top;
        top=temp;
        size++;
    }
    //pop
    void pop(){
        //checking underflow condition
        if(top==NULL){
         cout<<"the stack is underflowed\n";
        }
        else{
            cout<<"poped "<<top->data<<" from the stack\n";
           Node * temp=top;
           top=top->next;
           delete temp;
           size--;
        }
    }
    //peek
    int peek(){
        //checking underflow condition
        if(top==NULL){
         cout<<"the stack is underflowed\n";
        } 
        else{
            return top->data;
        }
    }
    //IsSize
    int IsSize(){
        return size;
    }
    //IsEmpty
    bool IsEmpty(){
        //checking underflow condition
        if(top==NULL){
         return 1;
        } 
        return 0;  
    }
};

int main(){

    Stack s1;
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
   cout<< s1.peek()<<endl;
    cout<<s1.IsEmpty()<<endl;
    cout<<s1.IsSize()<<endl;

    return 0;
}
