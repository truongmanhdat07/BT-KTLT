#include<stdio.h>
#include<stdlib.h>

void nhap(float **a,int n);
void in(float**a,int n);
float tongdcp(float **a,int n);
int kiemtramtdx(float **a,int n);

int main(){
	int n;
	printf("Vui long nhap ma tran vuong n :");	scanf("%d",&n);
	float **a=(float **)malloc(n*sizeof(float *));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	for(int i=0;i<n;i++){
		a[i]=(float*)malloc(n*sizeof(float));
		if(a[i]==NULL){
			printf("\nKhong the cap phat bo nho!");
			return 1;
		}
	}
	
	nhap(a,n);
	printf("\nMa tran vua nhap la :\n");
	in(a,n);
	printf("\nTong cac phan tu nam tren duong cheo phu la :%.2f",tongdcp(a,n));
	int kt=kiemtramtdx(a,n);
	if(kt==0)	printf("\nDay khong phai ma tran doi xung!");
	else		printf("\nDay la ma tran doi xung!");
	
	for(int i=0;i<n;i++){
		free(a[i]);
	}
	free(a);
	return 0;
}

void nhap(float **a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("Vui long nhap phan tu hang %d cot %d :",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
}
void in(float **a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%7.2f",a[i][j]);
		}
		printf("\n");
	}
}
float tongdcp(float **a,int n){
	float tong=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+j==n-1)	tong+=a[i][j];
		}
	}
	return tong;
}
int kiemtramtdx(float **a,int n){
	int kt=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=a[j][i]){
				kt=0;
				break;
			}
		}
	}
	return kt;
}
