/*Tache 2 realisée par SKAKRI BOUCHRA 232331513410 G3*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define k 100
#define min 1000
#define max 1000000

int estPremier(int n) {
    if (n < 2) return 0;

    for (int d = 2; d <= n / d; d++) {
        if (n % d == 0)
            return 0;
    }

    return 1;
}

int main(void) {
    srand((unsigned int)time(NULL));

    FILE *f = fopen("D:\\complixite\\prime10\\primes10.txt", "r");

    if (f == NULL) {
        perror("Erreur ouverture primes10.txt");
        return 1;
    }

    int table[k];
    int x;
    long long i = 0;

    while (fscanf(f, "%d", &x) == 1) {
        if (x >= min && x <= max && estPremier(x)) {
            i++;

            if (i <= k) {
                table[i - 1] = x;
            } else {
                long long j = (long long)(
                    ((double)rand() / ((double)RAND_MAX + 1.0)) * i
                );

                if (j < k)
                    table[j] = x;
            }
        }
    }

    fclose(f);

    if (i < k) {
        printf("Erreur : moins de 100 nombres premiers valides.\n");
        return 1;
    }

    FILE *out = fopen("D:\\complixite\\prime10\\Tp_Complexite_2026\\test-1.txt", "w");

    if (out == NULL) {
        perror("Erreur creation Test-1.txt");
        return 1;
    }

    for (int j = 0; j < k; j++)
        fprintf(out, "%d\n", table[j]);

    fclose(out);

    printf("100 nombres premiers enregistres dans test-1.txt\n");
    return 0;
}
