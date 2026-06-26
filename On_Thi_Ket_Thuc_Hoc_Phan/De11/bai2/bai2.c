#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char ma[10];
	char ten[30];
	int gia;
	float satthuong;
}tuong;

void docfile(FILE *f,tuong *a,int n);
void in(tuong *a,int n);
void inmax(tuong *a,int n);
void sapxep(tuong *a,int n);
void xuatfile(tuong *a,int n);


int main(){
	int n;
	FILE *f=fopen("tuong.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file tuong.txt");
		return 1;
	}
	fscanf(f,"%d",&n);
	tuong *a=(tuong*)malloc(n*sizeof(tuong));
	if(a==NULL){
		printf("\nKhong the cap phat dong");
		return 1;
	}
	
	docfile(f,a,n);
	printf("\nDanh sach tuong vua doc tu file tuong.txt la :");
	in(a,n);
	inmax(a,n);
	sapxep(a,n);
	xuatfile(a,n);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,tuong *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f,"%s",a[i].ma);
		fscanf(f," %[^\n]",a[i].ten);
		fscanf(f,"%d %f",&a[i].gia,&a[i].satthuong);
	}
	printf("\nDoc thanh cong file tuong.txt");
}
void in(tuong *a,int n){
	printf("\n| %-5s | %-12s | %-30s | %-12s | %-12s |","STT","Ma Tuong","Ten Tuong","Gia","Sat Thuong");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-12s | %-30s | %-12d | %-12.2f |",i+1,a[i].ma,a[i].ten,a[i].gia,a[i].satthuong);
	}
}
void inmax(tuong *a,int n){
	float max=a[0].satthuong;
	for(int i=0;i<n;i++){
		if(a[i].satthuong>max)	max=a[i].satthuong;
	}
	printf("\nTuong co sat thuong co ban cao nhat la :");
	printf("\n| %-12s | %-30s | %-12s | %-12s |","Ma Tuong","Ten Tuong","Gia","Sat Thuong");
	for(int i=0;i<n;i++){
		if(a[i].satthuong==max)	printf("\n| %-12s | %-30s | %-12d | %-12.2f |",a[i].ma,a[i].ten,a[i].gia,a[i].satthuong);
	}
}
void sapxep(tuong *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].gia<a[j].gia){
				tuong temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else if(a[i].gia==a[j].gia){
				if(strcmp(a[i].ten,a[j].ten)>0){
					tuong temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}
}
void xuatfile(tuong *a,int n){
	FILE *F=fopen("ketqua_tuong.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file ketqua_tuong.txt");
		exit(1);
	}
	
	fprintf(F,"\n| %-5s | %-12s | %-30s | %-12s | %-12s |","STT","Ma Tuong","Ten Tuong","Gia","Sat Thuong");
	for(int i=0;i<n;i++){
		fprintf(F,"\n| %-5d | %-12s | %-30s | %-12d | %-12.2f |",i+1,a[i].ma,a[i].ten,a[i].gia,a[i].satthuong);
	}
	printf("\nDa in thanh cong vao file ketqua_tuong.txt");
	fclose(F);
}
