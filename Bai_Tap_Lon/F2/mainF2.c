#include <stdio.h>
#include <stdlib.h>
#include "F2.h"

int main() {
	int n;
	printf("Vui long nhap so luong hang hoa :");
	scanf("%d", &n);
	hanghoa *a = (hanghoa *)malloc(n * sizeof(hanghoa));
	if (a == NULL) {
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	nhap(a, n);
	in(a, n);
	printf("\nTong so luong hang hoa la :%d", tonghanghoa(a, n));
	timkiem(a, n);
	sapxep(a, n);
	free(a);
	return 0;
}
