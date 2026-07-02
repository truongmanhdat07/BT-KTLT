#include<stdio.h>
#include<stdlib.h>

void nhap(float *a,int m);
void in(float *a,int m);
void timkiem(float *a,int m);
void timmax(float *a,int m);

int main(){
	int m;
	printf("Nhap so phan tu :");	scanf("%d",&m);
	float *a=(float*)malloc(m*sizeof(float));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	
	nhap(a,m);
	printf("\nMang vua nhap :");
	in(a,m);
	timkiem(a,m);
	timmax(a,m);
	
	free(a);
	return 0;
}
void nhap(float *a,int m){
	for(int i=0;i<m;i++){
		printf("Nhap phan tu thu %d :",i+1);
		scanf("%f",&a[i]);
	}
}
void in(float *a,int m){
	for(int i=0;i<m;i++){
		printf("%5.2f",a[i]);
	}
}
void timkiem(float *a,int m){
	int dem=0;
	for(int i=0;i<m;i++){
		if(a[i]>=2.5 && a[i]<=15.5)	dem++;
	}
	if(dem==0)	printf("\nKhong co phan tu nao thuoc [2.5,15.5]");
	else{
		printf("\nVi tri cac phan tu thuoc [2.5,15.5] la :");
		for(int i=0;i<m;i++){
			if(a[i]>=2.5 && a[i]<=15.5){
				printf("%d  ",i+1);
			}
		}
	}
}
void timmax(float *a,int m){
	float max=a[0];
	for(int i=0;i<m;i++){
		if(a[i]>max)	max=a[i];
	}
	printf("\nGia tri lon nhat cua mang :%.2f",max);
	printf("\nTai vi tri :");
	for(int i=0;i<m;i++){
		if(a[i]==max)	printf("%-3d",i+1);
	}
}
