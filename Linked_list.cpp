#include<iostream>
using namespace std;


class Node{

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }

};

//inserting at beginning

void insertatHead(Node* &head,int d){
    //new node create 
    Node* temp = new Node(d); // created a node
    temp -> next = head; // update the temp next from NULL to head addreses
    head = temp; // since temp's data becomes the first one we shift head to temp again
}

void insertatTail(Node* &tail,int d){
    //new node created
    Node* temp = new Node(d);
    tail ->next = temp; // temp has its own address which is given to tail's next hence temp becomes last node!
    tail = temp; // copy address
}

//middle insertion
void insertatPosition(Node* &tail,Node* &head,int position,int d){
     // insert at start
     if(position ==1){
        insertatHead(head,d);
        return;
     }

     Node* temp = head;
     int cnt=1;

     while(cnt<position-1){
        temp = temp->next;
        cnt++;
     }
     //inserting at last position
     if(temp->next==NULL){
        insertatTail(tail,d);
        return;
     }

     // creating a node for d
     Node* nodetoInsert = new Node(d);

     nodetoInsert -> next = temp-> next;
     temp ->next = nodetoInsert; 
}


void deletion(int position,Node* &head){
    //starting position
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting middle or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt =1;

        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp ->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}
int main(){

    Node* node1 = new Node(10);
    // cout<< node1->data<<endl;
    // cout<< node1->next<<endl;

    //head pointed to node
    Node* head = node1;
    Node* tail = node1;
    print(head);


    insertatTail(tail,12);
    print(head);

    insertatTail(tail,15);
    print(head);

    insertatPosition(tail,head,4,22);
    print(head);

    deletion(2,head);
    print(head);

    insertatHead(head,90);
    print(head);
    return 0;
} 