#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "F6.h"

int main() {
	char ten[50];
	printf("Nhap ten file : ");
	fgets(ten, sizeof(ten), stdin);
	ten[strcspn(ten, "\n")] = '\0';

	FILE *f = fopen(ten, "r");
	if (f == NULL) {
		printf("\nLoi : ko the mo hoac ko tim thay file !\n");
		exit(1);
	}

	dathuc dt[3];
	nhapfile(f, dt);

	printf("\n--------------------------------------------------\n");
	printf("\n\t-----Cac da thuc vua nhap-----\n");
	indt('A', dt, 0);
	indt('B', dt, 1);

	printf("\n--------------------------------------------------\n");
	gtdt(dt);

	printf("\n--------------------------------------------------\n");
	printf("\n\t---Da thuc moi sau khi cong---\n");
	congdt(dt);
	indt('S', dt, 2);

	printf("\n--------------------------------------------------\n");
	for (int i = 0; i < 3; i++) {
		free(dt[i].hs);
	}
	return 0;
}
