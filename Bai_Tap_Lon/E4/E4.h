#ifndef E4_H
#define E4_H

typedef struct giangvien {
	char hoten[30];
	char hocvi[5];
	int sotietday;
	float dongia;
	struct giangvien *next;
} giangvien;

giangvien* taogiangvien();
void bosungdau(giangvien **dau, giangvien *p);
void bosungcuoi(giangvien **dau, giangvien *p);
void nhapdanhsach(giangvien **dau, int n);
void indanhsach(giangvien *dau);
void timths(giangvien *dau);
float tinhtienday(giangvien *gv);
void sapxepgiamdan(giangvien *dau);
void giaiphong(giangvien *dau);

#endif
