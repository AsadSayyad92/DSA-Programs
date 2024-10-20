#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

/*
    This function inserts a new value into the heap.
    It maintains the heap property by comparing the value with its parent and swapping if necessary.
*/
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }


    void deletefromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        //step1: put last element into first index
        arr[1] = arr[size];

        //step2 remove last element
        size--;
        
        //step2take root node into its correct position
        int i=1;

        while(i<size){
            int leftIndex = 2*i;
            int rightIndex  =  2*i+1;

            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }

            else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }

            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};


//use to place node in proper place for complete binary tree
void heapify(int arr[],int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;

    if(left<=n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }

}

void heap_sort(int arr[],int n){
    int size = n;

    while(size>1){
        //step1 swap 
        swap(arr[size],arr[1]);
        size--;

        //step2 place the node at correct position
        heapify(arr,size,1);
    }
}

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromHeap();
    h.print();
    int arr[6] = {-1,54,53,55,52,50};
    int n=5;
    //creation heap
    for(int i = n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"printing the array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";   
    }cout<<endl;

    heap_sort(arr,n);
        cout<<"printing the sorted heap"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";   
    }cout<<endl;


    //maxheap
    priority_queue<int>pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"element at top "<<pq.top()<<endl;
    pq.pop();

    cout<<"element at top "<<pq.top()<<endl;

    cout<<"size is"<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"heap is empty"<<endl;

    }
    else{
        cout<<"heap is not empty"<<endl;
    }



    //minheap
    priority_queue<int,vector<int>,greater<int>>min;

    min.push(4);
    min.push(2);
    min.push(5);
    min.push(3);

    cout<<"element at top "<<min.top()<<endl;
    min.pop();

    cout<<"element at top "<<min.top()<<endl;

    cout<<"size is "<<min.size()<<endl;
    if(min.empty()){
        cout<<"heap is empty"<<endl;

    }
    else{
        cout<<"heap is not empty"<<endl;
    }


    
    return 0;
}