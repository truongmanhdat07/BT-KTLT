#ifndef MATRAN_H
#define MATRAN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** doc_ma_tran (const char *tenTep, int *soHang, int *soCot);
void in_ma_tran (int **maTran, int soHang, int soCot);
void tich_phan_tu_le (int **maTran, int soHang, int soCot);
void tim_chan_lon_nhat (int **maTran, int soHang, int soCot);
void tong_chia_het_7_moi_hang (int **maTran, int soHang, int soCot);
void giai_phong_ma_tran (int **maTran, int soHang);

#endif