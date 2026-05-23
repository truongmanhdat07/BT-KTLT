#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char tensach[100];
	char tentacgia[100];
	int namxuatban;
} sach;

void nhap(int *n,sach **a);
void in(int n,sach *a);
int demsach(int n,sach *a);
void thongke(int n,sach *a);
int menu();

int main(){
	int n = 0;
	sach *a = NULL;
	int luachon;
	do {
        luachon = menu();
        switch(luachon){
            case 1:
			 		nhap(&n,&a); 								
			 		break;
            case 2:
            	    if(a == NULL) printf("\nChua nhap sach! Vui long chon 1 truoc!");
					else	in(n,a); 										
					break;
            case 3:
            	    if(a == NULL) printf("\nChua nhap sach! Vui long chon 1 truoc!");
					else	demsach(n,a); 								
			 		break;
            case 4:
            		if(a == NULL) printf("\nChua nhap sach! Vui long chon 1 truoc!");
					else	thongke(n,a); 								
					break;
            case 5: printf("\nCam on quy khach da su dung!"); 		break;
            default:printf("\nVui long chon lai muc 1-5!");
        }
    } while(luachon != 5);
	
	free(a);
	return 0;
}

void nhap(int *n,sach **a){
	if( *a != NULL )	free(*a);
	
	printf("Vui long nhap so luong sach :");
	scanf("%d",n);
	*a=(sach*)malloc((*n) * sizeof(sach));
	if(*a==NULL){
		printf("Khong the cap phat bo nho!");
		exit(1);
	}
	
	for(int i = 0;i < *n; i++){
		printf("Vui long nhap thong tin sach thu %d : \n",i+1);
		
		printf("Ten sach :");
		fflush(stdin);
		gets((*a)[i].tensach);
		printf("Ten tac gia :");
		fflush(stdin);
		gets((*a)[i].tentacgia);
		printf("Nam xuat ban :");
		scanf("%d",&(*a)[i].namxuatban);
	}
}

void in(int n,sach *a){
	printf("\n================== DANH SACH CUON SACH =====================================\n");
    printf("%-5s | %-30s | %-25s | %-10s\n", "STT", "Ten Sach", "Tac Gia", "Nam XB");
    printf("----------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d | %-30s | %-25s | %-10d\n",i+1, a[i].tensach, a[i].tentacgia, a[i].namxuatban);
    }
    printf("============================================================================\n");
}

int demsach(int n,sach *a){
	char ten[100];
	int dem=0;
	printf("\nVui long nhap ten tac gia can kiem tra :");
	fflush(stdin);
	gets(ten);
	
	for(int i = 0;i < n; i++){
		if( strcmp( ten, a[i].tentacgia ) == 0 ){
			if(dem==0){
				printf("\n---Cac cuon sach cua tac gia %s la :---\n",ten);
				printf("%-5s | %-30s | %-25s | %-10s\n", "STT", "Ten Sach", "Tac Gia", "Nam XB");
			}
			printf("%-5d | %-30s | %-25s | %-10d\n",i+1, a[i].tensach, a[i].tentacgia, a[i].namxuatban);
			dem++;
		}
	}
	if(dem==0)	printf("\nKhong tim thay sach cua tac gia %s !",ten);
	return dem;
}

void thongke(int n,sach *a){
	printf("\n\n===== THONG KE THEO NAM XUAT BAN =========");
	printf("\n| %-20s | %-15s |","Nam Xuat Ban","So Sach");
	
	for(int i = 0;i < n; i++){
		int daxuly=0;
		for(int j = 0;j < i; j++){
			if( a[j].namxuatban == a[i].namxuatban ){
				daxuly = 1;
				break;
			}
		}
		
		if(daxuly != 0)		continue;
		int dem = 0;
		
        for (int k = i; k < n; k++) {
            if ( a[k].namxuatban == a[i].namxuatban )		dem++;
        }

        printf("\n| %-20d | %-15d |", a[i].namxuatban, dem);
    }

    printf("\n==========================================\n");
}

int menu() {
    int luachon;
    printf("\n\n===== QUAN LY THU VIEN SACH =====");
    printf("\n1.Nhap n cuon sach");
    printf("\n2.In n cuon sach");
    printf("\n3.Dem so sach cua tac gia");
    printf("\n4.Thong ke so sach theo nam");
    printf("\n5.Thoat\n");
    printf("\n=========================");
    printf("\nChon chuc nang :");
    scanf("%d", &luachon);
    return luachon;
}
