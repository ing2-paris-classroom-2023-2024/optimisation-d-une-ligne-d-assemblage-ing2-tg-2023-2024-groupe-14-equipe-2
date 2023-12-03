#include "SSP.h"

int main() {
    FILE *fichier;
    FILE *fichier_2;
    FILE *fichier_3;
    fichier = fopen("operations.txt", "r");
    fichier_2 = fopen("precedences.txt", "r");
    fichier_3 =  fopen("temps_cycle.txt", "r");
    mainEm(fichier,fichier_2,fichier_3);

/*    char *fileExclu;
     G* grapheExclu;

     fileExclu="exclusion.txt";
     grapheExclu=main_ex(fileExclu);
     menu(fileExclu);
     return 0;*/
}
