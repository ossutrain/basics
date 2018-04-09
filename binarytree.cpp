#include <iostream>
using namespace std;

typedef int T;
struct node{
	T data;
	struct node *left;
	struct node *right;
};

struct node* insertnode(struct node *root, struct node *n){
	if(root==NULL){
		return n;
	}
	if(n->data<=root->data)
		root->left = insertnode(root->left,n);
	else
		root->right = insertnode(root->right,n);
	return root;
}
void printinorder(struct node *root){
	if(root!=NULL){
		cout<<root->data<<"  ";
		printinorder(root->left);
		printinorder(root->right);
	}
}
void printpreorder(struct node *root){
	if(root!=NULL){
		printpreorder(root->left);
		cout<<root->data<<"  ";
		printpreorder(root->right);
	}
}
void printpostorder(struct node *root){
	if(root!=NULL){
		printpostorder(root->left);
		printpostorder(root->right);
		cout<<root->data<<"  ";
	}
}
int getheight(struct node* root){
	if(root == NULL)
		return 1;
	else
		return 1 + max(getheight(root->left),getheight(root->right));
}
bool checkbalance(struct node* root){
	int x = getheight(root->left);
	int y = getheight(root->right);
	if((x>=y && x - y <= 1) || (x<y && y-x<=1))
		return true;
	return false;
}
int main(){
	T x = 0;
	struct node *root = NULL;
	while(x!=1000){
		cin>>x;
		struct node *nx = new node;
		nx->data = x;
		nx->left = NULL;
		nx->right = NULL;
		root = insertnode(root,nx);
	}
	//printinorder(root);
	printpreorder(root);
	cout<<'\n';
	//printpostorder(root);
	if(checkbalance(root))
		cout<<"tree is balanced\n";
}
