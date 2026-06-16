#include <stdio.h>
#include <stdlib.h>
#include "F5.h"

int main() {
    int sodiem;
    
    printf("--- 1. nhap tu ban phim ---\n");
    toado *mangdiem = nhapday(&sodiem);

    if (mangdiem != NULL) {
        printf("\n--- 2. xuat ra file van ban ---\n");
        xuatdayrafilevanban(mangdiem, sodiem, "toado.txt");

        printf("\n--- 4. xuat ra file nhi phan ---\n");
        xuatdayrafilenhiphan(mangdiem, sodiem, "toado.bin");
        
        free(mangdiem);
    }
    
    printf("\n--- 3. nhap lai tu file van ban de kiem tra ---\n");
    int sodiemvanban = 0;
    toado *mangdiemvanban = nhapdaytufilevanban(&sodiemvanban, "toado.txt");
    inday(mangdiemvanban, sodiemvanban);
    if (mangdiemvanban != NULL) free(mangdiemvanban);

    printf("\n--- 5. nhap lai tu file nhi phan de kiem tra ---\n");
    int sodiemnhiphan = 0;
    toado *mangdiemnhiphan = nhapdaytufilenhiphan(&sodiemnhiphan, "toado.bin");
    inday(mangdiemnhiphan, sodiemnhiphan);
    if (mangdiemnhiphan != NULL) free(mangdiemnhiphan);
    
    return 0;
}
