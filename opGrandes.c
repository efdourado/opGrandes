#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remZeros (char r []) {
    int i, j = 0, encontrou = 0, tam = strlen (r);

    for (i =0; i < tam; i ++) {
        if (r [i] != '0') {
            encontrou = 1;
            break;
    } }

    if (encontrou) {
        for (; i < tam; i ++) {
            r [j ++] = r [i];
        }
        r [j] = '\0';
    } else {
        r [0] = '\0';
    }
}

void soma (char a [], char b [], char resposta []) {
    remZeros (a);
    remZeros (b);
    
    int tam_a = strlen (a), tam_b = strlen (b), tam_m = (tam_a > tam_b) ? tam_a : tam_b, c = 0;

    for (int i = 0; i < tam_m; i ++) {
        int da = (i < tam_a) ? a[tam_a - i - 1] - '0' : 0, db = (i < tam_b) ? b[tam_b - i - 1] - '0' : 0;

        int s = da + db + c;
        c = s / 10;
        resposta [tam_m - i - 1] = (s % 10) + '0';
    }
    if (c > 0) {
        for (int i = tam_m; i > 0; i --) {
            resposta [i] = resposta [i - 1];
        }
        resposta [0] = c + '0';
        tam_m ++;
    }
    resposta [tam_m] = '\0';
}

void subt (char a [], char b [], char resposta []) {
    remZeros (a);
    remZeros (b);

    int tam_a = strlen (a), tam_b = strlen (b);

    if (tam_a == tam_b && strcmp (a, b) == 0) {
        resposta [0] = '0';
        resposta [1] = '\0';
        return;
    }

    int neg =0;
    if (tam_a < tam_b || (tam_a == tam_b && strcmp (a, b) <0)) neg =1;

    int tam_m = (tam_a > tam_b) ? tam_a : tam_b, c =0, s =0;

    for (int i =0; i < tam_m; i ++) {

        int da = (i < tam_a) ? a[tam_a - i - 1] - '0' : 0, db = (i < tam_b) ? b[tam_b - i - 1] - '0' : 0;

        if (neg) {
            int s = db - da - c;

            if (db - c < da) c =1; else c =0;
            if (s <0) {
                s +=10;
                c =1;
            }

            resposta [tam_m -i -1] = s + '0';
        } else {
            int s = da - db - c;

            if (da - c < db) c =1; else c =0;
            if (s <0) {
                s +=10;
                c =1;
            }

            resposta [tam_m -i -1] = s + '0';
        }
        remZeros (resposta);
        resposta [tam_m] = '\0';      
    }

    if (neg) {

        int tam_r = strlen (resposta);
        tam_r ++;

        for (int i = tam_r; i > 0; i --) {
            resposta [i] = resposta [i -1];
        }
        resposta [0] = '-';
} }

void mtpc (char a [], char b [], char resposta []) {
    
    remZeros (a);
    remZeros (b);

    int tam_a = strlen (a), tam_b = strlen (b), tam_m = tam_a + tam_b, rt [tam_m];

    for (int i =0; i < tam_m; i ++) rt[i] =0;

    for (int i =0; i < tam_a; i ++) {
        int c =0;
        int da = a [tam_a -i -1] - '0';

        for (int j =0; j < tam_b; j ++) {
            int db = b [tam_b -j -1] - '0', p = da * db + c + rt [i + j];

            c = p/10;
            rt [i + j] = p % 10;
        }
        rt [i + tam_b] += c;
    }

    int i = tam_m - 1;

    while (i >=0 && rt [i] ==0) {
        i --;
    }
    if (i == -1) {
        resposta [0] = '0';
        resposta [1] = '\0';
    } else {
        int j =0;

        while (i >= 0) {
            resposta [j ++] = rt [i] + '0';
            i --;
        }
        resposta [j] = '\0';
} }

int main () {
    int n, c;
    scanf ("%d", &n);
    
    char a [501], b [501], resposta [1002], respostas [1002][1002];

    for (int i =0; i < n; i ++) {
        scanf (" %s %s", a, b);
        scanf (" %d", &c);

        if (c ==1) {
            soma (a, b, resposta);
            remZeros (resposta);
            strcpy (respostas [i], resposta);
        } else if (c ==2) {
            subt (a, b, resposta);
            strcpy (respostas [i], resposta);
        } else if (c ==3) {
            mtpc (a, b, resposta);
            strcpy (respostas [i], resposta);
    } }

    for (int i =0; i < n; i ++) {
        printf ("%s\n", respostas [i]);
    }

    return 0;
}