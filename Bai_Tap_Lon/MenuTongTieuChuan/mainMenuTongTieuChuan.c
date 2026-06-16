#include "MenuTongTieuChuan.h"

int main() {
    int luachon;
    do {
        hien_thi_menu();
        if (scanf("%d", &luachon) != 1) {
            fflush(stdin);
            luachon = -1;
        }

        chay_bai(luachon);
        
    } while (luachon != 13);

    return 0;
}
