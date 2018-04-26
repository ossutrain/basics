#include <iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

struct node* insertll(struct node *head, struct node *x){
	x->next = head;
	return x;
}

void printlist(struct node *head){
	while(head!=NULL){
		cout<<head->data<<"  ";
		head = head->next;
	}
	cout<<'\n';
}

struct node* reverse(struct node *head){
	if(!head)
		return head;
	struct node *temp = head->next;
	head->next = NULL;
	struct node *x=NULL;
	while(temp){
		x = temp->next;
		temp->next = head;
		head = temp;
		temp = x;
	}
	return head;
}

int main(){
	struct node * head = NULL;
	int n;
	cin>>n;
	while(n!=1000){
		struct node *x = new node;
		x->data = n;
		x->next = NULL;
		head = insertll(head,x);
		cin>>n;
	}
	printlist(head);
	head = reverse(head);
	printlist(head);
}
