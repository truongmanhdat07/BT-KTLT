
#include<stdio.h>
#include"bai1ham.h"

int main(){
	
	//tinh dien tich va chu vi
	float R;
	printf("Vui long nhap ban kinh duong tron :");
	scanf("%f",&R);
	printf("Dien tich :%.2f",tinhdientich(R));
	printf("\nChu vi :%.2f",tinhchuvi(R));
	
	//kiem tra so nguyen to
	int n;
	printf("\n\nVui long nhap so can kiem tra :");
	scanf("%d",&n);
	if(kiemtrasonguyento(n)==1)	printf("%d la so nguyen to",n);
	else						printf("%d Khong phai so nguyen to",n);
	
	//tinh khoang cach giua hai diem
	toado a[2];
	for(int i=0;i<2;i++){
		printf("\n\nVui long nhap toa do diem thu %d",i+1);
		printf("\nx :");	scanf("%f",&a[i].x);
		printf("y :");		scanf("%f",&a[i].y);
		printf("z :");		scanf("%f",&a[i].z);
	}
	printf("\nKhoang cach giua 2 diem vua nhap la :%.2f",tinhkhoangcach(a[0],a[1]) );
	
	//tinh luy thua bang de quy
	float x;
	printf("\n\nVui long nhap co so x :");	scanf("%f",&x);
	printf("Vui long nhap so mu n :");		scanf("%d",&n);
	printf("Ket qua cua x^n la :%.2lf",luythua(x,n));
	return 0;
}
