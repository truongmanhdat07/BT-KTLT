#include "MenuTongTieuChuan.h"

void hien_thi_menu() {
    system("cls");
    printf("================= BTL KTLT - NHOM 1 =================\n");
    printf("  Menu Tong :\n");
    printf("  1.  Chay bai E1\n");
    printf("  2.  Chay bai E2\n");
    printf("  3.  Chay bai E3\n");
    printf("  4.  Chay bai E4\n");
    printf("  5.  Chay bai E5\n");
    printf("  6.  Chay bai F2\n");
    printf("  7.  Chay bai F3\n");
    printf("  8.  Chay bai F4\n");
    printf("  9.  Chay bai F5\n");
    printf("  10. Chay bai F6\n");
    printf("  11. Chay bai F7\n");
    printf("  12. Chay bai F8\n");
    printf("  13. Thoat chuong trinh\n");
    printf("=====================================================\n");
    printf("Chon bai can chay (1-13): ");
}

void chay_bai(int luachon) {
    switch (luachon) {
        case 1:
            printf("\n=================== DANG CHAY BAI E1 ================\n");
            system("cd ..\\E1 && E1.exe"); 
            printf("\n");
            system("pause");
            break;
        case 2:
            printf("\n=================== DANG CHAY BAI E2 ================\n");
            system("cd ..\\E2 && E2.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 3:
            printf("\n=================== DANG CHAY BAI E3 ================\n");
            system("cd ..\\E3 && E3.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 4:
            printf("\n=================== DANG CHAY BAI E4 ================\n");
            system("cd ..\\E4 && E4.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 5:
            printf("\n=================== DANG CHAY BAI E5 ================\n");
            system("cd ..\\E5 && E5.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 6:
            printf("\n=================== DANG CHAY BAI F2 ================\n");
            system("cd ..\\F2 && F2.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 7:
            printf("\n=================== DANG CHAY BAI F3 ================\n");
            system("cd ..\\F3 && F3.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 8:
            printf("\n=================== DANG CHAY BAI F4 ================\n");
            system("cd ..\\F4 && F4.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 9:
            printf("\n=================== DANG CHAY BAI F5 ================\n");
            system("cd ..\\F5 && F5.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 10:
            printf("\n=================== DANG CHAY BAI F6 ================\n");
            system("cd ..\\F6 && F6.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 11:
            printf("\n=================== DANG CHAY BAI F7 ================\n");
            system("cd ..\\F7 && F7.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 12:
            printf("\n=================== DANG CHAY BAI F8 ================\n");
            system("cd ..\\F8 && F8.exe"); 
            printf("\n"); 
            system("pause"); 
            break;
        case 13:
            printf("\nKet thuc chuong trinh!\n");
            break;
        default:
            printf("\nLua chon khong hop le! Vui long nhap tu 1 den 13.\n");
            system("pause");
    }
}
