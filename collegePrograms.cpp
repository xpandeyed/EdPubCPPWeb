#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

int size=0;
struct Node *front = NULL;
struct Node *rear = NULL;

void printQueue(){
    cout << "Elements of Q are : " ;
    if(front==NULL && rear==NULL){
        cout << "List is empty" << endl;
        return ;
    }
    struct Node* temp = front;
    while(temp!=NULL){
        cout << temp->data << " " ;
        temp=temp->next;
    }
    cout << endl;
}

void frontAndRear(){
    if(front==NULL && rear==NULL){
        cout << "List is empty" << endl;
        return ;
    }
    cout << front->data << " " << rear->data << endl;
}

void enqueue(){
    int val ;
    cout << "Enter value : " ;
    cin >> val;
    struct Node* temp = new Node;
    temp->data= val;
    temp->next = NULL;
    if(front==NULL){
        front=temp;
        rear=temp;
        size++;
        printQueue();
        return;
    }
    rear->next = temp;
    rear=temp;
    size++;
    printQueue();
}
void dequeue(){
    if(front==NULL && rear==NULL){
        cout << "Empty queue" << endl;
        printQueue();
        return ;
    }
    if(front==rear){
        front=NULL;
        rear=NULL;
        size--;
        printQueue();
        return ;
    }
    front=front->next;
    size--;
    printQueue();
}
void isEmpty(){
    if(size==0){
        cout << "Q is empty" << endl;
    }else{
        cout << "Q is not empty" << endl;
    }
}
void sizeOfQ(){
    cout << "Size : "<<size << endl;
}

int main(){
    int n;
    while(true){
        cout << "1 for enqueue" << endl;
        cout << "2 for dequeue" << endl;
        cout << "3 for printing the queue" << endl;
        cout << "4 for front and rear" << endl;
        cout << "5 for isEmpty" << endl;
        cout << "6 for size" << endl;
        cout << "7 to end" << endl;

        cout << endl << "Choice : " ;
        cin >> n;
        switch(n){
            case 1:{
                enqueue();
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                printQueue();
                break;
            }
            case 4:{
                frontAndRear();
                break;
            }
            case 5:{
                isEmpty();
                break;
            }
            case 6:{
                sizeOfQ();
                break;
            }
            case 7:{
                return 0;
            }
            default:cout << "Wrong choice" << endl;
        }
    }
    return 0;
}
