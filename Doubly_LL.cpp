#include<iostream>
using namespace std;


class Node {
  public:
  int data;
  Node* next;
  Node* prev;

  //constructor
  Node(int d){
    this->data = d;
    this->next = NULL;
    this->prev = NULL;
  }

  ~Node(){
    int val = this->data;
    if(next!=NULL){
        delete next;
        next =NULL;
    }
    cout<<"memory free "<<val<<endl;  
  }
};


void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int len=0;
    Node* temp =head;

    while(temp!=NULL){
        len++;
        temp= temp->next;
    }
    return len;
}

//inserting at beginning
void insertatHead(Node* &tail,Node* &head,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertatTail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertatposition(Node* &tail,Node* &head,int position,int d){
    if(position ==1){
        insertatHead(tail,head,d);
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
        insertatTail(tail,head,d);
        return;
     }

     // creating a node for d
     Node* nodetoInsert = new Node(d);

     nodetoInsert -> next = temp-> next;
     temp->next -> prev = nodetoInsert; // the next node of the temp pointing to nodeatinsert
     temp->next = nodetoInsert;
     nodetoInsert ->prev = temp; 

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
        curr->prev=NULL;
        prev->next = curr->next;
        curr->next =NULL;
        delete curr;
    }
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    // cout<<getLength(head)<<endl;

    insertatHead(tail,head,11);
    print(head);

    insertatHead(tail,head,12);
    print(head);

    insertatTail(tail,head,25);
    print(head);

    insertatposition(tail,head,2,100);
    print(head);

    insertatposition(tail,head,4,101);
    print(head);

    deletion(1,head);
    print(head);

    return 0;
}