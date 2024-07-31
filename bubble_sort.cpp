#include<iostream>
using namespace std;

void bubble(int arr[],int n){
    bool shifted = false;
    for(int i=1;i<n;i++){
        for(int j = 0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                shifted = true;
            }
        }
        if(shifted==false){
            break;
        }
    }
    
}


void printArray(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    int arr[5] = {6,2,8,10,4};

    bubble(arr,5);

    cout<<"the sorted array is"<<endl;
    printArray(arr,5);
    cout<<endl;

    return 0;
}