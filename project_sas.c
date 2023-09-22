#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Global variables

int numeroservice,heure, minute, jeur, id;
char titre[50],description[500];
int sizetache = 0, i, j, sizetab = 0;
int cont = 0, status;
int finalle,debute,D[100] ;
int days, months;
int jeur1;
int mois2;
int annee2;

//Structure pour date final

typedef struct
{
    int mois;
    int jeur;
    int annee;

} deadline;



// Structure task

typedef struct
{
    int id;
    char titre[50];
    char description[500];
    char status[40];

    deadline dead;

} task;

//Tableau pour stocker les taches

task tache[100];

// Fonction pour ajouter des taches

void Ajouter_taches()
{
    printf("entrez le nombre de les tache ajouter : ");
    scanf("%d",&sizetache);
    for (i = 0 ; i < sizetache ; i++)
    {
        printf("\n\t --> entrez le titre de tache [%d]: ",i+1);
        getchar();
        gets(tache[cont].titre);
        printf("\n\t --> entrez le description de tache : ");
        gets(tache[cont].description);
        tache[cont].id = cont+2;
        printf("\n\n \t\t ******entrez la date final : ******\n ");
        printf("\t---> entrez le jeur: ");
        scanf("%d",&tache[cont].dead.jeur);
        printf("\t---> entrez le mois: ");
        scanf("%d",&tache[cont].dead.mois);

        do
        {
            printf("\n\n\t\t ****** entrez status ******\n\n");
            printf("\t\t ------------------------------------\n");
            printf("\t\t |-->> 1 - realiser                 |\n");
            printf("\t\t |-->> 2 - en cours de realisation  |\n");
            printf("\t\t |-->> 3 - finalisee                |\n");
            printf("\t\t ------------------------------------\n");
            printf("\t\t ---------->>>> entrez le numero de status : ");
            scanf("%d",&status);
            switch(status)
            {
            case 1 :
                strcpy(tache[cont].status,"realiser");
                break;
            case 2 :
                strcpy(tache[cont].status,"en cours de realisation");
                break;
            case 3 :
                strcpy(tache[cont].status,"finalisee");
                break;
            }
        }
        while(status !=1 && status != 2 && status !=3);

        // Calculer les jours et les mois restants jusqu 'a la date limite

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        jeur1 = tm.tm_mday;
        mois2 = ((tm.tm_mon+1) * 30);

        days = tache[cont].dead.jeur - jeur1;
        months = (tache[cont].dead.mois *30)- mois2;

        // Mettre à jour les champs d’échéance

        tache[cont].dead.jeur = days;
        tache[cont].dead.mois = months;
        tache[cont].dead.jeur = tache[cont].dead.jeur + months;


        cont ++;
    }
}

//Fonction tableaux

