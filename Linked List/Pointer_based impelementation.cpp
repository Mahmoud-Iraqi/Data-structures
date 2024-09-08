#include<iostream>
#include<algorithm>
#include<string>

#define elementtype int

using namespace std;

struct node{
elementtype data;
node* next;
};

#define pos  node* 
#define null NULL
class List{
pos head; 
pos tail;
int counter;
public:
List(){
    head = new node;
    head -> next = null;
    tail = null;
    counter = 0;
}
pos first(){
    if(counter == 0) return null; 
    return head;
}
pos end(){
    if(head->next == null) return head;
    return tail;
}

int size()
{
    return counter;
}

void insert(elementtype x , pos p = null){
if(p == NULL)
p = end();
node* new_node = new node;
new_node->data = x;
new_node->next = p->next;
p->next = new_node;
if(new_node->next == null) tail = new_node;
counter ++;
}

pos Del( pos p){
    if(p==end() || p==NULL)
    {
        cout << "NO Elements to be deleted\n";
        return null;
    }

    else{
        if(p->next == tail) tail = p;
        pos temp = p->next;
        p->next = p->next->next;
        temp->next = null;
        delete temp;
        counter --;
    }
}

pos locate(elementtype x){
    pos p;  
    p = head;
    while( p->next != null ){
        if(p->next->data == x)  return p;
        p=p->next;
    }
    return p;
}

elementtype retrieve(pos p){
    return p->next->data;
}

pos next(pos p){
    return p->next;
}

pos previous(pos p){
    if(p == head) return null;
pos temp;
temp = head;
while(temp->next != p){
    if(temp->next == p && temp != null) return temp;
    temp = temp->next;
}
return temp;
}

void display(){
if(head->next == NULL) cout << "List is empty\n";
pos p;
p= head->next;
while (p != null ){
    cout<<p->data<<" ";
    p=p-> next;
}
cout<<endl;
}
node* revers(node* head)
    {
        
        node *prev = null;
        node *nex = NULL;
        while (head != NULL) {
            nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        head = prev;
        return head;
    }
};

pos locateinsorted(int x , List &l){

}

///////////////Application

void purge(List &l){ // remoev duplicates from the list
pos i = l.first();
while(i != l.end()){
    pos j = l.next(i);
    while(j != l.end()){
        if( l.retrieve(i) == l.retrieve(j) ) l.Del(j);
    else j = l.next(j);
    }
    i = l.next(i);
}
}

void concat(List &l1 , List& l2){
    for(pos i=l2.first() ; i<l2.end() ; i=l2.next(i)){
        l1.insert(l2.retrieve(i) , l1.end());
    }
}

void split(List &l , List &odd , List &even){
    for(pos i=l.first() ; i!=l.end() ; i=l.next(i)){
        if(l.retrieve(i) %2 == 0) even.insert(l.retrieve(i) , even.end());
        else odd.insert(l.retrieve(i));
    }
}

int main(){
List l;
l.insert(1 , l.first());
l.insert(5);
l.insert(4 , l.locate(1));
l.insert(5);
l.insert(7);
l.insert(6);
l.display();
List a;
a.insert(8);
a.insert(9);
a.insert(10);
a.insert(11);
concat(l , a);
l.display();

List odd , even;
split(l , odd , even);
cout<<"odd "; odd.display();
cout<<"even "; even.display();
/* node* h = l.first();
h = l.revers(h);
node* ptr = h;
while(ptr!= l.end()){
    cout<<ptr->data<<" ";
    ptr = ptr->next;
} */
//l.display();
/*
purge(l);
l.display();
 */
    return 0;
}