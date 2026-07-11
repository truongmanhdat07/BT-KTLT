#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
	int bac;
	float *hs;
}dathuc;

void nhapfile(FILE *f,dathuc dt[]);
void indt(char,dathuc dt[],int);
void gtdt(dathuc dt[]);
void congdt(dathuc dt[]);

int main(){
	char ten[50];
	printf("Nhap ten file : ");
	fgets(ten,sizeof(ten),stdin);
	ten[strcspn(ten,"\n")]='\0';
	
	FILE *f=fopen(ten,"r");
	
	if( f == NULL){
		printf("\nLoi : ko the mo hoac ko tim thay file !\n");
		exit(1);
	}
	dathuc dt[3];
	nhapfile(f,dt);
	printf("\n--------------------------------------------------\n");
	printf("\n\t-----Cac da thuc vua nhap-----\n");
	indt('A',dt,0);
	indt('B',dt,1);
	printf("\n--------------------------------------------------\n");
	gtdt(dt);
	printf("\n--------------------------------------------------\n");
	printf("\n\t---Da thuc moi sau khi cong---\n");
	congdt(dt);
	indt('S',dt,2);
	printf("\n--------------------------------------------------\n");
	for(int i=0;i<3;i++){
		free(dt[i].hs);
	}
	return 0;
}

void nhapfile(FILE *f,dathuc dt[]){
	printf("\nDang nhap du lieu tu file...\n");
	fscanf(f,"%d %d",&dt[0].bac,&dt[1].bac);
	for(int i=0;i<2;i++){
		dt[i].hs=(float *)malloc((dt[i].bac+1)*sizeof(float));
		if(!dt[i].hs){
			printf("Loi : ko the cap phat bo nho!\n");
    		exit(1);
		}
		for(int j=0;j<=dt[i].bac;j++){
			fscanf(f,"%f",dt[i].hs+j);
		}
	}
	printf("\nDa nhap xong du lieu !\n");
	fclose(f);
}

void indt(char tendt,dathuc dt[],int a){
	float tam;
	printf("\nDa thuc %c(X):\t",tendt);
	for (int j=dt[a].bac;j>=0;j--){
		if(*(dt[a].hs+j)!=0){
			
			if      (*(dt[a].hs+j)<0)  tam = - *(dt[a].hs+j);
		    else                       tam = *(dt[a].hs+j);
		    
		    if (j == dt[a].bac && *(dt[a].hs+j) < 0)   printf(" - ");

		    if      (j==0)            printf("%.2f",tam);
            else if (j==1)            printf("%.2fX",tam);
            else                      printf("%.2fX^%d",tam,j);
           for(int m=j-1;m>=0;m--){
	          if       (*(dt[a].hs+m) > 0){
	              printf(" + ");
		          break;
	           }
	           else if (*(dt[a].hs+m) < 0){
		          printf(" - ");
		          break;
	           }
		   }	
        }
	}
	printf("\t\n");
}

void gtdt(dathuc dt[]){
	float k,r,s=0;
	printf("\nNhap gia tri cua k va r : ");     scanf("%f %f",&k,&r);
	for(int i=0;i<2;i++){
		if(i==0){
			for(int j=0;j<=dt[i].bac;j++)	s+=*(dt[i].hs+j)*pow(k,j);	
		}
		else{
			for(int j=0;j<=dt[i].bac;j++)	s+=*(dt[i].hs+j)*pow(r,j);
		}
	}
	printf("\n -> Gia tri cua S voi A(k) va B(r) la : %.2f\n",s);
}

void congdt(dathuc dt[]){
	if (dt[0].bac>dt[1].bac)   dt[2].bac=dt[0].bac;
	else                       dt[2].bac=dt[1].bac;
	dt[2].hs=(float *)calloc((dt[2].bac+1),sizeof(float));
	if(!dt[2].hs){
		printf("Loi : ko the cap phat bo nho!\n");
    	exit(1);
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<=dt[2].bac;j++){
			if(j<=dt[i].bac)  *(dt[2].hs+j)+=*(dt[i].hs+j);
		}
	}
}
