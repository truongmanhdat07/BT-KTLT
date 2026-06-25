#include<stdio.h>
#include<stdlib.h>

void docfile(FILE *f,float *a,int n);
void in(float *a,int n);
void tbc(float *a,int n);
void daydandau(float *a,int n);

int main(){
	int n;
	FILE *f=fopen("dayso.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file dayso.txt");
		return 1;
	}
	
	fscanf(f,"%d",&n);
	float *a=(float *)malloc(n*sizeof(float));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	docfile(f,a,n);
	printf("\nDay so vua doc tu file dayso.txt la :");
	in(a,n);
	tbc(a,n);
	daydandau(a,n);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,float *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f,"%f",&a[i]);
	}
}
void in(float *a,int n){
	for(int i=0;i<n;i++){
		printf("%-7.2f",a[i]);
	}
}
void tbc(float *a,int n){
	float tong=0;
	int dem=0;
	for(int i=0;i<n;i++){
		if(a[i]>0){
			dem++;
			tong+=a[i];
		}
	}
	if(dem==0)	printf("\nKhong co so duong nao trong day !");
	else		printf("\nTrung binh cong cac so duong cua day la :%.2f",tong/dem);
}
void daydandau(float *a,int n){
	for(int i=0;i<n-1;i++){
		if(a[i]*a[i+1]>0){
			printf("\nDay khong phai la day dan dau");
			return ;
		}
	}
	printf("\nDay la day dan dau");
}
