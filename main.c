#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct compte{ char cin[10]; char nom[20]; char prenom[20]; float montant;};
struct compte c[1000];
int nbrAccount = 0;

void charginDataToC(){
	int i = 0;
	struct compte p;
	FILE *file;
	file = fopen("data.txt", "r");
	while (1){
		fscanf(file, "%s %s %s %f", c[nbrAccount].nom, c[nbrAccount].prenom, c[nbrAccount].cin, &c[nbrAccount].montant);
		if (strlen(c[nbrAccount].cin) == 0){
			printf("Ligne vide");
		} else 
			nbrAccount++;
		if (feof(file)){
			break;
		}
	}
	fclose(file);
}
void cleanCls(){system("cls||clear");}
bool addAccount(int n){
	int i;
	for (i = 0 ; i < n; i++){
		printf("Entrer le CIN : ");
		scanf("%s", c[nbrAccount].cin);
		
		if(strcmp(c[nbrAccount].cin, "exit") == 0) { break;}
		
		printf("Entrer le nom : ");
		scanf("%s", c[nbrAccount].nom);
		printf("Entrer le prenom : ");
		scanf("%s", c[nbrAccount].prenom);
		printf("Entrer le montant : ");
		scanf("%f", &c[nbrAccount].montant);
		
		nbrAccount++;
		cleanCls();
		printf("\n \n \n Compte ajouter avec succes \n \n \n");
	}
} 
bool operations(){
	int _choix, i;
	char cin[10];
	float operationValue;
	
	printf("Entrer le CIN du compte : ");
	scanf("%s", cin);
	do {
		cleanCls();
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
								printf("Votre solde est inferieur à %g \n", operationValue);
							
							printf("Le montant est : %g \n \n \n", c[i].montant);
						}
					}
				break;
			default : printf("Votre choix n exist pas \n");
		}
	}while (_choix != 0);
	cleanCls();
}
bool getCIN() {
	int i;
	char cin[10];
	bool Trouve = false;
	printf("Entrer le CIN : ");
	scanf("%s", cin);
	for (i = 0; i < nbrAccount ; i++) {
		if(strcmp(c[i].cin, cin) == 0)
			Trouve = true;
	}
	if (Trouve) 
		printf("CIN Trouve \n");
	else 
		printf("CIN non trouve \n");
}
void affichage() {
	cleanCls();
	struct compte tempCompte;
	int _choix,i, j;
	float min;
	char cin[10];
	do {
		printf("\n\n\n\n\t \t \t \t\t 1. tri par nom  \n \n \n");
		printf("\t \t \t \t\t 2. tri par montant \n \n \n");
		printf("\t \t \t \t\t 3. Recherche par CIN \n \n \n");
		printf("\t \t \t \t\t 00. Menu principale \n \n \n");
		printf("Entrer votre choix : ");
		scanf("%d", &_choix);
		
		switch (_choix) {
			case 1 : 
				cleanCls();
				printf("\n\n\n\n\t \t \t \t\t 1. ASC \n \n \n");
				printf("\t \t \t \t\t 2. DESC \n \n \n");
				printf("Entrer votre choix : ");
				scanf("%d", &_choix);
				switch (_choix) {
					case 1 : 
						for(i = 0 ; i < nbrAccount ; i++){
						    for(j = 0 ; j < nbrAccount-i-1 ; j++){
						        if(strcmp(c[j].nom, c[j+1].nom) > 0){
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						printf("\n\n\n\t\t\tCIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("\t\t\t---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("\t\t\t%s \t %s \t %s \t %g \n\n\n\n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						
						break;
					case 2 :
						for(i = 0 ; i < nbrAccount ; i++){
						    for(j = 0 ; j < nbrAccount-i-1 ; j++){
						        if(strcmp(c[j].nom, c[j+1].nom) < 0){
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						printf("\n\n\n\t\t\tCIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("\t\t\t---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) 
							printf("\t\t\t%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						break;
				}
				break;
			case 2 : 
				printf("\t \t \t 1. ASC \n \n \n");
				printf("\t \t \t 2. DESC \n \n \n");
				printf("Entrer votre choix : ");
				scanf("%d", &_choix);
				switch (_choix) {
					case 1 :
						for(i = 0 ; i < nbrAccount ; i++){
						    for(j = 0 ; j < nbrAccount-i-1 ; j++){
						        if(c[j].montant > c[j+1].montant){
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						printf("Entrer la valeur MIN : ");
						scanf("%f", &min);
						printf("\n\n\n \t\t\tCIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							if(c[i].montant >= min)
								printf("\t\t\t %s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
					case 2 : 
						for(i = 0 ; i < nbrAccount ; i++){
						    for(j = 0 ; j < nbrAccount-i-1 ; j++){
						        if(c[j].montant < c[j+1].montant){
						        	tempCompte = c[j+1];
						            c[j+1]=c[j];
						            c[j]=tempCompte;
						        }
						    }
						}
						printf("Entrer la valeur MIN : ");
						scanf("%f", &min);
						printf("\n\n\n \t\t\tCIN \t NOM \t PRENOM \t MONTANT\n\n");
						printf("---------------------------------- \n \n ");
						for (i = 0 ; i < nbrAccount ; i++) {
							printf("\t\t\t%s \t %s \t %s \t %g \n", c[i].cin, c[i].nom, c[i].prenom, c[i].montant);
						}
						break;
				}
				break;
				case 3 :
						getCIN();
						break;
		}
	}while (_choix != 0);
}
bool fedilisation() {
	int i, j;
	struct compte tempCompte;
	for(i = 0 ; i < nbrAccount ; i++){
	    for(j = 0 ; j < nbrAccount-i-1 ; j++){
	        if(c[j].montant < c[j+1].montant){
	        	tempCompte = c[j+1];
	            c[j+1]=c[j];
	            c[j]=tempCompte;
	        }
	    }
	}
	for (i = 0 ; i < 3 ; i++) 
		c[i].montant += (c[i].montant * 1.3) / 100;
	
	cleanCls();
	printf("Les trois premier compte a ajouter 1.3 %s avec succes", "%");
}
void getAccount() {
	int i;
	if(nbrAccount > 0){
		printf("\t\t\t NOM \t\t | PRENOM \t\t | CIN \t\t | MONTANT | \n");
		for(i = 0; i < nbrAccount; i++) 
			printf("\t\t\t%s \t\t %s \t\t %s \t\t %f \n", c[i].nom, c[i].prenom, c[i].cin, c[i].montant);	
	} else 
		printf("il n y a pas de comptes !!");
}
double getSum(){
	int i;
	double sum = 0;
	for (i = 0; i < nbrAccount ; i++){
		sum += c[i].montant;
	}
	
	return sum;
}
double getAverage() {
	int i;
	double average, sum;
	average =  getSum() / nbrAccount;

	return average;
}
int main(){
	charginDataToC();
	
	
	int choix, nbrNewAccount, i;
	char cin[10];
	test:
	do {
		//cleanCls();
		printf("\n\n\n\n");
		printf("\t\t\t\t 1. Introduire un compte \n\n");
		printf("\t\t\t\t 2. Introduire plusieurs comptes \n\n");
		printf("\t\t\t\t 3. Operations \n\n");
		printf("\t\t\t\t 4. Consultation \n\n");
		printf("\t\t\t\t 5. Fidelisation \n\n");
		printf("\t\t\t\t 6. State \n\n");
		printf("\t\t\t\t 7. Nombre des comptes  \n\n");
		printf("\t\t\t\t 8. La somme des montants \n\n");
		printf("\t\t\t\t 9. La moyenne des la totalités des montants \n\n");
		printf("\t\t\t\t 0. Quitter \n\n");
		
		printf("Entrer votre choix : ");
		scanf("%d", &choix);
		
		switch (choix) {
			case 1 : addAccount(1);	break;
			case 2 :
				printf("Entrer le nombre des comptes que vous voulez cree : ");
				scanf("%d", &nbrNewAccount);
				addAccount(nbrNewAccount);
				break;
			case 3 :	operations();	break;
			case 4 : 	affichage();	break;
			case 5 : 	fedilisation();	break;
			case 6 : 	getAccount();	break;
			case 7 :	cleanCls();		printf("les comptes : %d", nbrAccount);	break;
			case 8 :	cleanCls();		printf(" La somme des montant dans la banque est : %f ", getSum());	 break;
			case 9 :	cleanCls();		printf("La moyenne est : %f \n", getAverage());	break;
			default : 	cleanCls();	printf(" \n \n \n \n \n \n \n  \t\t\t\t Votre choix n'est pas valide !");
						 getchar(); goto test;
						 
		}	
	} while(choix != 0);
	
	FILE *file;
	file = fopen("data.txt", "w");
	for (i = 0 ; i < nbrAccount ; i++){
		fprintf(file, "%s %s %s %f", c[i].nom, c[i].prenom, c[i].cin, c[i].montant);
	}
	fclose(file);
	return 0;
}
