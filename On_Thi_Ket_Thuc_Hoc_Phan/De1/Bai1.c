#include<stdio.h>
#include<stdlib.h>

void nhapmatran(float **,int m,int n);
void inmatran(float **,int m,int n);
float tongcotle(float **,int m,int n);
void timmax(float **a,int m,int n);

int main(){
	int m,n;
	printf("Vui long nhap so hang cua ma tran :");	scanf("%d",&m);
	printf("Vui long nhap so cot cua ma tran :");	scanf("%d",&n);
	float **a=(float**)malloc(m*sizeof(float*));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	for(int i=0;i<m;i++){
		a[i]=(float*)malloc(n*sizeof(float));
		if(a[i]==NULL){
			printf("\nKhong the cap phat bo nho!");
			return 1;
		}
	}
	
	printf("\nVui long nhap cac phan tu cua ma tran :\n");
	nhapmatran(a,m,n);
	
	printf("\nMa tran vua nhap la :\n");
	inmatran(a,m,n);
	
	printf("\nTong cac phan tu cua cot le la :%.2f",tongcotle(a,m,n));
	timmax(a,m,n);
	
	for(int i=0;i<m;i++){
		free(a[i]);
	}
	free(a);
}

void nhapmatran(float **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("Nhap phan tu a[%d][%d] :",i,j);
			scanf("%f",&a[i][j]);
		}
	}
}
void inmatran(float **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%7.2f",a[i][j]);
		}
		printf("\n");
	}
}
float tongcotle(float **a,int m,int n){
	float tong=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j+=2){
			tong+=a[i][j];
		}
	}
	return tong;
}
void timmax(float **a,int m,int n){
	float max=a[0][0];
	int vitrii=0,vitrij=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max){
			max=a[i][j];
			vitrii=i;
			vitrij=j;
			}
		}
	}
	printf("\nGia tri lon nhat cua ma tran la :%.2f tai vi tri a[%d][%d]",max,vitrii,vitrij);
}
