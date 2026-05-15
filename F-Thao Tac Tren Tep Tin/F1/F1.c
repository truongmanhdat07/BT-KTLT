#include<stdio.h>

int main(){
	char tenfile[100];
	printf("Vui long nhap ten file can doc :");
	fflush(stdin);
	gets(tenfile);
	FILE *f=fopen(tenfile,"r");
	if(f==NULL){
		printf("\nKhong the doc duoc file !");
		return 1;
	}
	printf("\nNoi dung cua file %s la :\n\n",tenfile);
	char temp[1000];
	while( fgets ( temp , sizeof(temp) , f )!=NULL ){
		printf("%s",temp);
	}
	printf("\n\nDa doc het file %s",tenfile);
	fclose(f);
	return 0;
}
