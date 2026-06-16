#include <stdio.h>
#include <stdlib.h>
#include "E3.h"

int main() {
    int sodt;
    printf("--------------------------------------------------\n");
    printf("\nChon so da thuc muon nhap : ");
    scanf("%d", &sodt);

    Node **dt = (Node **)calloc(sodt + 1, sizeof(Node *));
    if (!dt) {
        fprintf(stderr, "Loi : ko the cap phat bo nho\n");
        exit(1);
    }

    printf("\n--------------------------------------------------\n");
    printf("\n\t---Nhap bac va he so---\n");
    for (int i = 0; i < sodt; i++) {
        nhapdt(dt, i);
        printf("\n\t-----------------------\n");
    }

    printf("\n--------------------------------------------------\n");
    printf("\n\t-----Cac da thuc vua nhap-----\n");
    for (int i = 0; i < sodt; i++) {
        printf("\nDa thuc %d : \t", i + 1);
        indt(dt, i);
    }

    printf("\n--------------------------------------------------\n");
    printf("\n\t-----Tinh Gia Tri Tai X-----\n");
    printf("%.2f\n", tinhgt(dt, sodt));

    printf("\n--------------------------------------------------\n");
    printf("\n\t---Tinh Gia Tri Dao Ham Tai X---\n");
    printf("%.2f\n", tinhdh(dt, sodt));

    printf("\n--------------------------------------------------\n");
    congdt(dt, sodt);
    indt(dt, sodt);

    printf("\n--------------------------------------------------\n");
    for (int i = 0; i <= sodt; i++) {
        giaiphong(dt, i);
    }
    free(dt);
    return 0;
}
