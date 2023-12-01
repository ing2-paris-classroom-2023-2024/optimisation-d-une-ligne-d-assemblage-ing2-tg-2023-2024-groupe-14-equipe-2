#include "point_h_emile.h"
#define SIZE 10

void try_a_bulle(arbre* monArbre[], int ordre, int taille){
    arbre* tmp;

    for (int i=0 ; i < ordre-1; i++){
        for (int j=0 ; j < ordre-i-1; j++){
            if (monArbre[j]->nb_successeur < monArbre[j+1]->nb_successeur){
                tmp = monArbre[j];
                monArbre[j] = monArbre[j+1];
                monArbre[j+1] = tmp;
            }
        }
    }
}

int collorisation(){
    return  1 ;
}


void ouverture_de_fichier(arbre* tab_sommet[], int nombre_de_ligne, FILE* fichier){


    char caractere;
    int nb_successeur = 0;
    int nb_predecesseur = 0;
    int numero_du_sommet =0;
    int i = 0;

    for (int j = 0; j < nombre_de_ligne; j++) {
        tab_sommet[j] = (arbre*)malloc(sizeof(arbre));
        if (tab_sommet[j] == NULL) {
            printf("Erreur d'allocation de mémoire.\n");
            exit(EXIT_FAILURE);
        }
    }


    while (fscanf(fichier, "%d", &numero_du_sommet) == 1) {
        tab_sommet[i]->sommet = numero_du_sommet;
        i++;
    }

    rewind(fichier);

    for (int j = 0; j < nombre_de_ligne; j++) {
        printf("numero du sommet : %d\n", tab_sommet[i]->sommet);
    }

}



void optimisation_de_la_chaine(arbre* monArbre[], int taille, int ordre, float cycle){
/*
    for (int i = 0; i < ordre; i++) {
        printf("\nMon sommet [%d] : ", monArbre[i]->sommet);
        for (int j = 0; j < monArbre[i]->nb_successeur; j++) {
            printf(" [%d] ", monArbre[i]->successeur[j]);
        }
    }
*/
    try_a_bulle(monArbre, ordre, taille);
    float temps_list = 0;
    int potentiel_sommet = 0;
    float potentiel_temps_list =0;

    for (int i = 0; i < ordre; i++) {
        printf("\nMon sommet [%d] : ", monArbre[i]->sommet);
        for (int j = 0; j < monArbre[i]->nb_successeur; j++) {
            printf(" [%d] ", monArbre[i]->successeur[j]);
        }
    }
    push_queue(*monArbre[0]);
    temps_list = temps_list + monArbre[0]->temps_execution;

    if(monArbre[0]->nb_predecesseur > 0 ){
        for (int i = 0; i < monArbre[0]->nb_predecesseur; i++) {
            if(collorisation() == true){
                potentiel_sommet = monArbre[0]->predecesseur[i];
                potentiel_temps_list = temps_list + monArbre[potentiel_sommet]->temps_execution;
                if(potentiel_temps_list < cycle){

                }


            }
        }
    }
    else{
        printf("\n Le sommet d'origine est pris comme point de depart\n");
        pop_queue();
    }
}




Bool is_empty_queue(void) {
    if (first == NULL && last == NULL)
        return true;

    return false;
}

void print_queue(void){
    if(is_empty_queue()){
        printf("Rein a afficher, la files est vide\n");
        return;
    }
    QueueElement *temp = first;
    while(temp != NULL){
        printf(" [[%d]] ", temp->value.sommet);
        temp = temp->next;
    }
}

void push_queue(arbre x){
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

void pop_last(){
    if(is_empty_queue()){
        printf("la file est vide, aucun dernier element a retirer\n");
        return;
    }

    QueueElement *temp = first;


    if(first == last){
        first = NULL;
        last = NULL;
    }
    else{
        while (temp->next != last){
            temp = temp->next;
        }
        temp->next = NULL;
        last->next = temp;
        last = temp;

    }
    free(temp->next);
    nb_element--;
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