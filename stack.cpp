#include<iostream>
using namespace std;

class Stack{

    //properties
    public:
        int *arr;
        int top;
        int size;

    //behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(top<size-1){
            top++;
            arr[top] = element; 
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack is undeerflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }

        else{
            return false;
        }
    }
    
    void display(){
        cout<<"stack element is "<<endl;
        for(int i=0;i<5;i++){
            
            cout<<arr[i]<<endl;
        }
    }
};
int main(){

    Stack st(5);


    st.push(23);
    st.push(34);

    cout<<st.peek()<<endl;

    st.push(9);
    st.push(11);
    st.push(65);


    st.pop();
    cout<<st.peek()<<endl;
    st.display();





    return 0;
}