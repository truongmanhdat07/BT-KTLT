#ifndef E2_H
#define E2_H

typedef struct {
	char tensach[100];
	char tentacgia[100];
	int namxuatban;
} sach;

void nhap(int *n, sach **a);
void in(int n, sach *a);
int demsach(int n, sach *a);
void thongke(int n, sach *a);
int menu();

#endif
