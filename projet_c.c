#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet_c.h"

int test_vide(List_adh li){
    if (li==NULL){
        return 1;
    }
}

/*--------------------------------------------------------*/

int test_videl(List_liv li){
    if (li==NULL){
        return 1;
    }
}

/*--------------------------------------------------------*/

List_adh ajouter_adherant(List_adh ptr,adh_info new_adh){
    List_adh p;
    p=(List_adh)malloc(sizeof(adh));
    p->data=new_adh;
    p->next=NULL;
    if(p==NULL){
        printf("Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
    }
    if(test_vide(p)==1){
        ptr=p;
    }
    else{
        List_adh a;
        a=ptr;
        while(a->next!=NULL){
            a=a->next;
        }
        a->next=p;
    }
    return ptr;
}


/*---------------------------------------------------*/

List_adh supprimes_adherant(List_adh ptr,int code){
    List_adh p;
    p=ptr;
    if (p->data.num_adh==code){
        ptr=p->next;
        free(p);
        return ptr;
    }
    while(p->next->data.num_adh!=code ||p->next->next!=NULL){
        p=p->next;
    }
    if (p->next->next!=NULL){
        List_adh c=p->next;
        p->next=p->next->next;
        free(c);
        return ptr;
    }
    else{
        List_adh c=p->next;
        p->next=NULL;
        free(c);
        return ptr;
    }
}

/*-------------------------------------------------------------*/

List_liv ajouter_livre(List_liv ptr,livre_info new_live){
    List_liv p;
    p=(List_liv)malloc(sizeof(livre));
    p->info_liv=new_live;
    p->next=NULL;
    if(p==NULL){
        printf("Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
    }
    if(test_videl(p)==1){
        ptr=p;
    }
    else{
        List_liv a;
        a=ptr;
        while(a->next!=NULL){
            a=a->next;
        }
        a->next=p;
    }
    return ptr;
}

/*--------------------------------------------------------*/
List_liv supprimes_livre(List_liv ptr,int code){
    List_liv p;
    p=ptr;
    if (p->info_liv.num_liv==code){
        ptr=p->next;
        free(p);
        return ptr;
    }
    while(p->next->info_liv.num_liv!=code ||p->next->next!=NULL){
        p=p->next;
    }
    if (p->next->next!=NULL){
        List_liv c=p->next;
        p->next=p->next->next;
        free(c);
        return ptr;
    }
    else{
        List_liv c=p->next;
        p->next=NULL;
        free(c);
        return ptr;
    }
}

/*-------------------------------------------------*/

void enprunter_livre(List_adh ptra,List_liv ptrl,int codea,int codel){
    List_adh a;
    a=ptra;
    while(a->data.num_adh!=codea){
        a=a->next;
    }
    if(a->data.nbre_emprunts_adh>=3){
        printf("tu ne peux pas emprunter un autre livre");
        exit(EXIT_FAILURE);
    }
    List_liv l;
    l=ptrl;
    while(l->info_liv.num_liv!=codel){
        l=l->next;
    }
    l->info_liv.emprunteur_liv=codea;
}

/*-----------------------------------------------------------*/

void affichar_livre_emprintee(List_liv ptr){
    List_liv l;
    l=ptr;
    while(l->next!=NULL){
        if(l->info_liv.emprunteur_liv!=0){
            printf("%s\n",l->info_liv.titre_livre);
        }
        l=l->next;
    }
    if(l->info_liv.emprunteur_liv!=0){
        printf("%s\n",l->info_liv.titre_livre);
    }
}


