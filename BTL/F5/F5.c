#include <stdio.h>
#include <stdlib.h>
#include "F5.h"

toado *nhapday(int *n) {
    do {
        printf("Nhap so diem trong day: ");
        scanf("%d", n);
        if(*n <= 0) {
            printf("So diem khong hop le. Vui long nhap lai!\n");
        }
    } while(*n <= 0);

    toado *diem = (toado *)malloc(*n * sizeof(toado));

    if(diem == NULL) {
        printf("Loi khong the cap phat bo nho!\n");
        return NULL;
    }

    for(int i = 0; i < *n; i++) {
        printf("Nhap toa do diem thu %d (x, y, z): ", i + 1);
        scanf("%f %f %f", &diem[i].x, &diem[i].y, &diem[i].z);
    }
    return diem;
}

void xuatdayrafilevanban(toado *diem, int n, char *tenfile) {
    if(diem == NULL) {
        return;
    }
    FILE *f = fopen(tenfile, "w");
    if(f == NULL) {
        printf("Loi khoi tao file van ban de xuat du lieu.\n");
        return;
    }

    fprintf(f, "%d\n", n);

    for(int i = 0; i < n; i++) {
        fprintf(f, "%f %f %f\n", diem[i].x, diem[i].y, diem[i].z);
    }
    fclose(f);
    printf("Da xuat xong file van ban %s.\n", tenfile);
    return;
}

toado *nhapdaytufilevanban(int *n, char *tenfile) {
    FILE *f = fopen(tenfile, "r");
    if(f == NULL) {
        printf("Loi khong the mo file de doc: ");
        return NULL;
    }
    
    fscanf(f, "%d", n);

    toado *diem = (toado *)malloc(*n * sizeof(toado));
    if(diem == NULL) {
        printf("Loi khong the cap phat du lieu!\n");
        fclose(f);
        return NULL;
    }

    for(int i = 0; i < *n; i++) {
        fscanf(f, "%f %f %f", &diem[i].x, &diem[i].y, &diem[i].z);
    }
    fclose(f);
    printf("Da nhap xong du lieu tu file van ban %s.\n", tenfile);
    return diem;
}

void xuatdayrafilenhiphan(toado *diem, int n, char *tenfile) {
    if(diem == NULL) {
        return;
    }
    FILE *f = fopen(tenfile, "wb");
    if(f == NULL) {
        printf("Loi khong the khoi tao file nhi phan.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, f);

    fwrite(diem, sizeof(toado), n, f);
    fclose(f);
    printf("Da xuat xong file nhi phan %s.\n", tenfile);
}

toado *nhapdaytufilenhiphan(int *n, char *tenfile) {
    FILE *f = fopen(tenfile, "rb");
    if(f == NULL) {
        printf("Loi khong tim thay file nhi phan de doc.\n");
        return NULL;
    }
    fread(n, sizeof(int), 1, f);

    toado *diem = (toado *)malloc(*n * sizeof(toado));
    if(diem == NULL) {
        printf("Loi khong the cap phat bo nho!\n");
        fclose(f);
        return NULL;
    }

    fread(diem, sizeof(toado), *n, f);
    fclose(f);
    printf("Da doc xong du lieu tu file nhi phan %s.\n", tenfile);
    return diem;
}

void inday(toado *diem, int n) {
    if(diem == NULL){
        return;
    }
    printf("%d\n", n);
    for(int i = 0; i < n; i++) {
        printf("%.2f %.2f %.2f\n", diem[i].x, diem[i].y, diem[i].z);
    }
    return;
}
