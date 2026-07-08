#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char ten[30];
	float diem;
	char truong[3];
}sinhvien;

void docfile(FILE *f,sinhvien *a,int n);
void tongdiem(sinhvien *a,int n);
void xuatfile(sinhvien *a,int n);
void timkiem(sinhvien *a,int n);

int main(){
	int n;
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file input.txt");
		return 1;
	}
	
	fscanf(f,"%d",&n);
	sinhvien *a=(sinhvien*)malloc(n*sizeof(sinhvien));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	
	docfile(f,a,n);
	tongdiem(a,n);
	xuatfile(a,n);
	timkiem(a,n);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,sinhvien *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f," %[^\n]",a[i].ten);
		fscanf(f,"%f",&a[i].diem);
		fscanf(f,"%s",a[i].truong);
	}
	printf("Doc thanh cong file input.txt");
}
void tongdiem(sinhvien *a,int n){
	float tonga=0,tongb=0,tongc=0;
	for(int i=0;i<n;i++){
		if(strcmp("A",a[i].truong)==0)			tonga+=a[i].diem;
		else if(strcmp("B",a[i].truong)==0)		tongb+=a[i].diem;
		else									tongc+=a[i].diem;
	}
	float min;
	if(tongb<tongc && tongb<tonga)				min=tongb;
	else if(tongc<tonga && tongc<tongb)	 		min=tongc;
	else										min=tonga;
	
	if(min==tonga)			printf("\nTruong co diem thap nhat la truong A :%.2f",min);
	else if(min==tongb)		printf("\nTruong co diem thap nhat la truong B :%.2f",min);	
	else					printf("\nTruong co diem thap nhat la truong C :%.2f",min);	
}
void xuatfile(sinhvien *a,int n){
	float max=a[0].diem;
	for(int i=0;i<n;i++){
		if(a[i].diem>max)	max=a[i].diem;
	}
	
	FILE *F=fopen("caonhat.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file caonhat.txt");
		exit(1);
	}
	fprintf(F,"\nThi sinh co diem cao nhat la :");
	fprintf(F,"\n| %-30s | %-12s | %-12s |","Ho Va Ten","Diem","Truong");
	for(int i=0;i<n;i++){
		if(max==a[i].diem)	fprintf(F,"\n| %-30s | %-12.2f | %-12s |",a[i].ten,a[i].diem,a[i].truong);
	}
	printf("\nDa ghi thanh cong vao file caonhat.txt");
	fclose(F);
}
void timkiem(sinhvien *a,int n){
	char ho[30];
	printf("\nNhap ho can tim :");	gets(ho);
	int len=strlen(ho);
	int dem=0;
	float tongho=0;
	for(int i=0;i<n;i++){
		if(strncmp(ho,a[i].ten,len)==0 && a[i].ten[len]==' '){
			dem++;
			tongho+=a[i].diem;
		}
	}
  
	if(dem==0)	printf("\nKhong tim thay sinh vien co ho la %s",ho);
	else{
		printf("\nDiem trung binh cua sinh vien co ho %s la :%.2f",ho,tongho/dem);
	}
}
