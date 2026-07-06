#include<stdio.h>
#include<stdlib.h>

void docfile(FILE *f,int **a,int n);
void xuatfile(int **a,int n);
int timmax(int **a,int n);
void tgd(int **a,int n);
int timmin(int **a,int n);

int main(){
	int n;
	char tenfile[100];
	printf("\nNhap ten file can doc :");
	fflush(stdin);	gets(tenfile);
	
	FILE *f=fopen(tenfile,"r");
	if(f==NULL){
		printf("\nKhong the mo file %s",tenfile);
		return 1;
	}
	
	fscanf(f,"%d",&n);
	int **a=(int**)malloc(n*sizeof(int*));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	for(int i=0;i<n;i++){
		a[i]=(int*)malloc(n*sizeof(int));
		if(a[i]==NULL){
			printf("\nKhong the cap phat bo nho");
			return 1;
		}
	}
	
	docfile(f,a,n);
	xuatfile(a,n);
	printf("\nGia tri lon nhat cua ma tran la :%d",timmax(a,n));
	tgd(a,n);
	printf("\nGia tri nho nhat cua cac phan tu nam tren duong cheo phu la :%d",timmin(a,n));
	
	for(int i=0;i<n;i++)	free(a[i]);
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,int **a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
}
void xuatfile(int **a,int n){
	FILE *F=fopen("output.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file output.txt");
		exit(1);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			fprintf(F,"%5d",a[i][j]);
		}
		fprintf(F,"\n");
	}
	printf("\nDa ghi thanh cong ma tran vao file output.txt");
	
	fclose(F);
}
int timmax(int **a,int n){
	int max=a[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max)	max=a[i][j];
		}
	}
	return max;
}
void tgd(int **a,int n){
	int kt=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j>i && a[i][j]!=0)	kt=0;
		}
	}
	if(kt==0)	printf("\nDay khong phai ma tran tam giac duoi");
	else		printf("\nDay la ma tran tam giac duoi");
}
int timmin(int **a,int n){  
	int min=a[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+j<n-1){
				if(a[i][j]<min)	min=a[i][j];
			}
		}
	}
	return min;
}
