#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	float x,y;
}toado;

void nhap(toado *a,int n);
float dodai(toado *a,int n);
void maxx(toado *a,int n);

int main(){
	int n;
	printf("Vui long nhap so diem :");	scanf("%d",&n);
	toado *a=(toado *)malloc(n*sizeof(toado));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	nhap(a,n);
	printf("\nDo dai duong gap khuc di qua cac diem la :%.2f",dodai(a,n));
	maxx(a,n);
	
	free(a);
	return 0;
}
void nhap(toado *a,int n){
	for(int i=0;i<n;i++){
		printf("Hoanh do x%d:",i+1);	scanf("%f",&a[i].x);
		printf("Tung do y%d :",i+1);	scanf("%f",&a[i].y);
	}
}
float dodai(toado *a,int n){
	float tong=0;
	for(int i=0;i<n-1;i++){
		float dx=a[i].x-a[i+1].x;
		float dy=a[i].y-a[i+1].y;
		tong+= sqrt(dx*dx + dy*dy);
	}
	return tong;
}
void maxx(toado *a,int n){
	float max=fabs(a[0].y);
	for(int i=0;i<n;i++){
		float dy=(a[i].y>0) ? a[i].y : -a[i].y;
		if(dy>max)	max=dy;
	}
	printf("\nCac diem xa truc hoanh nhat la : dy = %.2f",max);
	for(int i=0;i<n;i++){
		float dy=fabs(a[i].y);
		if(dy==max){
			printf("\n(%.2f,%.2f)",a[i].x,a[i].y);
		}
	}
}
