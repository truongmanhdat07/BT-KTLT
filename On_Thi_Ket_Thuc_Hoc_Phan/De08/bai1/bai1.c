#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
	float x;
	float y;
}toado;

void nhap(FILE *f,toado *a,int n);
void in(toado *a,int n);
void timkcmax(toado *a,int n);
float tongdodai(toado *a,int n);

int main(){
	int n;
	FILE *f=fopen("toado.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file!");
		return 1;
	}
	fscanf(f,"%d",&n);
	toado *a=(toado *)malloc(n*sizeof(toado));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	nhap(f,a,n);
	in(a,n);
	timkcmax(a,n);
	printf("\nTong do dai duong gap khuc di qua tat ca cac diem la :%.2f",tongdodai(a,n));
	
	fclose(f);
	free(a);
	return 0;
}
void nhap(FILE *f,toado *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f,"%f %f",&a[i].x,&a[i].y);
	}
}
void in(toado *a,int n){
	for(int i=0;i<n;i++){
		printf("\nToa do diem thu %d la :(%.2f , %.2f)",i+1,a[i].x,a[i].y);
	}
}
void timkcmax(toado *a,int n){
	float max=a[0].x*a[0].x + a[0].y*a[0].y;
	for(int i=0;i<n;i++){
		float kc=(a[i].x * a[i].x + a[i].y * a[i].y);
		if(kc>max)	max=kc;
	}
	printf("\nKhoang cach xa goc toa do nhat la :%.2f",sqrt(max));
	for(int i=0;i<n;i++){
		if((a[i].x * a[i].x + a[i].y * a[i].y)==max)	printf(" voi toa do la :( %.2f,%.2f )",a[i].x,a[i].y);
	}
}
float tongdodai(toado *a,int n){
	float tong=0;
	for(int i=0;i<n-1;i++){
		float dx= (a[i].x-a[i+1].x);
		float dy= (a[i].y-a[i+1].y);
		tong+=sqrt(dx*dx +dy*dy);
	}
	return tong;
}
