#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define FICHIER_SCORES "scores.txt"


//Incr�mentation des fonctions et des pointeurs
int addition();
int multiplication();
int soustraction();
int table_multiplication();
int Division();
int jeu_conversion();
int duree();
int jeuDevinette();
int SauvegarderScore(const char *nom, int score);
int AfficherScores();
int RecupererScore(const char *nom);
int AfficherDernierScore(const char *nom);
int score=0;

//Programme principal
int main(){
//D�claration des variables
int n,r;
char nom[50];
//Lecture
printf("Bienvenue sur Champion des Maths !\n");
printf("\nQuel est votre prenom ?\n");
scanf("%s", nom);
RecupererScore(nom);//On appelle la fonction R�cupererScore afin de culum� l'ancien score � celui que l'on va faire maintenant
score=RecupererScore(nom);
printf("Vous aviez un score de : %d", score);
printf("\nChoisissez parmis les chiffres suivants : \n"); //Liste des diff�rents jeux disponibles pour laisser le choix au joueur de s'exercer sur la notion qu'il veut
printf("1.Addition,\n");
printf("2.Soustraction,\n");
printf("3.Multiplication,\n");
printf("4.Table de multiplication,\n");
printf("5.Division,\n");
printf("6.Jeu des conversions d'unite de mesure,\n");
printf("7.Jeu des conversions de duree,\n");
printf("8.Devinette geometrique,\n");
printf("0.Sortir du jeu. \n");
scanf("%d",&n);
//Traitement
while (n!=0){ //Ici le while permet de cr�er une boucle : tant que n est diff�rent de 0, la boucle se r�p�te jusqu'� ce que le joueur d�cide de s'arr�ter
    switch(n) //Switch nous permet de traiter les diff�rents cas de n en fonction de sa valeur
    {
    case 1 : printf("\n-Bienvenue dans le jeu des additions !-\n");
    addition(); break; //On appelle � chaque fois la fonction correspondante au choix du joueur pour actionner le jeu
    case 2 : printf("\n-Bienvenue dans le jeu des soustractions !-\n");
    soustraction(); break;
    case 3 : printf("\n-Bienvenue dans le jeu des multiplications !-\n");
    multiplication(); break;
    case 4 :printf("\n-Bienvenue dans le jeu des tables de multiplications !-\n");
    table_multiplication(); break;
    case 5 :printf("\n-Bienvenue dans le jeu des divisions !-\n");
    Division();break;
    case 6 : printf("\n-Bienvenue dans le jeu des conversions d'unite de mesure !-\n");
    jeu_conversion(); break;
    case 7 : printf("\n-Bienvenue dans le jeu des conversions de duree !-\n");
    duree(); break;
    case 8 : printf("\n-Bienvenue dans le jeu des devinettes geometriques !-\n");
    jeuDevinette();break;
    default : printf("\nAu revoir !\n");
    }
printf("\nChoisissez parmis les chiffres suivants : \n"); //On refait la liste des choix pour qu'elle r�apparaisse suite au jeu pr�c�demment jou�
printf("1.Addition,\n");
printf("2.Soustraction,\n");
printf("3.Multiplication,\n");
printf("4.Table de multiplication,\n");
printf("5.Division,\n");
printf("6.Jeu des conversions d'unite de mesure,\n");
printf("7.Jeu des conversions de duree,\n");
printf("0.Sortir du jeu. \n");
scanf("%d",&n);
}
//Affichage en sortie
printf("Merci de votre visite !\n");
SauvegarderScore(nom, score);
AfficherDernierScore(nom);
AfficherScores();
return 0;
}


