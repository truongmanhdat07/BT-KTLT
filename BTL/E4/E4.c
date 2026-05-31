#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E4.h"

giangvien* taogiangvien() {
	giangvien *gv = (giangvien*)malloc(sizeof(giangvien));

	fflush(stdin);
	printf("\nNhap ho ten: ");
	gets(gv->hoten);

	printf("Nhap hoc vi (TS/ThS/CN): ");
	gets(gv->hocvi);

	printf("Nhap so tiet day: ");
	scanf("%d", &gv->sotietday);

	printf("Nhap don gia: ");
	scanf("%f", &gv->dongia);

	gv->next = NULL;
	return gv;
}

void bosungdau(giangvien **dau, giangvien *p) {
	p->next = *dau;
	*dau = p;
}

void bosungcuoi(giangvien **dau, giangvien *p) {
	if (*dau == NULL) {
		*dau = p;
	} else {
		giangvien *tam = *dau;
		while (tam->next != NULL) {
			tam = tam->next;
		}
		tam->next = p;
	}
}

void nhapdanhsach(giangvien **dau, int n) {
	giangvien *p;
	for (int i = 0; i < n; i++) {
		printf("\n================================== GIANG VIEN THU %d ===============================\n", i + 1);
		p = taogiangvien();
		bosungcuoi(dau, p);
	}
}

float tinhtienday(giangvien *gv) {
	float heso;
	if      (strcmp(gv->hocvi, "TS")  == 0) heso = 1.5;
	else if (strcmp(gv->hocvi, "ThS") == 0) heso = 1.0;
	else                                     heso = 0.5;
	return gv->sotietday * gv->dongia * heso;
}

void indanhsach(giangvien *dau) {
	giangvien *tam = dau;
	int stt = 1;

	printf("===================================================================================\n");
	printf("| %-3s | %-25s | %-6s | %-8s | %-12s | %-10s |\n",
	       "STT", "HO TEN", "HOC VI", "SO TIET", "DON GIA", "TIEN DAY");
	printf("===================================================================================\n");

	while (tam != NULL) {
		printf("| %-3d | %-25s | %-6s | %-8d | %-12.0f | %-10.0f |\n",
		       stt, tam->hoten, tam->hocvi, tam->sotietday,
		       tam->dongia, tinhtienday(tam));
		printf("-----------------------------------------------------------------------------------\n");
		stt++;
		tam = tam->next;
	}
}

void timths(giangvien *dau) {
	giangvien *tam = dau;
	int timthay = 0;

	while (tam != NULL) {
		if (strcmp(tam->hocvi, "ThS") == 0) { timthay = 1; break; }
		tam = tam->next;
	}

	if (timthay == 0) {
		printf("Khong tim thay giang vien co hoc vi ThS.\n");
		return;
	}

	tam = dau;
	int stt = 1;

	printf("===================================================================================\n");
	printf("| %-3s | %-25s | %-10s | %-8s |\n",
	       "STT", "HO TEN", "SO TIET", "DON GIA");
	printf("===================================================================================\n");

	while (tam != NULL) {
		if (strcmp(tam->hocvi, "ThS") == 0) {
			printf("| %-3d | %-25s | %-10d | %-8.0f |\n",
			       stt, tam->hoten, tam->sotietday, tam->dongia);
			printf("-----------------------------------------------------------------------------------\n");
		}
		stt++;
		tam = tam->next;
	}
}

void sapxepgiamdan(giangvien *dau) {
	giangvien *p, *q;
	char hoten[50], hocvi[10];
	int sotietday;
	float dongia;

	for (p = dau; p != NULL; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->sotietday < q->sotietday) {
				strcpy(hoten, p->hoten);
				strcpy(p->hoten, q->hoten);
				strcpy(q->hoten, hoten);

				strcpy(hocvi, p->hocvi);
				strcpy(p->hocvi, q->hocvi);
				strcpy(q->hocvi, hocvi);

				sotietday = p->sotietday;
				p->sotietday = q->sotietday;
				q->sotietday = sotietday;

				dongia = p->dongia;
				p->dongia = q->dongia;
				q->dongia = dongia;
			}
		}
	}
}

void giaiphong(giangvien *dau) {
	giangvien *tam;
	while (dau != NULL) {
		tam = dau;
		dau = dau->next;
		free(tam);
	}
}
