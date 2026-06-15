#include<stdio.h>
#include<stdlib.h>

void nhap(int *a,int n);
void in(int *a,int n);
int timmax(int *a,int n);
void sapxep(int *a,int n);
void timkiem(int *a,int n);

int main(){
	int n;
	printf("\nVui long nhap so phan tu cua mang :");	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	nhap(a,n);
	printf("\nDay vua nhap la :");
	in(a,n);
	printf("\nGia tri lon nhat cua day la :%d",timmax(a,n));
	sapxep(a,n);
	printf("\nDay sau khi sap xep la :");
	in(a,n);
	timkiem(a,n);
	
	free(a);
	return 0;
}

void nhap(int *a,int n){
	for(int i=0;i<n;i++){
		printf("Phan tu thu %d :",i+1);	scanf("%d",&a[i]);
	}
}

void in(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%-5d",a[i]);
	}
}

int timmax(int *a,int n){
	int max=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>max)	max=a[i];
	}
	return max;
}

void sapxep(int *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void timkiem(int *a,int n){
	int x;
	int kt=0;
	printf("\nVui long nhap so can tim :");	scanf("%d",&x);
	for(int i=0;i<n;i++){
		if(x==a[i])	kt=1;
	}
	if(kt==0)	printf("\nKhong tim thay so can tim");
	else{
		for(int i=0;i<n;i++){
			if(x==a[i]){
				printf("\nTim thay so %d tai vi tri %d cua day",x,i+1);
			}
		}
	}
}
