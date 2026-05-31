#ifndef F6_H
#define F6_H

#include <stdio.h>

typedef struct {
	int bac;
	float *hs;
} dathuc;

void nhapfile(FILE *f, dathuc dt[]);
void indt(char tendt, dathuc dt[], int a);
void gtdt(dathuc dt[]);
void congdt(dathuc dt[]);

#endif
