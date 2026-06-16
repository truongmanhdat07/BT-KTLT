#include <stdio.h>
#include "F7.h"

int main() {
	nhanvien a[100];
	int n = docfile(a);
	indanhsach(a, n);
	timluongcaonhat(a, n);
	demnhanvien(a, n);
	ghifile(a, n);
	return 0;
}
