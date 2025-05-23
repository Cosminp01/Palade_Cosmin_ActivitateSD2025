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
//};
//
//typedef struct Nod Nod;
//
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
//void afisareRoutereLS(Nod* cap) {
//
//	while (cap != NULL) {
//		afisareRoutere(cap->infoUtil);
//		cap = cap->next;
//	}
//}
//
//void adaugareNodSfarsitLS(Nod** cap, Router routerNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = routerNou;
//	nou->next = NULL;
//
//	if ((*cap) != NULL) {
//		Nod* capAux = (*cap);
//		while (capAux->next != NULL) {
//			capAux = capAux->next;
//		}
//		capAux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//}
//
//void adaugareNodInceputLS(Nod** cap, Router routerNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = routerNou;
//	nou->next = *cap;
//	*cap = nou;
//}
//
//Router* citireRoutereLSFisier(const char* numeFisier) {
//
//	Nod* cap = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareNodSfarsitLS(&cap, citireRoutereFisier(file));
//		}
//	}
//	fclose(file);
//	return cap;
//}
//
//void dezalocareLS(Nod** cap) {
//
//	while ((*cap) != NULL) {
//		Nod* capAux = *cap;
//		*cap = (*cap)->next;
//		if (capAux->infoUtil.producator != NULL) {
//			free(capAux->infoUtil.producator);
//		}
//		if (capAux->infoUtil.model != NULL) {
//			free(capAux->infoUtil.model);
//		}
//		free(capAux);
//	}
//}
//
//void stergereNodLS(Nod** cap, int serieCautata) {
//
//	while ((*cap) != NULL && (*cap)->infoUtil.tip == serieCautata) {
//		Nod* capAux = *cap;
//		*cap = capAux->next;
//		if (capAux->infoUtil.producator != NULL) {
//			free(capAux->infoUtil.producator);
//		}
//		if (capAux->infoUtil.model != NULL) {
//			free(capAux->infoUtil.model);
//		}
//		free(capAux);
//	}
//
//	if (*cap != NULL) {
//		Nod* capAux = *cap;
//		while (capAux != NULL) {
//			while (capAux != NULL && capAux->next != NULL && capAux->next->infoUtil.tip != serieCautata) {
//				capAux = capAux->next;
//			}
//			if (capAux->next != NULL) {
//				Nod* nodAux = capAux->next;
//				capAux->next = nodAux->next;
//				if (nodAux->infoUtil.producator != NULL) {
//					free(nodAux->infoUtil.producator);
//				}
//				if (nodAux->infoUtil.model != NULL) {
//					free(nodAux->infoUtil.model);
//				}
//				free(nodAux);
//			}
//			else {
//				capAux = NULL;
//			}
//		}
//	}
//}
//
//int main()
//{
//	Nod* cap = citireRoutereLSFisier("routere.txt");
//	afisareRoutereLS(cap);
//
//	printf("\n------AFISARE LISTA DUPA STERGERE-------\n");
//	stergereNodLS(&cap, 'A');
//	afisareRoutereLS(cap);
//	printf("\n---------\n");
//
//	printf("\nAfisare lsita dupa dezalocarea memoriei!\n");
//	dezalocareLS(&cap);
//	afisareRoutereLS(cap);
//	return 0;
//}