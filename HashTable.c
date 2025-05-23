//#define _CRT_SECURE_NO_WARNINGS
//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//
//struct InfoBiletFilm {
//	int id;
//	char* numeFilm;
//	char* dataDifuzare;
//	unsigned char rand;
//	double locRand;
//	float pret;
//};
//typedef struct InfoBiletFilm Bilet;
//
//void afisareBileteFilm(Bilet b) {
//	printf("\nDetaliile pentru biletul cu nr %d , sunt:\n", b.id);
//	printf("Nume film: %s\n", b.numeFilm);
//	printf("Data difuzare la cinema: %s\n", b.dataDifuzare);
//	printf("Locul se afla pe randul: %c\n", b.rand);
//	printf("Nr loc: %.2f\n", b.locRand);
//	printf("Pret bilet: %5.2f\n", b.pret);
//}
//
//Bilet citireBileteFisier(FILE* file) {
//
//	Bilet b;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	b.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	b.numeFilm = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.numeFilm, aux);
//	aux = strtok(NULL, sep);
//	b.dataDifuzare = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.dataDifuzare, aux);
//	b.rand = strtok(NULL, sep)[0];
//	b.locRand = strtod(strtok(NULL, sep), NULL);
//	b.pret = atof(strtok(NULL, sep));
//	return b;
//}
//
//struct Nod {
//	Bilet infoUtil;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//struct HashTable {
//	int dim;
//	Nod** tabelaVector;
//};
//typedef struct HashTable HashTable;
//
//void afisareBileteFilmLS(Nod* cap) {
//	while (cap != NULL) {
//		afisareBileteFilm(cap->infoUtil);
//		cap = cap->next;
//	}
//}
//
//void adaugareBiletFilmLS(Nod* cap, Bilet biletNou) {
//
//	Nod* capAux = cap;
//	if(capAux->next != NULL) {
//		cap = capAux->next;
//	}
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = biletNou;
//	nou->next = NULL;
//	capAux->next = nou;
//}
//
//void dezalocareLS(Nod** cap) {
//	while (*cap != NULL) {
//		Nod* capAux = *cap;
//		*cap = (*cap)->next;
//		if (capAux->infoUtil.numeFilm != NULL) {
//			free(capAux->infoUtil.numeFilm);
//		}
//		if (capAux->infoUtil.dataDifuzare != NULL) {
//			free(capAux->infoUtil.dataDifuzare);
//		}
//		free(capAux);
//	}
//	*cap = NULL;
//}
//
//void afisareBileteFilmTabela(HashTable table) {
//
//	for (int i = 0; i < table.dim; i++) {
//		if (table.tabelaVector[i] != NULL) {
//			printf("\nLista biletelor de pe pozitia %d, sunt: \n", i);
//			afisareBileteFilmLS(table.tabelaVector[i]);
//		}
//		else {
//			printf("\nLista de pe pozitia %d, nu contine niciun bilet!\n", i);
//		}
//	}
//}
//
//HashTable initializareTabela(int dimensiune) {
//
//	HashTable table;
//	table.dim = dimensiune;
//	table.tabelaVector = (Nod**)malloc(dimensiune * sizeof(Nod*));
//	for (int i = 0; i < dimensiune; i++) {
//		table.tabelaVector[i] = NULL;
//	}
//	return table;
//}
//
//int calculeazaMetodaHash(const char* filmCautat, int dimensiune) {
//
//	int sumaASCI = 0;
//	for (int i = 0; i < strlen(filmCautat); i++) {
//		sumaASCI += filmCautat[i];
//	}
//	return sumaASCI % dimensiune;
//}
//
//void adaugareBiletFilmTabela(HashTable table,Bilet biletNou) {
//
//	int pozitie = calculeazaMetodaHash(biletNou.numeFilm, table.dim);
//		if (table.tabelaVector[pozitie] == NULL) {
//			table.tabelaVector[pozitie] = (Nod*)malloc(sizeof(Nod));
//			table.tabelaVector[pozitie]->infoUtil = biletNou;
//			table.tabelaVector[pozitie]->next = NULL;
//		}
//		else {
//			adaugareBiletFilmLS(table.tabelaVector[pozitie], biletNou);
//		}
//}
//
//HashTable citireBileteFilmTabelaFisier(const char* numeFisier, int dimensiune) {
//
//	HashTable ht = initializareTabela(dimensiune);
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			Bilet bilet = citireBileteFisier(file);
//			adaugareBiletFilmTabela(ht, bilet);
//		}
//	}
//	fclose(file);
//	return ht;
//}
//
//void dezalocareTabela(HashTable* table) {
//	for (int i = 0; i < table->dim; i++) {
//		dezalocareLS(&(table->tabelaVector[i]));
//	}
//	free(table->tabelaVector);
//	table->tabelaVector = NULL;
//	table->dim = 0;
//}
//
//int main()
//{
//	int nrBilete = 0;
//	HashTable table = citireBileteFilmTabelaFisier("bilete_film.txt", 10);
//	afisareBileteFilmTabela(table);
//	return 0;
//}