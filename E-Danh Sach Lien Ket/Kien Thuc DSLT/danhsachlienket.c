#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;	
}node;

node *makenode(int x);
void pushfront(node **head,int x);
void pushback(node **head,int x);
void insert(node **head,int x,int k);
void printflist(node *head);
int countnode(node *head);
void popfront(node **head);
void popback(node **head);
void popat(node **head,int k);
void clearlist(node **head);

int main(){
	node *head=NULL;
	
	for(int i=1;i<=5;i++){
		pushfront(&head,i);
	}
	printf("Sau khi them dau :");
	printflist(head);
		
	for(int i=10;i<=50;i+=10){
		pushback(&head,i);
	}
	printf("\n\nSau khi them cuoi :");
	printflist(head);
	
	insert(&head,111,3);
	printf("\n\nSau khi them 111 vao vi tri thu 3 :");
	printflist(head);
	
	popfront(&head);
	popback(&head);
	printf("\n\nSau khi xoa phan tu dau va cuoi cua danh sach :");
	printflist(head);
	
	popat(&head,5);
	printf("\n\nSau khi xoa phan tu thu 5 cua danh sach :");
	printflist(head);
	
	clearlist(&head);
	return 0;
}
node *makenode(int x){
	node *newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL){
		printf("\nKhong the cap phat bo nho!");
		exit(1);
	}
	
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}

void pushfront(node **head,int x){
	node *newnode = makenode(x);
	newnode ->next = *head; 
	*head = newnode;
}

void pushback(node **head,int x){
	node *newnode=makenode(x);
	
	if( *head == NULL ){
		*head = newnode;
		return;
	}
	
	node *temp=*head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newnode;
}
void insert(node **head,int x,int k){
	int n = countnode(*head);
	
	if(k<1 || k>n+1)	return;
	if(k==1){
		pushfront(head,x);
		return;
	}
	node *temp = *head;
	for(int i = 1;i < k-1; i++){
		temp = temp->next;
	}
	node *newnode = makenode(x);
	newnode->next = temp->next;
	temp->next = newnode;
}

void printflist(node *head){
	printf("\nCac gia tri danh sach hien tai :");
	while(head != NULL){
		printf("%-5d",head->data);
		head=head->next;
	}
}

int countnode(node *head){
	int count=0;
	while(head != NULL){
		count++;
		head = head->next;
	}
	return count;
}

void popfront(node **head){
	if(*head==NULL)	return;
	node *temp = *head;
	*head = (*head)->next;
	free(temp);
}
void popback(node **head){
	if(*head == NULL)	return;
	node *temp = *head;
	if(temp->next == NULL){
		*head = NULL;
		free(temp);
		return;
	}
	
	while (temp->next->next !=NULL){
		temp = temp->next;
	}
	node *last = temp->next;
	temp->next = NULL;
	free(last);
}

void popat(node **head,int k){
	int n = countnode(*head);
	if(k<1 || k>n)	return;
	
	if(k==1){
		popfront(head);
		return;
	}
	else{
		node *temp = *head;
		for(int i = 1;i < k-1; i++){
			temp = temp->next;
		}
		node *del = temp->next;	//node thu k
		temp->next = del->next;	//cho node k-1 ket noi voi node k+1
		free(del);
	}
}

void clearlist(node **head) {
    node *current = *head;
    node *nextnode;
    while (current != NULL) {
        nextnode = current->next; 	//luu lai node tiep theo
        free(current);            	//giai phong node hien tai
        current = nextnode;       	//nhay sang node tiep theo
    }
    *head = NULL;
}
