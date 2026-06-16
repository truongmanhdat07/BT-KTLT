#ifndef F2_H
#define F2_H

typedef struct {
	char tenhanghoa[100];
	int soluong;
	int loaihanghoa;
} hanghoa;

void nhap(hanghoa a[], int n);
void in(hanghoa a[], int n);
int tonghanghoa(hanghoa a[], int n);
void timkiem(hanghoa a[], int n);
void sapxep(hanghoa a[], int n);

#endif
