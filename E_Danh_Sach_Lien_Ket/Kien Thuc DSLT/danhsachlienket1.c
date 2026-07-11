#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node ;

node *makenode(int x){
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}

void inserthead(node **head,int x){
	node *newnode=makenode(x);
	newnode->next=*head;
	*head=newnode;
}

void printflist(node *head){
	node *curr=head;
	while(curr!=NULL){
		printf("%-5d",curr->data);
		curr=curr->next;
	}
	printf("NULL");
}
int main(){
	node *head=NULL;
	int x=5;
	inserthead(&head,x);
	printflist(head);
}
