#include "SSP.h"

int main() {
    char *fileExclu;
     G* grapheExclu;

     fileExclu="exclusion.txt";
     grapheExclu=main_ex(fileExclu);
     menu(fileExclu);
     return 0;
}
