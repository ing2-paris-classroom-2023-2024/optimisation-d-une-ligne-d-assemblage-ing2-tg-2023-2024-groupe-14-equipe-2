#include "relie.h"

int trouvTaille(char filename[50]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int node1, node2;
    int count = 0;

    while (fscanf(file, "%d %d", &node1, &node2) == 2) {
        count++;
    }

    fclose(file);

    return count;
}

int trouvOrdre(char nom_fichier[50]) {
    FILE *fichier = fopen(nom_fichier, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    int ordre = 0;
    int sommet1, sommet2;

    while (fscanf(fichier, "%d %d", &sommet1, &sommet2) == 2) {
        if (sommet1 > ordre) {
            ordre = sommet1;
        }
        if (sommet2 > ordre) {
            ordre = sommet2;
        }
    }

    fclose(fichier);

    return ordre;
}

void ouverture_du_fichier(graphe* precedences, char nom_du_fichier[50]){

    int ordre = 0;
    int taille = 0;
    int som_1 = 0;
    int som_2 = 0;
    int temp;
    int poids = 0;
    FILE *fichier;

    fichier = fopen(nom_du_fichier, "r");

    //fscanf(fichier, "%d", &ordre);
    precedences->ordre_graphe = ordre;
    printf("\nordre du graphe : %d\n", ordre);

    precedences->matrice_ajacence = (sommet **)calloc(ordre, sizeof(sommet *));
    for (int j = 0; j < precedences->ordre_graphe; j++) {
        precedences->matrice_ajacence[j] = (sommet *) calloc(ordre, sizeof (sommet));
    }

    for (int i = 0; i < precedences->ordre_graphe; i++) {
        for (int j = 0; j < precedences->ordre_graphe; j++) {
            precedences->matrice_ajacence[i][j].poids = -1;
        }
    }



    //fscanf(fichier,"%d",&taille);
    precedences->taille = taille;

    for (int j = 0; j < precedences->taille; j++) {
        fscanf(fichier, "%d%d%d", &som_1, &som_2, &poids);
        precedences->matrice_ajacence[som_1][som_2].adjacence = 1;
        precedences->matrice_ajacence[som_2][som_1].adjacence = 1;

        precedences->matrice_ajacence[som_1][som_2].poids = poids;
        precedences->matrice_ajacence[som_2][som_1].poids = poids;
    }

    for (int i = 0; i < precedences->ordre_graphe; i++) {
        for (int j = 0; j < precedences->ordre_graphe; j++) {
            precedences->matrice_ajacence[i][j].num_sommet = j;
        }
    }

    printf("\n/**********************Voila la matrice d'adjacence****************************/\n");
    for (int k = 0; k < precedences->ordre_graphe; k++) {
        printf("\n");
        for (int l = 0; l < precedences->ordre_graphe; l++) {
            printf(" %d ", precedences->matrice_ajacence[k][l].adjacence);
        }
    }
    printf("\n\n");

    printf("\n/**********************Voila la matrice de poids en fonction de la matrice d'adjacence****************************/\n");
    for (int k = 0; k < precedences->ordre_graphe; k++) {
        printf("\n");
        for (int l = 0; l < precedences->ordre_graphe; l++) {
            printf(" %d ", precedences->matrice_ajacence[k][l].poids);
        }
    }
    printf("\n\n");

    fclose(fichier);
}

void libererMatriceAdjacence(graphe* graphe, int ordre) {
    for (int i = 0; i < ordre; i++) {
        free(graphe->matrice_ajacence[i]);
    }
    free(graphe->matrice_ajacence);
    printf("\nLa memoire du graphe a bien ete liberee\n");
}


Bool is_empty_queue(void) {
    if (first == NULL && last == NULL)
        return true;

    return false;
}

int longueur_queue(void){
    return nb_element;
}

void print_queue(void){
    if(is_empty_queue()){
        printf("Rein a afficher, la files est vide\n");
        return;
    }
    QueueElement *temp = first;
    while(temp != NULL){
        printf("%d  ", temp->value);
        temp = temp->next;
    }
}

void push_queue(int x){
    QueueElement *element;
    element = malloc(sizeof(*element));

    element->value = x;
    element->next = NULL;

    if(is_empty_queue()){
        first = element;
        last = element;
    }else{
        last->next = element;
        last= element;
    }
    nb_element++;
}

void pop_queue(void){
    if(is_empty_queue()){
        printf("la file est vide, il n'y a rien à retirer\n");
        return;
    }

    QueueElement *temp = first;

    if(first == last){
        first = NULL;
        last = NULL;
    }
    else{
        first = first -> next;
    }
    free(temp);
    nb_element--;
}

void clear_queue(void){
    if(is_empty_queue()){
        printf(" \nrien a supprimer, la file est vide\n");
        return;
    }
    while (!is_empty_queue()){
        pop_queue();
    }
}