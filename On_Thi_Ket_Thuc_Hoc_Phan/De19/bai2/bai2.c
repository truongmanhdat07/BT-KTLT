#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char ma[20];
	char ten[30];
	int stcb;
	float tocdanh;
	char hetoc[20];
	float dps;
}nhanvat;

void docfile(FILE *f,nhanvat *a,int k);
void in1(nhanvat *a,int k);
void in2(nhanvat *a,int k);
void timkiem(nhanvat *a,int k);
void sapxep(nhanvat *a,int k);
void xuatfile(nhanvat *a,int k);

int main(){
	int k;
	char tenfile[20];
	printf("Nhap ten file :");
	fflush(stdin);	gets(tenfile);
	FILE *f=fopen(tenfile,"r");
	if(f==NULL){
		printf("\nKhong the mo file %s",tenfile);
		return 1;
	}
	
	fscanf(f,"%d",&k);
	nhanvat *a=(nhanvat*)malloc(k*sizeof(nhanvat));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	
	docfile(f,a,k);
	printf("\nDanh sach nhan vat vua doc la :");
	in1(a,k);
	printf("\n\nDanh sach nhan vat sau khi bo sung :");
	in2(a,k);
	timkiem(a,k);
	sapxep(a,k);
	xuatfile(a,k);
	
	fclose(f);
	free(a);
	return 0;
}
void docfile(FILE *f,nhanvat *a,int k){
	for(int i=0;i<k;i++){
		fscanf(f,"%s",a[i].ma);
		fscanf(f," %[^\n]",a[i].ten);
		fscanf(f," %[^\n]",a[i].hetoc);
		fscanf(f,"%d %f",&a[i].stcb,&a[i].tocdanh);
		a[i].dps=a[i].tocdanh * a[i].stcb;
	}
}
void in1(nhanvat *a,int k){
	printf("\n| %-5s | %-10s | %-30s | %-15s | %-12s | %-12s |","STT","Ma","Ten","He Toc","Sat Thuong","Toc Danh");
	for(int i=0;i<k;i++){
		printf("\n| %-5d | %-10s | %-30s | %-15s | %-12d | %-12.2f |",i+1,a[i].ma,a[i].ten,a[i].hetoc,a[i].stcb,a[i].tocdanh);
	}
}
void in2(nhanvat *a,int k){
	float tongdps=0;
	printf("\n| %-5s | %-10s | %-30s | %-15s | %-12s | %-12s | %-12s |","STT","Ma","Ten","He Toc","Sat Thuong","Toc Danh","DPS");
	for(int i=0;i<k;i++){
		printf("\n| %-5d | %-10s | %-30s | %-15s | %-12d | %-12.2f | %-12.2f |",i+1,a[i].ma,a[i].ten,a[i].hetoc,a[i].stcb,a[i].tocdanh,a[i].dps);
		tongdps+=a[i].dps;
	}
	printf("\nTong dps la :%.2f",tongdps);
}
void timkiem(nhanvat *a,int k){
	char tim[20];
	printf("\nNhap he can tim :");
	fflush(stdin);	gets(tim);
	int dem=0;
	for(int i=0;i<k;i++){
		if(strcmp(tim,a[i].hetoc)==0  && a[i].dps>1000)	dem++;
	}
	if(dem==0)	printf("\nKhong co nhan vat dat yeu cau");
	else{
		printf("\nDanh sach nhan vat dat yeu cau la :");
		printf("\n| %-10s | %-30s | %-15s | %-12s | %-12s | %-12s |","Ma","Ten","He Toc","Sat Thuong","Toc Danh","DPS");
		for(int i=0;i<k;i++){
			if(strcmp(tim,a[i].hetoc)==0  && a[i].dps>1000)	printf("\n| %-10s | %-30s | %-15s | %-12d | %-12.2f | %-12.2f |",a[i].ma,a[i].ten,a[i].hetoc,a[i].stcb,a[i].tocdanh,a[i].dps);
		}	
	}
}
void sapxep(nhanvat *a,int k){
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			if(a[i].dps<a[j].dps){
				nhanvat temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else if(a[i].dps==a[j].dps){
				if(strcmp(a[i].ma,a[j].ma)>0){
					nhanvat temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}
}
void xuatfile(nhanvat *a,int k){
	FILE *F=fopen("ketqua.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file ketqua.txt");
		exit(1);
	}
	fprintf(F,"Danh sach nhan vat sau khi sap xep la :");
	fprintf(F,"\n| %-5s | %-10s | %-30s | %-15s | %-12s | %-12s | %-12s |","STT","Ma","Ten","He Toc","Sat Thuong","Toc Danh","DPS");
	for(int i=0;i<k;i++){
		fprintf(F,"\n| %-5d | %-10s | %-30s | %-15s | %-12d | %-12.2f | %-12.2f |",i+1,a[i].ma,a[i].ten,a[i].hetoc,a[i].stcb,a[i].tocdanh,a[i].dps);
	}
	printf("\nDa ghi thanh cong vao file ketqua.txt");
	fclose(F);
}
