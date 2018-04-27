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

bool checkcycle(struct node *head){
	struct node * temp;
	temp = head->next;
	while(temp){
		temp = temp->next;
		if(temp == head)
			return 1;
		else if(temp){
			head = head->next;
			temp = temp->next;
		}
		else
			return 0;
	}
	return 0;
}

int main(){
	struct node * head = NULL;
	int n;
	cin>>n;
	struct node *y = new node;
	y->data = n;
	y->next = NULL;
	head = insertll(head,y);
	while(n!=1000){
		cin>>n;
		struct node *x = new node;
		x->data = n;
		x->next = NULL;
		head = insertll(head,x);
	}
	printlist(head);
	//y->next = head;
	
	if(checkcycle(head))
		cout<<"cycle exists";
}
