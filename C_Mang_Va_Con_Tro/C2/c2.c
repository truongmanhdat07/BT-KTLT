#include<stdio.h>
#include<stdlib.h>

void nhap(float **a,int n);
float tdcp(float **a,int n);
float timmax(float **a,int n);
void tichcot(float **a,int n);
int kttgt(float **a,int n);
int kttgd(float **a,int n);

int main(){
	int n;
	printf("\nVui long nhap ma tran cap n :");	scanf("%d",&n);
	float **a=(float **)malloc(n*sizeof(float*));
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
	printf("\nTong cac phan tu nam tren duong cheo phu la :%.2f",tdcp(a,n));
	printf("\nGia tri lon nhat cua ma tran la :%.2f",timmax(a,n));
	tichcot(a,n);
	int tgt=kttgt(a,n);
	int tgd=kttgd(a,n);
	if(tgt==1 && tgd==1)	printf("\nDay la ma tran duong cheo");
	else if(tgt==1)			printf("\nDay la ma tran tam giac tren");
	else if(tgd==1)			printf("\nDay la ma tran tam giac duoi");
	else					printf("\nDay khong phai ma tran tam giac");
	
	for(int i=0;i<n;i++)	free(a[i]);
	free(a);
	return 0;
}
void nhap(float**a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("Vui long nhap phan tu hang %d cot %d :",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	}
}
float tdcp(float **a,int n){
	float tong=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tong+=a[i][n-1-i];
		}
	}
	return tong;
}
float timmax(float **a,int n){
	float max=a[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max)	max=a[i][j];
		}
	}
	return max;
}
void tichcot(float **a,int n){
	float mintich=1;
	int cot=0;
	for(int i=0;i<n;i++){
		mintich*=a[i][0];
	}
	
	for(int j=0;j<n;j++){
		float tich=1;
		for(int i=0;i<n;i++){
			tich*=a[i][j];
		}
		if(tich<mintich){
			mintich=tich;
			cot=j;
		}
		printf("\nTich cac phan tu cot %d la :%.2f",j+1,tich);
	}
	printf("\nTich cot nho nhat la :%.2f tai cot %d",mintich,cot+1);
}
int kttgt(float **a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j<i){
				if(a[i][j]!=0)	return 0;
			}
		}
	}
	return 1;
}
int kttgd(float **a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j>i){
				if(a[i][j]!=0)	return 0;
			}
		}
	}
	return 1;
}
