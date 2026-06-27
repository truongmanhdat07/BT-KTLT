#include<stdio.h>
#include<stdlib.h>

void docfile(FILE *f,int **a,int m,int n);
void in(int **a,int m,int n);
void hangmax(int **a,int m,int n);
int dem(int **a,int m,int n);

int main(){
	int m,n;
	FILE *f=fopen("bando.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file bando.txt");
		return 1;
	}
	fscanf(f,"%d %d",&m,&n);
	
	int **a=(int **)malloc(m*sizeof(int *));
	if(a==NULL){
		printf("\nKhong the cap phat dong");
		return 1;
	}
	for(int i=0;i<m;i++){
		a[i]=(int *)malloc(n*sizeof(int));
		if(a[i]==NULL){
			printf("\nKhong the cap phat dong");
			return 1;
		}
	}
	
	docfile(f,a,m,n);
	printf("\nMa tran vua doc tu file bando.txt la :\n");
	in(a,m,n);
	hangmax(a,m,n);
	printf("\nSo o co tai nguyen lon hon X la :%d",dem(a,m,n));
	
	for(int i=0;i<m;i++)	free(a[i]);
	free(a);
	fclose(f);
	return 0;
}
void docfile(FILE *f,int **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fscanf(f,"%d",&a[i][j]);
		}
	}
	printf("\nDoc thanh cong file bando.txt");
}
void in(int **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
void hangmax(int **a,int m,int n){
	int max=-1;
	int vitri=0;
	for(int i=0;i<m;i++){
		int tong=0;
		for(int j=0;j<n;j++){
			tong+=a[i][j];
		}
		if(tong>max){
			max=tong;
			vitri=i;
		}
	}
	printf("\nHang chua nhieu tai nguyen nhat la hang %d :%d",vitri+1,max);
}
int dem(int **a,int m,int n){
	int x;
	printf("\nVui long nhap X :");	scanf("%d",&x);
	int dem=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(x<a[i][j])	dem++;
		}
	}
	return dem;
}
