#ifndef MATRAN_H
#define MATRAN_H

float **capphatmatran(int sohang, int socot);
void giaiphongbonho(float **matran, int sohang);
float **nhapmatran(int *sohang, int *socot);
float **nhapmatrantufilevanban(int *sohang, int *socot, char *tenfile);
void xuatmatranrafilevanban(float **matran, int sohang, int socot, char *tenfile);
void xuatmatranrafilenhiphan(float **matran, int sohang, int socot, char *tenfile);
float **nhapmatrantufilenhiphan(int *sohang, int *socot, char *tenfile);
void inmatran(float **matran, int sohang, int socot);

#endif
