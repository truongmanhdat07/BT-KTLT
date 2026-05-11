#include<stdio.h>
#include<math.h>
void nhapdathuc(float [],int);
void indathuc(float [],int);
float tinhdathuc(float [],int,float);
int tong2dathuc(float [],int,float [],int,float []);
int main(){
	int m;
	printf("Vui long nhap bac cua da thuc :");	scanf("%d",&m);
	float a[m+1];
	nhapdathuc(a,m);
	indathuc(a,m);
	float d;
	printf("Vui long nhap d :");	scanf("%f",&d);
	printf("Gia tri cua da thuc tai diem vua nhap la :%.2f",tinhdathuc(a,m,d) );
	int n;
	printf("\nVui long nhap bac cua da thuc P :");	scanf("%d",&m);
	float p[m+1];
	printf("\nNhap da thuc P :\n");
	nhapdathuc(p,m);
	printf("Da thuc P :");
	indathuc(p,m);
	printf("\nVui long nhap bac cua da thuc Q :");	scanf("%d",&n);
	float q[n+1];
	printf("\nNhap da thuc Q :\n");
	nhapdathuc(q,n);
	printf("Da thuc Q :");
	indathuc(q,n);
	int bactong2dathuc=(m>n) ? m : n;
	float r[bactong2dathuc+1];
	int k=tong2dathuc(p,m,q,n,r);
	printf("\n--- TONG HAI DA THUC ---\n");
    printf("R(x) = P(x) + Q(x): "); 
    indathuc(r,k);
    float x1,x2;
    printf("\nVui long nhap x1 de tinh P(x1) :");	scanf("%f",&x1);
    printf("Vui long nhap x2 de tinh Q(x2) :");		scanf("%f",&x2);
    printf("Tong cua P(x1) + Q(x2) la :%.2f",tinhdathuc(p,m,x1) + tinhdathuc(q,n,x2) );
    return 0;
}
void nhapdathuc(float a[],int m){
	for(int i=m;i>=0;i--){
		printf("Vui long nhap he so bac %d :",i);	scanf("%f",a+i);
	}
}
void indathuc(float a[], int m){
    int count = 0; 
    for(int i = m; i >= 0; i--){
    	//dau
        if(a[i] == 0) continue; 
        if(count == 0){
            if(a[i] < 0) 	printf("-");
        } 
		else {
            if(a[i] > 0)	printf(" + ");
            else 			printf(" - ");
        }
        //he so
        float val = (a[i] > 0) ? a[i] : -a[i];
        if(val != 1 || i == 0)	printf("%.2f", val);
        if(i > 1) 				printf("x^%d", i);
        else if(i == 1) 		printf("x");
        count++; 
    }
    if(count == 0) printf("0");
    printf("\n");
}
float tinhdathuc(float a[],int m,float x){
	float kq=0;
	for(int i=0;i<=m;i++){
		kq+=*(a+i) * pow(x,i);
	}
	return kq;
}
int tong2dathuc(float p[],int m,float q[],int n,float r[]){
	int k=(m>n) ? m : n;
	for(int i=0;i<=k;i++){
		float hesop=(i<=m) ? p[i] : 0;
		float hesoq=(i<=n) ? q[i] : 0;
		r[i]=hesop+hesoq;
	}
	while(k>0 && r[k]==0){
		k--;
	}
	return k;
}