//Fonction permettant la cr�ation du jeu addition
int addition(){
    int v1,v2,r,s,essai=1;
    srand(time(NULL));
    v1=rand() %101; //rand permet d'assimiler � la variable une valeur al�atoire entre 1 et 100
    v2=rand()%100+1;
    printf("Combien fait %d + %d ?\n", v1, v2);
    r=v1+v2;
    printf("Entrez votre reponse :\n");
    scanf("%d",&s); //s va servir � comparer le r�sultat correcte "r" � la solution donn�e par le joueur
    //ci-dessous l'attribution des points selon le nombre de tentative du joueur
    while (essai<4)
    {
        if (s==r && essai==1)
        {
            printf("Bravo +10 !\n");
            score=score+10;
            essai=5; //j'ai utilis� cette m�thode pour qu'essai soit strictement sup�rieur � 3 et ainsi sortir de la boucle while
        }
        else
        {
            essai++;
            printf("Reessayez : Entrez votre reponse\n");
            scanf("%d",&s);
            if (s==r && essai==2)
            {
                printf("Bravo +5 !\n");
                score=score+5;
                essai=5;
            }
            else
            {
                essai++;
                printf("Reessayez : Entrez votre reponse\n");
                scanf ("%d",&s);
                if (s==r && essai==3)
                {
                    printf("Bravo +1 !\n");
                    score++;
                    essai=5;
                }
                else
                {
                    printf("Perdu... La bonne reponse etait %d\n",r);
                    essai++; //essai sera comme �a sup�rieur � 3 pour sortir de la boucle et �viter une boucle infinie
                }
            }
        }
    }
return EXIT_SUCCESS;
}


//Fonction permettant la cr�ation du jeu multiplication (le fonctionnement est indentique � celui de la fonction addition)
int multiplication(){
    int v1,v2,r,s,essai=1;
    srand(time(NULL));
    v1 = rand() %11;
    v2=rand()%10+1;
    printf("Combien fait %d x %d", v1, v2);
    r=v1*v2;
    printf("\nEntrez votre resultat \n");
    scanf("%d",&s);
    while (essai<4)
    {
        if (s==r && essai==1)
        {
            printf("Bravo +10 !\n");
            score=score+10;
            essai=5;
        }
        else
        {
            essai++;
            printf("Reessayez : Entrez votre reponse\n");
            scanf("%d",&s);
            if (s==r && essai==2)
            {
                printf("Bravo +5 !\n");
                score=score+5;
                essai=5;
            }
            else
            {
                essai++;
                printf("Reessayez : Entrez votre reponse\n");
                scanf ("%d",&s);
                if (s==r && essai==3)
                {
                    printf("Bravo +1 !\n");
                    score++;
                    essai=5;
                }
                else
                {
                    printf("Perdu... La bonne reponse etait %d\n",r);
                    essai++;
                }
            }
        }
    }
return EXIT_SUCCESS;
}


//Fonction permettant la cr�ation du jeu soustraction (le fonctionnement est indentique � celui de la fonction addition)
int soustraction(){
    int v1,v2,v3,r,s,essai=1;
    srand(time(NULL));
    v1 = rand() %101;
    v2=rand()%100+1;
    if (v1<v2) //Permution des valeurs afin de ne pas avoir de r�sultats n�gatifs
    {
        v3=v1;
        v1=v2;
        v2=v3;
    }
    printf("Combien fait %d - %d", v1, v2);
    r=v1-v2;
    printf("\nEntrez votre resultat \n");
    scanf("%d",&s);
    while (essai<4)
    {
        if (s==r && essai==1)
        {
            printf("Bravo +10 !\n");
            score=score+10;
            essai=5;
        }
        else
        {
            essai++;
            printf("Reessayez : Entrez votre reponse\n");
            scanf("%d",&s);
            if (s==r && essai==2)
            {
                printf("Bravo +5 !\n");
                score=score+5;
                essai=5;
            }
            else
            {
                essai++;
                printf("Reessayez : Entrez votre reponse\n");
                scanf ("%d",&s);
                if (s==r && essai==3)
                {
                    printf("Bravo +1 !\n");
                    score++;
                    essai=5;
                }
                else
                {
                    printf("Perdu... La bonne reponse etait %d\n",r);
                    essai++;
                }
            }
        }
    }
return EXIT_SUCCESS;
}


//Fonction permettant l'apprentissage les tables de multiplications
int table_multiplication(){
int j,n,m,r;
printf("Quelle table voulez vous afficher ?\n"); //S�lection par le joueur de la table � travailler
scanf("%d",&n); //Lecture
for (j=1;j<=10;j++) //Boucle Pour permettant d'afficher les calculs que le joueur devra effectuer et d'augmenter j de 1 jusqu'� ce que j soit �gal � 10
{
    printf("%d x %d = ...\n",n,j);
    printf("Entrez votre reponse :\n");
    scanf("%d",&r);
    m=j*n;
    if (m==r) //Comparaison de la solution correcte m avec le r�sultat r donn� par le joueur
    {
        printf("Bravo!\n");
        score=score+1;
    }
    else
    {
        printf("Perdu...La bonne reponse etait %d\n",m);
    }

}
}


