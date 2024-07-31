#include<iostream>
using namespace std;

//pointer declaration and its meaning

int main(){
    // int num=5;
    // cout<<num<<endl;

    // int *ptr = &num;
    
    //  //* = value at address of. & = address of operator

    //  cout<<"address is"<<ptr<<endl;
    //  cout<<"address is"<<&num<<endl;
    //  cout<<"value is"<<*ptr<<endl;

    //  double d= 4.3;
    //  double *p = &d;

    //  cout<<"address is"<<p<<endl;
    //  cout<<"value is"<<*p<<endl;


    // pointer to int is created and pinting to some garbage address 
    //int *p=0;
    //cout<<*p<<endl;

    // int i =5;
    // int *q=&i;
    // cout<<q<<endl;
    // cout<<*q<<endl;

    // int *p=0;
    // p=&i;

    // cout<<p<<endl;
    // cout<<*p<<endl;

    int num=5;
    int a = num;
    a++;

    cout<<num<<endl;

    int *p = &num;
    cout<<"before "<<num<<endl;
    (*p)++;
    cout<<"after "<<num<<endl;

    // copying a pointer

    int *q = p;
    cout<<p<<" - "<<q<<endl;
    cout<<*p<<" - "<<*q<<endl;

    //important concept
    int i=3;
    int *t = &i;
    //cout<<(*t)++<<endl;
    *t = *t +1;
    cout<<*t<<endl;
    cout<<"before t"<<t<<endl;
    t=t+1;
    cout<<"after t"<<t<<endl;




    return 0;
}