#ifndef DANH_SACH_H
#define DANH_SACH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct thiSinh{
    char hoTen[50];
    float toan, ly, hoa;
    struct thiSinh* Next;
}thiSinh;

thiSinh *taoThiSinh(char *hoTen, float toan, float ly, float hoa);
void boSungDau(thiSinh **dau, thiSinh *nodeMoi);
void boSungCuoi(thiSinh **dau, thiSinh *nodeMoi);

void nhapDanhSach(thiSinh **dau, int n);
void inDanhSach(thiSinh *dau);

void xuatFileNhiPhan(thiSinh *dau, const char *tenFile);
void nhapFileNhiPhan(thiSinh **dau, const char *tenFile);
void xuatFileVanBan(thiSinh *dau, const char *tenFile);
void nhapFileVanBan(thiSinh **dau, const char *tenFile);

void diemToanMax(thiSinh *dau);
void diemLyMin(thiSinh **dau);

void giaiPhongDanhSach(thiSinh **dau);
void Menu();
#endif