//Fonction permettant la cr�ation du jeu division (le fonctionnement est indentique � celui de la fonction addition)
int Division(){
    int v1,v2,v3,r1,q1,r2,q2,essai=1;
    srand(time(NULL));
    v1 = rand() %101;
    v2=rand()%100+1;
    if (v1<v2) //Permution des valeurs afin de ne pas avoir de r�sultats n�gatifs
    {
        v3=v1;
        v1=v2;
        v2=v3;
    }
    printf("Combien fait %d / %d", v1, v2);
    q1=v1/v2; //la seule diff�rence est que nous comparons le quotient et le reste corrects avec les r�ponses donn�es par le joueur
    r1=v1%v2;
    printf("\nEntrez le quotient\n");
    scanf("%d",&q2);
    printf("Entrez le reste\n");
    scanf("%d",&r2);
    while (essai<4)
    {
        if (q1==q2 && r1==r2 && essai==1)
        {
            printf("Bravo +10 !\n");
            score=score+10;
            essai=5;
        }
        else
        {
            essai++;
            printf("Reessayez : Entrez le quotient\n");
            scanf("%d",&q2);
            printf("Et le reste :\n");
            scanf("%d",&r2);
            if (q1==q2 && r1==r2 && essai==2)
            {
                printf("Bravo +5 !\n");
                score=score+5;
                essai=5;
            }
            else
            {
                essai++;
                printf("Reessayez : Entrez le quotient\n");
                scanf ("%d",&q2);
                printf("Et le reste :\n");
                scanf("%d",&r2);
                if (q1==q2 && r1==r2 && essai==3)
                {
                    printf("Bravo +1 !\n");
                    score++;
                    essai=5;
                }
                else
                {
                    printf("Perdu... Les bonnes reponses etaient %d pour le quotient et %d pour le reste\n",q1,r1);
                    essai++;
                }
            }
        }
    }
return EXIT_SUCCESS;
}


//Fonction permettant de cr�er un nouveau fichier et d'y entrer l'historique des scores effectu�s
int SauvegarderScore(const char *nom, int score) {
    FILE *f = fopen("FICHIER_SCORES", "a"); //S�lection du fichier, ici "a" permet de cr�er un fichier et d'y ajouter des valeurs
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 0;
    } //Permet d'indiquer si le fichier n'existe pas pour sortir de la fonction
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(f, "%s %02d/%02d/%04d %02d:%02d:%02d %d\n",
            nom, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
            t->tm_hour, t->tm_min, t->tm_sec, score); //Ecriture dans le fichier du nom du joueur ainsi que la date et l'heure � laquelle il a jou�, puis son score
    fclose(f); //Marque la fin de la fonction car on ferme le fichier
    printf("Score sauvegarder avec succes\n");
}


//Fonction permettant de lire dans le fichier et d'afficher l'historique des scores effectu�s avec le pr�nom du joueur
int AfficherScores() {
    FILE *f = fopen("FICHIER_SCORES", "r"); //"r" ici vaut dire read donc lire pour faire la lecture des scores
    if (f == NULL) {
        printf("Aucun score enregistre pour le moment.\n");
        return 0;
    } //Permet d'indiquer si le fichier n'existe pas pour sortir de la fonction
    char ligne[100];
    printf("\n--- Scores enregistres ---\n");
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        printf("%s", ligne);
    } //fgets noius permet ici de lire chaque ligne une � une pour ensuite les afficher avec printf
    fclose(f);
}



//Fonction permettant de r�cup�rer un score en particulier dans le fichier selon le pr�nom entrer
int RecupererScore(const char *nom) {
    FILE *f = fopen("FICHIER_SCORES", "r"); //Lecture du fichier pour ensuite comparer les noms enregistr�s
    if (f == NULL) {
        return 0;
    }
    char nomFichier[50];
    int score = 0, dernierScore = 0;
    char date[20], heure[20];
    while (fscanf(f, "%s %s %s %d", nomFichier, date, heure, &score) == 4) { //Lecture des donn�es enregistr�es
        if (strcmp(nomFichier, nom) == 0) { //strcmp est une fonction de comparaison, ici on compare le nom indiqu� par le joueur avec ceux enregistr�s
            dernierScore = score; //Le dernier score enregistr� est donc incr�ment� au pointeur score de la fonction principal
        }
    }
    fclose(f);
    return dernierScore;
}



