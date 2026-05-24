#ifndef F7_H
#define F7_H

typedef struct {
	int manv;
	char hoten[50];
	char phong;
	int luong;
} nhanvien;

int docfile(nhanvien a[]);
void indanhsach(nhanvien a[], int n);
void timluongcaonhat(nhanvien a[], int n);
void demnhanvien(nhanvien a[], int n);
void ghifile(nhanvien a[], int n);

#endif
