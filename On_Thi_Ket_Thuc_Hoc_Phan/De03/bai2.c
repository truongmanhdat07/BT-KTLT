#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int matuong;
	char tentuong[100];
	char hetoc[100];
	int stcb;
}tuong;

void nhap(tuong *a,int n);
void in(tuong *a,int n);
void timhetoc(tuong *a,int n);
void timmax(tuong *a,int n);

int main(){
	int  n;
	printf("Vui long nhap so tuong :");	scanf("%d",&n);
	tuong *a=(tuong*)malloc(n*sizeof(tuong));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	nhap(a,n);
	in(a,n);
	timhetoc(a,n);
	timmax(a,n);
	
	free(a);
	return 0;
}

void nhap(tuong *a,int n){
	for(int i=0;i<n;i++){
		printf("\nVui long nhap thong tin tuong thu %d :",i+1);
		printf("\nMa Tuong :");
		scanf("%d",&a[i].matuong);
		printf("Ten Tuong :");
		fflush(stdin);
		gets(a[i].tentuong);
		printf("He Toc :");
		fflush(stdin);
		gets(a[i].hetoc);
		printf("Sat Thuong Co Ban :");
		scanf("%d",&a[i].stcb);
	}
}
void in(tuong *a,int n){
	printf("\nDANH SACH TUONG");
	printf("\n| %-5s | %-10s | %-30s | %-15s | %-20s |","STT","Ma Tuong","Ten Tuong","Toc He","Sat Thuong Co Ban");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-10d | %-30s | %-15s | %-20d |",i+1,a[i].matuong,a[i].tentuong,a[i].hetoc,a[i].stcb);
	}
}
void timhetoc(tuong *a,int n){
	char hetoccantim[100];
	printf("\n\nVui long nhap He Toc can tim :");
	fflush(stdin);
	gets(hetoccantim);
	int count =0;
	for(int i=0;i<n;i++){
		if(strcmp(hetoccantim,a[i].hetoc)==0){
			if(count==0){
				printf("\nDANH SACH TUONG");
				printf("| %-5s | %-10s | %-30s | %-20s |","STT","Ma Tuong","Ten Tuong","Sat Thuong Co Ban");
			}	
			printf("\n| %-5d | %-10d | %-30s | %-20d |",i+1,a[i].matuong,a[i].tentuong,a[i].stcb);
			count++;
		}
	}
	if(count==0)	printf("\nKhong co tuong nao thuoc toc he :%s",hetoccantim);
	else			printf("\nCo %d tuong thuoc toc he :%s",count,hetoccantim);
}
void timmax(tuong *a,int n){
	int max=a[0].stcb;
	for(int i=0;i<n;i++){
		if(a[i].stcb>max)	max=a[i].stcb;
	}
	for(int i=0;i<n;i++){
		if(a[i].stcb==max){
			printf("\nVi tuong dau tien co sat thuong co ban lon nhat la :");
			printf("\n| %-5s | %-10s | %-30s | %-15s | %-20s |","STT","Ma Tuong","Ten Tuong","Toc He","Sat Thuong Co Ban");
			printf("\n| %-5d | %-10d | %-30s | %-15s | %-20d |",i+1,a[i].matuong,a[i].tentuong,a[i].hetoc,a[i].stcb);
			break;
		}
	}
}
