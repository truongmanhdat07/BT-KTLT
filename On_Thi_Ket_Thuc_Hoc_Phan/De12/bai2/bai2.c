#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char ma[20];
	char ten[30];
	float chienluc;
	int tuoi;
}tusi;

void docfile(FILE *f,tusi *a,int n);
void in(tusi *a,int n);
void maxchienluc(tusi *a,int n);
void sapxep(tusi *a,int n);
void xuatfile(tusi *a,int n);

int main(){
	int n;
	FILE *f=fopen("tutien.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file tutien.txt");
		return 1;
	}
	fscanf(f,"%d",&n);
	tusi *a=(tusi *)malloc(n*sizeof(tusi));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	docfile(f,a,n);
	printf("\nDanh sach vua doc tu file tutien.txt la :");
	in(a,n);
	maxchienluc(a,n);
	sapxep(a,n);
	xuatfile(a,n);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,tusi *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f,"%s",a[i].ma);
		fscanf(f," %[^\n]",a[i].ten);
		fscanf(f,"%f %d",&a[i].chienluc,&a[i].tuoi);
	}
	printf("\nDoc thanh cong file tutien.txt");
}
void in(tusi *a,int n){
	printf("\n| %-5s | %-20s | %-30s | %-12s | %-12s |","STT","Ma Tong Mon","Ten","Chien Luc","Tuoi");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-20s | %-30s | %-12.2f | %-12d |",i+1,a[i].ma,a[i].ten,a[i].chienluc,a[i].tuoi);
	}
}
void maxchienluc(tusi *a,int n){
	float max=a[0].chienluc;
	for(int i=0;i<n;i++){
		if(a[i].chienluc>max)	max=a[i].chienluc;
	}
	printf("\nTu si co chien luc cao nhat la :");
	printf("\n| %-5s | %-20s | %-30s | %-12s | %-12s |","STT","Ma Tong Mon","Ten","Chien Luc","Tuoi");
	for(int i=0;i<n;i++){
		if(a[i].chienluc==max)	 printf("\n| %-5d | %-20s | %-30s | %-12.2f | %-12d |",i+1,a[i].ma,a[i].ten,a[i].chienluc,a[i].tuoi);
	}
}
void sapxep(tusi *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].chienluc<a[j].chienluc){
				tusi temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			if(a[i].chienluc==a[j].chienluc){
				if(a[i].tuoi>a[j].tuoi){
					tusi temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}
}
void xuatfile(tusi *a,int n){
	FILE *F=fopen("bangxephang.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file bangxephang.txt");
		exit(1);
	}
	fprintf(F,"\n| %-5s | %-20s | %-30s | %-12s | %-12s |","STT","Ma Tong Mon","Ten","Chien Luc","Tuoi");
	for(int i=0;i<n;i++){
		fprintf(F,"\n| %-5d | %-20s | %-30s | %-12.2f | %-12d |",i+1,a[i].ma,a[i].ten,a[i].chienluc,a[i].tuoi);
	}	
	printf("\nDa ghi thanh cong danh sach sau khi sap xep vao file bangxephang.txt");
	
	fclose(F);
}
