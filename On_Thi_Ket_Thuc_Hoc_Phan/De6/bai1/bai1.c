#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void nhap(FILE *f,float *dathuc,int bac);
void tinhtoan(float *dathuc,int bac);
void daoham(float *dathuc,int bac);
void timhesomax(float *dathuc,int bac);

int main(){
	int m;
	FILE *f=fopen("dathuc.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file!");
		return 1;
	}
	fscanf(f,"%d",&m);
	float *p=(float*)malloc((m+1)*sizeof(float));
	if(p==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	nhap(f,p,m);
	tinhtoan(p,m);
	daoham(p,m);
	timhesomax(p,m);
	
	fclose(f);
	free(p);
	return 0;
}
void nhap(FILE *f,float *dathuc,int bac){
	for(int i=0;i<=bac;i++){
		fscanf(f,"%f",&dathuc[i]);
	}
}
void tinhtoan(float *dathuc,int bac){
	float x,kq=0;
	printf("Vui long nhap x :");	scanf("%f",&x);
	for(int i=0;i<=bac;i++){
		kq+= dathuc[i] * pow(x,i);
	}
	printf("\nGia tri cua da thuc P tai x la :%.2f",kq);
}
void daoham(float *dathuc,int bac){
	if(bac==0){
		printf("0");
		return;
	}
	int bacdaoham=bac-1;
	float *a=(float*)malloc((bacdaoham+1)*sizeof(float));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return;
	}
	for(int i=1;i<=bac;i++){
		a[i-1]=dathuc[i]*i;
	}
	printf("\nCac he so cua da thuc P sau khi dao ham la :");
	for(int i=0;i<=bacdaoham;i++){
		printf("%-7.2f",a[i]);
	}
	
	free(a);
}
void timhesomax(float *dathuc,int bac){
	float max=fabs(dathuc[0]);
	for(int i=0;i<=bac;i++){
		if(fabs(dathuc[i])>max)	max=fabs(dathuc[i]);
	}
	
	for(int i=0;i<=bac;i++){
		if(max==fabs(dathuc[i])){
			printf("\nGia tri he so max la :%.2f",dathuc[i]);
			printf("\nTai vi tri :%d",i);
		}
	}
}
