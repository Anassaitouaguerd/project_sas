#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int numeroservice,heure, minute, jeur, id;
char titre[50],description[500];
int sizetache = 0 , i,sizetab = 0;
int cont = 0 , status;
typedef struct
{
    int heure, mois;
    int jeur;

} date_debut;
typedef struct
{
    int heure2,mois2;
    int jeur2;

} date_final;


typedef struct
{
    int id;
    char titre[50];
    char description[500];
    char status[40];
    date_debut debut;
    date_final finall;

} task;

task tache[100];


void Ajouter_taches()
{
    printf("entrez le nombre de les tache ajouter : ");
    scanf("%d",&sizetache);
    for (i = 0 ; i < sizetache ; i++)
    {
        printf("\n\t --> entrez le titre de tache : ");
        getchar();
        gets(tache[cont].titre);
        printf("\n\t --> entrez le description de tache : ");
        gets(tache[cont].description);
        printf("\n\t --> entrez le id de tache : ");
        scanf("%d",&tache[cont].id);
        cont ++;
        printf("\t\t ******entrez la date debut : ******\n ");
        printf("\t---> entrez le mois : ");
        scanf("%d",&tache[cont].debut.mois);
        printf("\t---> entrez le jeur: ");
        scanf("%d",&tache[cont].debut.jeur);
        printf("\t---> entrez le heure : ");
        scanf("%d",&tache[cont].debut.heure);
        printf("\t\t ******entrez la date final : ******\n ");
        printf("\t---> entrez le mois : ");
        scanf("%d",&tache[cont].finall.mois2);
        printf("\t---> entrez le jeur: ");
        scanf("%d",&tache[cont].finall.jeur2);
        printf("\t---> entrez le heure : ");
        scanf("%d",&tache[cont].finall .heure2);
        printf("\t\t ****** entrez status ******\n\n");
        printf("\t\t ------------------------------------\n");
        printf("\t\t -->> 1 - realiser                 \n|");
        printf("\t\t -->> 2 - en cours de réalisation  \n|");
        printf("\t\t -->> 3 - finalisée                \n|");
        printf("\t\t ------------------------------------\n");
        printf("\t\t ---------->>>> entrez le numero de status : ");
        scanf("%d",&status);
       do {
            switch(status){
            case 1 : strcpy(tache[cont].status ,"realiser");
            break;
            case 2 : strcpy(tache[cont].status ,"en cours de réalisation");
            break;
            case 3 : strcpy(tache[cont].status ,"finalisée");
            break;
            }

       }while(status !=1 && status != 2 && status !=3);


    }
}
void Afficher_liste()
{
    int reponse;



    for (i = 0; i < cont  ; i++)
    {
        printf("----- >> le titre de tache [%d] :  ",i+1);
        puts(tache[i].titre);

        printf("----- >> description de tache [%d] : ",i+1);
        puts(tache[i].description);

        printf("----- >> le id de tache [%d] : %d\n\n ",i+1,tache[i].id);

    }
}






int main()
{


    do
    {
        printf("\n\n\t\t\t\t**************** liste de services: ****************\n");
        printf("\t\t\t\t\t  -------------------------------------------\n ");
        printf("\t\t\t\t\t | 1 --> Ajouter nouvelles taches            |\n ");
        printf("\t\t\t\t\t | 2 --> Afficher la liste d\'taches         |\n ");
        printf("\t\t\t\t\t | 3 --> Ajouter plusieurs nouvelles taches |\n ");
        printf("\t\t\t\t\t | 4 --> Modifier une tache                 |\n ");
        printf("\t\t\t\t\t | 5 --> Rechercher les taches              |\n ");
        printf("\t\t\t\t\t | 6 --> Supprimer une tache                |\n ");
        printf("\t\t\t\t\t | 7 --> Statistiques                       |\n ");
        printf("\t\t\t\t\t  ------------------------------------------\n ");
        printf("\n\n \t\t--------> entrez le numero de service  :    ");
        scanf("%d",&numeroservice);
        system("cls");
        switch(numeroservice)
        {
        case 1 :
            Ajouter_taches();
            break;

        case 2 :
            Afficher_liste();
            break;
        /*
        case 3 :
         Ajouter_plusieurs_taches();
        break;
        case 4 :
         Modifier_tache ();
        break;
        case 5 :
        Rechercher_taches();
        break;
        case 6 :
        Supprimer_tache();
        break;

        case 7 :
        Statistiques();
        break;
        */

        default :
            printf("\n\n \t\t -->>>>!!le numero service n\'existe pas ! <<---\n\n\n\n");


        }

    }
    while(numeroservice !=0 && numeroservice <=10);

    return 0;
}


