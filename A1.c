
#include <stdio.h>
#include <time.h>

int main() {
    long long N, i; 
    int premier = 1;
    //clock_t debut, fin; : stocke les valeurs de l'horloge du processeur au début et à la fin.
    clock_t debut, fin;
    double T;

    printf("Donner un nombre entier : ");  //1U
    scanf("%lld", &N);                     //1U
    //debut = clock(); : commence la mesure.
    debut = clock();                        //1U

    if (N < 2) {   // 1U
        premier = 0;  //1U 
    } else {
        for (i = 2; i < N; i++) {  //3U (nombre d'itération : N-2)
            if (N % i == 0) {    //2U
                premier = 0;     //1U
                break;    //1U
            }
        }
    }
    //fin = clock(); : termine la mesure.
    fin = clock();  //1U
    //CLOCKS_PER_SEC : permet de convertir la différence en secondes.
    T = (double)(fin - debut) / CLOCKS_PER_SEC;  //3U

    if (premier == 1) {  //1U
        printf("%lld est premier.\n", N); //1U
    } else {
        printf("%lld n'est pas premier.\n", N); //1U
    }

    printf("Temps d'execution : %.6f secondes\n", T);  //1U

    return 0;  //1U
    // la complexité temporelle au pire cas --> O(N)
}
