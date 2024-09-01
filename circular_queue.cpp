#include<iostream>
using namespace std;

class CQueue{

    public:
        int *arr;
        int size;
        int qfront;
        int rear;


    CQueue(int size){
        size = 1000;
        qfront = -1;
        rear = -1;
        arr = new int[this -> size];
    }

    bool enqueue(int value){
        if((qfront == 0 && rear == size-1) || rear == (qfront-1)%(size-1)){
            cout<<"queue is full";
            return false;
        }

        else if(qfront == -1){
             // first element to push
            qfront = rear = 0;
            arr[rear] = value;
        }

        else if(rear == size-1 & qfront !=0){
            rear =0;
            arr[rear] = value;
        }

        else{
            rear++;
            arr[rear] = value;
        }
    }

    bool dequeue(){
        if(qfront ==-1){
            cout<<"queue is empty";
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        if(qfront == rear){
            qfront = rear = -1;
        }

        else if(qfront == size-1){
            qfront =0;
        }
        else{
            qfront++;
        }
        return ans;
    }

    void display(){
        for(int i=0;i<5;i++){
            cout<<arr[i]<<" ";
        }
    }

};


int main(){
    CQueue q(5);

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(52);
    q.enqueue(34);
    

    cout<<"dequeued "<<q.dequeue()<<endl;
    cout<<"dequeued "<<q.dequeue()<<endl;
    return 0;
}       