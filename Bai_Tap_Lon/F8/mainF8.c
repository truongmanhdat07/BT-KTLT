#include <stdio.h>
#include "F8.h"

int main(){
    int soHang=0, soCot=0;
    int **maTran = NULL;
    const char *tenTep = "input.txt";
    
    maTran = doc_ma_tran(tenTep, &soHang, &soCot);
    if(maTran == NULL){
        return 1;
    }
    in_ma_tran(maTran, soHang, soCot);
    tich_phan_tu_le(maTran, soHang, soCot);
    tim_chan_lon_nhat(maTran, soHang, soCot);
    tong_chia_het_7_moi_hang(maTran, soHang, soCot);
    giai_phong_ma_tran(maTran, soHang);

    return 0;
}

