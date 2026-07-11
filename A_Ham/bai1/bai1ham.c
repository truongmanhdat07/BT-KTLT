#include"bai1ham.h"
#include<math.h>
float tinhdientich(float R){
	return 3.14*R*R;
}
float tinhchuvi(float R){
	return 2*3.14*R;
}
int kiemtrasonguyento(int n){
	if(n<2)			return 0;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)	return 0;
	}
	return 1;
}
float tinhkhoangcach(toado p1,toado p2){
	float dx=p1.x-p2.x;
	float dy=p1.y-p2.y;
	float dz=p1.z-p2.z;
	float bpkc=dx*dx + dy*dy + dz*dz;
	return sqrt(bpkc);
}
double luythua(float x,int n){
	if(n==0)	return 1.0;
	if(n<0)		return 1.0/luythua(x,-n);
	return x*luythua(x,n-1);
}
