#ifndef PROJET_C_H_INCLUDED
#define PROJET_C_H_INCLUDED

/*les structurs*/

typedef struct adherant_info{
    int num_adh;
    char nom_adh[20];
    char prenom_adh[20];
    char email_adh[60];
    char adress_adh[100];
    int nbre_emprunts_adh;
}adh_info;

typedef struct adherant{
    adh_info data;
    struct adherant* next;
}adh,*List_adh;

typedef struct _AUTEUR{
    char nom_aut[20];
    char prenom_aut[20];

}auteur;
typedef struct _LIVRE_INFO{
    int num_liv;
    char titre_livre[20];
    char categ_liv[2]; // codes des cat�gories ; par exemple : 00 pour la litairature ...
    auteur auteur_liv;
    int emprunteur_liv;
}livre_info;
typedef struct _LIVRE{
    livre_info info_liv;
    struct _LIVRE *next;
}livre,*List_liv;

// les prototypes :

int test_vide(List_adh li);
List_adh ajouter_adherant(List_adh ptr,adh_info new_adh);
List_adh supprimes_adherant(List_adh ptr,int code);
int test_videl(List_liv li);
List_liv ajouter_livre(List_liv ptr,livre_info new_live);
List_liv supprimes_livre(List_liv ptr,int code);
void enprunter_livre(List_adh ptra,List_liv ptrl,int codea,int codel);
void affichar_livre_emprintee(List_liv ptr);



#endif // PROJET_C_H_INCLUDED
