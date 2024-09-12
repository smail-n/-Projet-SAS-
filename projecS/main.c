#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "Hider.h"



int main(){
    int again, chos, MoSu, i;
    int Push;
    int deNumber;
    char name [50];
    char departement [50];



    Ajouter_de_nouveaux_etudiants ();

    do{
        printf ("  ------------ MENU ------------");
        printf ("1. ajouter etudian\n");
        printf ("2. aficher\n");
        printf ("3. Modifier ou supprimer un etudiant\n");
        printf ("4. Calculer la moyenne générale \n");
        printf ("5. Statistiques \n");
        printf ("6. Rechercher un etudiant par...\n");
        printf ("7. Trier un étudiant par...\n");

        printf ("enter : ");
        scanf ("%d", &chos);

        switch (chos){
        case 1:
             Ajouter_de_nouveaux_etudiants ();
             break;
        case 2:
            Afficher_les_details_un_etudiant ();
            break;
        case 3:
            printf ("1. Modifier\n");
            printf ("2. supprimer\n");
            printf ("enter : ");
            scanf ("%d", &MoSu);
            switch (MoSu){
                case 1:
                     Modifier_ou_supprimer (true);
                     break;
                case 2:
                     Modifier_ou_supprimer (false);
                     break;
                default:
                    printf ("Votre choix n'existe pas\n");
                    break;
            }
            break;
            case 4:
                printf ("1. la moyenne generale de chaque departement\n");
                printf ("2. la moyenne generale de universite\n");
                printf ("enter : ");
                scanf ("%d", &MoSu);
                switch (MoSu){
                    case 1:
                         Calculer_la_moyenne_generale (true);
                         break;
                    case 2:
                         Calculer_la_moyenne_generale (false);
                         break;
                    default:
                        printf ("Votre choix n'existe pas\n");
                        break;
                }
                break;
                case 5:
                    printf ("1. Afficher le nombre total detudiants inscrits.\n");
                    printf ("2. Afficher le nombre d etudiants dans chaque departement.\n");
                    printf ("3. Afficher les etudiants ayant une moyenne generale superieure à un certain seuil.\n");
                    printf ("4. Afficher les 3 etudiants ayant les meilleures notes.\n");
                    printf ("5. Afficher le nombre d etudiants ayant reussi dans chaque departement (ceux ayant une note superieure ou egale a 10/20).\n");
                    printf ("enter : ");
                    scanf ("%d", &MoSu);
                    switch (MoSu){
                        case 1:
                             printf ("total detudiants inscrits %d", NomberTotalEtudian);
                             break;
                        case 2:
                            deNumber = etudiants_dans_chaque_departement ();
                            printf ("le nombre d etudiants dans chaque departement %d", deNumber);
                            break;
                        case 3:
                            etudiants_ayant_une_moyenne_generale_superieure_a_un_certain_seuil ();
                            break;
                        case 4:
                            Afficher_les_etudiants_ayant_les_meilleures_notes ();
                            break;
                        case 5:
                            Afficher_le_nombre_detudiants_ayant_Top_eussi_dans_chaque_departement ();
                            break;
                        default:
                            printf ("switch 1 -> 5\n");
                            break;
                        }
                break;
                case 6:
                    printf ("1. Rechercher un etudiant par son nom\n");
                    printf ("2. Afficher la liste des etudiants inscrits dans un departement specifique\n");
                    printf ("enter : ");
                    scanf ("%d", &MoSu);
                    switch (MoSu){
                        case 1:
                            printf ("enter nom d'un etudiant pour recherch : ");
                            scanf ("%49s", name);
                            Push = search_etudiant (name );
                            if (Push != -1){
                                printf ("-----------Etudiant %d-------\n\n", Push+1);
                                printf ("\tnom : %s\n", TEtudiant[Push].nom);
                                printf ("\tprenom :%s\n", TEtudiant[Push].prenom);
                                printf ("\tID : %d\n", TEtudiant[Push].ID);
                                printf ("\tDate de naissance %d/ %d/ %d\n", TEtudiant[Push].Naissance.day, TEtudiant[Push].Naissance.month, TEtudiant[Push].Naissance.year);
                                printf ("\t Departement %s \n", TEtudiant[Push].Departement);
                                printf ("\tNote generale %.2f\n", TEtudiant[Push].NoteGenerale);
                            }
                            break;
                        case 2:
                            printf ("enter departement : ");
                            scanf ("%49s", departement);
                            for (i = 0; i < NomberTotalEtudian; i++){
                                if (strcasecmp (TEtudiant [i].Departement, departement) == 0){
                                    printf ("-----------Etudiant departement %s -------\n\n", departement);
                                    printf ("\tnom : %s\n", TEtudiant[i].nom);
                                    printf ("\tprenom :%s\n", TEtudiant[i].prenom);
                                    printf ("\tID : %d\n", TEtudiant[i].ID);
                                    printf ("\tDate de naissance %d/ %d/ %d\n", TEtudiant[i].Naissance.day, TEtudiant[i].Naissance.month, TEtudiant[i].Naissance.year);
                                    printf ("\t Departement %s \n", TEtudiant[i].Departement);
                                    printf ("\tNote generale %.2f\n", TEtudiant[i].NoteGenerale);
                                }
                            }
                         break;
                        default:
                            printf ("Votre choix n'existe pas\n");
                            break;
                    }
                    break;
                    case 7:
                        printf ("1. Tri alphabetique des etudiants en fonction de leur nom de A a Z\n");
                        printf ("2. Tri des etudiants par moyenne generale, du plus eleve au plus faible ou inversement.\n");
                        printf ("3. Tri des etudiants selon leur statut de reussite 10 -> 20.\n");
                        printf ("enter : ");
                        scanf ("%d", &MoSu);

                        switch (MoSu){
                        case 1:
                            Tri_alphabetique ();
                        break;
                        case 2:
                            printf ("1. Tri par du plus eleve au plus faible\n");
                            printf ("2. Tri par du plus faible au plus eleve\n");
                            printf ("enter : ");
                            scanf ("%d", &MoSu);

                            switch (MoSu){
                            case 1:
                                Tri_par_du_plus (true);
                                break;
                            case 2:
                                Tri_par_du_plus (false);
                                break;
                            default :
                                printf ("your chois isn't exist");
                                break;
                            }
                        break;
                        case 3:
                            Tri_des_etudiants_selon_leur_statut_de_reussite ();
                            break;
                        default :
                            printf ("Votre choix n'existe pas\n");
                        break;
                    }
                    break;
                    default :
                        printf ("Votre choix n'existe pas. 1 -> 7\n");
                        break;
            }
                    printf ("\n");
                    printf ("again   0: no, any number: yes \nenter : ");
                    scanf ("%d", &again);
                    printf ("\n\n\n");
        }while (again);


    free(TEtudiant);
    return 0;

}
