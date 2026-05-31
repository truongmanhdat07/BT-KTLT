#include <stdio.h>
#include <stdlib.h>
#include "E1.h"

int main() {
	float *arr = NULL;
	int n = 0;
	float solonnhat;
	int luaChon;

	do {
		luaChon = menu();

		switch (luaChon) {
			case 1:
				if (arr != NULL) {
					free(arr);
					arr = NULL;
				}
				n = nhap(&arr);
				break;

			case 2:
				if (arr == NULL || n <= 0) {
					printf("Loi: Chua co day so!\n");
				} else {
					xuat(n, arr);
				}
				break;

			case 3:
				if (arr == NULL || n <= 0) {
					printf("Loi: Chua co day so!\n");
				} else {
					if (soduonglonnhat(n, arr, &solonnhat) == 1) {
						printf("-> Max duong la: %.2f\n", solonnhat);
					} else {
						printf("-> Mang khong co so duong!\n");
					}
				}
				break;

			case 4:
				if (arr == NULL || n <= 0) {
					printf("Loi: Chua co day so!\n");
				} else {
					if (sofibo(n, arr) == 1) {
						printf("-> Day so co tinh chat Fibonacci.\n");
					} else {
						printf("-> Day so khong co tinh chat Fibonacci.\n");
					}
				}
				break;

			case 5:
				printf("Dang thoat...\n");
				if (arr != NULL) {
					free(arr);
				}
				break;

			default:
				printf("Lua chon khong hop le!\n");
				break;
		}
	} while (luaChon != 5);

	return 0;
}
