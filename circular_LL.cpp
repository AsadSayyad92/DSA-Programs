#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            next =NULL;
        }
        cout<<"memory free "<<value<<endl;  
    }
};

void insertatNode(Node* &tail,int element,int d){
    //assuming the element is present in the list
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    } 
    else{
         //assuming the element is present in the list
        Node* curr = tail;
        
        while(curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail,int value){

    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    else{
        Node* prev=tail;
        Node* curr = prev->next;

        while (curr->data!=value)
        {
            /* code */
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        //single node linked list
        if(curr==prev){
            tail =NULL;
        }
        //
        if(tail==curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
         
    }
}

void print(Node* &tail){
    Node* temp = tail;
    
    if(tail==NULL){
        cout<<"list is empty"<<endl; 
        return;
}
    do{
        cout<<tail->data<<" ";
        tail = tail ->next;

    }while (tail!=temp);
    cout<<endl;
}


int main(){
    Node* tail = NULL;

    insertatNode(tail,5,3);
    print(tail);

    insertatNode(tail,3,5);
    print(tail);

    insertatNode(tail,5,7);
    print(tail); 

    deleteNode(tail,3);
    print(tail);
    return 0;
}