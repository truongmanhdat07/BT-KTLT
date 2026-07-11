#include<stdio.h>
#include<stdlib.h>

void docfile(FILE *f,float **a,int m,int n);
void in(float **a,int m,int n);
void timmax(float **a,int m,int n);
float tongcotchan(float **a,int m,int n);

int main(){
	int m,n;
	
	FILE *f=fopen("matran.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file matran.txt");
		return 1;
	}
	fscanf(f,"%d %d",&m, &n);
	
	float **a=(float **)malloc(m*sizeof(float*));
	if(a==NULL){
		printf("\nKhong the cap phat dong!");
		return 1;
	}
	for(int i=0;i<m;i++){
		a[i]=(float*)malloc(n*sizeof(float));
		if(a[i]==NULL){
			printf("\nKhong the cap phat bo nho!");
			return 1;
		}
	}
	
	docfile(f,a,m,n);
	printf("\nMa tran vua nhap tu file la :\n");
	in(a,m,n);
	timmax(a,m,n);
	printf("\nTong cac phan tu thuoc cot chan la :%.2f",tongcotchan(a,m,n));
	
	for(int i=0;i<m;i++)	free(a[i]);
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,float **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%f",&a[i][j]);
		}
	}
	printf("\nDa doc thanh cong file matran.txt");
}
void in(float **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%7.2f",a[i][j]);
		}
		printf("\n");
	}
}
void timmax(float **a,int m,int n){
	float max=a[0][0];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max)	max=a[i][j];
		}
	}
	printf("\nGia tri lon nhat cua ma tran la :%.2f tai cac vi tri :",max);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==max){
				printf(" hang %d cot %d ,",i+1,j+1);
			}
		}
	}
}
float tongcotchan(float **a,int m,int n){
	float tong=0;
	for(int j=0;j<n;j+=2){
		for(int i=0;i<m;i++){
			tong+=a[i][j];
		}
	}
	return tong;
}
