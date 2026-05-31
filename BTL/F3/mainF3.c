#include <stdio.h>
#include <stdlib.h>
#include "F3.h"

int main() {
    int sohang, socot;
    
    printf("\n--- 1. NHAP MA TRAN TU BAN PHIM ---\n");
    float **matran = nhapmatran(&sohang, &socot);
    printf("Ma tran ban vua nhap:\n");
    inmatran(matran, sohang, socot);

    printf("\n--- 3. XUAT MA TRAN RA FILE VAN BAN ---\n");
    xuatmatranrafilevanban(matran, sohang, socot, "matran.txt");

    printf("\n--- 4. GHI MA TRAN RA FILE NHI PHAN ---\n");
    xuatmatranrafilenhiphan(matran, sohang, socot, "matran.bin");

    giaiphongbonho(matran, sohang);

    printf("\n--- 2. DOC MA TRAN TU FILE VAN BAN ---\n");
    int sohangvanban, socotvanban;
    float **matrandocvanban = nhapmatrantufilevanban(&sohangvanban, &socotvanban, "matran.txt");
    if(matrandocvanban != NULL) {
        printf("Ma tran doc duoc tu matran.txt:\n");
        inmatran(matrandocvanban, sohangvanban, socotvanban);
        giaiphongbonho(matrandocvanban, sohangvanban); 
    }

    printf("\n--- 5. DOC MA TRAN TU FILE NHI PHAN ---\n");
    int sohangnhiphan, socotnhiphan;
    float **matrandocnhiphan = nhapmatrantufilenhiphan(&sohangnhiphan, &socotnhiphan, "matran.bin");
    if(matrandocnhiphan != NULL) {
        printf("Ma tran doc duoc tu matran.bin:\n");
        inmatran(matrandocnhiphan, sohangnhiphan, socotnhiphan);
        giaiphongbonho(matrandocnhiphan, sohangnhiphan); 
    }

    printf("\n--- HOAN THANH CHUONG TRINH ---\n");
    return 0;
}
