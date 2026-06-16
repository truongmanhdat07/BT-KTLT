#include <stdio.h>
#include <stdlib.h>


int nhap(float **);
void xuat(int, float *);
int soduonglonnhat(int , float *, float *);
int sofibo(int , float *);
int menu();

int main() {
    float *arr = NULL; 
    int n = 0;         
    float solonnhat;       
    int luaChon;       

    do {
        luaChon = menu(); 

        switch (luaChon) {
            case 1:
                if (arr != NULL) {
                    free(arr);
                    arr = NULL;
                }
                n = nhap(&arr);
                break;

            case 2:
                if (arr == NULL || n <= 0) {
                    printf("Loi: Chua co day so!\n");
                } else {
                    xuat(n, arr);
                }
                break;

            case 3:
                if (arr == NULL || n <= 0) {
                    printf("Loi: Chua co day so!\n");
                } else {
                    if (soduonglonnhat(n, arr, &solonnhat) == 1) {
                        printf("-> Max duong la: %.2f\n", solonnhat);
                    } else {
                        printf("-> Mang khong co so duong!\n");
                    }
                }
                break;

            case 4:
                if (arr == NULL || n <= 0) {
                    printf("Loi: Chua co day so!\n");
                } else {
                    if (sofibo(n, arr) == 1) {
                        printf("-> Day so co tinh chat Fibonacci.\n");
                    } else {
                        printf("-> Day so khong co tinh chat Fibonacci.\n");
                    }
                }
                break;

            case 5:
                printf("Dang thoat...\n");
                if (arr != NULL) {
                    free(arr);
                }
                break;

            default:
                printf("Lua chon khong hop le!\n");
                break;
        }

    } while (luaChon != 5);

    return 0;
}

int nhap(float **a) {
    int n;
    do {
        printf("Nhap so phan tu cua day: ");
        scanf("%d", &n);

        if(n <= 0) {
            printf("So phan tu cua day phai lon hon 0! Vui long nhap lai!\n");
        }
    } while(n <= 0);

    *a = (float *)malloc(n * sizeof(float));

    if(*a == NULL) {
        printf("Loi khong the cap phat bo nho!\n");
        return 0;
    }

    for(int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%f", &(*a)[i]);
    }
    return n;
}

void xuat(int n, float *a) {
    printf("Day sau khi nhap la: ");
    for(int i = 0; i < n; i++) {
        printf("%5.2f ", a[i]);
    }
    printf("\n");
}

int soduonglonnhat(int n, float *a, float *sln) {
    int cosoduong = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            if(a[i] > *sln || cosoduong == 0) {
                *sln = a[i];
                cosoduong = 1;
            }
        }
    }
    return cosoduong;
}

int sofibo(int n, float *a) {
    if(n < 3) {
        return 0;
    }
    for(int i = 2; i < n; i++) {
        if(a[i] != a[i - 1] + a[i - 2]){
            return 0;
        }
    }
    return 1;
}

int menu() {
    int chon;
    printf("\n================ MENU ================\n");
    printf("1. Nhap day so\n");
    printf("2. Xuat day so\n");
    printf("3. Tim so duong lon nhat\n");
    printf("4. Kiem tra tinh chat Fibonacci\n");
    printf("5. Thoat chuong trinh\n");
    printf("======================================\n");
    do{
        printf("Nhap lua chon cua ban (1-5): ");
        scanf("%d", &chon);
        if(chon < 1 || chon > 5) {
            printf("Gia tri khong hop le !Vui long nhap lai!\n");
        }
    }while(chon < 1 || chon > 5);
    
    return chon; 
}

