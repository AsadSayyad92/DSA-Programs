#include<iostream>
using namespace std;

bool search(int arr[], int n,int key){

    for(int i =0;i<n;i++){
        if(arr[i]==key){
            return 1;
        }
    }

    return 0;

}

int main(){
    int size;
    int key;
    cout<<"enter the size of an array"<<endl;
    cin>>size;

    int arr[100];

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"enter the number to be found"<<endl;
    cin>>key;

    bool found = search(arr,size,key);

    if(found){
        cout<<"the number is present"<<endl;
    }
    else{
        cout<<"number is absent";
    }   

    

    return 0;
}