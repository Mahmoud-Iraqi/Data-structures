#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int const n = 100;

struct list {
    int* elem = new int[n];
    int last;

    list() {
        last = -1; // empty list
    }
    list(int x){
        last = x;
    }
};

int end(list& l) {
    return l.last + 1;
}

int first(list& l) {
    return 0;
}

int next(int p, list& l) {
    if (p >= n - 1) {
        cout << "p at last position";
        return -1;
    }
    else if (p < 0 || p > l.last + 1) {
        cout << "p is out of range";
        return -1;
    }
    else {
        return p + 1;
    }
}

int prev(int p, list& l) {
    if (p == 0) {
        cout << "p is the first position";
        return -1;
    }
    else if (p < 0 || p > l.last + 1) {
        cout << "p is out of range";
        return -1;
    }
    else {
        return p - 1;
    }
}

void insert(int x, int p, list& l) {
    if (p == n - 1) {
        cout << "list is full";
    }
    else if (p < 0 || p > l.last + 1) {
        cout << "p is out of range";
    }
    else {
        for (int i = l.last; i >=p ; i--) {
            l.elem[i + 1] = l.elem[i]; // shifting
        }
        l.elem[p] = x;
        l.last = l.last + 1;
    }
}

void del(int p, list& l) {
    if (l.last == -1) {
        cout << "list is empty";
    }
    else if (p < 0 || p > l.last) {
        cout << "p is out of range"<<endl;
    }
    else {
        for (int i = p + 1; i <= l.last; i++) {
            l.elem[i - 1] = l.elem[i];
        }
        l.last--;
    }
}

int locate(int x, list& l) {
    for (int i = 0; i <= l.last; i++) {
        if (l.elem[i] == x) {
            return i;
        }
    }
    return end(l);
}

int retrieve(int p, list& l) {
    if (p < 0 || p > l.last) {
        cout << "p is out of range ";
        return -1;
    }
    else {
        return l.elem[p];
    }
}

void makeNull(list& l) {
    l.last = -1;
}

void printList(list& l) {
    for (int i = 0; i <= l.last; i++) {
        cout << l.elem[i] << " ";
    }
    cout << endl;
}

void purge(list &l){
    for(int i=first(l) ; i<end(l) ; i++){
        for(int j=i+1 ; j<end(l) ; j++){
            if(retrieve(i , l) == retrieve(j ,l) ) del(j , l);
        }
    }
}

void revers(list &l ){
    int r=first(l) , e=end(l)-1;
    while (r < e){
        int a = retrieve(r ,l), b=retrieve(e , l);
        del(r ,l);
        insert(b , r ,l);
        del(e ,l);
        insert(a , e , l);
        r=next(r ,l) ; e=prev(e , l);
    }
}

void insertxaftery(int x , int y , list&l){
    int i = locate(y,l);
    insert(x , next(i ,l) , l);
}

list conc(list l1 , list l2){
    int news = end(l1) + end(l2);
    list l3(news);
    for(int i=first(l1) ; i<end(l1) ; i++){
        insert( retrieve(i , l1), end(l3) , l3);
    }
    for(int i=first(l2) ; i<end(l2) ; i++){
        insert( retrieve(i , l2), end(l3) , l3);
    }
    return l3;
}

void Split(list L, list& lOdd, list& lEven) //Splits The Linked To Two Lists, One For Odd Numbers And One For Even Numbers.
{
	int curr = first(L);
	while (curr != end(L))
	{
		int x = retrieve(curr ,L);
		if (x % 2 == 0)
		{
			insert(x, end(lEven) , lEven);
		}
		else
		{
		insert(x, end(lOdd) , lOdd);
		}
		curr = next(curr , L);
	}
}

int sum(list &l){
    int sum=0;
    for(int i=first(l) ; i<end(l) ; i++){
        sum+=retrieve(i , l);
    }
    return sum;
}

int main() {
    list l;
    insert(9, first(l), l);
    insert(20, end(l), l);
    insert(100, first(l), l);
    insert(150, first(l), l);
    insert(10, first(l), l);
    printList(l);
    cout<<sum(l);
    /* int p = locate(9, l);
    cout << "9 at pos " << p << endl;
    printList(l);
    del(locate(9, l), l);
    printList(l);
    del(locate(9, l), l);
    printList(l); */
    return 0;
}