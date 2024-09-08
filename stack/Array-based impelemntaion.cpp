#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int size=13;
int stack [size];
int  top =-1 ;

void push( int element){
    if(top >= size-1) cout<<"stack is full"<<endl;
    else
    {
        top++;
        stack[top] = element;
    }
}

float expr(float x , float y , char opr){
    switch (opr)
    {
    case '+':
        return x+y;
        break;
    case '-':
        return x-y;
        break;
    case '*':
        return x*y;
        break;
    case '/':
        return x/y;
        break;
    default:
        break;
    }
}

int pop(){
    if(top <= -1) cout<<"stack sis empty"<<endl;
    else{
        return stack[top--];
        //cout<<"deleted elemnt "<<stack[top--]<<endl;
    }
}

float evaluate(string s){
    for(int i=0 ; i<s.length() ; i++){
        if(isdigit(s[i])) push(s[i] - '0');
        else{
            float op2 = stack[top];
            pop();
            float op1 = stack[top];
            pop();
            float result = expr(op1 , op2 , s[i]);
            push(result);
        }
    }
    return stack[top];
}

void peek(){
    cout<<stack[top];
}

void sortstack(){
    vector<int> v;
    for(int i=top ; i>=0 ;--i){
        v.push_back(stack[i]);
    }

    sort(v.begin() , v.end());
top =-1;
    for(auto i=v.rbegin() ; i<v.rend() ; ++i){
        push(*i);
    }
}

bool Pair(char op , char cl){
if(op == '(' && cl == ')') return true ;
else if(op == '[' && cl == ']') return true;
else if(op == '{' && cl == '}') return true;
else return false;
}

bool balanced(string s){
    for(int i=0 ; i<s.length() ; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' ) push(s[i]);

        else if(s[i] == ')' || s[i] == ']' || s[i] == '}' ) {
            if(top == -1 || !Pair(stack[top] , s[i]) ) return false;
            else pop();
        }
    }
    return top==-1? true : false ;
}

void display(){
    if(top == -1) cout<<"stack is empty "<<endl;
    for(int i=top ; i>=0 ; i--)
    {
        cout<<stack[i]<<endl;
    }
}

void conv(int n){
    while(n > 0){
        push(n % 2);
        n /= 2;
    }
    display();
}

void rearrange(){

}

int main(){
//conv(10);
/* string exp; cin>>exp;
if(balanced(exp)) cout<<"balanced";
else cout<<"not balanced";   */
cout<<evaluate("4572+-*");
/*  push(2);
push(1);
push(6);    
push(5);
display();
cout <<"sorted stack: " << endl;
sortstack();
display();  */
    return 0;
}