// doc ma tran tu tep va in ra man hinh
// tinh tb cac ptu co gia tri khong am
// tim max va in ra vi tri


#include<stdio.h>
#include<stdlib.h>


void docfile(FILE *f,int **a,int m,int n);
void in(int **a,int m,int n);
float tbka(int **a,int m,int n);
void timmax(int **a,int m,int n);


int main(){
	FILE*f=fopen("input.txt","r");
	if(f==NULL){
		printf("\nKhong the doc file !");
		return 1;
	}
	int m,n;
	fscanf(f,"%d %d",&m,&n);
	int **a=(int **)malloc(m*sizeof(int *));
	if(a==NULL){
		printf("\nKhong the cap phat dong!");
		return 1;
	}
	for(int i=0;i<m;i++){
		a[i]=(int*)malloc(n*sizeof(int));
		if(a[i]==NULL){
			printf("\nKhong the cap phat bo nho!");
			return 1;
		}
	}
	docfile(f,a,m,n);
	printf("Ma tran vua doc tu file la :\n");
	in(a,m,n);
	printf("\nTrung binh cac phan tu khong am cua ma tran la :%.2f",tbka(a,m,n));
	timmax(a,m,n);
	
	for(int i=0;i<m;i++){
		free(a[i]);
	}
	free(a);
	fclose(f);
}

void docfile(FILE *f,int **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
}
void in(int **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
float tbka(int **a,int m,int n){
	int dem=0,tong=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>=0){
				dem++;
				tong+=a[i][j];
			}
		}
	}
	return (float)tong/dem;
}
void timmax(int **a,int m,int n){
	int max=a[0][0];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max)		max=a[i][j];
		}
	}
	printf("\nGia tri lon nhat cua ma tran la :%d",max);
	printf("\nVi tri cua max la :");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==max){
				printf("a[%d][%d]   ",i,j);
			}
		}
	}
}
