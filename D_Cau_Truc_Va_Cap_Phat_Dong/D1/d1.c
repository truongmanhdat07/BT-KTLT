#include<stdio.h>
#include<stdlib.h>


typedef struct {
	char ten[30];
	float tin,triet,tienganh;
	float gpa;
}sinhvien;

void nhap(sinhvien *a,int n);
void in(sinhvien *a,int n);
void tienganh(sinhvien *a,int n);
void sapxep(sinhvien *a,int n);
void gpa(sinhvien *a,int n);

int main(){
	int n;
	printf("\nVui long nhap so luong sinh vien :");	scanf("%d",&n);
	sinhvien *a=(sinhvien *)malloc(n*sizeof(sinhvien));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	nhap(a,n);
	printf("\nDanh sach sinh vien vua nhap la :");
	in(a,n);
	tienganh(a,n);
	sapxep(a,n);
	printf("\nDanh sach sinh vien sau khi sap xep la :");
	in(a,n);
	gpa(a,n);
	
	free(a);
	return 0;
}
void nhap(sinhvien *a,int n){
	for(int i=0;i<n;i++){
		printf("Vui long nhap thong tin sinh vien thu %d :",i+1);
		printf("\nHo Va Ten :");
		fflush(stdin);
		gets(a[i].ten);
		printf("Diem Tin Hoc Dai Cuong :");	scanf("%f",&a[i].tin);
		printf("Diem Triet Hoc :");			scanf("%f",&a[i].triet);
		printf("Diem Tieng Anh :");			scanf("%f",&a[i].tienganh);
		a[i].gpa= (a[i].tin+a[i].triet+a[i].tienganh)/3;
	}
}
void in(sinhvien *a,int n){
	printf("\n| %-5s | %-30s | %-12s | %-12s | %-12s | %-12s |","STT","Ho Va Ten","Tin","Triet","Tieng Anh","GPA");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-30s | %-12.2f | %-12.2f | %-12.2f | %-12.2f |",i+1,a[i].ten,a[i].tin,a[i].triet,a[i].tienganh,a[i].gpa);
	}
}
void tienganh(sinhvien *a,int n){
	int dem =0;
	for(int i=0;i<n;i++){
		if(a[i].tienganh>=9)	dem++;
	}
	if(dem==0)	printf("\n\nKhong co sinh vien nao co diem Tieng Anh >=9");
	else{
		printf("\n\nThi sinh co diem Tieng Anh >= 9 la :");
		printf("\n| %-5s | %-30s | %-12s | %-12s | %-12s | %-12s |","STT","Ho Va Ten","Tin","Triet","Tieng Anh","GPA");
		for(int i=0;i<n;i++){
			if(a[i].tienganh>=9)	printf("\n| %-5d | %-30s | %-12.2f | %-12.2f | %-12.2f | %-12.2f |",i+1,a[i].ten,a[i].tin,a[i].triet,a[i].tienganh,a[i].gpa);
		}
	}
}
void sapxep(sinhvien *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].gpa>a[j].gpa){
				sinhvien temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void gpa(sinhvien *a,int n){
int dem =0;
	for(int i=0;i<n;i++){
		if(a[i].gpa>=8)	dem++;
	}
	if(dem==0)	printf("\n\nKhong co sinh vien nao co gpa >= 8");
	else{
		printf("\n\nThi sinh co gpa >= 8 la :");
		printf("\n| %-5s | %-30s | %-12s | %-12s | %-12s | %-12s |","STT","Ho Va Ten","Tin","Triet","Tieng Anh","GPA");
		for(int i=0;i<n;i++){
			if(a[i].gpa>=8)	printf("\n| %-5d | %-30s | %-12.2f | %-12.2f | %-12.2f | %-12.2f |",i+1,a[i].ten,a[i].tin,a[i].triet,a[i].tienganh,a[i].gpa);
		}
	}	
}
