#ifndef E3_H
#define E3_H

typedef struct Node {
	float hs;
	int bac;
	struct Node* next;
} Node;

Node* taoNode(float hs, int bac);
void  nhapdt(Node *dt[], int a);
void  indt(Node *dt[], int a);
float tinhgt(Node *dt[], int a);
float tinhdh(Node *dt[], int a);
void  congdt(Node *dt[], int a);
void  giaiphong(Node *dt[], int a);

#endif
