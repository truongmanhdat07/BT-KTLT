#include<stdio.h>
#include<stdlib.h>

void nhap(float *dathuc,int bac);
void in(float *dathuc,int bac);
int tinhtong(float *p,int n,float *q,int m,float *r);

int main(){
	int n,m;
	printf("Vui long nhap bac n cua da thuc P :");	scanf("%d",&n);
	printf("Vui long nhap bac m cua da thuc Q :");	scanf("%d",&m);
	float *p=(float*)malloc((n+1)*sizeof(float));
	float *q=(float*)malloc((m+1)*sizeof(float));
	if(p==NULL || q==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	printf("\nVui long nhap da thuc P :\n");
	nhap(p,n);
	printf("\nVui long nhap da thuc Q :\n");
	nhap(q,m);
	printf("\nDa thuc P vua nhap la :");
	in(p,n);
	printf("\nDa thuc Q vua nhap la :");
	in(q,m);
	
	int bactemp=(n>m) ? n : m;
	float *r=(float *)malloc((bactemp+1)*sizeof(float));
	if(r==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	int bacmax=tinhtong(p,n,q,m,r);
	printf("\nDa thuc R = P + Q la :");
	in(r,bacmax);
	
	
	free(q);free(p);free(r);
	return 0;
}
void nhap(float *dathuc,int bac){
	for(int i=bac;i>=0;i--){
		printf("Vui long nhap he so bac %d :",i);
		scanf("%f",&dathuc[i]);
	}
}
void in(float *dathuc,int bac){
	int count =0;
	for(int i=bac;i>=0;i--){
		if(dathuc[i]==0)	continue;
		if(count==0){
			if(dathuc[i]<0)	printf("-");
		}
		else{
			if(dathuc[i]>0)	printf(" + ");
			if(dathuc[i]<0)	printf(" - ");
		}
		
		float value=(dathuc[i]>0) ? dathuc[i] : -dathuc[i];
		if(value !=1 || i==0)		printf("%.2f",value);
		if(i>1)						printf("x^%d",i);
		else if(i==1)				printf("x");
		count ++;
	}
	if(count==0)	printf("0");
}
int tinhtong(float *p,int n,float *q,int m,float *r){
	int bacmax=(n>m) ? n : m;
	for(int i=bacmax;i>=0;i--){
		float hesop=(i<=n) ? p[i] : 0;
		float hesoq=(i<=m) ? q[i] : 0;
		r[i]=hesop + hesoq;
	}
	while(bacmax>0 && r[bacmax]==0)	bacmax--;
	return bacmax;
}
