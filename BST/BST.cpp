#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
struct node{
public:
    int elem;
    node*left;
    node*right;
    node(int x,node*l,node*r){
    elem=x;
    left=l;
    right=r;
    }
    node(){
    elem=0;
    left=NULL;
    right=NULL;
    }
    bool isExternal(){
    return left==NULL&&right==NULL;
    }
    list<node*>children(){
    list<node*>l;
    if(left!=NULL){
        l.push_back(left);
    }
    if(right!=NULL){
        l.push_back(right);
    }
    return l;
    }

};
class bst{
    public:
node* root;
int counter;
bst(){
root=NULL;
int counter=0;
}
void inorder(node*p){
if(p==NULL)
    return;
inorder(p->left);
cout<<p->elem<<"  ";
inorder(p->right);
}
void preorder(node* p)
	{
		cout << " " << p->elem << " ";
		if (p->left != NULL)
			preorder(p->left);
		if (p->right != NULL)
			preorder(p->right);
	}
	void postorder(node* p)
	{
		if (p->left != NULL)
			postorder(p->left);
		if (p->right != NULL)
			postorder(p->right);
		cout << " " << p->elem << " ";
	}
bool isEmpty(){
return root==NULL;
}
int size(node*p,int &sizee){
    if(p!=NULL){
            size(p->left,sizee);
    sizee++;
            size(p->right,sizee);

    }
    return sizee;
}
node* getRoot(){
return root;
}
void insert(node* &ptr,int data){
    if(ptr==NULL)
        ptr=new node(data,NULL,NULL);
    else {
        if(data>ptr->elem)
            insert(ptr->right,data);
        else
                        insert(ptr->left,data);

    }

}
void insert(int data){
insert(root,data);
}
node* search(int x){
node*p=root;
while(p!=NULL){
    if(p->elem==x){
        return p;
    }
    else if(p->elem>x){
        p=p->left;
    }
    else
        p=p->right;
}
}
node* minn(node* ptr){
node* current=ptr;

while(current->left!=NULL){
    current=current->left;
}
return current;
}
node* maxi(node* ptr){
node* current=ptr;

while(current->right!=NULL){
    current=current->right;
}
return current;
}
void remove(node* &ptr,int x){
if(ptr==NULL)
    return;
if(x==ptr->elem){
        if(ptr->left!=NULL&&ptr->right!=NULL){
            node* minright=minn(ptr->right);
            ptr->elem==minright->elem;
            remove(ptr->right,minright->elem);
        } else
        {
            node* discard=ptr;
            if(discard->isExternal())
                ptr=NULL;
            else if(ptr->left!=NULL)
                ptr=ptr->left;
            else
                ptr=ptr->right;

                        delete discard;
        }

} else if(x<ptr->elem)
remove(ptr->left,x);
else
    remove(ptr->right,x);

}
long long summ(node*p,long long &s){
if(p!=NULL){
    summ(p->left,s);
    s+=p->elem;
        summ(p->right,s);

}
return s;
}
int occur(node* p,int r,int &c){
if(p==NULL)
    return c;
if(p->elem>r){
    if(p->elem==r)
        c++;
    occur(p->left,r,c);
}
else {
    if(p->elem==r)
        c++;
    occur(p->right,r,c);
}
}
};
int main()
{
    long long s=0;
int size=0,c=0;
    bst t;
t.insert(4);
t.insert(2);
t.insert(1);
t.insert(3);
t.insert(3);
t.insert(6);
t.insert(5);
t.insert(7);

cout<<"num of bst is  "<<t.size(t.root,size)<<endl;

cout<<"min value is : "<<t.minn(t.root)->elem<<endl;
cout<<"max value is : "<<t.maxi(t.root)->elem<<endl;
t.inorder(t.root);
cout<<endl;
t.preorder(t.root);
cout<<endl;
t.postorder(t.root);
cout<<endl;
/*t.remove(t.root,4);
t.inorder(t.root);*/
cout<<endl;

cout<<"the sum is = "<<t.summ(t.root,s)<<endl;
int num;
cin>>num;
cout<<"the occurence of "<<num<<" is = "<<t.occur(t.root,num,c);


    return 0;
}
