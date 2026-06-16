#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char ma[10];
	char ten[50];
	int soluong;
	float gia;
	float giatri;
}hanghoa;

void nhap(hanghoa *a,int k);
void in(hanghoa*a ,int k);
void sapxep(hanghoa *a,int k);
void loc(hanghoa *a,int k);

int main(){
	int k;
	printf("Vui long nhap so hang hoa :");	scanf("%d",&k);
	hanghoa *a=(hanghoa*)malloc(k*sizeof(hanghoa));
	if(a==NULL){
		printf("Khong the cap phat bo nho!");
		return 1;
	}
	
	nhap(a,k);
	printf("\nDanh Sach Hang Hoa vua nhap la :");
	in(a,k);
	sapxep(a,k);
	printf("\nDanh Sach Hang Hoa sau khi sap xep la :");
	in(a,k);
	loc(a,k);
	
	free(a);
	return 0;
}
void nhap(hanghoa *a,int k){
	for(int i=0;i<k;i++){
		printf("\nVui long nhap hang hoa thu %d :",i+1);
		printf("\nMa Hang Hoa :");
		fflush(stdin);
		gets(a[i].ma);
		printf("Ten Hang Hoa :");
		fflush(stdin);
		gets(a[i].ten);
		printf("So Luong :");
		scanf("%d",&a[i].soluong);
		printf("Gia :");
		scanf("%f",&a[i].gia);
		
		a[i].giatri=a[i].soluong * a[i].gia;
	}
}
void in(hanghoa *a,int k){
	printf("\n======================================================================================================");
	printf("\n| %-5s | %-12s | %-30s | %-12s | %-12s | %-12s |","STT","Ma Hang Hoa","Ten Hang Hoa","So Luong","Gia","Gia Tri");
	for(int i=0;i<k;i++){
		printf("\n| %-5d | %-12s | %-30s | %-12d | %-12.2f | %-12.2f |",i+1,a[i].ma,a[i].ten,a[i].soluong,a[i].gia,a[i].giatri);
	}
	printf("\n======================================================================================================");
	
}
void sapxep(hanghoa *a,int k){
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			if(a[i].giatri<a[j].giatri){
				hanghoa temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void loc(hanghoa *a,int k){
	int count=0;
	for(int i=0;i<k;i++){
		if(a[i].soluong<10)	count ++;
	}
	FILE *f=fopen("CANHBAO.txt","w");
		if(f==NULL){
			printf("\nKhong the mo file !");
			exit(1);
		}
	if(count==0)	fprintf(f,"Kho hang an toan");
	else{
		fprintf(f,"\nDanh Sach Hang Hoa co so luong duoi 10 la :");
		fprintf(f,"\n=========================================================");
		fprintf(f,"\n| %-5s | %-12s | %-30s |","STT","Ma Hang Hoa","Ten Hang Hoa");
		for(int i=0;i<k;i++){
			if(a[i].soluong<10)	fprintf(f,"\n| %-5d | %-12s | %-30s |",i+1,a[i].ma,a[i].ten);
		}
		fprintf(f,"\n=========================================================");
	}
	printf("\nDa ghi thanh cong vao file CANHBAO.txt");
	fclose(f);
}
