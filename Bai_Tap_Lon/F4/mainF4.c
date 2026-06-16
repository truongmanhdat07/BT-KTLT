#include <stdio.h>
#include <stdlib.h>
#include "f4.h"


int main(){
    thiSinh *danhSach = NULL;
    int luaChon=0;
    int soLuong=0;

    do{
        Menu();
        if(scanf("%d", &luaChon)!=1){
            while(getchar()!='\n');
            luaChon = -1;
        }
        switch(luaChon){
            case 1:
                printf("Nhap so luong thi sinh can them: ");
                scanf("%d", &soLuong);
                nhapDanhSach(&danhSach, soLuong);
                break;
            case 2:
                if(danhSach == NULL){
                    printf("Danh sach dang rong!\n");
                }else{
                    inDanhSach(danhSach);
                }
                break;
            case 3:
                xuatFileVanBan(danhSach, "output.txt");
                printf("Da ghi du lieu ra file 'output.txt' thanh cong!\n");
                break;
            case 4:
                nhapFileVanBan(&danhSach, "input.txt");
                printf("Da doc du lieu tu file 'input.txt' vao danh sach!\n");
                break;
            case 5:
                xuatFileNhiPhan(danhSach, "output.bin");
                printf("Da ghi du lieu ra file 'output.bin' thanh cong!\n");
                break;
            case 6:
                nhapFileNhiPhan(&danhSach, "intput.bin");
                printf("Da doc du lieu tu file 'input.bin' vao danh sach!\n");
                break;
            case 7:
                diemToanMax(danhSach);
                break;
            case 8:
                diemLyMin(&danhSach);
                printf("Da xoa cac thi sinh co diem ly thap nhat khoi danh sach!\n");
                break;
            case 0:
                giaiPhongDanhSach(&danhSach);
                printf("Da giai phong bo nho. Chuong trinh ket thuc!\n");
                break;
            default:
            printf("Lua chon nhap vao khong hop le!Vui long nhap tu 0 den 8!\n");
        }
    }while(luaChon!=0);

    return 0;
}