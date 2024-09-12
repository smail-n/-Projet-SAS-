#ifndef HIDER_H
#define HIDER_H


typedef struct DateNaissance {
    int day;
    int month;
    int year;
}Date;

typedef struct ToutEtudiant {
    int ID;
    char nom [50];
    char prenom [50];
    Date Naissance;
    char Departement [50];
    float NoteGenerale;

}etudiant;

extern etudiant *TEtudiant ;
extern int NomberTotalEtudian ;



int search_etudiant (char name[]);
void Modifier_ou_supprimer (bool b);
void  Ajouter_de_nouveaux_etudiants ();
void Afficher_les_details_un_etudiant ();
void Calculer_la_moyenne_generale (bool Q);
int etudiants_dans_chaque_departement ();
void etudiants_ayant_une_moyenne_generale_superieure_a_un_certain_seuil ();
void Afficher_les_etudiants_ayant_les_meilleures_notes ();
void Afficher_le_nombre_detudiants_ayant_Top_eussi_dans_chaque_departement ();
void changeTowElemant(int A, int B);
void Tri_alphabetique ();
void Tri_par_du_plus (bool a);
void Tri_des_etudiants_selon_leur_statut_de_reussite ();



#endif
