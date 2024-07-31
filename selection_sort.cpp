#include<iostream>
using namespace std;

void selection(int arr[],int n){
    
    for(int i=0;i<n-1;i++){

        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])    
                minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }

}

void printArray(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    
    int size; 
    cout<<"enter the size"<<endl;
    cin>>size;

    int arr[5]={1,6,45,33,4};

    selection(arr,size);
    printArray(arr,size);

    return 0;
}