#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "E3.h"

Node* taoNode(float hs, int bac) {
    Node* Nodemoi = (Node*)malloc(sizeof(Node));
    if (Nodemoi == NULL) {
        printf("Loi : ko the cap phat bo nho!\n");
        exit(1);
    }
    Nodemoi->hs   = hs;
    Nodemoi->bac  = bac;
    Nodemoi->next = NULL;
    return Nodemoi;
}

void nhapdt(Node *dt[], int a) {
    int bac;
    do {
        printf("\n\tBac da thuc %d  = ", a + 1);
        scanf("%d", &bac);
        if (bac < 0) printf("\nLoi : Bac cua da thuc phai lon hon hoac bang 0! Vui long nhap lai!\n");
    } while (bac < 0);

    Node *dau  = NULL;
    Node *duoi = NULL;
    for (int j = bac; j >= 0; j--) {
        float hstam;
        if      (j == 0) { printf("\n\tHS tu do = ");       scanf("%f", &hstam); }
        else if (j == 1) { printf("\n\tHS cua X = ");       scanf("%f", &hstam); }
        else             { printf("\n\tHS cua X^%d = ", j); scanf("%f", &hstam); }
        if (hstam != 0) {
            Node *Nodemoi = taoNode(hstam, j);
            if (dau == NULL) {
                dau  = Nodemoi;
                duoi = Nodemoi;
            } else {
                duoi->next = Nodemoi;
                duoi = Nodemoi;
            }
        }
    }
    dt[a] = dau;
}

void indt(Node *dt[], int a) {
    float hstam;
    Node *tam = dt[a];
    if (tam == NULL) {
        printf("0\n");
        return;
    }
    int co = 1;
    while (tam != NULL) {
        hstam = (tam->hs < 0) ? -tam->hs : tam->hs;

        if (co == 1) {
            if (tam->hs < 0) printf(" - ");
            co = 0;
        } else {
            if      (tam->hs > 0) printf(" + ");
            else if (tam->hs < 0) printf(" - ");
        }

        if      (tam->bac == 0) printf("%.2f",        hstam);
        else if (tam->bac == 1) printf("%.2fX",       hstam);
        else                    printf("%.2fX^%d",    hstam, tam->bac);
        tam = tam->next;
    }
    printf("\n");
}

float tinhgt(Node *dt[], int a) {
    int b;
    float x, gt = 0;
    do {
        printf("\nChon da thuc muon tinh : ");
        scanf("%d", &b);
        if (1 > b || b > a) printf("\nLoi : Da thuc ko ton tai hay chon lai!\n");
    } while (1 > b || b > a);
    printf("\nNhap gia tri cua x : ");
    scanf("%f", &x);

    Node *tam = dt[b - 1];
    if (tam == NULL) return 0;
    while (tam != NULL) {
        gt += tam->hs * pow(x, tam->bac);
        tam = tam->next;
    }
    printf("\n-->Gia tri cua da thuc %d voi x = %.2f la : ", b, x);
    return gt;
}

float tinhdh(Node *dt[], int a) {
    int b;
    float x, gt = 0;
    do {
        printf("\nChon da thuc muon tinh : ");
        scanf("%d", &b);
        if (1 > b || b > a) printf("\nLoi : Da thuc ko ton tai hay chon lai!\n");
    } while (1 > b || b > a);
    printf("\nNhap gia tri cua x : ");
    scanf("%f", &x);

    Node *tam = dt[b - 1];
    if (tam == NULL) return 0;
    while (tam != NULL) {
        if (tam->bac > 0) gt += tam->hs * tam->bac * pow(x, tam->bac - 1);
        tam = tam->next;
    }
    printf("\n-->Gia tri cua da thuc %d sau khi dao ham voi x = %.2f la : ", b, x);
    return gt;
}

void congdt(Node *dt[], int a) {
    int b[2];
    do {
        printf("\nChon 2 da thuc muon cong : ");
        scanf("%d %d", &b[0], &b[1]);
        if (b[0] == b[1])                           printf("\nLoi : Khong chon 2 da thuc giong nhau ! Vui long chon lai!\n");
        if (1 > b[0] || b[0] > a || 1 > b[1] || b[1] > a) printf("\nLoi : Da thuc ko ton tai ! Vui long chon lai!\n");
    } while (1 > b[0] || b[0] > a || 1 > b[1] || b[1] > a || b[0] == b[1]);

    Node *p1 = dt[b[0] - 1];
    Node *p2 = dt[b[1] - 1];
    printf("\n\t---Da thuc moi sau khi cong---\n\n");

    Node *dau  = NULL;
    Node *duoi = NULL;
    while (p1 != NULL || p2 != NULL) {
        float hstam = 0;
        int   bactam = 0;
        if (p1 != NULL && p2 != NULL) {
            if      (p1->bac == p2->bac) { hstam = p1->hs + p2->hs; bactam = p1->bac; p1 = p1->next; p2 = p2->next; }
            else if (p1->bac >  p2->bac) { hstam = p1->hs;           bactam = p1->bac; p1 = p1->next; }
            else                         { hstam = p2->hs;           bactam = p2->bac; p2 = p2->next; }
        } else if (p1 != NULL) {
            hstam = p1->hs; bactam = p1->bac; p1 = p1->next;
        } else {
            hstam = p2->hs; bactam = p2->bac; p2 = p2->next;
        }
        if (hstam != 0) {
            Node *Nodemoi = taoNode(hstam, bactam);
            if (dau == NULL) { dau = Nodemoi; duoi = Nodemoi; }
            else             { duoi->next = Nodemoi; duoi = Nodemoi; }
        }
    }
    dt[a] = dau;
}

void giaiphong(Node *dt[], int a) {
    while (dt[a]) {
        Node *tam = dt[a];
        dt[a] = dt[a]->next;
        free(tam);
    }
}
