//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//void afisareMasina(Masina masina) {
//	printf("ID:%d\n", masina.id);
//	printf("Numar usi:%d\n", masina.nrUsi);
//	printf("Pret:%.2f\n", masina.pret);
//	printf("Model:%s\n", masina.model);
//	printf("Nume sofer:%s\n", masina.numeSofer);
//	printf("Serie:%c\n\n", masina.serie);
//}
//
//void afisareVector(Masina* masini, int nrMasini) {
//	for (int i = 0; i < nrMasini; i++) {
//		afisareMasina(masini[i]);
//	}
//}
//
//void adaugareMasinaInVector(Masina** masini, int* nrMasini, Masina masinaNoua) {
//	Masina* vectorAux = (Masina*)malloc(sizeof(Masina) * ((*nrMasini) + 1));
//	for (int i = 0; i < (*nrMasini); i++) {
//		vectorAux[i] = (*masini)[i];
//	}
//	vectorAux[(*nrMasini)] = masinaNoua;
//	free(*masini);
//	(*masini) = vectorAux;
//	(*nrMasini)++;
//}
//
//Masina citireMasinaFisier(FILE* file) {
//	Masina m;
//	char buffer[100]; //bufferul unde va citi
//	char sep[4] = ",;\n"; //definim separatoarele pentru fisier
//	fgets(buffer, 100, file); //ne folosim de aceasta functie pentru a citi tot randul din fisier
//	//primeste 3 parametri, bufferul, nr maxim de caractere, stream-ul
//
//	m.id = atoi(strtok(buffer, sep)); //ne folosim de functia atoi (ASCII to Integer)
//	//strtok returneaza un sir de caractere(un tokken, adica gaseste ce gaseste pana la primul separator)
//	//primeste parametri: 1. sirul de caractere pe care vreau sa-l sparg(buffer) si 2.delimitatorul(sep)
//	m.nrUsi = atoi(strtok(NULL, sep));
//	m.pret = atof(strtok(NULL, sep));
//	char* aux; //pentru un sir de caractere ne declaram un aux in care vom avea acel sir
//	aux = strtok(NULL, sep);
//	m.model = (char*)malloc(strlen(aux) + 1);//alocam zona de memorie si de asemenea determinam dimensiunea sirului de caractere
//	strcpy(m.model, aux);
//	aux = strtok(NULL, sep);
//	m.numeSofer = (char*)malloc(strlen(aux) + 1);
//	strcpy(m.numeSofer, aux);
//	m.serie = strtok(NULL, sep)[0];
//	return m;
//}
//
//Masina* citireMasinaVector(const char* numeFisier, int* nrMasini) {
//	FILE* file = fopen(numeFisier, "r");
//	//declaram un nou vector
//	Masina* masini = NULL;
//	(*nrMasini) = 0;
//	//trebuie sa verificam daca am ajuns sau nu la sfarsitul fisierului, pentru asta ne folosim de functie feof(FILE END OF FILE)
//	while (!feof(file)) {
//		adaugareMasinaInVector(&masini, nrMasini, citireMasinaFisier(file));
//	}
//	//ATENTIE de inchis fisierul la final
//	fclose(file);
//	return masini;
//}
//
//void dezalocareVector(Masina** masini, int* nrMasini) {
//	for (int i = 0; i < (*nrMasini); i++) {
//		if (((*masini)[i].model != NULL) && ((*masini)[i].numeSofer != NULL)) {
//			free((*masini)[i].model);
//			free((*masini)[i].numeSofer);
//		}
//	}
//	free(*masini);
//	(*masini) = NULL;
//	*nrMasini = 0;
//}
//
//int main() {
//	
//	int nrMasini = 0;
//	Masina* masini = citireMasinaVector("masini.txt", &nrMasini);
//	afisareVector(masini, nrMasini);
//	return 0;
//}