void tableaux()
{
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("|        titre        |     description        |     deadline     |       idantifiant            |         status  |\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}


//Fonction Tableau des cas

void tableauCase()
{
    int i;

    for (i = 0; i < cont; i++)
    {
        printf("|    %s    |    %5s |   %02d jeur    |   %d  |    %s    |\n\n",tache[i].titre,tache[i].description,tache[i].dead.jeur,tache[i].id,tache[i].status);
    }
}
// Fonction Affichage

void Afficher_liste()
{

    int reponse,exist = 0;
    task tri_alphabet;
    task tri_deadline;

    printf("entrez le nombre de choix : \n");
    printf(" 1 - ALPHABET ***\n");
    printf(" 2 - deadline ***\n");
    printf(" 3 - les taches dont le deadline est dans 3 jours ou moins ***\n");
    scanf("%d",&reponse);

    switch(reponse)
    {
    case 1 :

        // Trier les taches par ordre alphabetique par titre

        for(i = 0 ; i < cont ; i++)
        {
            for (j = i + 1 ; j < cont ; j++)
            {
                if(strcmp(tache[i].titre, tache[j].titre)>0)
                {
                    tri_alphabet = tache[i];
                    tache[i] = tache[j];
                    tache[j] = tri_alphabet;
                }
            }
        }
        tableaux();
        tableauCase();
        break ;
    case 2 :
        // tri par ordre deadline

        for(i = 0 ; i < cont ; i++)
        {
            for( j = i + 1 ; j < cont ; j++)
            {
                if(tache[i].dead.jeur > tache[j].dead.jeur)
                {
                    tri_deadline = tache[i] ;
                    tache[i] = tache[j] ;
                    tache[j] = tri_deadline;
                }
            }
        }
        tableaux();
        tableauCase();
        break ;

    case 3 :

        //tri les tache inferieur ou egal a 3 jours

        for( i = 0 ; i < cont ; i++)
        {
            if(tache[i].dead.jeur <= 3)
            {
                tableaux();
                printf("|    %s    |    %5s |   %02d jeur    |   %d  |    %s    |\n\n",tache[i].titre,tache[i].description,tache[i].dead.jeur,tache[i].id,tache[i].status);
            }
            else if(tache[i].dead.jeur > 3)
            {
                printf("\t\t !!! Il n\'y a pas de taches de moins de 3 jours !!! \n\n");
            }
        }
    }
}

//Fonction modification des taches

void Modifier_tache()
{
    int md;
    tableaux();
    tableauCase();

    printf("entrez le identifiant de tache :");
    scanf("%d",&md);
    for ( i = 0 ; i < cont ; i++)
    {
        if (tache[i].id == md)
        {
            printf("\n\t --> entrez le titre de tache : ");
            getchar();
            gets(tache[i].titre);
            printf("\n\t --> entrez le description de tache : ");
            gets(tache[i].description);

            tache[i].id = cont + 2;

            printf("\n\n \t\t ******entrez la date final : ******\n ");
            printf("\t---> entrez le jeur: \n");
            scanf("%d",&tache[i].dead.jeur );
            printf("\t---> entrez le mois: ");
            scanf("%d",&tache[i].dead.mois);

            time_t t = time(NULL);
            struct tm tm = *localtime(&t);

            jeur1 = tm.tm_mday;
            mois2 = ((tm.tm_mon+1) * 30);
            annee2 = (tm.tm_year + 1900) * 365;

            days = tache[i].dead.jeur - jeur1;
            months = (tache[i].dead.mois *30)- mois2;

            tache[i].dead.jeur = days;
            tache[i].dead.mois = months;
            tache[i].dead.jeur = tache[i].dead.jeur + months;
        }
    }
}

//Fonction recherche des taches

void Rechercher_taches()
{
    int rep, K,exist = 0;
    int N;
    char Tit[50];

    printf("\n\t\t\t----------------------------\n");
    printf("\t\t\t |1 - chercher par Identifiant  |\n");
    printf("\t\t\t |2 - chercher par titre        |\n");
    printf("\n\t\t\t----------------------------\n");
    scanf("%d",&rep);

    switch(rep)
    {
        case 1 :
            printf("entrez le idantifiant : ");
            scanf("%d",&N);
            for(i=0; i<cont; i++)
            {
            if(tache[i].id == N)
            {
                exist = 1;
                tableaux();
                printf("\n |    %s    |    %5s |   %02d jeur  |   %d  |    %s    |\n",tache[i].titre, tache[i].description,tache[i].dead.jeur,tache[i].id,tache[i].status);
            }
            if(exist == 0)
            {
                printf("!!!! le idantifiant no disponible !!!!!!!");
            }
            }
                break ;

        case 2 :
            printf("entrez le titre de tache :");
            scanf("%s", Tit);
            for( i = 0 ; i < cont ; i++)
            {
            K = strcmp(tache[i].titre, Tit);
            if(K == 0)
                {
                exist = 1;

                tableaux();
                printf("\n |    %s    |    %5s |   %02d jeur  |   %d  |    %s    |\n",tache[i].titre, tache[i].description,tache[i].dead.jeur,tache[i].id,tache[i].status);
                }
            if(exist == 0)
                {
                printf("!!!! le titre no disponible !!!!!!!");
                }
            }
                break;
    default :
            printf("!!!!!!! --> le nombre de choix no disponible!!! <--");
    }
}

//supprimer des taches

void Supprimer_tache()
{
    int index, exist = 0;

    tableaux();
    tableauCase();

    printf("\t ------ >> entrez le identifiant de la tache : ");
    scanf("%d",&index);
    for( i = 0 ; i < cont ; i++)
    {
        if(index == tache[i].id)
        {
            exist = 1;
            tache[i] = tache[i+1];
            cont --;
        }
        if(exist == 0)
        {
            printf("------ !!!! le identifiant no disponible !!!! ---- ");
        }
    }
}

// Fonction statistiques

void Statistiques()
{
    int temp = cont ;
    char incomplete[50] = "realiser";
    char complete [50] =   "finalisee";
    int longeure=0, longeure2=0;

    printf("\t\t\t\t\t ------------------------------------------------ \n");
    printf("\t\t\t\t\t         le nombre des taches est : %d           \n",temp);
    printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");
    for(i =0 ; i < cont ; i++)
    {
        if(strcmp(complete, tache[i].status)==0)
        {
            longeure++;
        }
    }
    for(i =0 ; i < cont ; i++)
    {
        if(strcmp(incomplete, tache[i].status)==0)
        {
            longeure2++;
        }
    }
    printf("\t\t\t\t\t ------------------------------------------------ \n");
    printf("\t\t\t\t\t         le nombre des taches complete : %d           \n",longeure);
    printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");
    printf("\t\t\t\t\t ------------------------------------------------ \n");
    printf("\t\t\t\t\t         le nombre des taches incomplete : %d           \n",longeure2);
    printf("\t\t\t\t\t ------------------------------------------------ \n\n\n");

    for (i = 0 ; i < cont ; i++){
        printf("\t\t\t\t\t---------------------------------------\n");
        printf("\t\t\t\t\t|      id         |      deadline     |");
        printf("\t\t\t\t\t---------------------------------------\n");
        printf("\t\t\t\t\t--------------------------------------\n");
        printf("\t\t\t\t\t|      %d        |     %02d  jeur    |\n",tache[i].id,tache[i].dead.jeur);
        printf("\t\t\t\t\t--------------------------------------\n");
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
        printf("\t\t\t\t\t | 3 --> Modifier une tache                 |\n ");
        printf("\t\t\t\t\t | 4 --> Rechercher les taches              |\n ");
        printf("\t\t\t\t\t | 5 --> Supprimer une tache                |\n ");
        printf("\t\t\t\t\t | 6 --> Statistiques                       |\n ");
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
        case 3 :
            Modifier_tache ();
            break;

        case 4 :
            Rechercher_taches();
            break;

        case 5 :
            Supprimer_tache();
            break;

        case 6 :
            Statistiques();
            break;


        default :
            printf("\n\n \t\t -->>>>!!le numero service n\'existe pas ! <<---\n\n\n\n");


        }

    }
    while(numeroservice !=0 && numeroservice <=10);

    return 0;
}