//Fonction permettant de cumuler l'ancien score s�lectionn� avec le nouveau et de sauvegarder ce nouveau score
int AfficherDernierScore(const char *nom) {
    FILE *f = fopen("FICHIER_SCORES", "r");
    if (f == NULL) {
        printf("Aucun score enregistre pour le moment.\n");
        return 0;
    }
    char nomFichier[50];
    int score = 0, dernierScore = 0;
    char date[20], heure[20];
    while (fscanf(f, "%s %s %s %d", nomFichier, date, heure, &score) == 4) {
        if (strcmp(nomFichier, nom) == 0) {
            dernierScore = score;
        }
    }
    fclose(f);
    if (dernierScore == 0) {
        printf("Aucun score trouv�");
    } else {
        printf("\n--- Score de %s ---\n", nom);
        printf("Date : %s %s\n", date, heure);
        printf("Score : %d\n", dernierScore);
    }
}


//Fonction permmettant de cr�er le jeu des conversions d'unit� de mesure (inspir� du site)
int jeu_conversion(){
    int n1,n2,essai=1;
    float v,r,s;
    srand(time(NULL));
    v=rand() %101;
    printf("Choisissez l'option a laquelle vous voulez jouer :\n");
    printf("1. Conversion de longueur (metres, centimetres, kilometres)\n");
    printf("2. Conversion de masse (grammes, kilogrammes)\n");
    printf("Entrez votre choix :\n");
    scanf("%d", &n1);
    if (n1==1) {
        printf("\n--- Conversion de Longueur ---\n");
        printf("1. Convertir des metres en centimetres\n");
        printf("2. Convertir des metres en kilometres\n");
        printf("3. Convertir des centimetres en metres\n");
        printf("4. Convertir des kilometres en metres\n");
        printf("Entrez votre choix :\n");
        scanf("%d",&n2);
        switch(n2){
        case 1 : printf("%.2f metres = ... centimetres\n",v);
        r=v*100; break;
        case 2 : printf("%.2f metres = ... kilometres\n",v);
        r=v/1000; break;
        case 3 : printf("%.2f centimetres = ... metres\n",v);
        r=v/100; break;
        case 4 : printf("%.2f kilometres = ... metres\n",v);
        r=v*1000; break;
        default : printf("Choix invalide...");}
        printf("\nEntrez votre r�sultat :");
        scanf("%f",&s);
         while (essai<4)
         {
             if (s==r && essai==1)
             {
                 printf("Bravo +10 !\n");
                 score=score+10;
                 essai=5;
             }
             else
             {
                 essai++;
                 printf("Reessayez : Entrez votre reponse\n");
                 scanf("%d",&s);
                 if (s==r && essai==2)
                 {
                     printf("Bravo +5 !\n");
                     score=score+5;
                     essai=5;
                 }
                 else
                 {
                     essai++;
                     printf("Reessayez : Entrez votre reponse\n");
                     scanf ("%d",&s);
                     if (s==r && essai==3)
                     {
                         printf("Bravo +1 !\n");
                         score++;
                         essai=5;
                     }
                     else
                     {
                         printf("Perdu... La bonne reponse etait %d\n",r);
                         essai++;
                     }
                 }
             }
        }
    }
    if (n1=2)
    {
        printf("\n--- Conversion de Masse ---\n");
        printf("1. Convertir des grammes en kilogrammes\n");
        printf("2. Convertir des kilogrammes en grammes\n");
        printf("Entrez votre choix :\n");
        scanf("%d",&n2);
        switch(n2){
        case 1 : printf("%.2f grammes = ... kilogrammes\n",v);
        r=v/1000; break;
        case 2 : printf("%.2f kilogrammes = ... grammes\n",v);
        r=v*1000; break;
        default : printf("Choix invalide...\n");}
        printf("Entrez votre r�ponse :\n");
        scanf("%f",&s);
        while (essai<4)
         {
             if (s==r && essai==1)
             {
                 printf("Bravo +10 !\n");
                 score=score+10;
                 essai=5;
             }
             else
             {
                 essai++;
                 printf("Reessayez : Entrez votre reponse\n");
                 scanf("%d",&s);
                 if (s==r && essai==2)
                 {
                     printf("Bravo +5 !\n");
                     score=score+5;
                     essai=5;
                 }
                 else
                 {
                     essai++;
                     printf("Reessayez : Entrez votre reponse\n");
                     scanf ("%d",&s);
                     if (s==r && essai==3)
                     {
                         printf("Bravo +1 !\n");
                         score++;
                         essai=5;
                     }
                     else
                     {
                         printf("Perdu... La bonne reponse etait %d\n",r);
                         essai++;
                     }
                 }
             }
        }
    }
    return EXIT_SUCCESS;
}


