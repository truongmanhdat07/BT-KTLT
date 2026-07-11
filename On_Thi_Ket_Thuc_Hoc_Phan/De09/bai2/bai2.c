#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char masv[12];
	char ten[30];
	float diemly,diemtoan,diemhoa;
	float diemtb;
}sinhvien;

void docfile(FILE *f,sinhvien *a,int k);
void in(sinhvien *a,int k);
void sapxep(sinhvien *a,int k);
void timmax(sinhvien *a,int k);
void xuatfile(sinhvien *a,int k);

int main(){
	int k;
	FILE *f=fopen("sinhvien.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file sinhvien.txt");
		return 1;
	}
	fscanf(f,"%d",&k);
	sinhvien *a=(sinhvien*)malloc(k*sizeof(sinhvien));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho!");
		return 1;
	}
	
	docfile(f,a,k);
	in(a,k);
	sapxep(a,k);
	timmax(a,k);
	xuatfile(a,k);
	
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,sinhvien *a,int k){
	for(int i=0;i<k;i++){
		fscanf(f,"%s",a[i].masv);
		fscanf(f," %[^\n]",a[i].ten);
		fscanf(f,"%f %f %f",&a[i].diemtoan,&a[i].diemly,&a[i].diemhoa);
		a[i].diemtb= (a[i].diemtoan + a[i].diemly + a[i].diemhoa)/3 ;

	}
	printf("\nDa doc thanh cong file sinhvien.txt");
}
void in(sinhvien *a,int k){
	printf("\n| %-5s | %-12s | %-30s | %-12s | %-12s | %-12s | %-12s |","STT","Ma Sinh Vien","Ho Va Ten","Diem Toan","Diem Ly","Diem Hoa","Diem TB");
	for(int i=0;i<k;i++){
		printf("\n| %-5d | %-12s | %-30s | %-12.2f | %-12.2f | %-12.2f | %-12.2f |",i+1,a[i].masv,a[i].ten,a[i].diemtoan,a[i].diemly,a[i].diemhoa,a[i].diemtb);
	}
}
void sapxep(sinhvien *a,int k){
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			if(a[i].diemtb<a[j].diemtb){
				sinhvien temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void timmax(sinhvien *a,int k){
	float max=a[0].diemtb;
	printf("\nDanh sach sinh vien co diem trung binh cao nhat la :");
	printf("\n| %-5s | %-12s | %-30s | %-12s | %-12s | %-12s | %-12s |","STT","Ma Sinh Vien","Ho Va Ten","Diem Toan","Diem Ly","Diem Hoa","Diem TB");
	for(int i=0;i<k;i++){
		if(a[i].diemtb==max){
			printf("\n| %-5d | %-12s | %-30s | %-12.2f | %-12.2f | %-12.2f | %-12.2f |",i+1,a[i].masv,a[i].ten,a[i].diemtoan,a[i].diemly,a[i].diemhoa,a[i].diemtb);
		}
	}
}
void xuatfile(sinhvien *a,int k){
	FILE *F=fopen("ketqua_sv.txt","w");
	if(F==NULL){
		printf("\nKhong the mo file ketqua_sv.txt");
		exit(1);
	}
	fprintf(F,"Danh Sach Sinh Vien ");
	fprintf(F,"\n| %-5s | %-12s | %-30s | %-12s | %-12s | %-12s | %-12s |","STT","Ma Sinh Vien","Ho Va Ten","Diem Toan","Diem Ly","Diem Hoa","Diem TB");
	for(int i=0;i<k;i++){
		fprintf(F,"\n| %-5d | %-12s | %-30s | %-12.2f | %-12.2f | %-12.2f | %-12.2f |",i+1,a[i].masv,a[i].ten,a[i].diemtoan,a[i].diemly,a[i].diemhoa,a[i].diemtb);
	}	
	printf("\nDa ghi thanh cong vao file ketqua_sv.txt");
	fclose(F);
}
