#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void nhap(FILE *f,int **a,int m,int n);
void in(int **a,int m,int n);
int  kiemtrasnt(int k);
void kiemtra(int **a,int m,int n);
void sapxephang(int **a,int m,int n);
void xuatfile(int **a,int m,int n);


int main(){
	int m,n;
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("\nKhong mo duoc file !");
		return 1;
	}
	fscanf(f,"%d %d",&m,&n);
	int **a=(int**)malloc(m*sizeof(int*));
	if(a==NULL){
		printf("\nKhong the cap phat dong!");
		return 1;
	}
	for(int i=0;i<m;i++){
		a[i]=(int*)malloc(n*sizeof(int));
		if(a[i]==NULL){
			printf("\nKhong the cap phat dong!");
			return 1;
		}
	}
	
	nhap(f,a,m,n);
	printf("\nMa tran vua nhap la :\n");
	in(a,m,n);
	printf("\nCac so nguyen to trong ma tran la :");
	kiemtra(a,m,n);
	xuatfile(a,m,n);
	
	for(int i=0;i<m;i++){
		free(a[i]);
	}
	free(a);
	fclose(f);
	return 0;
}
void nhap(FILE *f,int **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
}
void in(int **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%-5d",a[i][j]);
		}
		printf("\n");
	}
}
int kiemtrasnt(int k){
	if(k<2)	return 0;
	for(int i=2;i<=sqrt(k);i++){
		if(k%i==0)	return 0;
	}
	return 1;
}
void kiemtra(int **a,int m,int n){
	int count=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(kiemtrasnt(a[i][j])==1){
				count++;
				printf("%-5d",a[i][j]);
			}
		}
	}
	if(count==0)	printf("\nMa tran khong co so nguyen to nao ton tai!");
}
void sapxep(int *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}		
		}
	}
}
void sapxephang(int **a,int m,int n){
	for(int i=0;i<m;i++){
		sapxep(a[i],n);
	}
}
void xuatfile(int **a,int m,int n){
	FILE *f=fopen("output.txt","w");
	if(f==NULL){
		printf("\nKhong the mo file!");
		exit(1);
	}
	sapxephang(a,m,n);
	fprintf(f,"%d %d\n",m,n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fprintf(f,"%-5d",a[i][j]);
		}
		fprintf(f,"\n");
	}
	printf("\nMa tran sau khi sap xep da duoc ghi vao file output.txt");
	fclose(f);
}
