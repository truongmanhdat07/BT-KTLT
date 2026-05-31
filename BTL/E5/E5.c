#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E5.h"

sach* taosach() {
	sach *s = (sach*)malloc(sizeof(sach));

	fflush(stdin);
	printf("\nNhap ten sach: ");
	gets(s->tensach);

	printf("Nhap so luong: ");
	scanf("%d", &s->soluong);

	fflush(stdin);
	printf("Nhap loai sach (A/B/C): ");
	scanf("%c", &s->loaisach);

	printf("Nhap nam xuat ban: ");
	scanf("%d", &s->namxuatban);

	s->next = NULL;
	return s;
}

void bosungdau(sach **dau, sach *p) {
	p->next = *dau;
	*dau = p;
}

void bosungcuoi(sach **dau, sach *p) {
	if (*dau == NULL) {
		*dau = p;
	} else {
		sach *tam = *dau;
		while (tam->next != NULL) {
			tam = tam->next;
		}
		tam->next = p;
	}
}

void nhapdanhsach(sach **dau, int n) {
	sach *p;
	for (int i = 0; i < n; i++) {
		printf("\n================ SACH THU %d ================\n", i + 1);
		p = taosach();
		bosungcuoi(dau, p);
	}
}

void indanhsach(sach *dau) {
	sach *tam = dau;
	int stt = 1;

	printf("=============================================================================\n");
	printf("| %-3s | %-30s | %-10s | %-8s | %-10s |\n",
	       "STT", "TEN SACH", "SO LUONG", "LOAI", "NAM XB");
	printf("=============================================================================\n");

	while (tam != NULL) {
		printf("| %-3d | %-30s | %-10d | %-8c | %-10d |\n",
		       stt, tam->tensach, tam->soluong, tam->loaisach, tam->namxuatban);
		printf("-----------------------------------------------------------------------------\n");
		stt++;
		tam = tam->next;
	}
}

void xoasach2010(sach **dau) {
	sach *tam = *dau;
	sach *truoc = NULL;

	while (tam != NULL) {
		if (tam->namxuatban == 2010) {
			if (truoc == NULL) {
				*dau = tam->next;
				free(tam);
				tam = *dau;
			} else {
				truoc->next = tam->next;
				free(tam);
				tam = truoc->next;
			}
		} else {
			truoc = tam;
			tam = tam->next;
		}
	}
}

void tongloaisach(sach *dau) {
	sach *tam = dau;
	int tonga = 0, tongb = 0, tongc = 0;

	while (tam != NULL) {
		if      (tam->loaisach == 'A') tonga += tam->soluong;
		else if (tam->loaisach == 'B') tongb += tam->soluong;
		else if (tam->loaisach == 'C') tongc += tam->soluong;
		tam = tam->next;
	}

	printf("================================\n");
	printf("| %-15s | %-10s |\n", "LOAI SACH", "SO LUONG");
	printf("================================\n");
	printf("| %-15s | %-10d |\n", "Loai A", tonga);
	printf("| %-15s | %-10d |\n", "Loai B", tongb);
	printf("| %-15s | %-10d |\n", "Loai C", tongc);
	printf("================================\n");
}

void sapxeptangdan(sach *dau) {
	sach *p, *q;
	char tensach[50];
	int soluong, namxuatban;
	char loaisach;

	for (p = dau; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->soluong > q->soluong) {
				strcpy(tensach, p->tensach);
				strcpy(p->tensach, q->tensach);
				strcpy(q->tensach, tensach);

				soluong = p->soluong;
				p->soluong = q->soluong;
				q->soluong = soluong;

				loaisach = p->loaisach;
				p->loaisach = q->loaisach;
				q->loaisach = loaisach;

				namxuatban = p->namxuatban;
				p->namxuatban = q->namxuatban;
				q->namxuatban = namxuatban;
			}
		}
	}
}

void giaiphong(sach *dau) {
	sach *tam;
	while (dau != NULL) {
		tam = dau;
		dau = dau->next;
		free(tam);
	}
}
