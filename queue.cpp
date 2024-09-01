#include<iostream>
using namespace std;

class Queue{

public:
    int *arr;
    int size;
    int qfront;
    int rear;

Queue(){
    // initialization
    size = 5;
    arr = new int[size];
    qfront = 0;
    rear = 0;
}

bool isEmpty(){
    // declare empty function
    if(qfront == rear){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int data){
    if(qfront ==0 && rear == size){
        cout<<"queue is full"<<endl;
    }
    else{
        arr[rear] = data;
        rear++;
    }
}

int dequeue(){
    if(rear == qfront){
        return -1;
    }
    else{
        int ans = arr[qfront];
        arr[qfront] =-1;
        qfront++;
        if(rear == qfront){
            qfront =0;
            rear = 0;
        }
        return ans;
    }
}

int front(){
    if(qfront == rear){
        return -1;
    }
    else{
        return arr[qfront];
    }
}

void display(){
        cout<<"queue element is "<<endl;
        for(int i=0;i<5;i++){
            
            cout<<arr[i]<<endl;
        }
    }

};



int main(){
    
    Queue q;

    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.dequeue();
    q.dequeue();
    
    q.enqueue(7);
    

    q.display();    
    return 0;
}