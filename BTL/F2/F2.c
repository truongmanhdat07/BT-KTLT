#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "F2.h"

void nhap(hanghoa a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Vui long nhap hang hoa thu %d :", i + 1);
		printf("\nTen hang hoa :");
		fflush(stdin);
		gets(a[i].tenhanghoa);
		printf("Loai hang hoa :");
		scanf("%d", &a[i].loaihanghoa);
		printf("So luong :");
		scanf("%d", &a[i].soluong);
	}
}

void in(hanghoa a[], int n) {
	FILE *f = fopen("hanghoa.txt", "w");
	if (f == NULL) {
		printf("\nKhong tao duoc file !");
		exit(1);
	}
	fprintf(f, "\nDanh Sach Hang Hoa :\n");
	fprintf(f, "\n| %-30s | %-15s | %-15s |", "Ten Hang Hoa", "Loai Hang Hoa", "So Luong");
	for (int i = 0; i < n; i++) {
		fprintf(f, "\n| %-30s | %-15d | %-15d |", a[i].tenhanghoa, a[i].loaihanghoa, a[i].soluong);
	}
	printf("\nDa in thanh cong vao file :\"hanghoa.txt\"");
	fclose(f);
}

int tonghanghoa(hanghoa a[], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += a[i].soluong;
	}
	return tong;
}

void timkiem(hanghoa a[], int n) {
	char tenhangcantim[100];
	printf("\nNhap ten hang hoa can tim :");
	fflush(stdin);
	gets(tenhangcantim);
	int timthay = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].tenhanghoa, tenhangcantim) == 0) {
			if (timthay == 0) {
				printf("\nTim thay hang hoa can tim :\n");
				printf("\n| %-30s | %-15s | %-15s |", "Ten Hang Hoa", "Loai Hang Hoa", "So Luong");
			}
			printf("\n| %-30s | %-15d | %-15d |", a[i].tenhanghoa, a[i].loaihanghoa, a[i].soluong);
			timthay = 1;
		}
	}
	if (timthay == 0) {
		printf("\nKhong tim thay hang hoa co ten: %s\n", tenhangcantim);
	}
}

void sapxep(hanghoa a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(a[i].tenhanghoa, a[j].tenhanghoa) > 0) {
				hanghoa tamthoi = a[i];
				a[i] = a[j];
				a[j] = tamthoi;
			}
		}
	}
	printf("\n\nDa sap xep thanh cong");
	FILE *F = fopen("hanghoa.data", "wb");
	if (F == NULL) {
		printf("\nKhong tao duoc file");
		exit(1);
	}
	fwrite(a, sizeof(hanghoa), n, F);
	printf("\nDa in thanh cong danh sach hang hoa sau khi sap xep vao file \"hanghoa.data\"");
	fclose(F);
}
