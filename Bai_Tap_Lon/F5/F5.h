#ifndef TOADO_H
#define TOADO_H

typedef struct {
    float x;
    float y;
    float z;
} toado;


toado *nhapday(int *n);
void xuatdayrafilevanban(toado *diem, int n, char *tenfile);
toado *nhapdaytufilevanban(int *n, char *tenfile);
void xuatdayrafilenhiphan(toado *diem, int n, char *tenfile);
toado *nhapdaytufilenhiphan(int *n, char *tenfile);
void inday(toado *diem, int n);

#endif
