#include <stdio.h>
#include <stdlib.h>
#include "E2.h"

int main() {
	int n = 0;
	sach *a = NULL;
	int luachon;
	do {
		luachon = menu();
		switch (luachon) {
			case 1:
				nhap(&n, &a);
				break;
			case 2:
				if (a == NULL) printf("\nChua nhap sach! Vui long chon 1 truoc!");
				else in(n, a);
				break;
			case 3:
				if (a == NULL) printf("\nChua nhap sach! Vui long chon 1 truoc!");
				else demsach(n, a);
				break;
			case 4:
				if (a == NULL) printf("\nChua nhap sach! Vui long chon 1 truoc!");
				else thongke(n, a);
				break;
			case 5:
				printf("\nCam on quy khach da su dung!");
				break;
			default:
				printf("\nVui long chon lai muc 1-5!");
		}
	} while (luachon != 5);

	free(a);
	return 0;
}
