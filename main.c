#include "SSP.h"

int main() {
    FILE *fichierOper;
    FILE *fichierPreced;
    FILE *fichierTpsCycle;
    char* fileExclu;
    G* grapheExclu;
    fichierOper = fopen("operations.txt", "r");
    fichierPreced = fopen("precedences.txt", "r");
    fichierTpsCycle =  fopen("temps_cycle.txt", "r");
    fileExclu="exclusions.txt";
    menu(fichierOper, fichierPreced, fichierTpsCycle, fileExclu);
    return 0;

/*    char *fileExclu;
     G* grapheExclu;

     fileExclu="exclusion.txt";
     grapheExclu=main_ex(fileExclu);
     menu(fileExclu);
     */
}
