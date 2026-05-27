#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tao cau truc
typedef struct Student{
    char name[50];
    float score;
    struct Student *next;
} Student;

Student *head = NULL; // con tro vao dau danh sách

// Hàm thêm sinh viên vào danh sách
void addStudent(char name[], float score) {
    Student *newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Khong the cap phat bo nho!\n");
        return;
    }
    strcpy(newStudent->name, name);
    newStudent->score = score;
    newStudent->next = NULL;
    
    if (head == NULL) {
        head = newStudent;
    } else {
        Student *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// In danh sach sinh viên
void printStudents() {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    printf("\nDanh sach sinh vien:\n");
    printf("%-20s %7s\n", "Ho ten", "Diem");
    Student *temp = head;
    while (temp != NULL) {
        printf("%-20s %7.2f\n", temp->name, temp->score);
        temp = temp->next;
    }
}
// giai phong bo nho
void freeList() {
    Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    char name[50];
    float score;

    printf("Nhap so sinh vien: ");  scanf("%d", &n);
    getchar(); // xoa bo nho dem

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i + 1);
        printf("Ho ten: "); fflush(stdin); gets(name);
        printf("Diem: ");   scanf("%f", &score);
      
        addStudent(name, score);
    }
    printStudents();
    freeList(); // 
}
