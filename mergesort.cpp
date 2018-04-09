#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

void splitlist(struct node *head, struct node **firsthalf, struct node **secondhalf){
	struct node *slowptr = head;
	struct node *fastptr = head->next;
	while(fastptr!=NULL){
		if(fastptr->next!=NULL){
			fastptr = fastptr->next;
			slowptr = slowptr->next;
		}
		fastptr = fastptr->next;	
	}
	*firsthalf = head;
	*secondhalf = slowptr->next;
	slowptr->next = NULL;
}

struct node* mergelists(struct node* firsthalf, struct node* secondhalf){
	if(firsthalf==NULL)
		return secondhalf;
	if(secondhalf==NULL)
		return firsthalf;
	struct node* result = NULL;
	if(firsthalf->data<=secondhalf->data){
		result = firsthalf;
		result->next = mergelists(firsthalf->next,secondhalf);
	}
	else{
		result = secondhalf;
		result->next = mergelists(firsthalf,secondhalf->next);
	}
	return result;
}

void mergesort(struct  node **headAddress){
	struct node *head = *headAddress;
	//zero entry or one entry lists
	if(head == NULL || head->next==NULL){
		return;
	}
	struct node *firsthalf, *secondhalf;
	splitlist(head,&firsthalf,&secondhalf);
	/*
	cout<<"first half\n";
	struct node *ptr = firsthalf;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<"second half\n";
	ptr = secondhalf;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}	
	cout<<'\n';
	*/
	
	mergesort(&firsthalf);
	mergesort(&secondhalf);
	
	
	//merge here
	*headAddress = mergelists(firsthalf,secondhalf);
	/*
	struct node *newhead = NULL;
	struct node *newtail = NULL;
	while((firsthalf!=NULL) && (secondhalf!=NULL)){
		if(firsthalf->data <= secondhalf->data){
			if(newhead==NULL){
				newhead = firsthalf;
				newtail = firsthalf;
				cout<<"inserted first entry "<<newtail->data<<'\n';
			}
			else{
				newtail->next = firsthalf;
				newtail = newtail->next;
				cout<<"inserted entry "<<newtail->data<<'\n';
			}
			firsthalf = firsthalf->next;
		}
		else{
			if(newhead==NULL){
				newhead = secondhalf;
				newtail = secondhalf;
				cout<<"inserted first entry "<<newtail->data<<'\n';
			}
			else{
				newtail->next = secondhalf;
				newtail = newtail->next;
				cout<<"inserted entry "<<newtail->data<<'\n';
			}
			secondhalf = secondhalf->next;			
		}
	}
	if(firsthalf!=NULL){
		newtail->next = firsthalf;
	}
	else{
		newtail->next = secondhalf;
	}
	*/
	/*
	//print all starting from newhead
	cout<<"printing the list in newhead\n";
	//struct node *ptr;
	ptr = *headAddress;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<'\n';
	*/
}

int main(){
	int n;
	cin>>n;
	node *head = NULL;
	//insert at head
	for(int i=0;i<n;i++){
		node *temp = new node;
		temp->next = head;
		cin>>temp->data;
		head = temp;
	}
	mergesort(&head);//not passing n-lenght of list; compute it using fast-slow pointers
	cout<<"printing the list in end\n";
	struct node *ptr;
	ptr = head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<'\n';
	return 0;
}
