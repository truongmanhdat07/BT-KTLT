#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void docfile(FILE *f,float *dathuc,int bac);
void in(float *dathuc,int bac);
float tinhtoan(float *dathuc,int bac,float x);
void daoham(float *dathuc,int bac);

int main(){
	int m,n;
	FILE *f=fopen("dathuc.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file dathuc.txt");
		return 1;
	}
	
	fscanf(f,"%d",&n);
	float *p=(float *)malloc((n+1)*sizeof(float));
	if(p==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	docfile(f,p,n);
	
	fscanf(f,"%d",&m);
	float *q=(float *)malloc((m+1)*sizeof(float));
	if(q==NULL){
		printf("\nKhong the cap phat dong");
		return 1;
	}
	docfile(f,q,m);
	
	printf("\nDa thuc P :");
	in(p,n);
	printf("\nDa thuc Q :");
	in(q,m);
	
	float x;
	printf("\nVui long nhap x :");	scanf("%f",&x);
	printf("\nS = P(x) + Q(x) = %.2f",tinhtoan(p,n,x)+tinhtoan(q,m,x));
	
	daoham(p,n);
	
	free(p);free(q);
	fclose(f);
	return 0;
}
void docfile(FILE *f,float *dathuc,int bac){
	for(int i=0;i<=bac;i++){
		fscanf(f,"%f",&dathuc[i]);
	}
}
void in(float *dathuc,int bac){
	int dem=0;
	for(int i=0;i<=bac;i++){
		if(dathuc[i]==0)	continue;
		if(dem==0){
			if(dathuc[i]<0)	printf("-");
		}
		else{
			if(dathuc[i]>0)			printf(" + ");
			else if(dathuc[i]<0)	printf(" - ");
		}
		
		float value=(dathuc[i]>0) ? dathuc[i] : -dathuc[i];
		if(value !=1 || i==0)	printf("%.2f",value);
		if(i>1)					printf("x^%d",i);
		else if(i==1)			printf("x");
		dem++;
	}
	if(dem==0)	printf("0");
}
float tinhtoan(float *dathuc,int bac,float x){
	float kq=0;
	for(int i=0;i<=bac;i++){
		kq+=dathuc[i]* pow(x,i);
	}
	return kq;
}
void daoham(float *dathuc,int bac){
	int bacdaoham=bac-1;
	float *daoham=(float*)malloc((bacdaoham+1)*sizeof(float));
	if(daoham==NULL){
		printf("\nKhong the cap phat dong!");
		exit(1);
	}
	for(int i=0;i<bac;i++){
		daoham[i]=dathuc[i+1]*(i+1);
	}
	printf("\nDa thuc P sau khi dao ham la :");
	for(int i=0;i<=bacdaoham;i++){
		printf("%7.2f",daoham[i]);
	}
	
	free(daoham);
}
