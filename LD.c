////#define _CRT_SECURE_NO_WARNINGS
////#include<stdlib.h>
////#include<stdio.h>
////#include<string.h>
////
////struct InfoBiletFilm {
////	int id;
////	char* numeFilm;
////	char* dataDifuzare;
////	unsigned char rand;
////	double locRand;
////	float pret;
////};
////typedef struct InfoBiletFilm Bilet;
////
////void afisareBileteFilm(Bilet b) {
////	printf("\nDetaliile pentru biletul cu nr %d , sunt:\n", b.id);
////	printf("Nume film: %s\n", b.numeFilm);
////	printf("Data difuzare la cinema: %s\n", b.dataDifuzare);
////	printf("Locul se afla pe randul: %c\n", b.rand);
////	printf("Nr loc: %.2f\n", b.locRand);
////	printf("Pret bilet: %5.2f\n", b.pret);
////}
////
////Bilet citireBileteFisier(FILE* file) {
////
////	Bilet b;
////	char buffer[100];
////	char sep[3] = ",\n";
////	fgets(buffer, 100, file);
////
////	b.id = atoi(strtok(buffer, sep));
////	char* aux;
////	aux = strtok(NULL, sep);
////	b.numeFilm = (char*)malloc(strlen(aux) + 1);
////	strcpy(b.numeFilm, aux);
////	aux = strtok(NULL, sep);
////	b.dataDifuzare = (char*)malloc(strlen(aux) + 1);
////	strcpy(b.dataDifuzare, aux);
////	b.rand = strtok(NULL, sep)[0];
////	b.locRand = strtod(strtok(NULL, sep), NULL);
////	b.pret = atof(strtok(NULL, sep));
////	return b;
////}
//
//struct Nod {
//	Bilet infoUtil;
//	struct Nod* next;
//	struct Nod* prev;
//};
//typedef struct Nod Nod;
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//	int nrNoduri;
//};
//typedef struct ListaDubla ListaDubla;
//
//void afisareBileteFilmInceputLD(ListaDubla lista) {
//
//	Nod* capAux = lista.first;
//	while (capAux != NULL) {
//		afisareBileteFilm(capAux->infoUtil);
//		capAux = capAux->next;
//	}
//}
//
//void afisareBileteFilmSfarsitLD(ListaDubla lista) {
//
//	Nod* capAux = lista.last;
//	while (capAux != NULL) {
//		afisareBileteFilm(capAux->infoUtil);
//		capAux = capAux->prev;
//	}
//}
//
//void adaugareBiletLDInceput(ListaDubla* lista, Bilet biletNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = biletNou;
//	nou->next = lista->first;
//	nou->prev = NULL;
//
//	if (lista->first != NULL) {
//		lista->first->prev = nou;
//	}
//	else {
//		lista->last = nou;
//	}
//	lista->first = nou;
//	lista->nrNoduri++;
//}
//
//void adaugareBiletLDSfarsit(ListaDubla* lista, Bilet biletNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = biletNou;
//	nou->next = NULL;
//	nou->prev = lista->last;
//
//	if (lista->last != NULL) {
//		lista->last->next = nou;
//	}
//	else {
//		lista->first = nou;
//	}
//	lista->last = nou;
//	lista->nrNoduri++;
//}
//
//ListaDubla citireBileteFilmLDFisier(const char* numeFisier) {
//
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareBiletLDSfarsit(&lista, citireBileteFisier(file));
//		}
//	}
//	fclose(file);
//	return lista;
//}
//
//void dezalocareLD(ListaDubla* lista) {
//
//	Nod* nodAux = lista->first;
//	while (nodAux != NULL) {
//		Nod* capAux = nodAux;
//		capAux = capAux->next;
//		if (capAux->infoUtil.numeFilm != NULL) {
//			free(capAux->infoUtil.numeFilm);
//		}
//		if (capAux->infoUtil.dataDifuzare != NULL) {
//			free(capAux->infoUtil.dataDifuzare);
//		}
//		free(capAux);
//	}
//}
//
//void stergeBiletLD(ListaDubla* lista, int idCautat) {
//
//	if (lista->first == NULL) {
//		return;
//	}
//	Nod* capAux = lista->first;
//	while (capAux != NULL && capAux->infoUtil.id !=idCautat) {
//		capAux = capAux->next;
//	}
//	if (capAux == NULL) {
//		return;
//	}
//
//	if (capAux->prev == NULL) {
//		lista->first = capAux->next;
//		if (lista->first != NULL) {
//			lista->first->prev = NULL;
//		}
//	}
//	else {
//		capAux->prev->next = capAux->next;
//		if (capAux->next != NULL) {
//			capAux->next->prev = capAux->prev;
//		}
//		else {
//			capAux->prev->prev = NULL;
//		}
//		if (capAux->infoUtil.numeFilm != NULL) {
//			free(capAux->infoUtil.numeFilm);
//		}
//		if (capAux->infoUtil.dataDifuzare != NULL) {
//			free(capAux->infoUtil.dataDifuzare);
//		}
//		free(capAux);
//	}
//	lista->nrNoduri--;
//}
//
//float mediePretBilet(ListaDubla lista) {
//
//	float sumaBilete = 0;
//	if (lista.nrNoduri > 0) {
//		Nod* nou = lista.first;
//		while (nou != NULL) {
//			sumaBilete += nou->infoUtil.pret;
//			nou = nou->next;
//		}
//		return sumaBilete / lista.nrNoduri;
//	}
//	return 0;
//}
//
//int main() {
//
//	ListaDubla lista = citireBileteFilmLDFisier("bilete_film.txt");
//	printf("\n----------------------\n");
//	printf("\nAfisarea bilete de la inceput!\n");
//	printf("\n----------------------\n");
//	afisareBileteFilmInceputLD(lista);
//
//	printf("\n----------------------\n");
//	printf("\nAfisarea bilete de la sfarsit!\n");
//	printf("\n----------------------\n");
//	afisareBileteFilmSfarsitLD(lista);
//
//	printf("\n----------------------\n");
//	printf("\Afisarea mediei preturilor biletelor:%5.2f \n", mediePretBilet(lista));
//	printf("\n----------------------\n");
//
//	printf("\n----------------------\n");
//	printf("\nAfisare LD bilete dupa stergerea biletlui cu id-ul 1: \n");
//	stergeBiletLD(&lista, 1);
//	afisareBileteFilmInceputLD(lista);
//	printf("\n----------------------\n");
//
//	printf("\n----------------------\n");
//	printf("\nAfisare LD dupa dezalocare!\n");
//	printf("\n----------------------\n");
//
//	return 0;
//}