#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void nhap(float *a,int n);
void in(float *a,int n);
float tinhtoan(float *a,int n);

int main(){
	int n;
	printf("Vui long nhap bac cua da thuc :");	scanf("%d",&n);
	float *a=(float*)malloc((n+1)*sizeof(float));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho !");
		return 1;
	}
	nhap(a,n);
	printf("\nDa thuc vua nhap la :");
	in(a,n);
	printf("\nGia tri cua bieu thuc S la :%.2f",tinhtoan(a,n));
	free(a);
}

void nhap(float *a,int n){
	for(int i=n;i>=0;i--){
		printf("Vui long nhap he so bac %d :",i);
		scanf("%f",&a[i]);
	}
}
void in(float *a,int n){
	int count=0;
	for(int i=n;i>=0;i--){
		if(a[i]==0)	continue;
		if(count==0){
			if(a[i]<0)	printf("-");
		}
		else{
			if(a[i]>0)	printf(" + ");
			else		printf(" - ");
		}
		float val=(a[i]>0) ? a[i] : -a[i];

		if(val !=1 || i==0)	printf("%.2f",val);

		if(i >1)			printf("x^%d",i);
		else if(i == 1)		printf("x");
		count++;
	}
}
float tinhtoan(float *a,int n){
	float x;
	printf("\nVui long nhap x :");	scanf("%f",&x);
	float p=0,P=0;
	for(int i=n;i>=0;i--){
		p+= a[i]*pow(x,i);
		if(i>0)		P+= i * a[i] * pow(x,i-1);
	}
	float S=2021+p+P;
	if(S<0){
		printf("\nLoi bieu thuc trong can am!");
		return -1;
	}
		
	return sqrt(S);
}
