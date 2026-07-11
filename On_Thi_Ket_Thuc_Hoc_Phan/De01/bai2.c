#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int masach;
	char tensach[100];
	char tentacgia[100];
	float giasach;
}sach;

void nhap(sach *a,int n);
void xuat(sach *a,int n);
void timkiem(sach *a,int n);
void sapxep(sach *a,int n);

int main(){
	int n;
	printf("Vui long nhap so quyen sach :");	scanf("%d",&n);
	sach *a=(sach*)malloc(n*sizeof(sach));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	nhap(a,n);
	printf("\nDanh sach cuon sach vua nhap la :");
	xuat(a,n);
	timkiem(a,n);
	sapxep(a,n);
	printf("\nDanh sach cuon sach sau khi sap xep la :");
	xuat(a,n);
	free(a);
}

void nhap(sach *a,int n){
	for(int i=0;i<n;i++){
		printf("\nVui long nhap thong tin sach thu %d :",i+1);
		
		printf("\nMa sach :");
		scanf("%d",&a[i].masach);
		printf("Ten sach :");
		fflush(stdin);
		gets(a[i].tensach);
		printf("Ten tac gia :");
		fflush(stdin);
		gets(a[i].tentacgia);
		printf("Gia sach :");
		scanf("%f",&a[i].giasach);
	}
}
void xuat(sach *a,int n){
	printf("\n==========================================================================================================");
	printf("\n| %-5s | %-10s | %-30s | %-30s | %-15s |","STT","Ma Sach","Ten Sach","Ten Tac Gia","Gia Sach");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-10d | %-30s | %-30s | %-15.2f |",i+1,a[i].masach,a[i].tensach,a[i].tentacgia,a[i].giasach);
	}
	printf("\n==========================================================================================================\n");
}
void timkiem(sach *a,int n){
	char ten[100];
	int count=0;
	printf("\nVui long nhap ten tac gia can tim :");
	fflush(stdin);
	gets(ten);
	for(int i=0;i<n;i++){
		if(strcmp(ten,a[i].tentacgia)==0){
			count++;
		}
	}
	if(count==0)	printf("\nKhong tim thay tac pham cua tac gia %s",ten);
	else{
		printf("\nCac cuon sach cua tac gia %s la :",ten);
		printf("\n==========================================================================");
		printf("\n| %-5s | %-10s | %-30s | %-15s |","STT","Ma Sach","Ten Sach","Gia Sach");
		for(int i=0;i<n;i++){
			if(strcmp(ten,a[i].tentacgia)==0){
				printf("\n| %-5d | %-10d | %-30s | %-15.2f |",i+1,a[i].masach,a[i].tensach,a[i].giasach);
			}
		}
		printf("\n==========================================================================");
	}
}
void sapxep(sach *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].giasach<a[j].giasach){
				sach temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
