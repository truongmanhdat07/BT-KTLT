#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
	char ma[20];
	char ten[50];
	int soluong;
	float gia;
}hanghoa;

void docfile(FILE *f,hanghoa *a,int n);
float tinhtong(hanghoa *a,int n);
void sapxep1(hanghoa *a,int n);
void sapxep2(hanghoa *a,int n);
void in(hanghoa *a,int n);
void xuatfile(hanghoa *a,int n);

int main(){
	int n;
	FILE *f=fopen("nongsan.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file!");
		return 1;
	}
	fscanf(f,"%d",&n);
	hanghoa *a=(hanghoa*)malloc(n*(sizeof(hanghoa)));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	docfile(f,a,n);
	printf("Tong gia tri hang hoa la :%.2f",tinhtong(a,n));
	sapxep1(a,n);
	printf("\nDanh Sach Hang Hoa co don gia cao nhat la :");
	in(a,3);
	sapxep2(a,n);
	printf("\nDanh Sach Hang Hoa theo so luong giam dan la :");
	xuatfile(a,n);
	
	fclose(f);
	free(a);
	return 0;
}
void docfile(FILE *f,hanghoa *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f,"%s",a[i].ma);
		fscanf(f," %[^\n]",a[i].ten);
		fscanf(f,"%d %f",&a[i].soluong,&a[i].gia);
	}
}
float tinhtong(hanghoa *a,int n){
	float tong=0;
	for(int i=0;i<n;i++){
		tong+=a[i].gia * a[i].soluong;
	}
	return tong;
}
void sapxep1(hanghoa *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].gia<a[j].gia){
				hanghoa temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void sapxep2(hanghoa *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].soluong<a[j].soluong){
				hanghoa temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			if(a[i].soluong==a[j].soluong){
				if(strcmp(a[i].ten,a[j].ten)<0){
					hanghoa temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}
}
void in(hanghoa *a,int n){
	printf("\n| %-5s | %-12s | %-30s | %-12s | %-12s |","STT","Ma San Pham","Ten San Pham","So Luong","Gia");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-12s | %-30s | %-12d | %-12.2f |",i+1,a[i].ma,a[i].ten,a[i].soluong,a[i].gia);
	}
}

void xuatfile(hanghoa *a,int n){
	FILE *F=fopen("ketqua.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file!");
		exit(1);
	}
	fprintf(F,"\n| %-5s | %-12s | %-30s | %-12s | %-12s |","STT","Ma San Pham","Ten San Pham","So Luong","Gia");
	for(int i=0;i<n;i++){
		fprintf(F,"\n| %-5d | %-12s | %-30s | %-12d | %-12.2f |",i+1,a[i].ma,a[i].ten,a[i].soluong,a[i].gia);
	}
	printf("\nDa ghi thanh cong vao file ketqua.txt");
	fclose(F);
}
