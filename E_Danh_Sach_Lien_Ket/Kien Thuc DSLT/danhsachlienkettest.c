#include <stdio.h>
#include <stdlib.h>
//xay dung danh sach lien ket voi day so nguyen
// dinh nghia cau truc cua 1 nut
struct Node {
    int data;
    struct Node* next;
};
// tao nut moi
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; //giong nhu newNode.data
    newNode->next = NULL;
    return newNode;
}
// them nut vao cuoi DS
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) { //neu ds rong thi them vao dau ds
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) { //ds k rong thi duyet va them vao cuoi ds
        temp = temp->next;
    }
    temp->next = newNode;
}

// chen vao vi tri bat ky
void insertNodeAt(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Vi tri khong hop le.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Xoa nut theo gia tri
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;

    // neu nut dau tien chua gia tri can xoa
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Da xoa gia tri %d.\n", key);
        return;
    }

    // Tim nut can xoa
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Khong tim thay gia tri %d.\n", key);
        return;
    }

    // Xóa nút
    prev->next = temp->next;
    free(temp);
    printf("Da xoa gia tri %d.\n", key);
}

// tim nut theo gia tri
void searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Gia tri %d tim thay tai vi tri %d.\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Khong tim thay gia tri %d.\n", key);
}
// in danh sach 
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Giai phong bo nho
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int n, value;    
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &value);appendNode(&head, value);
    }

    printf("Danh sach liên ket la: ");   printList(head);
    int val, pos;
    printf("Nhap gia tri can them: "); scanf("%d",&val);
    printf("Nhap vi tri can them: "); scanf("%d",&pos);
    insertNodeAt(&head,val,pos);
	printf("Danh sach liên ket sau khi them la: ");
    printList(head);
    
    freeList(head); 
}
