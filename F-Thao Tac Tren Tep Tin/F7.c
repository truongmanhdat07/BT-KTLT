#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int manv;
	char hoten[50];
	char phong;
	int luong;
} nhanvien;

int docfile(nhanvien a[]);
void indanhsach(nhanvien a[],int n);
void timluongcaonhat(nhanvien a[],int n);
void demnhanvien(nhanvien a[],int n);
void ghifile(nhanvien a[],int n);

int main(){
	nhanvien a[100];	
	int n = docfile(a);
	indanhsach(a,n);
	timluongcaonhat(a,n);
	demnhanvien(a,n);
	ghifile(a,n);
	return 0;
}
int docfile(nhanvien a[]){
	FILE *f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        exit(1);
    }
	int n = 0;
	
	while ( fscanf(f, "%d %s %c %d", &a[n].manv, a[n].hoten, &a[n].phong, &a[n].luong) != EOF ) 	n++;

    fclose(f);
    return n;
}
void indanhsach(nhanvien a[],int n){
	printf("\nDanh sach nhan vien :");
	printf("\n| %-15s | %-30s | %-15s | %-20s |","Ma Nhan Vien","Ho Va Ten","Phong","Luong");
	printf("\n=============================================================================================");
	for(int i = 0;i < n; i++){
		printf("\n| %-15d | %-30s | %-15c | %-20d |", a[i].manv, a[i].hoten, a[i].phong, a[i].luong);
	}
	printf("\n=============================================================================================");
}
void timluongcaonhat(nhanvien a[],int n){
	int max = a[0].luong;
	for(int i = 0;i < n; i++){
		if( a[i].luong>max )	max=a[i].luong;
	}
	
	printf("\n\nDanh sach nhan vien co luong cao nhat la :");
	printf("\n| %-15s | %-30s | %-15s | %-20s |","Ma Nhan Vien","Ho Va Ten","Phong","Luong");
	printf("\n=============================================================================================");
	for(int i = 0;i < n; i++){
		if( a[i].luong == max ){
			printf("\n| %-15d | %-30s | %-15c | %-20d |", a[i].manv, a[i].hoten, a[i].phong, a[i].luong);	
		}
	}
	printf("\n=============================================================================================");
}
void demnhanvien(nhanvien a[],int n){
	int demA =0, demB =0, demC =0;
	for(int i = 0;i < n; i++){
		if( a[i].phong == 'A' )			demA++;
		else if( a[i].phong == 'B' )	demB++;
		else if( a[i].phong == 'C' )	demC++;
	}
	printf("\n\nSo luong nhan vien cua moi phong :");
	printf("\n| %-5s | %-12s |","Phong","So Nhan Vien");
	printf("\n========================");
	printf("\n| %-5s | %-12d |","A", demA);
	printf("\n| %-5s | %-12d |","B", demB);
	printf("\n| %-5s | %-12d |","C", demC);
	printf("\n========================");
}
void ghifile(nhanvien a[],int n){
	FILE *F=fopen("output.txt","w");
	if(F == NULL){
		printf("Khong tao duoc file!");
		exit(1);
	}
	fprintf(F,"Danh sach nhan vien :");
	fprintf(F,"\n| %-15s | %-30s | %-15s | %-20s |","Ma Nhan Vien","Ho Va Ten","Phong","Luong");
	fprintf(F,"\n=============================================================================================");
	for(int i = 0;i < n; i++)
		fprintf(F,"\n| %-15d | %-30s | %-15c | %-20d |", a[i].manv, a[i].hoten, a[i].phong, a[i].luong);
	fprintf(F,"\n=============================================================================================");

	int max = a[0].luong;
	for(int i = 0;i < n; i++)
		if( a[i].luong > max ) max = a[i].luong;

	fprintf(F,"\n\nDanh sach nhan vien co luong cao nhat la :");
	fprintf(F,"\n| %-15s | %-30s | %-15s | %-20s |","Ma Nhan Vien","Ho Va Ten","Phong","Luong");
	fprintf(F,"\n=============================================================================================");
	for(int i = 0;i < n; i++)
		if(a[i].luong == max)
			fprintf(F,"\n| %-15d | %-30s | %-15c | %-20d |", a[i].manv, a[i].hoten, a[i].phong, a[i].luong);
	fprintf(F,"\n=============================================================================================");

	int demA =0, demB =0, demC =0;
	for(int i = 0;i < n; i++){
		if( a[i].phong == 'A' )			demA++;
		else if( a[i].phong == 'B' )	demB++;
		else if( a[i].phong == 'C' )	demC++;
	}
	fprintf(F,"\n\nSo luong nhan vien cua moi phong :");
	fprintf(F,"\n| %-5s | %-12s |","Phong","So Nhan Vien");
	fprintf(F,"\n========================");
	fprintf(F,"\n| %-5s | %-12d |","A", demA);
	fprintf(F,"\n| %-5s | %-12d |","B", demB);
	fprintf(F,"\n| %-5s | %-12d |","C", demC);
	fprintf(F,"\n========================");

	fclose(F);
	printf("\n\nDa ghi ket qua vao file output.txt\n");
}
