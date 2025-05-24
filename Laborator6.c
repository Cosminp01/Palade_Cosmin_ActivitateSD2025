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
//
//typedef struct StructuraMasina Masina;
//
//struct Nod {
//	Masina infoUtil;
//	struct Nod* next;
//};
//
//typedef struct Nod Nod;
//
//struct HashTable {
//	int dim;
//	Nod** vectorTabela;
//};
//typedef struct HashTable HashTable;
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
//Masina citireMasiniFisier(FILE* file) {
//	Masina m;
//	char buffer[100];
//	char sep[4] = ",;\n";
//	fgets(buffer, 100, file);
//
//	m.id = atoi(strtok(buffer, sep));
//	m.nrUsi = atoi(strtok(NULL, sep));
//	m.pret = atof(strtok(NULL, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	m.model = (char*)malloc(strlen(aux) + 1);
//	strcpy(m.model, aux);
//	aux = strtok(NULL, sep);
//	m.numeSofer = (char*)malloc(strlen(aux) + 1);
//	strcpy(m.numeSofer, aux);
//	m.serie = strtok(NULL, sep)[0];
//	return m;
//}
//
//void afisareLS(Nod* cap) {
//	while (cap != NULL) {
//		afisareMasina(cap->infoUtil);
//		cap = cap->next;
//	}
//}
//
//void adaugareNodLS(Nod* cap, Masina nouamasina) {
//
//	Nod* capAux = cap;
//	if (capAux->next != NULL) {
//		capAux = capAux->next;
//	}
//
//	Nod* nodAux = (Nod*)malloc(sizeof(Nod));
//	nodAux->infoUtil = nouamasina;
//	nodAux->next = NULL;
//	capAux->next = nodAux;
//}
//
//HashTable initializareTabela(int dimensiune) {
//
//	HashTable ht;
//	ht.dim = dimensiune;
//	ht.vectorTabela = (Nod**)malloc(dimensiune * sizeof(Nod*));
//	for (int i = 0; i < dimensiune; i++) {
//		ht.vectorTabela[i] = NULL;
//	}
//	return ht;
//}
//
//int calculeazaHash(const char* nume, int dimensiune) {
//
//	int suma = 0;
//	for (int i = 0; i < strlen(nume); i++) {
//		suma += nume[i];
//	}
//	return suma % dimensiune;
//}
//
//void adaugareMasinaInTabela(HashTable table, Masina masinaNoua) {
//
//	int pozitie = calculeazaHash(masinaNoua.numeSofer, table.dim);
//	if (table.vectorTabela[pozitie] == NULL) {
//		table.vectorTabela[pozitie] = (Nod*)malloc(sizeof(Nod));
//		table.vectorTabela[pozitie]->infoUtil = masinaNoua;
//		table.vectorTabela[pozitie]->next = NULL;
//	}
//	else {
//		adaugareNodLS(table.vectorTabela[pozitie], masinaNoua);
//	}
//}
//
//HashTable citireTabelaMasiniFisier(const char* numeFisier, int dimensiune) {
//
//	HashTable hash = initializareTabela(dimensiune);
//
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			Masina masinaNoua = citireMasiniFisier(file);
//			adaugareMasinaInTabela(hash, masinaNoua);
//		}
//	}
//	fclose(file);
//	return hash;
//}
//
//void afisareTabelaMasiniFisier(HashTable ht) {
//	
//	for (int i = 0; i < ht.dim; i++) {
//		if (ht.vectorTabela[i] != NULL) {
//			printf("\nMasinile de pe pozitia %d, sunt:\n", i);
//			afisareLS(ht.vectorTabela[i]);
//		}
//		else {
//			printf("\nNu avem masini pe pozitia %d \n", i);
//		}
//	}
//}
//
//int main()
//{
//	HashTable ht = citireTabelaMasiniFisier("masini.txt",7);
//	afisareTabelaMasiniFisier(ht);
//	return 0;
//}