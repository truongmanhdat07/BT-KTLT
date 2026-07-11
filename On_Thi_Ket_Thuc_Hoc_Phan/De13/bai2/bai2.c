#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char ma[20];
	char ten[30];
	int soluong;
	float gia;
	float tonggiatri;
}laptop;

void docfile(FILE *f,laptop *a,int k);
void in(laptop *a,int k);
void timmax(laptop *a,int k);
void sapxep(laptop *a,int k);
void xuatfile(laptop *a,int k);

int main(){
	int k;
	FILE *f=fopen("laptop.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file laptop.txt");
		return 1;
	}
	fscanf(f,"%d",&k);
	laptop *a=(laptop *)malloc(k*sizeof(laptop));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	
	docfile(f,a,k);
	printf("\nDanh sach laptop vua doc tu file la :");
	in(a,k);
	timmax(a,k);
	sapxep(a,k);
	xuatfile(a,k);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,laptop *a,int k){
	for(int i=0;i<k;i++){
		fscanf(f,"%s",a[i].ma);
		fscanf(f," %[^\n]",a[i].ten);
		fscanf(f,"%d %f",&a[i].soluong,&a[i].gia);
		a[i].tonggiatri=a[i].soluong * a[i].gia;
	}
	printf("\nDoc thanh cong file laptop.txt");
}
void in(laptop *a,int k){
	printf("\n| %-5s | %-10s | %-30s | %-12s | %-12s | %-15s |","STT","Ma","Ten","So Luong","Gia","Tong Gia Tri");
	for(int i=0;i<k;i++){
		printf("\n| %-5d | %-10s | %-30s | %-12d | %-12.2f | %-15.2f |",i+1,a[i].ma,a[i].ten,a[i].soluong,a[i].gia,a[i].tonggiatri);
	}
}
void timmax(laptop *a,int k){
	float max=a[0].tonggiatri;
	
	for(int i=0;i<k;i++){
		if(a[i].tonggiatri>max)	max=a[i].tonggiatri;
	}
	printf("\nMau may co tong gia tri cao nhat la :");
	printf("\n| %-5s | %-10s | %-30s | %-12s | %-12s | %-15s |","STT","Ma","Ten","So Luong","Gia","Tong Gia Tri");
	for(int i=0;i<k;i++){
		if(a[i].tonggiatri==max)	printf("\n| %-5d | %-10s | %-30s | %-12d | %-12.2f | %-15.2f |",i+1,a[i].ma,a[i].ten,a[i].soluong,a[i].gia,a[i].tonggiatri);
	}
}
void sapxep(laptop *a,int k){
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			if(a[i].gia<a[j].gia){
				laptop temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			else if(a[i].gia==a[j].gia){
				if(a[i].soluong>a[j].soluong){
					laptop temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
	}
}
void xuatfile(laptop *a,int k){
	FILE *F=fopen("kho_laptop.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file kho_laptop.txt");
		exit(1);
	}
	fprintf(F,"\n| %-5s | %-10s | %-30s | %-12s | %-12s | %-15s |","STT","Ma","Ten","So Luong","Gia","Tong Gia Tri");
	for(int i=0;i<k;i++){
		fprintf(F,"\n| %-5d | %-10s | %-30s | %-12d | %-12.2f | %-15.2f |",i+1,a[i].ma,a[i].ten,a[i].soluong,a[i].gia,a[i].tonggiatri);
	}	
	printf("\nDa in thanh cong vao file kho_laptop.txt");
	fclose(F);
}
