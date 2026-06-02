#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float **capphatmatran(int , int);
void giaiphongbonho(float **, int);
float **nhapmatran(int *, int *);
float **nhapmatrantufilevanban(int *, int *, char *tenfile);
void xuatmatranrafilevanban(float **, int, int, char *);
void xuatmatranrafilenhiphan(float **, int ,int , char *);
float **nhapmatrantufilenhiphan(int *, int *, char *);
void inmatran(float **, int sohang, int socot);

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


float **capphatmatran(int sohang, int socot) {
    float **matran = (float **)malloc(sohang * sizeof(float *));
    for(int i = 0; i < sohang; i++) {
        matran[i] = (float *)malloc(socot * sizeof(float));
    }
    return matran;
}

void giaiphongbonho(float **matran, int sohang) {
    for(int i = 0; i < sohang; i++) {
        free(matran[i]);
    }free(matran);
}

float **nhapmatran(int *sohang, int *socot) {
    printf("Nhap so hang cua ma tran: ");
    scanf("%d", sohang);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", socot);

    float **matran = capphatmatran(*sohang, *socot);

    for(int i = 0; i < *sohang; i++) {
        for(int j = 0; j < *socot; j ++) {
            printf("Nhap phan tu [%d][%d]: ",i + 1, j + 1);
            scanf("%f", &matran[i][j]);
        }
    }
    return matran;
}

float **nhapmatrantufilevanban(int *sohang, int *socot, char *tenfile) {
    FILE *f = fopen( tenfile , "r");
    if(f == NULL) {
        printf("Loi khong the mo file de doc. \n ");
        return NULL;
    }

    fscanf(f, "%d %d", sohang, socot);

    float **matran = capphatmatran(*sohang, *socot);
    if(matran == NULL) {
        printf("Loi khong the cap phat bo nho!\n");
        return NULL;
    }

    for(int i = 0; i < *sohang; i++) {
        for(int j = 0; j < *socot; j++) {
            fscanf(f, "%f", &matran[i][j]);
        }
    }
    fclose(f);
    printf("Da doc xong ma tran tu file van ban %s. \n", tenfile);
    return matran;
}

void xuatmatranrafilevanban(float **matran, int sohang, int socot, char *tenfile) {
    if(matran == NULL) return;
    FILE *f = fopen(tenfile, "w");
    if(f == NULL) {
        printf("Loi khong the khoi tao file de ghi. \n");
        return;
    }

    fprintf(f, "%d %d\n", sohang, socot);

    for(int i = 0; i < sohang; i ++) {
        for(int j = 0; j < socot; j++) {
            fprintf(f, "%f ", matran[i][j]);
        }
        fputc('\n', f);
    }

    fclose(f);
    printf("Da ghi xong ma tran vao file %s",tenfile);
}

void xuatmatranrafilenhiphan(float **matran, int sohang, int socot, char *tenfile) {
    if(matran == NULL) return;
    FILE *f = fopen(tenfile, "wb");
    if(f == NULL) {
        printf("Loi khong the khoi tao file de ghi. \n");
        return;
    }

    fwrite(&sohang, sizeof(int), 1, f);
    fwrite(&socot, sizeof(int), 1, f);

    for(int i = 0; i < sohang; i++) {
        for(int j = 0; j < socot; j++) {
            fwrite(&matran[i][j], sizeof(float), 1, f);
        }
    }
    fclose(f);
    printf("Da ghi xong ma tran ra file nhi phan %s. \n",tenfile);
}
float **nhapmatrantufilenhiphan(int *sohang, int *socot, char *tenfile) {
    FILE *f = fopen(tenfile, "rb");
    if(f == NULL){
        printf("Loi khong mo file de doc.\n");
        return NULL;
    }
    fread(sohang, sizeof(int), 1, f);
    fread(socot, sizeof(int), 1, f);

    float **matran = capphatmatran(*sohang, *socot);
    if(matran == NULL) {
        printf("Loi khong the cap phat bo nho");
        return NULL;
    }

    for(int i = 0; i < *sohang; i++) {
        for(int j = 0; j < *socot; j++) {
            fread(&matran[i][j], sizeof(float), 1, f);
        }
    }
    fclose(f);
    printf("Da doc xong ma tran tu file nhi phan %s.\n",tenfile);
    return matran;
}
void inmatran(float **matran, int sohang, int socot) {
    if(matran == NULL) {
        printf("Loi khong ton tai ma tran. \n");
        return;
    }

    for(int i = 0; i < sohang; i++) {
        for(int j = 0; j < socot; j++) {
            printf("%5.2f ", matran[i][j]);
        }
        printf("\n");
    }
}
