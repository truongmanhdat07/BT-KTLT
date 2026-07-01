#include<stdio.h>
#include<stdlib.h>

void nhap(int **a,int n,int m);
int tongchan(int **a,int n,int m);
void maxle(int **a,int n,int m);
void tong(int **a,int n,int m);

int main(){
	int n,m;
	printf("Nhap so hang cua ma tran :");	scanf("%d",&n);
	printf("Nhap so cot cua ma tran :");	scanf("%d",&m);
	int **a=(int**)malloc(n*sizeof(int*));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	for(int i=0;i<n;i++){
		a[i]=(int*)malloc(m*sizeof(int));
		if(a[i]==NULL){
			printf("\nKhong the cap phat bo nho");
			return 1;
		}
	}
	
	nhap(a,n,m);
	printf("\nTong cac phan tu chan cua ma tran la :%d",tongchan(a,n,m));
	maxle(a,n,m);
	tong(a,n,m);
	
	for(int i=0;i<n;i++)	free(a[i]);
	free(a);
	return 0;
}
void nhap(int **a,int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("Nhap phan tu hang %d cot %d :",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
}
int tongchan(int **a,int n,int m){
	int tong=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]%2==0)	tong+=a[i][j];
		}
	}
	return tong;
}
void maxle(int **a,int n,int m){
	int max;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]%2!=0){
				max=a[i][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]%2!=0 && a[i][j]>max){
				max=a[i][j];
			}
		}
	}
	printf("\nMax le la %d tai vi tri",max);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==max)	printf(" hang %d cot %d ,",i+1,j+1);
		}
	}
}
void tong(int **a,int n,int m){
	int dem=0;
	int tong=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]%3==0){
				dem++;
				tong+=a[i][j];
			}
		}
	}
	if(dem==0)	printf("\nKhong co so nao chia het cho 3");
	else		printf("\nTong cac so chia het cho 3 la :%d",tong);
}
