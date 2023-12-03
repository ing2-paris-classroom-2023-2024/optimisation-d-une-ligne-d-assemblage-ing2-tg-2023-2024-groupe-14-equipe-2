#include "relie.h"

int main() {
    char nom_fichier[50];
    graphe mongraphe;
    int point_depart = 0;
    int point_arrive = 0;
    printf("Veiller saisir le nom du fichier\n");
    scanf("%[^\n]%*c", nom_fichier);
    //ouverture_du_fichier(&mongraphe, nom_fichier);
    printf("\ntaille du graphe: %d", trouvTaille(nom_fichier));
    printf("\nordre du graphe: %d", trouvOrdre(nom_fichier));
    return 0;
}
