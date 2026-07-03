#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char tensp[30];
	char masp[20];
	float gia;
	int soluong;
	char ctysx[3];
	int namsx;
}hanghoa;

void nhap(hanghoa *a,int n);
void in(hanghoa *a,int n);
void timkiem(hanghoa *a,int n);
void sapxep(hanghoa *a,int n);
void xuatfile(hanghoa *a,int n);

int main(){
	int n;
	printf("Nhap so luong hang :");	scanf("%d",&n);
	hanghoa *a=(hanghoa*)malloc(n*sizeof(hanghoa));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	
	nhap(a,n);
	printf("\nDanh sach hang vua nhap :");
	in(a,n);
	timkiem(a,n);
	sapxep(a,n);
	xuatfile(a,n);
	
	free(a);
	return 0;
}
void nhap(hanghoa *a,int n){
	for(int i=0;i<n;i++){
		printf("Nhap thong tin hang thu %d :",i+1);
		printf("\nTen :");
		fflush(stdin);	gets(a[i].tensp);
		printf("Ma :");
		fflush(stdin);	gets(a[i].masp);
		printf("So Luong :");
		scanf("%d",&a[i].soluong);
		printf("Gia :");
		scanf("%f",&a[i].gia);
		printf("CtySx :");
		fflush(stdin);
		gets(a[i].ctysx);
		printf("NamSx :");
		scanf("%d",&a[i].namsx);
	}
}
void in(hanghoa *a,int n){
	printf("\n| %-5s | %-30s | %-10s | %-10s | %-10s | %-10s | %-10s |","STT","Ten","Ma","So Luong","Gia","CtySX","NamSX");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-30s | %-10s | %-10d | %-10.2f | %-10s | %-10d |",i+1,a[i].tensp,a[i].masp,a[i].soluong,a[i].gia,a[i].ctysx,a[i].namsx);
	}
}
void timkiem(hanghoa *a,int n){
	int kt=0;
	for(int i=0;i<n;i++){
		if(a[i].namsx==2024 && strcmp("A",a[i].ctysx)==0)	kt=1;
	}
	if(kt==0)	printf("\nKhong tim thay san pham do cty A san xuat nam 2024");
	else{
		printf("\nDanh sach hang cty A san xuat nam 2024 la :");
		printf("\n| %-30s | %-10s | %-10s | %-10s | %-10s | %-10s |","Ten","Ma","So Luong","Gia","CtySX","NamSX");
		for(int i=0;i<n;i++){
			if(a[i].namsx==2024 && strcmp("A",a[i].ctysx)==0){
				printf("\n| %-30s | %-10s | %-10d | %-10.2f | %-10s | %-10d |",a[i].tensp,a[i].masp,a[i].soluong,a[i].gia,a[i].ctysx,a[i].namsx);
			}
		}
	}
}
void sapxep(hanghoa *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].soluong<a[j].soluong){
				hanghoa temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void xuatfile(hanghoa *a,int n){
	FILE *f=fopen("sanpham.txt","w");
	if(f==NULL){
		printf("\nKhong the mo file sanpham.txt");
		exit(1);
	}
	fprintf(f,"\nDanh sach hang sau khi sap xep :");
	fprintf(f,"\n| %-5s | %-30s | %-10s | %-10s | %-10s | %-10s | %-10s |","STT","Ten","Ma","So Luong","Gia","CtySX","NamSX");
	for(int i=0;i<n;i++){
		fprintf(f,"\n| %-5d | %-30s | %-10s | %-10d | %-10.2f | %-10s | %-10d |",i+1,a[i].tensp,a[i].masp,a[i].soluong,a[i].gia,a[i].ctysx,a[i].namsx);
	}	
	printf("\nDa ghi thanh cong vao file sanpham.txt");
	
	fclose(f);
}
