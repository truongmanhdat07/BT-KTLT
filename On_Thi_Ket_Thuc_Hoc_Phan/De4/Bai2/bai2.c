#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int madetu;
	char hoten[100];
	char canhgioi[30];
	int diemconghien;
}detu;

void nhap(detu *a,int n);
void in(detu *a,int n);
void timkiem(detu *a,int n);
void sapxep(detu *a,int n);
void xuatfile(detu *a,int n);
void docfile(detu *a,int n);


int main(){
	int n;
	printf("Vui long nhap so de tu :");	scanf("%d",&n);
	detu *a=(detu*)malloc(n*sizeof(detu));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	nhap(a,n);
	printf("\n\nDanh sach de tu vua nhap la :");
	in(a,n);
	timkiem(a,n);
	xuatfile(a,n);
	free(a);
	
	detu *A=(detu *)malloc(n*sizeof(detu));
	if(A==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	docfile(A,n);
	free(A);
	return 0;
}

void nhap(detu *a,int n){
	for(int i=0;i<n;i++){
		printf("\nVui long nhap thong tin de tu thu %d :",i+1);
		printf("\nHo Va Ten :");
		fflush(stdin);
		gets(a[i].hoten);
		printf("Ma de tu :");
		scanf("%d",&a[i].madetu);
		printf("Canh Gioi :");
		fflush(stdin);
		gets(a[i].canhgioi);
		printf("Diem Cong Hien :");
		scanf("%d",&a[i].diemconghien);
	}
}
void in(detu *a,int n){
	printf("\n===================================== Danh Sach De Tu =====================================");
	printf("\n===========================================================================================");
	printf("\n| %-5s | %-10s | %-30s | %-15s | %-15s |","STT","Ma De Tu","Ho Va Ten","Canh Gioi","Diem Cong Hien");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-10d | %-30s | %-15s | %-15d |",i+1,a[i].madetu,a[i].hoten,a[i].canhgioi,a[i].diemconghien);
	}
	printf("\n===========================================================================================");
}
void timkiem(detu *a,int n){
	int count =0;
	for(int i=0;i<n;i++){
		if( strcmp(a[i].canhgioi,"nguyen dan")==0 && a[i].diemconghien>=1000    )	count++;
	}
	if(count==0)	printf("\n\nKhong co de tu nao dat yeu cau!");
	else{
		printf("\n\nSo de tu dat yeu cau la :%d",count);
		printf("\n===================================== Danh Sach De Tu =====================================");
		printf("\n===========================================================================================");
		printf("\n| %-5s | %-10s | %-30s | %-15s | %-15s |","STT","Ma De Tu","Ho Va Ten","Canh Gioi","Diem Cong Hien");
		for(int i=0;i<n;i++){
			if( strcmp(a[i].canhgioi,"nguyen dan")==0 && a[i].diemconghien>=1000 ){
				printf("\n| %-5d | %-10d | %-30s | %-15s | %-15d |",i+1,a[i].madetu,a[i].hoten,a[i].canhgioi,a[i].diemconghien);
			}
		}
		printf("\n===========================================================================================");
	}
}
void sapxep(detu *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].diemconghien<a[j].diemconghien){
				detu temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void xuatfile(detu *a,int n){
	FILE *f=fopen("data.bin","wb");
	if(f==NULL){
		printf("\nKhong the mo file!");
		exit(1);
	}
	sapxep(a,n);
	fwrite(a,sizeof(detu),n,f);
	fclose(f);
}
void docfile(detu *A,int n){
	FILE *F=fopen("data.bin","rb");
	if(F==NULL){
		printf("\nKhong mo duoc file!");
		exit(1);
	}
	fread(A,sizeof(detu),n,F);
	fclose(F);
	printf("\n\nDanh sach de tu sau khi doc tu file data.bin la :");
	in(A,n);
}
