#include "cycle.h"
#include <stdio.h>
#include <stdlib.h>

//Fonction pour la lecture du fichier des operations
Operation* Lecture_Operations(const char* operationsfile, int* operations_total) {
    FILE *file = fopen(operationsfile, "r");

    // Vérifier si l'ouverture du fichier a réussi
    if (!file)
    {
        printf("Erreur de lecture fichier\n"); // Message d'erreur si le fichier ne peut pas être ouvert
        exit(-1);
    }

    // Initialisation liste vide
    Operation* operations = NULL;
    *operations_total = 0;

    // Lire chaque ligne du fichier
    while (!feof(file)) {
        int num_op, temps_op;
        // Lire le numéro de l'opération (num_op) et son temps d'exécution (temps_op) depuis le fichier
        if (fscanf(file, "%d %d", &num_op, &temps_op) == 2) {
            // Ajouter (num_op, temps_op) à la liste operations
            *operations_total += 1;

            // Réallouer la mémoire pour la liste Operations
            operations = realloc(operations, (*operations_total) * sizeof(Operation));

            // Stockage numéro de l'opération et sa durée dans la nouvelle entrée de la liste
            operations[*operations_total - 1].operation = num_op;
            operations[*operations_total - 1].duration = temps_op;
        }
    }

    // Fermer le fichier
    fclose(file);
    // Retourner la liste des opérations lues
    return operations;
}

// Fonction pour la lecture du fichier de temps de cycle
int Lecture_Temps_Cycle(const char* tempscyclefile) {
    FILE *file = fopen(tempscyclefile, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier TimeCycleFile");
        exit(EXIT_FAILURE);
    }

    int temps_cycle;

    // Extraire la durée du temps de cycle
    if (fscanf(file, "%d", &temps_cycle) != 1) {
        fprintf(stderr, "Erreur de lecture de la durée du temps de cycle.\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return temps_cycle;
}

// Fonction pour vérifier la contrainte de temps
int Contrainte_Temps_Cycle(Operation* operations, int operations_total, int temps_cycle) {
    // Initialiser la somme des durées des opérations
    int durations_total = 0;

    // Calculer la somme des durées des opérations
    for (int i = 0; i < operations_total; ++i) {
        durations_total += operations[i].duration;
    }

    // Comparer la somme avec le temps de cycle
    if (durations_total > temps_cycle) {
        return 1;  // contrainte de temps violée
    }

    return 0;  // contrainte de tempsespectée
}
