#include "F8.h"

int** doc_ma_tran(const char* tenTep, int *soHang, int *soCot){
    FILE* tep= fopen(tenTep, "r");
    if(tep == NULL){
        printf("Loi: Khong the mo tep %s!\n", tenTep);
        return NULL;
    }
    fscanf(tep, "%d %d", soHang, soCot);

    int** maTran = (int**)malloc((*soHang) * sizeof(int*));
    for(int i=0; i < *soHang; i++){
        maTran[i] = (int*)malloc((*soCot) * sizeof(int));
        for (int j=0; j < *soCot; j++){
            fscanf(tep, "%d", &maTran[i][j]);
        }
    }
    fclose(tep);
    return maTran;
}
void in_ma_tran (int **maTran, int soHang, int soCot){
    printf("Danh sach phan tu cua ma tran:\n");
    for(int i=0; i < soHang; i++){
        for(int j=0; j < soCot; j++){
            printf("%d\t", maTran[i][j]);
        }
        printf("\n");
    }
}
void tich_phan_tu_le (int **maTran, int soHang, int soCot){
    long long tich=1;
    bool coSoLe = false;
    for(int i=0; i<soHang; i++){
        for(int j=0; j<soCot; j++){
            if(maTran[i][j] % 2 != 0){
                tich *= maTran[i][j];
                coSoLe = true;
            }
        }
    }
    if(coSoLe){
        printf("\nTich cac phan tu le trong ma tran: %lld", tich);
    }else{
        printf("\nMa tran khong co phan tu le!");
    }
}
void tim_chan_lon_nhat (int **maTran, int soHang, int soCot){
    int maxChan = 0;
    int viTriHang = -1;
    int viTriCot = -1;
    bool coSoChan = false;
    for(int i=0; i<soHang; i++){
        for(int j=0; j<soCot; j++){
            if(maTran[i][j] % 2 == 0){
                if(!coSoChan || maTran[i][j] > maxChan){
                    maxChan = maTran[i][j];
                    viTriHang = i;
                    viTriCot = j;
                    coSoChan = true;
                }
            }
        }
    }
    if(coSoChan){
        printf("\nPhan tu chan lon nhat la: %d", maxChan);
        printf("\nChi so hang va cot cua phan tu chan lon nhat la: (%d, %d)\n", viTriHang, viTriCot);
    }else{
        printf("\nMa tran khong co phan tu chan nao!\n");
    }
}

void tong_chia_het_7_moi_hang (int **maTran, int soHang, int soCot){
    printf("Tong cac phan tu chia het cho 7 tren moi hang la:\n");
    for(int i=0; i<soHang; i++){
        int tong = 0;
        for(int j=0; j<soCot; j++){
            if(maTran[i][j] % 7 == 0){
                tong+=maTran[i][j];
            }
        }
        printf("Hang %d: %d\n", i, tong);
    }
}
void giai_phong_ma_tran (int **maTran, int soHang){
    for(int i=0; i<soHang; i++){
        free(maTran[i]);
    }
    free(maTran);
}