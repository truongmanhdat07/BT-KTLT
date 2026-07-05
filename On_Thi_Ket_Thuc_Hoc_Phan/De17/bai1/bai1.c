#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void docfile(FILE *f,float *dathuc,int bac);
float tinh(float *dathuc,int bac,float x);
void daoham(float *dathuc,int bac);
void in(float *dathuc,int bac);
void nhap(float *dathuc,int bac);
void congdathuc(float *dathuc1,int bac1,float *dathuc2,int bac2);

int main(){
	int n;
	FILE *f=fopen("dathuc.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file dathuc.txt");
		return 1;
	}
	
	fscanf(f,"%d",&n);
	float *p=(float*)malloc((n+1)*sizeof(float));
	if(p==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	
	docfile(f,p,n);
	printf("\nDa thuc P :");
	in(p,n);
	daoham(p,n);
	
	int m;
	printf("\nNhap bac da thuc Q :");
	scanf("%d",&m);
	float* q=(float*)malloc((m+1)*sizeof(float));
	if(q==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	
	nhap(q,m);
	printf("\nDa thuc Q :");
	in(q,m);
	congdathuc(p,n,q,m);
	
	printf("\nGia tri cua P(5) la :%.2f",tinh(p,n,5));
	printf("\nGia tri cua P(3) + Q(3) la :%.2f",tinh(p,n,3)+tinh(q,m,3));
	
	free(p);free(q);
	fclose(f);
	return 0;
}
void docfile(FILE *f,float *dathuc,int bac){
	for(int i=0;i<=bac;i++){
		fscanf(f,"%f",&dathuc[i]);
	}
	printf("\nDoc thanh cong file dathuc.txt");
}
float tinh(float *dathuc,int bac,float x){
	float kq=0;
	for(int i=0;i<=bac;i++){
		kq+=dathuc[i] * pow(x,i);
	}
	return kq;
}
void daoham(float *dathuc,int bac){
	if(bac==0){
		printf("\nDao ham cua P la : 0");
		return ;
	}
	int k=bac-1;
	float *d=(float *)malloc((k+1)*sizeof(float));
	if(d==NULL){
		printf("\nKhong the cap phat bo nho");
		exit(1);
	}
	for(int i=1;i<=bac;i++){
		d[i-1]=dathuc[i] * i;
	}
	printf("\nDao ham cua P la :");
	in(d,k);
	
	free(d);
}
void in(float *dathuc,int bac){
	int dem=0;
	for(int i=0;i<=bac;i++){
		if(dathuc[i]==0)	continue;
		if(dem==0){
			if(dathuc[i]<0)	printf("-");
		}
		else{
			if(dathuc[i]<0)	printf(" - ");
			else			printf(" + ");
		}
		
		float heso=fabs(dathuc[i]);
		if(heso != 1 || i==0 )	printf("%.2f",heso);
		if(i>1)					printf("x^%d",i);
		else if(i==1)			printf("x");
		dem++;
	}
	if(dem==0)	printf("0");
}
void nhap(float *dathuc,int bac){
	for(int i=0;i<=bac;i++){
		printf("Nhap he so bac %d :",i);
		scanf("%f",&dathuc[i]);
	}
}
void congdathuc(float *dathuc1,int bac1,float *dathuc2,int bac2){
	int bacmax=(bac1>bac2) ? bac1 : bac2;
	float *dathuc=(float*)malloc((bacmax+1)*sizeof(float));
	if(dathuc==NULL){
		printf("\nKhong the cap phat bo nho");
		exit(1);
	}
	
	for(int i=0;i<=bacmax;i++){
		float heso1=(i<=bac1) ? dathuc1[i] : 0;
		float heso2=(i<=bac2) ? dathuc2[i] : 0;
		dathuc[i]=heso1+heso2;
	}
	while(bacmax>0 && dathuc[bacmax]==0)	bacmax--;
	printf("\nTong 2 da thuc la :");
	in(dathuc,bacmax);
	
	free(dathuc);
}
