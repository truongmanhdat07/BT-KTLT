#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	float x,y;
}toado;

void docfile(FILE *f,toado *a,int n);
void in(toado *a,int n);
void dem(toado *a,int n);
void maxtgv(toado *a,int n);

int main(){
	int n;
	FILE *f=fopen("toado.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file toado.txt");
		return 1;
	}
	
	fscanf(f,"%d",&n);
	toado *a=(toado*)malloc(n*sizeof(toado));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	
	docfile(f,a,n);
	printf("\nCac diem vua nhap :");
	in(a,n);
	dem(a,n);
	maxtgv(a,n);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,toado *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f,"%f %f",&a[i].x,&a[i].y);
	}
	printf("\nDoc thanh cong file toado.txt");
}
void in(toado *a,int n){
	for(int i=0;i<n;i++){
		printf("(%.2f,%.2f)   ",a[i].x,a[i].y);
	}
}
void dem(toado *a,int n){
	int dem=0;
	float R;
	printf("\nNhap ban kinh R :");	scanf("%f",&R);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			float bpd1=a[i].x*a[i].x + a[i].y*a[i].y;
			float bpd2=a[j].x*a[j].x + a[j].y*a[j].y;
			if(bpd1 <= R*R && bpd2 <= R*R)	dem++;
		}
	}
	printf("\nSo doan thang nam trong duong tron ban kinh R la :%d",dem);
}
void maxtgv(toado *a,int n){
	float maxdt=-1;
	int timthay=0;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				float AB2=(a[j].x-a[i].x)*(a[j].x-a[i].x)+(a[j].y-a[i].y)*(a[j].y-a[i].y);
				float BC2=(a[k].x-a[j].x)*(a[k].x-a[j].x)+(a[k].y-a[j].y)*(a[k].y-a[j].y);
				float AC2=(a[k].x-a[i].x)*(a[k].x-a[i].x)+(a[k].y-a[i].y)*(a[k].y-a[i].y);
				
				int vuong=0;
				float canh1=0,canh2=0;
				
				if		(AB2+BC2==AC2){ vuong=1; canh1=AB2; canh2=BC2; }      
				else if (AB2+AC2==BC2){ vuong=1; canh1=AB2; canh2=AC2; } 
				else if (BC2+AC2==AB2){ vuong=1; canh1=BC2; canh2=AC2; } 

				if(vuong){
					timthay=1;
					float dt=0.5*sqrt(canh1)*sqrt(canh2);
					if(dt>maxdt) maxdt=dt;
				}
			}
		}
	}
	if(timthay==0)	printf("\nKhong co tam giac vuong");
	else			printf("\nTam giac vuong co dien tich lon nhat la :%.2f",maxdt);
}
