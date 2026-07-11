#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void nhap(float *a,int n);
void in(float *a,int n);
void tinhtoan(float *a,int n);
int kiemtra(float *a,int n);

int main(){
	int n;
	printf("Vui long nhap so phan tu cua day :");	scanf("%d",&n);
	float *a=(float*)malloc(n*sizeof(float));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	nhap(a,n);
	printf("\nDay so vua nhap la :");
	in(a,n);
	tinhtoan(a,n);
	if(kiemtra(a,n)==1)	printf("\nDay co tinh chat tang dan");
	else				printf("\nDay khong co tinh chat tang dan");
	
	free(a);
}

void nhap(float *a,int n){
	for(int i=0;i<n;i++){
		printf("Vui long nhap phan tu thu %d :",i+1);	
		scanf("%f",&a[i]);
	}
}
void in(float *a,int n){
	for(int i=0;i<n;i++){
		printf("%-7.2f",a[i]);
	}
}
void tinhtoan(float *a,int n){
	float x,tong=0;
	int dem=0;
	printf("\nVui long nhap x :");	scanf("%f",&x);
	for(int i=0;i<n;i++){
		if(fabs(a[i])>x){
			tong+=a[i];
			dem++;
		}
	}
	if(dem==0)	printf("\nKhong co phan tu nao thoa man gia tri tuyet doi lon hon x");
	else{
		printf("\nSo phan tu co gia tri tuyet doi lon hon x la :%d",dem);
		printf("\nTrung binh cong cac so co gia tri tuyet doi lon hon x la :%.2f",(float)tong/dem);
	}	
}
int kiemtra(float *a,int n){
	if(n==0 || n==1)	return 1;
	else{
		for(int i=0;i<n-1;i++){
			if(a[i]>=a[i+1])	return 0;
		}
	}
	return 1;
}
