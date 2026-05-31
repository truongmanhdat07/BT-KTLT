#include "f4.h"

thiSinh *taoThiSinh(char *hoTen, float toan, float ly, float hoa){
    thiSinh *p = (thiSinh*)malloc(sizeof(thiSinh));
    if(p==NULL) return NULL;
    strcpy(p -> hoTen, hoTen);
    p -> toan = toan;
    p -> ly = ly;
    p -> hoa = hoa;
    p -> Next = NULL;
    return p;
}

void boSungDau(thiSinh **dau, thiSinh *nodeMoi){
    if(nodeMoi == NULL){
        return;
    }
    nodeMoi -> Next = *dau;
    *dau = nodeMoi;
}

void boSungCuoi(thiSinh **dau, thiSinh *nodeMoi){
    if(nodeMoi == NULL){
        return;
    }
    if(*dau == NULL){
        *dau = nodeMoi;
        return;
    }
    thiSinh *p = *dau;
    while(p -> Next != NULL){
        p = p -> Next;
    }
    p -> Next = nodeMoi;
}

void nhapDanhSach(thiSinh **dau, int n){
    char hoTen[50];
    float toan, ly, hoa;
    for(int i=0; i<n; i++){
        printf("Nhap thong tin thi sinh %d:\n", i+1);
        getchar();
        printf("Ho ten: ");
        fgets(hoTen, sizeof(hoTen), stdin);
        hoTen[strlen(hoTen) - 1] = '\0';
        printf("Diem Toan - Ly - Hoa: ");
        scanf("%f %f %f", &toan, &ly, &hoa);

        boSungCuoi(dau, taoThiSinh(hoTen, toan, ly, hoa));
    }
}

void inDanhSach(thiSinh *dau){
    printf("%-20s | %-5s | %-5s | %-5s\n", "Ho Ten", "Toan", "Ly", "Hoa");
    for(thiSinh *p = dau; p!=NULL; p = p->Next){
        printf("%-20s | %-5.2f | %-5.2f | %-5.2f\n", p->hoTen, p->toan, p->ly, p->hoa);
    }
}

void xuatFileVanBan(thiSinh *dau, const char *tenFile){
    FILE *f = fopen(tenFile, "w");
    if(!f) return;
    for(thiSinh *p = dau; p!=NULL; p = p->Next){
        fprintf(f, "%s\n%.2f %.2f %.2f\n", p->hoTen, p->toan, p->ly, p->hoa);
    }
    fclose(f);
}

void nhapFileVanBan(thiSinh **dau, const char *tenFile){
    FILE *f = fopen(tenFile, "r");
    if(!f) return;
    char hoTen[50];
    float toan, ly, hoa;

    while(fgets(hoTen, sizeof(hoTen), f) != NULL){
        hoTen[strlen(hoTen)-1] = '\0';
        fscanf(f, "%f %f %f", &toan, &ly, &hoa);
        fgetc(f);
        
        boSungCuoi(dau, taoThiSinh(hoTen, toan, ly, hoa));
    }
    fclose(f);
}

void xuatFileNhiPhan(thiSinh *dau, const char *tenFile){
    FILE *f = fopen(tenFile, "wb");
    if(!f) return;
    for(thiSinh *p = dau; p!=NULL; p = p->Next){
        fwrite(p, sizeof(thiSinh), 1, f);
    }
    fclose(f);
}

void nhapFileNhiPhan(thiSinh **dau, const char *tenFile){
    FILE *f = fopen(tenFile, "rb");
    if(!f) return;
    thiSinh tamThoi;
    while(fread(&tamThoi, sizeof(thiSinh), 1, f) == 1){
        boSungCuoi(dau, taoThiSinh(tamThoi.hoTen, tamThoi.toan, tamThoi.ly, tamThoi.hoa));
    }
    fclose(f);
}

void diemToanMax(thiSinh *dau){
    if(dau == NULL) return;
    float maxToan = dau -> toan;
    for(thiSinh *p = dau; p!=NULL; p = p->Next){
        if(p->toan > maxToan) maxToan = p->toan;
    }

    printf("Cac thi sinh co diem Toan cao nhat (%.2f) la: \n", maxToan);
    for(thiSinh *p = dau; p!=NULL; p = p->Next){
        if(p->toan == maxToan){
            printf("%s\n", p->hoTen);
        }
    }
}

void diemLyMin(thiSinh **dau){
    if(*dau == NULL) return;

    float minLy = (*dau)->ly;
    for(thiSinh *p = *dau; p!=NULL; p=p->Next){
        if(p->ly < minLy) minLy = p->ly;
    }

    thiSinh *hienTai = *dau;
    thiSinh *truocDo = NULL;
    while(hienTai != NULL){
        if(hienTai->ly == minLy){
            thiSinh *tamThoi = hienTai;
            if(truocDo == NULL){
                *dau = hienTai->Next;
                hienTai = *dau;
            }else{
                truocDo->Next = hienTai->Next;
                hienTai = hienTai->Next;
            }
            free(tamThoi);
        }else{
            truocDo = hienTai;
            hienTai = hienTai->Next;
        }
    }
}

void giaiPhongDanhSach(thiSinh **dau){
    while(*dau != NULL){
        thiSinh *tamThoi = *dau;
        *dau = (*dau)->Next;
        free(tamThoi);
    }
}

void Menu(){
    printf("-MENU QUAN LY THI SINH-\n");
    printf("1. Nhap danh sach tu ban phim\n");
    printf("2. In danh sach ra man hinh\n");
    printf("3. Ghi danh sach ra file van ban (output.txt)\n");
    printf("4. Doc danh sach tu file van ban (input.txt)\n");
    printf("5. Ghi danh sach ra file nhi phan (output.bin)\n");
    printf("6. Doc danh sach tu file nhi phan (input.bin)\n");
    printf("7. Tim cac thi sinh co diem Toan cao nhat\n");
    printf("8. Xoa cac thi sinh co diem Ly thap nhat\n");
    printf("0. Thoat chuong trinh\n");
    printf("---------------------------------------------\n");
    printf("Moi ban nhap lua chon (0-8): ");
}