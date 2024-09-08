#include <iostream>
#include <list>
#define elmtype char
#define null NULL
using namespace std;

struct  node
{
	elmtype e;
	node* left ;
	node* right;
	node* p;
	node(){
		e=0;
		left = null;
		right = null;
		p = null;
	}
	node(elmtype x , node* l , node* r , node* P){
		e=x;
		left = l;
		right = r;
		p = P;
	}

	bool isleaf(){	return left==null && right==null; }

	list<node*> children(){
		list<node*> l;
		if(left != null)l.push_back(left);
		if(right != null)l.push_back(right);
		return l;
	}

	bool isroot(){ return p == null; }
};

class binarytree{
public:
node* root;
int c;
binarytree(){
	root = null;
	c=0;
}

bool empty(){
	return root==null;
}

node* addroot(elmtype e){
	if(!empty()) cout<<"tree not empty \n";
	else {
		root = new node(e , null , null , null);
		c++;
	}
	return root;
}

node* addleft(node* p , elmtype e){
	if(p->left != null) {cout<<"can't add here \n"; return null;}
	else{
		node* child = new node(e , null , null , null);
		p->left = child;
		c++;
		return child;
	}
}
node* addright(node* p , elmtype e){
	if(p->right != null) {cout<<"can't add here \n"; return null;}
	else{
		node* child = new node(e , null , null , null);
		p->right = child;
		c++;
		return child;
	}
}

void attach(node* p , binarytree t1 , binarytree t2){
	if(!p->isleaf()){ cout<<"p must be a leaf \n"; }
	else{
		p->left = t1.root;
		p->right = t2.root;
		if(t1.root != null) t1.root->p = p;
		if(t2.root != null) t2.root->p = p;
		c+= (t1.c + t2.c);
	}
}

    void inorder(node* ptr){
        if(ptr!=NULL){
            inorder(ptr->left);
            cout<<" "<<ptr->e<<" ";
            inorder(ptr->right);
        }
    }

    void preorder(node* ptr){
        if(ptr!=NULL){
            cout<<" "<<ptr->e<<" ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder(node* ptr){
        if(ptr!=NULL){
            postorder(ptr->left);
            postorder(ptr->right);
            cout<<" "<<ptr->e<<" ";
        }
    }

	int evaluate(node* p){
		if(!p->isleaf()){
			int x = evaluate(p->left);
			int y = evaluate(p->right);
			switch (p->e)
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
				return 0;
			}
		}
		else return int(p->e - '0');
	}

};

int main(){
//cout<<int('3'-'0');
binarytree T1;
T1.addroot('-'); 
binarytree T2;
T2.addroot('/');
binarytree T3;
T3.addroot('+');
binarytree T4;
T4.addroot('*');
binarytree T5;
T5.addroot('+'); 
binarytree T6;
T6.addroot('*');
binarytree T7;
T7.addroot('6');
binarytree T8;
T8.addroot('+'); 
binarytree T9;
T9.addroot('3'); 
binarytree T10;
T10.addroot('-'); 
binarytree T11;
T11.addroot('2'); 
binarytree T12;
T12.addroot('3');
binarytree T13;
T13.addroot('-');
binarytree T16;
T16.addroot('3');
binarytree T17;
T17.addroot('1');
binarytree T20;
T20.addroot('9'); 
binarytree T21;
T21.addroot('5'); 
binarytree T26;
T26.addroot('7'); 
binarytree T27;
T27.addroot('4');
T8.attach(T8.root,T16,T17);
T10.attach(T10.root,T20,T21); 
T13.attach(T13.root,T26,T27); 
T4.attach(T4.root,T8,T9); 
T5.attach(T5.root,T10,T11); 
T6.attach(T6.root,T12,T13); 
T2.attach(T2.root,T4,T5); 
T3.attach(T3.root,T6,T7); 
T1.attach(T1.root,T2,T3);

cout<<"evaluate ";
cout<<T1.evaluate(T1.root);cout<<endl;
cout<<"post: ";
T1.postorder(T1.root);cout<<endl;
cout<<"pre: ";
T1.preorder(T1.root);cout<<endl;
cout<<"inorder: ";
T1.inorder(T1.root);
	return 0;
}