#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "F6.h"

void nhapfile(FILE *f, dathuc dt[]) {
	printf("\nDang nhap du lieu tu file...\n");
	fscanf(f, "%d %d", &dt[0].bac, &dt[1].bac);
	for (int i = 0; i < 2; i++) {
		dt[i].hs = (float *)malloc((dt[i].bac + 1) * sizeof(float));
		if (!dt[i].hs) {
			printf("Loi : ko the cap phat bo nho!\n");
			exit(1);
		}
		for (int j = 0; j <= dt[i].bac; j++) {
			fscanf(f, "%f", dt[i].hs + j);
		}
	}
	printf("\nDa nhap xong du lieu !\n");
	fclose(f);
}

void indt(char tendt, dathuc dt[], int a) {
	float tam;
	printf("\nDa thuc %c(X):\t", tendt);
	for (int j = dt[a].bac; j >= 0; j--) {
		if (*(dt[a].hs + j) != 0) {
			if (*(dt[a].hs + j) < 0)  tam = -*(dt[a].hs + j);
			else                       tam =  *(dt[a].hs + j);

			if (j == dt[a].bac && *(dt[a].hs + j) < 0) printf(" - ");

			if      (j == 0) printf("%.2f",       tam);
			else if (j == 1) printf("%.2fX",      tam);
			else             printf("%.2fX^%d",   tam, j);

			for (int m = j - 1; m >= 0; m--) {
				if      (*(dt[a].hs + m) > 0) { printf(" + "); break; }
				else if (*(dt[a].hs + m) < 0) { printf(" - "); break; }
			}
		}
	}
	printf("\t\n");
}

void gtdt(dathuc dt[]) {
	float k, r, s = 0;
	printf("\nNhap gia tri cua k va r : ");
	scanf("%f %f", &k, &r);
	for (int i = 0; i < 2; i++) {
		float x = (i == 0) ? k : r;
		for (int j = 0; j <= dt[i].bac; j++)
			s += *(dt[i].hs + j) * pow(x, j);
	}
	printf("\n -> Gia tri cua S voi A(k) va B(r) la : %.2f\n", s);
}

void congdt(dathuc dt[]) {
	dt[2].bac = (dt[0].bac > dt[1].bac) ? dt[0].bac : dt[1].bac;
	dt[2].hs  = (float *)calloc((dt[2].bac + 1), sizeof(float));
	if (!dt[2].hs) {
		printf("Loi : ko the cap phat bo nho!\n");
		exit(1);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= dt[i].bac; j++)
			*(dt[2].hs + j) += *(dt[i].hs + j);
	}
}
