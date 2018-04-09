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
int checkbalance(struct node* root, bool* balance){
	if(root == NULL){
		*balance = true;
		return 0;
	}
	else{
		//check if left subtree is balanced
		bool lbal = true;
		int lheight = checkbalance(root->left, &lbal);
		if(!lbal){
			cout<<"left subtree is not balanced\n";
		}
		//check if left subtree is balanced
		bool rbal = true;
		int rheight = checkbalance(root->right, &rbal);
		if(!rbal)
			cout<<"right subtree is not balanced\n";
		if(rbal && lbal && abs(lheight - rheight)<=1){
			*balance = true;
			return 1 + max(lheight,rheight);
		}
		else{
			*balance = false;
			return 1 + max(lheight,rheight);
		}
	}
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
	bool bal = true;
	int height = checkbalance(root,&bal);
	if(bal)
		cout<<"tree is balanced and height is "<<height<<" \n";
	else
		cout<<"tree height is "<<height<<" \n";
}
