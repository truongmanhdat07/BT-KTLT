#include<stdio.h>
#include<stdlib.h>

typedef struct {
    float x;
    float y;
    float z;
} toado;

toado *nhapday(int *);
void xuatdayrafilevanban(toado *, int , char *);
toado *nhapdaytufilevanban(int *, char *);
void xuatdayrafilenhiphan(toado *, int , char *);
toado *nhapdaytufilenhiphan(int *, char *);
void inday(toado *, int );

int main() {
    int sodiem;
    
    printf("--- 1. nhap tu ban phim ---\n");
    toado *mangdiem = nhapday(&sodiem);

    if (mangdiem != NULL) {
        printf("\n--- 2. xuat ra file van ban ---\n");
        xuatdayrafilevanban(mangdiem, sodiem, "toado.txt");
        printf("da xuat du lieu vao file %s\n","toado.txt");

        printf("\n--- 4. xuat ra file nhi phan ---\n");
        xuatdayrafilenhiphan(mangdiem, sodiem, "toado.bin");
        printf("da xuat du lieu vao file %s\n", "toado.bin");
        free(mangdiem);
    }
    printf("\n--- 3. nhap lai tu file van ban de kiem tra ---\n");
    int sodiemvanban;

    toado *mangdiemvanban = nhapdaytufilevanban(&sodiemvanban, "toado.txt");

    inday(mangdiemvanban, sodiemvanban);

    if (mangdiemvanban != NULL) free(mangdiemvanban);

    printf("\n--- 5. nhap lai tu file nhi phan de kiem tra ---\n");
    int sodiemnhiphan;

    toado *mangdiemnhiphan = nhapdaytufilenhiphan(&sodiemnhiphan, "toado.bin");

    inday(mangdiemnhiphan, sodiemnhiphan);

    if (mangdiemnhiphan != NULL) free(mangdiemnhiphan);
    return 0;
}

toado *nhapday(int *n) {
    do {
        printf("Nhap so diem trong day: ");
        scanf("%d", n);
        if(*n <= 0) {
            printf("So diem khong hop le. Vui long nhap lai!\n");
        }
    }while(*n <= 0);

    toado *diem = (toado *)malloc(*n * sizeof(toado));

    if(diem == NULL) {
        printf("Loi khong the cap phat bo nho!\n");
        return NULL;
    }

    for(int i = 0; i < *n; i++) {
        printf("Nhap toa do diem thu %d (x, y, z):", i + 1);
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
    printf("Da xuat xong file van ban %s.\n",tenfile);
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
        return NULL;
    }

    fread(diem, sizeof(toado), *n, f);
    fclose(f);
    printf("Da doc xong du lieu tu file nhi phan %s.\n",tenfile);
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