//Fonction permmettant de cr�er le jeu des conversions d'unit� de mesure (site)
int duree(){
    int v,r,s,essai=1;
    srand(time(NULL));
    v=rand()%11;
    printf("%d heures= ... minutes\n",v);
    printf("Entrez votre reponse :\n");
    scanf("%d",&s);
    r=v*60;
    while (essai<4)
    {
        if (s==r && essai==1)
        {
            printf("Bravo +10 !\n");
            score=score+10;
            essai=5;
        }
        else
        {
            essai++;
            printf("Reessayez : Entrez votre reponse\n");
            scanf("%d",&s);
            if (s==r && essai==2)
            {
                printf("Bravo +5 !\n");
                score=score+5;
                essai=5;
            }
            else
            {
                essai++;
                printf("Reessayez : Entrez votre reponse\n");
                scanf ("%d",&s);
                if (s==r && essai==3)
                {
                    printf("Bravo +1 !\n");
                    score++;
                    essai=5;
                }
                else
                {
                    printf("Perdu...La bonne reponse etait %d\n",r);
                    essai++;
                }
            }
        }
    }
return EXIT_SUCCESS;
}



//Fonction permettant de cr�er un jeu de devinette autour de la g�om�trie
int jeuDevinette(){
    int s,r,question,l,L,cote,forme,i;
    srand(time(NULL));
    for(i=1;i<=5;i++) //Boucle Pour afin d'avoir une succession de 5 devinettes
    {
        question=rand()%4; //Variable al�atoire pour choisir al�atoirement une notion
        switch (question) {
        case 0 : cote=rand()%10+1; //Notion de p�rim�tre d'un carr�
        printf("Devinette %d : Quel est le perimetre d'un carre de cote %d cm ?\n",i,cote);
        r=cote*4; break;
        case 1 : l=rand()%10+1;L=rand()%10+1; //Notion d'aire d'un rectangle
        printf("Devinette %d : Quelle est l'air d'un rectangle de longueur %d et de largeur %d ?\n",i,L,l);
        r=l*L; break;
        case 2 : forme=rand()%3; //Notion d'angles (0=carr�, 1=triangle, 2=pentagone)
        if (forme==0)
        {
            printf("Devinette %d : Combien d'angles a un carre ?\n",i);
            r=4;
        }
        else
        {
            if(forme==1)
            {
                printf("Devinette %d : Combien d'angles poss�de un triangle ?\n",i);
                r=3;
            }
            else
            {
                printf("Devinette %d : Combien d'angles poss�de un pentagone ?\n",i);
                r=5;
            }
        }
        break;
        case 3 : cote=rand()%3+3; //Notion de c�t�s
        printf("Choisissez entre triangle (1), carre/rectangle (2) ou pentagone (3)\n");
        if (cote==3)
        {
            printf("Devinette %d : Quelle est la forme geometrique qui possede 3 cotes ?\n",i);
            r=1;
        }
        else
        {
            if(cote==4)
            {
                printf("Devinette %d : Quelle est la forme geometrique qui possede 4 cotes ?\n",i);
                r=2;
            }
            else
            {
                printf("Devinette %d : Quelle est la forme geometrique qui possede 5 cotes ?\n",i);
                r=3;
            }
        }
        break;
        default : printf("Cjoix invalide...");}
        printf("Entrez votre reponse :\n");
        scanf("%d",&s);
        if(s==r)
        {
            printf("Bravo +2 !\n");
            score=score+2;
        }
        else
        {
            printf("Perdu... La bonne reponse etait %d",r);
        }
    }
    printf("\nVotre score final est de %d !\n",score);
    return EXIT_SUCCESS;
}
