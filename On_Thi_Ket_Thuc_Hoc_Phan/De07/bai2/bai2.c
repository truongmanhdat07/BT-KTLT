//nhap 1 danh sach nhan vien tu tep gom : manv,ten,luong,phong
//doc va in ra man hinh
// dem so nhan vien tung phong
//sap xep theo luong giam dan
// tim luong max,min
//luu danh sach sau khi sap xep vao file output.txt

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int ma;
	char hoten[50];
	float luong;
	char phong[3];
}nhanvien;

int docfile(nhanvien *a);
void in(nhanvien *a,int n);
void dem(nhanvien *a,int n);
void sapxep(nhanvien *a,int n);
void timminmax(nhanvien *a,int n);
void xuatfile(nhanvien *a,int n);

int main(){
	nhanvien a[100];
	int n=docfile(a);
	in(a,n);
	dem(a,n);
	sapxep(a,n);
	printf("\nDanh sach nhan vien sau khi sap xep theo luong giam dan la :");
	in(a,n);
	timminmax(a,n);
	xuatfile(a,n);
	
	return 0;
}

int docfile(nhanvien *a){
	FILE *f=fopen("input.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file!");
		exit(1);
	}
	int sonhanvien=0;
//	while(1>0){
//		if(fscanf(f,"%d",&a[sonhanvien].ma) != 1)		break;
//		fgetc(f);
//		
//		if(fgets(line,sizeof(line),f) == NULL)			break;
//		line[strcspn(line,"\n")]='\0';
//		strcpy(a[sonhanvien].hoten,line);
//		
//		if(fgets(line,sizeof(line),f) == NULL)			break;
//		line[strcspn(line,"\n")]='\0';
//		strcpy(a[sonhanvien].phong,line);
//		
//		if(fscanf(f,"%f",&a[sonhanvien].luong) !=1)		break;
//		fgetc(f);
//		sonhanvien++;
//	}
	//cach 2
	while(1>0){
		if(fscanf(f,"%d",&a[sonhanvien].ma) != 1)			break;
		
		if(fscanf(f," %[^\n]",a[sonhanvien].hoten) != 1)	break;
		
		if(fscanf(f,"%s",a[sonhanvien].phong) != 1)			break;

		if(fscanf(f,"%f",&a[sonhanvien].luong) !=1)			break;

		sonhanvien++;
	}
	fclose(f);
	return sonhanvien;
}
void in(nhanvien *a,int n){
	printf("\n=============================== Danh Sach Nhan Vien ===============================");
	printf("\n| %-5s | %-12s | %-30s | %-10s | %-10s |","STT","Ma Nhan Vien","Ten Nhan Vien","Phong","Luong");
	for(int i=0;i<n;i++){
		printf("\n| %-5d | %-12d | %-30s | %-10s | %-10.2f |",i+1,a[i].ma,a[i].hoten,a[i].phong,a[i].luong);
	}
	printf("\n===================================================================================");
}
void dem(nhanvien *a,int n){
	int demA=0,demB=0,demC=0;
	for(int i=0;i<n;i++){
		if(strcmp(a[i].phong,"A")==0)	demA++;
		if(strcmp(a[i].phong,"B")==0)	demB++;
		if(strcmp(a[i].phong,"C")==0)	demC++;
	}
	printf("\nSo nhan vien theo cua tung phong la :");
	printf("\n| %-5s | %-10s | %-15s |","STT","Phong","So Nhan Vien");
	printf("\n| %-5d | %-10s | %-15d |",1,"A",demA);
	printf("\n| %-5d | %-10s | %-15d |",2,"B",demB);
	printf("\n| %-5d | %-10s | %-15d |",3,"C",demC);
}
void sapxep(nhanvien *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].luong<a[j].luong){
				nhanvien temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void timminmax(nhanvien *a,int n){				//co the dung for in ra a[0] va a[n-1] luon 
	float max=a[0].luong;
	float min=a[0].luong;
	for(int i=0;i<n;i++){
		if(a[i].luong>max)	max=a[i].luong;
		if(a[i].luong<min)	min=a[i].luong;
	}
	printf("\nMuc luong cao nhat la :%.2f",max);
	printf("\nMuc luong thap nhat la :%.2f",min);
}
void xuatfile(nhanvien *a,int n){
	FILE *f=fopen("output.txt","w");
	if(f==NULL){
		printf("\nKhong the mo file!");
		exit(1);
	}
	
	
	fprintf(f,"\n=============================== Danh Sach Nhan Vien ===============================");
	fprintf(f,"\n| %-5s | %-12s | %-30s | %-10s | %-10s |","STT","Ma Nhan Vien","Ten Nhan Vien","Phong","Luong");
	for(int i=0;i<n;i++){
		fprintf(f,"\n| %-5d | %-12d | %-30s | %-10s | %-10.2f |",i+1,a[i].ma,a[i].hoten,a[i].phong,a[i].luong);
	}
	fprintf(f,"\n===================================================================================");
	printf("\nDa in Danh Sach Nhan Vien sau khi sap xep thanh cong vao file output.txt");
	
	fclose(f);
}
