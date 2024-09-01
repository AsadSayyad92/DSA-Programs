#include<iostream>
using namespace std;

class Dequeue{

    public:
        int *arr;
        int size;
        int front;
        int rear;

    Dequeue(size){
        size = 1000;
        front = rear = -1;
        arr = new int(size);
    }

    bool pushFront(int x){
        if((front == 0 && rear == size-1) || rear == (front-1)%(size-1)){
            return false;
        }

        else if(front == -1){
             // first element to push
            front = rear = 0;
            
        }

        else if(front ==0 && rear != size-1){
           front = size-1;
        }

        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(){
        if((front == 0 && rear == size-1) || rear == (front-1)%(size-1)){
            return false;
        }

        else if(front == -1){
             // first element to push
            front = rear = 0;
            
        }

        else if(rear == size-1 && front!=0){
           rear=0;
        }

        else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    bool popfront(){
        if(front ==-1){
            cout<<"queue is empty";
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }

        else if(qfront == size-1){
            front =0;
        }
        else{
            front++;
        }
        return ans;
    }

    bool poprear(){
        if(front ==-1){
            cout<<"queue is empty";
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(qfront == rear){
            qfront = rear = -1;
        }

        else if(rear==0){
            rear = size-1; 
        }
        else{
            rear--;
        }
        return ans;
    }

    
};

int main(){
    Dequeue d(5);

    
    return 0;
}