 // A) Queue Array Implementation (Circular Queue). 
#include <iostream>
#include <stack>
#include<queue>
using namespace std;
class arrQueue{
	public:
int rear ,front;
int count;
int* element;
int capacity;

	arrQueue(int size = 10){
	capacity = size ;
	element = new int[size];
	front=0;
	rear= capacity-1;
	count=0 ;
	}
	//FUN :to check Q is full or empty both --> Tn= O(1).
	bool IsEmpty(){ return count == 0; }
	bool IsFull(){ return count == capacity; }

	// FUN :to return the first element or element of front Tn= O(1).
	int first(){
		if(IsEmpty())
			cout << "Error: Queue Is Empty \n ";
		else
		return element[front]; 
	}

	// FUN :to return the last element or element of rear  Tn= O(1).
	int Getrear(){
		if(IsEmpty())
			cout << "Error: Queue Is Empty \n ";
		else
		return element[rear];
	}

	// FUN :to return No. of items in Q  Tn= O(1). 
    int Size() {
    return count;
}  
	// Enqueue (insert) operation --> Tn= O(1).
	void Enqueue(int x){
		if(IsFull())
			cout<<"Error: Queue Is Full \n";
		else{
	rear = (rear+1)%capacity;
	element[rear] = x;
	count++;
		}
	}
	//Dequeue (Delete) operation --> Tn= O(1).
	int	Dequeue(){  //Delete Element in Fisrt And Return The Element.
	if(IsEmpty())
	cout << " Error: Queue Is Empty \n ";
		else {
		int DelElem = element[front];
		front=(front+1)%capacity;	
    count--;
	return DelElem;
		}
	}
	// FUN :to print items at Q --> Tn= O(n).
	void print(){
if(IsEmpty()){
	cout << " Error: Queue Is Empty \n ";
	return;
}
	for(int i= front; i !=rear; i =(i+1)%capacity)
	cout<<"\t\t|\t"<<element[i]<<"\t|"<<endl;

	cout<< "\t\t|\t"<<element[rear]<<"\t|"<<endl;
	cout<< "\t\t|---------------|"<<endl;
		
	}

int Queuesearch(int x){
	if(IsEmpty()){
	cout << " Error: Queue Is Empty \n ";
}
	int pos=-1;
	for(int i= front; i !=rear; i=(i+1)%capacity){
		if(element[i] == x)
			pos = i;
	}
		if(element[rear] == x)
			pos=rear;
		
	return pos;
	}
int sum(){  int s=0;
		if(IsEmpty()){
	cout << " Error: Queue Is Empty \n ";
	return 0;
	}
		for(int i= front; i !=rear; i =(i+1)%capacity){
		s+=element[i];
		}
		s+=element[rear];
    return s;
}
	int MAX(){  int m=element[front];
		if(IsEmpty()){
	cout << " Error: Queue Is Empty \n ";
	return 0;
}
		for(int i= front; i !=rear; i =(i+1)%capacity){
			if(element[i]>m){m=element[i];}
		}
		if (element[rear]>m)
			m=element[rear];
		return m;
	}
};
arrQueue Extract(arrQueue& q1){
arrQueue q_even;
if(q1.IsEmpty()){
	cout << " Error: Queue Is Empty \n ";
	return 0;
}
for(int i= q1.front; i !=q1.rear; i =(i+1)%q1.capacity){
	if(q1.element[i]%2==0){
		q_even.Enqueue(q1.element[i]);
	}
}
if(q1.element[q1.rear]%2==0){q_even.Enqueue(q1.element[q1.rear]);}
q_even.print();
return q_even;
}

bool palindrmoe(string s){
    stack<char> st ; queue<char> q;
    for(int i=0 ; i<s.size() ; i++){
        st.push(s[i]);q.push(s[i]);
    }

    while(!st.empty() && !q.empty()){
        if(q.front() != st.top()) return false;
        else{
            q.pop();
            st.pop();
        }
    }
    return true;
}

int main()
{
	//string s; cin>>s;
    if(palindrmoe("aabba")) cout<<"ok\n";
    else cout<<"not ok\n";
	/* arrQueue Q(n);
	Q.Enqueue(10);
	Q.Enqueue(20);
	Q.Enqueue(3);
	Q.Enqueue(40);
	Q.Enqueue(50);
		Q.print();
    // Q.Enqueue(60);    Error Queue is full 
	Q.Dequeue();

	Q.Enqueue(60);
		Q.print();
		Extract(Q);
		//Q.print(); */

/*
		cout<<" Sum = "<< Q.sum()<<endl;
		cout<<" MAX element = "<<Q.MAX()<<endl;
		*/
	 /*
	int v;
	cout<<"Enter element for searching ";
	cin>>v;
	if(Q.Queuesearch(v)<0)
		cout<<"Element is not found \n";
	else 
	cout<<"Element at index : "<<Q.Queuesearch(v)<<endl;
	*/

	return 0;
}
