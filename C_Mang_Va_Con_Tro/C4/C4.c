#include<stdio.h>
#include<stdlib.h>

void nhap(float **a,int m,int n);
void in(float **a,int m,int n);
float timmax(float **a,int m,int n);
float tongduongcheochinh(float **a,int m,int n);
void timmaxhang(float **a,int m,int n);
void tongkhongam(float **a,int m,int n);
void intamgiactren(float **a,int m,int n);
void intamgiacduoi(float **a,int m,int n);

int main(){
	int m,n;
	printf("Vui long nhap so hang cua ma tran :");	scanf("%d",&m);
	printf("Vui long nhap so cot cua ma tran :");	scanf("%d",&n);
	float **a=(float**)malloc(m*sizeof(float*));
	if(a==NULL){
		printf("Khong the cap phat bo nho!");
		return 1;
	}
	for(int i=0;i<m;i++){
		a[i]=(float*)malloc(n*sizeof(float));
		if(a[i]==NULL){
			printf("\nKhong the cap phat bo nho!");
			return 1;
		}
	}
	nhap(a,m,n);
	printf("\nMa tran vua nhap la :\n");
	in(a,m,n);
	printf("\nGia tri lon nhat cua ma tran la :%.2f",timmax(a,m,n));
	printf("\nTong duong cheo chinh cua ma tran la :%.2f",tongduongcheochinh(a,m,n));
	timmaxhang(a,m,n);
	tongkhongam(a,m,n);
	intamgiactren(a,m,n);
	intamgiacduoi(a,m,n);
	
	for(int i=0;i<m;i++)	free(a[i]);
	free(a);
}
void nhap(float **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("Vui long nhap a[%d][%d] :",i,j);
			scanf("%f",&a[i][j]);
		}
	}
}
void in(float **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%7.2f",a[i][j]);
		}
		printf("\n");
	}
}
float timmax(float **a,int m,int n){
	float max=a[0][0];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max)	max=a[i][j];
		}
	}
	return max;
}
float tongduongcheochinh(float **a,int m,int n){
	float tongdcc=0;
	int min=(m<n) ? m : n;
	for(int i=0;i<min;i++){
		tongdcc+=a[i][i];
	}
	return tongdcc;
}
void timmaxhang(float **a,int m,int n){
	for(int i=0;i<m;i++){
		float maxhang=a[i][0];
		for(int j=0;j<n;j++){
			if(a[i][j]>maxhang)	maxhang=a[i][j];
		}
		printf("\nGia tri lon nhat hang %d la :%.2f",i+1,maxhang);
	}
}
void tongkhongam(float **a,int m,int n){
	for(int j=0;j<n;j++){
		float tongduong=0;
		for(int i=0;i<m;i++){
			if(a[i][j]>=0)	tongduong+=a[i][j];
		}
		printf("\nTong cac phan tu khong am cua cot %d la :%.2f",j+1,tongduong);
	}
}
void intamgiactren(float **a,int m,int n){
	printf("\nPhan tam giac tren :\n");
	for (int i = 0; i < m; i++) {
	    for (int j = 0; j < n; j++) {
	        if (i <= j) 	printf("%7.2f", a[i][j]); 
	        else 			printf("       "); 
	    }
	    printf("\n");
	}
}
void intamgiacduoi(float **a,int m,int n){
	printf("\nPhan tam giac duoi :\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i>=j)			printf("%7.2f",a[i][j]);
			else			printf("       ");
		}
		printf("\n");
	}
}
