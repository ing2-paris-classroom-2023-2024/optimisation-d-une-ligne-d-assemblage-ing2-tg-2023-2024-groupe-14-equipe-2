#include "point_h_emile.h"

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


    try_a_bulle(monArbre, ordre, taille);
    for (int i = 0; i < ordre; i++) {
        if(monArbre[i]->nb_predecesseur == 0){
            int sommet_initiale = monArbre[i]->sommet;
            break;
        }
    }

    float temps_list = 0;
    int potentiel_sommet = 0;
    float potentiel_temps_list =0;
    int nb_predecesseur = 0;

    printf("\nTri par nb successeur\n");

    for (int i = 0; i < ordre; i++) {
        printf("\n[%d] = [%f]\n", monArbre[i]->sommet, monArbre[i]->temps_execution);
    }

    for (int i = 0; i < ordre; i++) {
        printf("\nMon sommet [%d] : ", monArbre[i]->sommet);
        for (int j = 0; j < monArbre[i]->nb_predecesseur; j++) {
            printf(" predecesseur [%d] ", monArbre[i]->predecesseur[j]);
        }
    }

    push_queue(*monArbre[0]);
    nb_predecesseur = monArbre[0]->nb_predecesseur;
    temps_list = temps_list + monArbre[0]->temps_execution;

    if(monArbre[0]->nb_predecesseur > 0 ){
        for (int i = 0; i < nb_predecesseur; i++) {
            if(collorisation() == true){

                potentiel_sommet = monArbre[0]->predecesseur[i];
                printf("\n\nle potentiel sommet [%d]\n", potentiel_sommet);

                //on viens convertir le potentielle sommet en donner utilisable pour le mettre des les crochet d'un tableau
                for (int j = 0; j < ordre; j++) {
                    if(monArbre[j]->sommet == potentiel_sommet){
                        potentiel_sommet = j;
                        break;
                    }
                }
                //printf("\nnv potentiel sommet [%d]\n", potentiel_sommet);

                potentiel_temps_list = temps_list + monArbre[potentiel_sommet]->temps_execution;
                printf("\nle potentiel temp de list [%f]\n", potentiel_temps_list);

                if(potentiel_temps_list < cycle){
                    push_queue(*monArbre[potentiel_sommet]);
                    //printf("\nPush queue\n\n");
                }else{
                    printf("\nLe cycle a ete sature\n\n");
                    print_queue();
                    exit(EXIT_SUCCESS);
                }
            }
        }
        push_queue_G();
        print_queue_G();


        exit(EXIT_SUCCESS);
    }
    else{
        printf("\n Le sommet d'origine est pris comme point de depart\n");
    }
}




Bool is_empty_queue(void) {
    if (first_p == NULL && last_p == NULL)
        return true;

    return false;
}


void print_queue(void){
    if(is_empty_queue()){
        printf("Rein a afficher, la files est vide\n");
        return;
    }
    QueueElement *temp = first_p;
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
        first_p = element;
        last_p = element;
    }else{
        last_p->next = element;
        last_p= element;
    }
    nb_element_p++;
}

void pop_last(){
    if(is_empty_queue()){
        printf("la file est vide, aucun dernier element a retirer\n");
        return;
    }

    QueueElement *temp = first_p;


    if(first_p == last_p){
        first_p = NULL;
        last_p = NULL;
    }
    else{
        while (temp->next != last_p){
            temp = temp->next;
        }
        temp->next = NULL;
        last_p->next = temp;
        last_p = temp;

    }
    free(temp->next);
    nb_element_p--;
}


void pop_queue(void){
    if(is_empty_queue()){
        printf("\nla file est vide, il n'y a rien à retirer\n");
        return;
    }

    QueueElement *temp = first_p;

    if(first_p == last_p){
        first_p = NULL;
        last_p = NULL;
    }
    else{
        first_p = first_p -> next;
    }
    free(temp);
    nb_element_p--;
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



Bool is_empty_queue_G(void) {
    if (first_G == NULL && last_G == NULL)
        return true;

    return false;
}

void print_queue_G(void){
    if(is_empty_queue_G()){
        printf("Rein a afficher, la files generale est vide\n");
        return;
    }
    printf("\nAffichage de la file generale\n");
    QueueElement_G *temp_G = first_G;
    while(temp_G != NULL){
        QueueElement *temp = temp_G->first;
        while (temp != NULL) {
            printf(" [[%d]] ", temp->value.sommet);
            temp = temp->next;
        }
        printf("\n");
        temp_G = temp_G ->next;
    }
}

void push_queue_G(void){
    QueueElement_G *element;
    element = malloc(sizeof(*element));

    element->first = first_p;
    first_p = NULL;
    element->last = last_p;
    last_p = NULL;
    element->next = NULL;


    if(is_empty_queue_G()){
        first_G = element;
        last_G = element;
    }else{
        last_G->next = element;
        last_G= element;
    }
    nb_element_G++;
} //En réaliter on n'a pas vraiment d'élément à ajouter, on relie plutot le first et le last de notre list simple a ce de la structure de la list_General

void pop_queue_G(void){
    if(is_empty_queue_G()){
        printf("\nRien a supprimer, la file generale est vide\n");
    }

    QueueElement_G *temp_G = first_G;
    if( last_G == first_G) {
        first_G = NULL;
        last_G = NULL;
    }
    else{
        while(temp_G->nb_element != 0){
            QueueElement *temp = temp_G->first;
            if(temp_G->first == temp_G->last){
                temp_G->first = NULL;
                temp_G->last = NULL;
            }
            else{
                temp_G->first = temp_G->first -> next;
            }
            free(temp);
            temp_G->nb_element--;
        }
        first_G = first_G->next;
    }
    free(temp_G);
    nb_element_G--;
} // si on doit vidé un point de notre list Général il Faut vidé tous les points à l'intérrieur du last et du first de notre list elle meme dans la list général

void clear_queue_G(void){
    if(is_empty_queue_G()){
        printf(" \nrien a supprimer, la file est vide\n");
        return;
    }
    while (!is_empty_queue_G()){
        pop_queue_G();
    }
}