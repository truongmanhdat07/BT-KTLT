#ifndef E5_H
#define E5_H

typedef struct sach {
	char tensach[30];
	int soluong;
	char loaisach;
	int namxuatban;
	struct sach *next;
} sach;

sach* taosach();
void bosungdau(sach **dau, sach *p);
void bosungcuoi(sach **dau, sach *p);
void nhapdanhsach(sach **dau, int n);
void indanhsach(sach *dau);
void xoasach2010(sach **dau);
void tongloaisach(sach *dau);
void sapxeptangdan(sach *dau);
void giaiphong(sach *dau);

#endif
