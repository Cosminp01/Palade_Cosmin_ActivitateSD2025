//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct InfoRouter {
//	int id;
//	char* producator;
//	char* model;
//	double serie;
//	unsigned char tip;
//	float pret;
//};
//
//typedef struct InfoRouter Router;
//
//struct Nod {
//	Router infoUtil;
//	struct Nod* next;
//	struct Nod* prev;
//};
//
//typedef struct Nod Nod;
//
//struct ListaDubla {
//	Nod* first;
//	Nod* last;
//	int nrNoduri;
//};
//
//typedef struct ListaDubla ListaDubla;
//
//void afisareRoutere(Router r) {
//
//	printf("Caracteristicile pentru Router-ul %d, sunt:\n", r.id);
//	printf("Producator: %s\n", r.producator);
//	printf("Model: %s\n", r.model);
//	printf("Seria: %.2f\n", r.serie);
//	printf("Tipul: %c\n", r.tip);
//	printf("Pret: %5.2f\n\n", r.pret);	
//}
//
//Router citireRoutereFisier(FILE* file) {
//
//	Router r;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	r.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	r.producator = (char*)malloc(strlen(aux) + 1);
//	strcpy(r.producator, aux);
//	aux = strtok(NULL, sep);
//	r.model = (char*)malloc(strlen(aux) + 1);
//	strcpy(r.model, aux);
//	r.serie = strtod(strtok(NULL, sep), NULL);
//	r.tip = strtok(NULL, sep)[0];
//	r.pret = atof(strtok(NULL, sep));
//	return r;
//}
//
//void afisareListaDublaInceput(ListaDubla lista) {
//	Nod* nou = lista.first;
//	while (nou != NULL) {
//		afisareRoutere(nou->infoUtil);
//		nou = nou->next;
//	}
//}
//
//void afisareListaDublaSfarsit(ListaDubla lista) {
//	Nod* nou = lista.last;
//	while (nou != NULL) {
//		afisareRoutere(nou->infoUtil);
//		nou = nou->prev;
//	}
//}
//
//void adaugareNodListaDublaSfarsit(ListaDubla* lista, Router routerNou) {
//	
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = routerNou;
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
//void adaugareNodListaDublaInceput(ListaDubla* lista, Router routerNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = routerNou;
//	nou->prev = NULL;
//	nou->next = lista->first;
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
//ListaDubla citireRoutereListaDublaFisier(const char* numeFisier) {
//
//	ListaDubla lista;
//	lista.first = NULL;
//	lista.last = NULL;
//	lista.nrNoduri = 0;
//
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareNodListaDublaSfarsit(&lista, citireRoutereFisier(file));
//		}
//	}
//	fclose(file);
//	return lista;
//}
//
//void dezalocareListaDubla(ListaDubla* lista) {
//
//	Nod* nodAux = lista->first;
//	while (nodAux != NULL) {
//		Nod* capAux = nodAux->next;
//		capAux = capAux->next;
//		if (capAux->infoUtil.producator != NULL) {
//			free(capAux->infoUtil.producator);
//		}
//		if (capAux->infoUtil.model != NULL) {
//			free(capAux->infoUtil.model);
//		}
//		free(capAux);
//	}
//	lista->first = NULL;
//	lista->last = NULL;
//	lista->nrNoduri = 0;
//}
//
//void stergereNodListaDubla(ListaDubla* lista, int idCautat) {
//
//	if (lista->first == NULL) {
//		return;
//	}
//	Nod* capAux = lista->first;
//	while (capAux != NULL && capAux->infoUtil.id != idCautat) {
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
//			lista->last = capAux->prev;
//		}
//	}
//	if (capAux->infoUtil.producator != NULL) {
//		free(capAux->infoUtil.producator);
//	}
//	if (capAux->infoUtil.model != NULL) {
//		free(capAux->infoUtil.model);
//	}
//	free(capAux);
//	lista->nrNoduri--;
//}
//
//float mediaPretRoutere(ListaDubla lista) {
//
//	float sumaTotala = 0;
//	if (lista.nrNoduri > 0) {
//		Nod* capAux = lista.first;
//		if (capAux != NULL) {
//			sumaTotala += capAux->infoUtil.pret;
//			capAux = capAux->next;
//		}
//		return sumaTotala / lista.nrNoduri;
//	}
//	return 0;
//}
//
//int main()
//{
//	ListaDubla lista = citireRoutereListaDublaFisier("routere.txt");
//	afisareListaDublaInceput(lista);
//
//	printf("\n--------------\n");
//	printf("\nMedia preturilor este: %5.2f", mediaPretRoutere(lista));
//	printf("\n--------------\n");
//
//	printf("\n--------------\n");
//	printf("\nAfisare LD in sens invers!\n");
//	printf("\n--------------\n\n");
//	stergereNodListaDubla(&lista, 3);
//	afisareListaDublaSfarsit(lista);
//
//	printf("\nAfisare lista dupa dezalocarea memoriei!\n");
//	dezalocareListaDubla(&lista);
//	return 0;
//}