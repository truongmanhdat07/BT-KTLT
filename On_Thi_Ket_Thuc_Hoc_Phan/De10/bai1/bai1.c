#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
	float x,y,z;
}toado;

void docfile(FILE *f,toado *a,int n);
void in(toado *a,int n);
void thuocmatcau(toado *a,int n);
void kcmax(toado *a,int n);

int main(){
	int n;
	FILE *f=fopen("toado3d.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file !");
		return 1;
	}
	fscanf(f,"%d",&n);
	toado *a=(toado*)malloc(n*sizeof(toado));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	docfile(f,a,n);
	printf("\nToa do cac diem vua doc tu file la :");
	in(a,n);
	thuocmatcau(a,n);
	kcmax(a,n);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,toado *a,int n){
	for(int i=0;i<n;i++){
		fscanf(f,"%f %f %f",&a[i].x,&a[i].y,&a[i].z);
	}
	printf("\nDa doc thanh cong file toado3d.txt");
}
void in(toado *a,int n){
	for(int i=0;i<n;i++){
		printf("\nDiem thu %d :( %.2f , %.2f , %.2f )",i+1,a[i].x,a[i].y,a[i].z);
	}
}
void thuocmatcau(toado *a,int n){
	float R;
	int dem=0;
	printf("\nVui long nhap ban kinh R de kiem tra :");	scanf("%f",&R);
	for(int i=0;i<n;i++){
		float bpkc=a[i].x*a[i].x + a[i].y*a[i].y + a[i].z*a[i].z;
		if(bpkc<R*R){
			dem++;
		}
	}
	if(dem==0)	printf("\nKhong co diem nao thuoc mat cau tam O ban kinh %.2f",R);
	else{
		printf("\nCac diem thuoc mat cau tam O ban kinh %.2f la :",R);
		for(int i=0;i<n;i++){
			float bpkc=a[i].x*a[i].x + a[i].y*a[i].y + a[i].z*a[i].z;
			if(bpkc<R*R){
				printf("\n( %.2f , %.2f , %.2f )",a[i].x,a[i].y,a[i].z);
			}
		}
	}
}
void kcmax(toado *a,int n){
	float bpkcmax= pow(a[0].x-a[1].x,2) + pow(a[0].y-a[1].y,2) + pow(a[0].z-a[1].z,2);
	int p1=0,p2=1;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			float dx= a[i].x-a[j].x;
			float dy= a[i].y-a[j].y;
			float dz= a[i].z-a[j].z;
			float bpkc=dx*dx + dy*dy + dz*dz;
			if(bpkc > bpkcmax){
				bpkcmax=bpkc;
				p1=i;
				p2=j;
			}
		}
	}
	printf("\n2 diem co khoang cach xa nhau nhat la : (%.2f,%.2f,%.2f)->(%.2f,%.2f,%.2f) =%.2f ",a[p1].x,a[p1].y,a[p1].z,a[p2].x,a[p2].y,a[p2].z,sqrt(bpkcmax));
}
