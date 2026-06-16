#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char ten[30];
	float diem;
	int truong;
}thisinh;

void nhap(thisinh *a,int n);
void tongdiem(thisinh *a,int n);
void sapxep(thisinh *a,int n);
void in(thisinh *a,int n);
void thongke(thisinh *a,int n);

int main(){
	int n;
	printf("Vui long nhap so thi sinh :");	scanf("%d",&n);
	thisinh *a=(thisinh*)malloc(n*sizeof(thisinh));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho ");
		return 1;
	}
	
	nhap(a,n);
	tongdiem(a,n);
	sapxep(a,n);
	printf("\nDanh sach thi sinh sau khi sap xep la :");
	in(a,n);
	printf("\nThong ke diem cac truong :");
	thongke(a,n);
	
	free(a);
	return 0;
}
void nhap(thisinh *a,int n){
	for(int i=0;i<n;i++){
		printf("Vui long nhap thong tin thi sinh thu %d :",i+1);
		printf("\nHo Va Ten :");
		fflush(stdin);
		gets(a[i].ten);
		printf("Diem :");	scanf("%f",&a[i].diem);
		printf("Truong :");	scanf("%d",&a[i].truong);
	}
}
void tongdiem(thisinh *a,int n){
	int k;
	int kt=0;
	float tong=0;
	printf("\nVui long nhap truong can tinh diem :");	scanf("%d",&k);
	for(int i=0;i<n;i++){
		if(a[i].truong==k){
			tong+=a[i].diem;
			kt=1;
		}
	}
	if(kt==0)	printf("\nKhong tim thay truong vua nhap!");
	else		printf("Tong diem cua truong %d la :%.2f",k,tong);

}
void sapxep(thisinh *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].diem<a[j].diem){
				thisinh temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void in(thisinh *a,int n){
	printf("\n| %-5s | %-30s | %-12s | %-12s |","STT","Ho Va Ten","Diem","Truong");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-30s | %-12.2f | %-12d |",i+1,a[i].ten,a[i].diem,a[i].truong);
	}
}
void thongke(thisinh *a,int n){
	float *tong=(float *)malloc((n+1)*sizeof(float));
	for(int i=0;i<n+1;i++){
		tong[i]=0;
	}
	
	printf("\n| %-12s | %-12s |","Truong","Diem");
	for(int i=0;i<n;i++){
		int matruong=a[i].truong;
		tong[matruong]+=a[i].diem;
	}
	float max=tong[1];
	int truongmax=1;
	for(int i=1;i<=n;i++){
		printf("\n| %-12d | %-12.2f |",i,tong[i]);
		if(tong[i]>max){
			max=tong[i];
			truongmax=i;
		}
	}
	printf("\nTruong co tong diem cao nhat la truong %d :%.2f",truongmax,max);
	free(tong);
}
