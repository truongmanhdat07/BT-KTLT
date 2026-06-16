#include "MenuTongNangCao.h"

int main() {
    system("title BTL KTLT - Nhom 1");
    system("mode con: cols=85 lines=30");
    hidecursor(); 
    
    hien_thi_loading();
    system("cls");
    
    int luachon = 1;
    int phim_bam;
    in_menu(luachon);
    
    while (1) {
        phim_bam = getch();
        
        if (phim_bam == 224) {
            phim_bam = getch();
            if (phim_bam == 72) { 
                Beep(1200, 40);
                luachon--;
                if (luachon < 1) luachon = 13;
                in_menu(luachon);
            } 
            else if (phim_bam == 80) { 
                Beep(600, 40);
                luachon++;
                if (luachon > 13) luachon = 1;
                in_menu(luachon);
            }
        }
        else if (phim_bam == 13) {        
            Beep(1000, 80);
            chay_bai(luachon);
            in_menu(luachon);
        }
        else if (phim_bam >= '1' && phim_bam <= '9') {  
            xu_ly_phim_so(phim_bam);
            in_menu(luachon);
        }
    }
    return 0;
}
