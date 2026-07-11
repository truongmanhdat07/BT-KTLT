#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char ma[10];
	char tentx[40];
	int soluong;
	float giave;
	float doanhthu;
}chuyenxe;

void docfile(FILE *f,chuyenxe *a,int n);
void timmax(chuyenxe *a,int n);
void xuatfile(chuyenxe *a,int n);

int main(){
	int n;
	FILE *f=fopen("chuyenxe.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file chuyenxe.txt !");
		return 1;
	}
	fscanf(f,"%d",&n);
	chuyenxe *a=(chuyenxe*)malloc(n*sizeof(chuyenxe));
	if(a==NULL){
		printf("\nKhong the cap phat dong!");
		return 1;
	}
	docfile(f,a,n);
	timmax(a,n);
	xuatfile(a,n);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,chuyenxe *a,int n){
	float tongdoanhthu=0;
	for(int i=0;i<n;i++){
		fscanf(f,"%s",a[i].ma);
		fscanf(f," %[^\n]",a[i].tentx);
		fscanf(f,"%d %f",&a[i].soluong,&a[i].giave);
		a[i].doanhthu=a[i].soluong*a[i].giave;
		tongdoanhthu+=a[i].doanhthu;
	}
	printf("\nDoc file thanh cong!");
	printf("\nTong doanh thu cua chuyen xe la :%.2f",tongdoanhthu);
}
void timmax(chuyenxe *a,int n){
	int max=a[0].soluong;
	int vitri=0;
	for(int i=0;i<n;i++){
		if(a[i].soluong>max){
			max=a[i].soluong;
			vitri=i;
		}
	}
	printf("\nChuyen xe co so luong khach nhieu nhat la :");
	printf("\n| %-12s | %-30s | %-12s | %-12s | %-12s |","Ma Chuyen Xe","Ten Tai Xe","So Luong","Gia Ve","Doanh Thu");
	printf("\n| %-12s | %-30s | %-12d | %-12.2f | %-12.2f |",a[vitri].ma,a[vitri].tentx,a[vitri].soluong,a[vitri].giave,a[vitri].doanhthu);
}
void xuatfile(chuyenxe *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].doanhthu<a[j].doanhthu){
				chuyenxe temp=a[i];
				a[i]=a[j];
				a[j]=temp;				
			}
			else if(a[i].doanhthu==a[j].doanhthu){
				if(strcmp(a[i].ma,a[j].ma)>0){
					chuyenxe temp=a[i];
					a[i]=a[j];
					a[j]=temp;	
				}
			}
		}
	}
	FILE *F=fopen("ketqua_cx.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file ketqua_cx.txt !");
		exit(1);
	}
	fprintf(F,"\nDanh sach chuyen xe sau khi sap xep la  :");
	fprintf(F,"\n| %-12s | %-30s | %-12s | %-12s | %-12s |","Ma Chuyen Xe","Ten Tai Xe","So Luong","Gia Ve","Doanh Thu");
	for(int i=0;i<n;i++){
		fprintf(F,"\n| %-12s | %-30s | %-12d | %-12.2f | %-12.2f |",a[i].ma,a[i].tentx,a[i].soluong,a[i].giave,a[i].doanhthu);
	}
	printf("\nDa ghi thanh cong vao file ketqua_c.txt");
	fclose(F);
}
