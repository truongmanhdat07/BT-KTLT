#include <stdio.h>
#include "F2.h"

int main() {
	int n;
	printf("Vui long nhap so luong hang hoa :");
	scanf("%d", &n);
	hanghoa a[n];
	nhap(a, n);
	in(a, n);
	printf("\nTong so luong hang hoa la :%d", tonghanghoa(a, n));
	timkiem(a, n);
	sapxep(a, n);
	return 0;
}
