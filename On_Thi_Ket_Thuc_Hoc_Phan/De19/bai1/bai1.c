#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void docfile(FILE *f,int **a,int m,int n);
void in(int **a,int m,int n);
int snt(int k);
void songuyento(int **a,int m,int n);
void inmax(int **a,int m,int n);
void sapxep(int *a,int n);
void sapxepcot(int **a,int m,int n);

int main(){
	int m,n;
	FILE *f=fopen("bando.txt","r");
	if(f==NULL){
		printf("\nKhong the mo file bando.txt");
		return 1;
	}
	
	fscanf(f,"%d %d",&m,&n);
	int **a=(int**)malloc(m*sizeof(int*));
	if(a==NULL){
		printf("\nKhong the cap phat bo nho");
		return 1;
	}
	for(int i=0;i<m;i++){
		a[i]=(int*)malloc(n*sizeof(int));
		if(a[i]==NULL){
			printf("\nKhong the cap phat bo nho");
			return 1;
		}
	}
	
	docfile(f,a,m,n);
	printf("\nMa tran vua doc tu file bando.txt la :\n");
	in(a,m,n);
	songuyento(a,m,n);
	inmax(a,m,n);
	sapxepcot(a,m,n);
	printf("\nMa tran sau khi sap xep la :\n");
	in(a,m,n);
	
	for(int i=0;i<m;i++) free(a[i]);
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
}
void in(int **a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
int snt(int k){
	if(k<2)	return 0;
	for(int i=2;i<=sqrt(k);i++){
		if(k%i==0)	return 0 ;
	}
	return 1;
}
void songuyento(int **a,int m,int n){
	if(m!=n){
		printf("\nDay khong phai ma tran vuong");
		return;
	}
	int dem=0,tong=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if( i==j || i+j==n-1){
				if(snt(a[i][j])==1){
					dem++;
					tong+=a[i][j];
				}		
			}
		}
	}
	if(dem==0)	printf("\nKhong co so nguyen to nao thoa man");
	else		printf("\nTrung binh cong cac so nguyen to thoa man la :%.2f ",(float)tong/dem);
}
void inmax(int **a,int m,int n){
	int max=a[0][0];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]>max)	max=a[i][j];
		}
	}
	printf("\nDiem co gia tri nang luong lon nhat = %d la  :",max);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==max)	printf("a[%d][%d]  ",i,j);
		}
	}
}
void sapxep(int *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]<a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void sapxepcot(int **a,int m,int n){
	int *b = (int *)malloc(m * sizeof(int));
	if(b==NULL){
		printf("\nKhong the cap phat bo nho");
		exit(1);
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<m;i++){
			b[i]=a[i][j];
		}
		sapxep(b,m);
		for(int i=0;i<m;i++){
			a[i][j]=b[i];
		}
	}
	
	free(b);
}
