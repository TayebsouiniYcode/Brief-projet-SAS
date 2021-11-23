#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//struct account
struct compte {
	char cin[10];
	char nom[20];
	char prenom[20];
	float montant;
};

struct compte c[1000];
int nbrAccount = 0;

//function Clean
void cleanCls(){
	system("cls||clear");
}

//fonction
bool addAccount(int n){
	//struct compte c[nbrAccount];
	int i;
	if (n==0) n = 1;
	for (i = 0 ; i < n; i++){
		printf("Entrer le CIN : ");
		scanf("%s", c[i].cin);
		
		printf("Entrer le nom : ");
		scanf("%s", c[i].nom);
		
		printf("Entrer le prenom : ");
		scanf("%s", c[i].prenom);
		
		printf("Entrer le montant : ");
		scanf("%f", &c[i].montant);
		nbrAccount++;
	}
	return true;
} 

//Depot
bool depot(char cin[10]) {
	
}
//fonction operation
bool operations(){
	int _choix, i;
	char cin[10];
	float operationValue;
	
	printf("Entrer le CIN du compte : ");
	scanf("%s", cin);

	cleanCls();
	do {
		printf("\n\n\n\n\n\n");
		printf("\t \t \t 1. Depot \n \n \n");
		printf("\t \t \t 2. Retrait \n \n \n");
		printf("\t \t \t 00. Menu principale \n");
		printf("Entrer un choix : ");
		scanf("%d", &_choix);
		
		switch (_choix) {
			case 1 : 
				cleanCls();
					for(i = 0; i < nbrAccount; i++) {
						if (strcmp(cin, c[i].cin) == 0) {
							printf("Entrer la valeur de depot : ");
							scanf("%f", &operationValue);
							c[i].montant += operationValue;
							
							printf("Le montant est : %g", c[i].montant);
						}
					}
				break;
			case 2 : 
				cleanCls();
				for(i = 0; i < nbrAccount; i++) {
						if (strcmp(cin, c[i].cin) == 0) {
							printf("Entrer la valeur de retrait : ");
							scanf("%f", &operationValue);
							if (c[i].montant >= operationValue)
								c[i].montant -= operationValue;
							else 
								printf("Votre solde est inferieur � %g \n", operationValue);
							
							printf("Le montant est : %g \n \n \n", c[i].montant);
						}
					}
				break;
			default : printf("Votre choix n exist pas \n");
		}
	}while (_choix != 0);
	cleanCls();
}


void affichage() {
	cleanCls();
	struct compte tempCompte;
	int _choix, __choix;
	int tri, i, j;
	do {
		printf("\t \t \t 1. tri par nom  \n \n \n");
		printf("\t \t \t 2. tri par montant \n \n \n");
		printf("\t \t \t 3. Recherche par CIN \n \n \n");
		printf("\t \t \t 00. Menu principale \n \n \n");
		printf("Entrer votre choix : ");
		scanf("%d", &_choix);
		
		switch (_choix) {
			case 1 : 
				printf("\t \t \t 1. ASC \n \n \n");
				printf("\t \t \t 2. DESC \n \n \n");
				printf("Entrer votre choix : ");
				scanf("%d", &__choix);
				switch (__choix) {
					case 1 : 
						for(i = 0 ; i < nbrAccount ; i++)
						{
						    for(j = 0 ; j < nbrAccount-i-1 ; j++)
						    {
						        //if(c[j].montant > c[j+1].montant)
						        if(strcmp(c[j].prenom, c[j+1].prenom) > 1)
						        {
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						
						//affichage
						printf("CIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
					case 2 :
						for(i = 0 ; i < nbrAccount ; i++)
						{
						    for(j = 0 ; j < nbrAccount-i-1 ; j++)
						    {
						        //if(c[j].montant > c[j+1].montant)
						        if(strcmp(c[j].prenom, c[j+1].prenom) < 0)
						        {
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						
						//affichage
						printf("CIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
						break;
				}
				break;
			case 2 : 
				printf("\t \t \t 1. ASC \n \n \n");
				printf("\t \t \t 2. DESC \n \n \n");
				printf("Entrer votre choix : ");
				scanf("%d", &__choix);
				switch (__choix) {
					case 1 :
						for(i = 0 ; i < nbrAccount ; i++)
						{
						    for(j = 0 ; j < nbrAccount-i-1 ; j++)
						    {
						        if(c[j].montant > c[j+1].montant)
						        {
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						
						//affichage
						printf("CIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
					case 2 : 
						for(i = 0 ; i < nbrAccount ; i++)
						{
						    for(j = 0 ; j < nbrAccount-i-1 ; j++)
						    {
						        if(c[j].montant < c[j+1].montant)
						        {
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						
						//affichage
						printf("CIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
				}

				break;
		}
	}while (_choix != 0);
}

int main(){
	int choix, nbrNewAccount, i;
	char data[50], cin[10];

	//Menu
	do {
		
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t 1. Introduire un compte \n\n\n");
		printf("\t\t\t\t 2. Introduire plusieurs comptes \n\n\n");
		printf("\t\t\t\t 3. Operations \n\n\n");
		printf("\t\t\t\t 4. Consultation \n\n\n");
		printf("\t\t\t\t 5. Fidelisation \n\n\n");
		printf("\t\t\t\t 0. Quitter \n\n\n");
		
		printf("Entrer votre choix : ");
		scanf("%d", &choix);
		
		switch (choix) {
			case 1 : 
				cleanCls();
				if(addAccount(0)){
					printf("Votre compte a ete cree avec succes ");
				} else {
					printf("Erreur !");
				}
				break;
			case 2 :
				printf("Entrer le nombre des comptes que vous pouvez cree : ");
				scanf("%d", &nbrNewAccount);
				addAccount(nbrNewAccount);
				break;
			case 3 :
				operations();
				break;
			case 4 : 
				affichage();
				break;
			case 6 : 
				cleanCls();
				break;
		}
		
		
	} while(choix != 0);
	
	
	return 0;
}
