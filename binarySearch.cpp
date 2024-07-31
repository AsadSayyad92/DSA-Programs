#include<iostream>
using namespace std;


int binarySearch(int arr[],int size, int key){

    int start=0;
    int end = size-1;
    int mid = start+ (end-start)/2;

    while(start<=end){

        if(arr[mid]==key){
            return mid;
        }

        if(key>arr[mid]){
            start = mid+1;
        }

        else{
            end = mid-1;
        }
        mid = start+ (end-start)/2;
    }
    return -1;
}
int main(){
    int size;
    int key;

    cout<<"enter the size of an array"<<endl;
    cin>>size;

    cout<<"enter the key to be found"<<endl;
    cin>>key;

    int arr[1000];

    cout<<"enter the numbers in list in sorted manner"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int search = binarySearch(arr,size,key);

    cout<<"the key "<<key<<" found at index "<<search;

    return 0;
}