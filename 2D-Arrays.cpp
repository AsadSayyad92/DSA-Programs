#include<iostream>
using namespace std;

bool ispresent(int arr[][3],int target,int i, int j){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
    }
    return 0;
}

// void sumarray(int arr[][3],int i,int j){
//     for(int i=0;i<3;i++){
//         int sum=0;
//         for(int j=0;j<3;j++){
//             sum =sum + arr[i][j];
//         }
//         cout<<sum<<endl;
//     }
//     cout<<endl;
// }
void sumcolarray(int arr[][3],int i,int j){
    for(int j=0;j<3;j++){
        int sum=0;
        for(int i=0;i<3;i++){
            sum =sum + arr[i][j];
        }
        cout<<sum<<endl;
    }
    cout<<endl;
}

int maxrowsum(int arr[][3],int i,int j){
    int maxi=INT16_MIN;
    int rowindex = -1;
     for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum =sum + arr[i][j];
        }
        if(sum>maxi){
            maxi = sum;
            rowindex = i;
        }
    }
    cout<<"the maximum sum is "<<maxi<<endl;
    return rowindex;
}
    


int main(){
    int arr[3][3];
    //initialising using rows
    //int arr[3][4] = {{1,11,111,1111},{2,5,222,2222},{3,33,333,3333}};

    cout<<"enter the elements"<<endl;
    //row-wise input
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }

    //column-wise input
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<3;j++){
    //         cin>>arr[j][i];
    //     }
    // }

    //output
    cout<<"printing the array"<<endl;
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    /*cout<<"enter the element to be found"<<endl;
    int target;
    cin>>target;

    if(ispresent(arr,target,3,3)){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }

    // sumarray(arr,3,3);
    
    sumcolarray(arr,3,3);
    */
   int result = maxrowsum(arr,3,3);
   cout<<"max row is at index "<<result<<endl;
    return 0;
}