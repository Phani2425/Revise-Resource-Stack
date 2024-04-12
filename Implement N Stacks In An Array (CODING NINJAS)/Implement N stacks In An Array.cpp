#include <bits/stdc++.h> 

class Node
{
    public:
    int data;//this will store the index value
    Node * next;//poniter to node

    //constructor
    Node(int value){
        data=value;
        next=NULL;
    }
};

class NStack
{
public:
     int * arr; //original array where value will get stored when pushed
     Node* * Top; //array of pointers to node which will store indexes in which value pushed into a stack is stored
     stack<int> empt;//stack that will store the indexes which are empty in original array so that when a value is pushed we can store that in those empty index


    // Initialize your data structure.
    NStack(int N, int S)
    {

        arr=new int[S];
        Top=new Node *[N];
        for(int i=0;i<N;i++){
            Top[i]=NULL;
        }
        for(int i=0;i<S;i++){
            empt.push(i);
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(empt.empty()){
            return false;
        }
        else{
            arr[empt.top()]=x;
            Node * temp= new Node(empt.top());
            temp->next=Top[m-1];
            Top[m-1]=temp;
            empt.pop();
            return true;
        }
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
           if(Top[m-1]==NULL){
               return -1;
           }
           else{
               int index=Top[m-1]->data;
               Top[m-1]=Top[m-1]->next;
               empt.push(index);
               return arr[index];
           }
    }
};
