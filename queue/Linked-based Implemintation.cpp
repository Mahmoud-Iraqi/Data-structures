
#include <ctype.h> 
#include <iostream>
#include <stdio.h> 
using namespace std;
typedef int elemntype;
struct node{
elemntype data;
node* next;
};
typedef node* position;
class Lqueue{
    position front , rear ;
    int counter;
    public:
    Lqueue(){
        front = NULL;
        rear = NULL;
        counter = 0;
    }

    bool empty(){
        return front == NULL;
    }

    void enqueue(elemntype x){
        position new_node = new node;
        new_node->data = x;
        new_node->next = NULL;
        if(counter == 0){
            rear = new_node;
            front = rear ;
        }
        else{
            rear->next = new_node;
            rear = new_node;
        }
        counter++;
    }

    elemntype dequeue(){
        if(empty()){
            cout<<"queue is empty can't delete more elements\n";
            return -555;
        }
        else {
            elemntype x = front->data;
            position tmp = front;
            front = front->next;
            delete tmp;
            counter --;
            if(counter == 0) rear = NULL;
            return x;
        }
    }

    elemntype first(){
        if(empty()){
            cout<<"queue is empty\n";
            return -99; 
        }
        else return front->data;
    }

    void print(){
        position p = front;
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;
        }
    }
};

int main() 
{ 
Lqueue q;
q.enqueue(4);
q.enqueue(3);
q.enqueue(2);
q.enqueue(1);
q.print();
cout<<"\n-----------------\n";
q.dequeue();
q.print();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();

q.dequeue();
cout<<q.first();
	return 0; 
} 
