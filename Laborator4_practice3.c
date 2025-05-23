//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct InfoTelevizor {
//	int id;
//	float pretTV;
//	double diagonalaTV;
//	char* producator;
//	char* tehnologie;
//	unsigned char clasaEnergetica;
//};
//
//typedef struct InfoTelevizor Televizor;
//
//void afisareTelevizoare(Televizor t) {
//
//	printf("Televizorul cu id-ul %d, are urmatoarele specificatii:\n", t.id);
//	printf("Pret este de: %5.2f RON\n", t.pretTV);
//	printf("Diagonala:%.2f inch\n", t.diagonalaTV);
//	printf("Producator:%s\n", t.producator);
//	printf("Tehnologie:%s\n", t.tehnologie);
//	printf("Clasa Energetica:%c\n\n", t.clasaEnergetica);
//}
//
//Televizor citireTelevizoareFisier(FILE* file) {
//
//	Televizor t;
//	char buffer[100];
//	char sep[4] = ",;\n";
//	fgets(buffer, 100, file);
//
//	t.id = atoi(strtok(buffer, sep));
//	t.pretTV = atof(strtok(NULL, sep));
//	t.diagonalaTV = strtod(strtok(NULL, sep), NULL);
//	char* aux;
//	aux = strtok(NULL, sep);
//	t.producator = (char*)malloc(strlen(aux) + 1);
//	strcpy(t.producator, aux);
//	aux = strtok(NULL, sep);
//	t.tehnologie = (char*)malloc(strlen(aux) + 1);
//	strcpy(t.tehnologie, aux);
//	t.clasaEnergetica = strtok(NULL, sep)[0];
//	return t;
//}
//
//struct Nod {
//	Televizor infoUtil;
//	struct Nod* next;
//};
//
//typedef struct Nod Nod;
//
//void afisareListaTelevizoare(Nod* cap) {
//	
//	while (cap != NULL) {
//		afisareTelevizoare(cap->infoUtil);
//		cap = cap->next;
//	}
//}
//
//void adaugareNodLaSfarsitDeLista(Nod** cap, Televizor televizorNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = televizorNou;
//	nou->next = NULL;
//
//	if (*cap != NULL) {
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
//void adaugareNodLaInceputDeLista(Nod** cap, Televizor televizorNou) {
//	
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = televizorNou;
//	nou->next = *cap;
//	*cap = nou;
//}
//
//Televizor* citireListaTelevizoareFisier(const char* numeFisier) {
//
//	Nod* cap = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareNodLaSfarsitDeLista(&cap, citireTelevizoareFisier(file));
//		}
//	}
//	fclose(file);
//	return cap;
//}
//
//void dezalocareLista(Nod** cap) {
//
//	while (*cap != NULL) {
//		Nod* capAux = (*cap);
//		*cap = (*cap)->next;
//		if (capAux->infoUtil.producator != NULL) {
//			free(capAux->infoUtil.producator);
//		}
//		if (capAux->infoUtil.tehnologie != NULL) {
//			free(capAux->infoUtil.tehnologie);
//		}
//		free(capAux);
//	}
//}
//
//void stergereNodDinLista(Nod** cap, char clasaEnergeticaCautata) {
//	while ((*cap) != NULL && (*cap)->infoUtil.clasaEnergetica == clasaEnergeticaCautata) {
//		Nod* capAux = *cap;
//		*cap = capAux->next;
//
//		if (capAux->infoUtil.producator != NULL) {
//			free(capAux->infoUtil.producator);
//		}
//		if (capAux->infoUtil.tehnologie != NULL); {
//			free(capAux->infoUtil.tehnologie);
//		}
//		free(capAux);
//	}
//
//	if (*cap != NULL) {
//		Nod* capAux = *cap;
//		while (capAux != NULL) {
//			while (capAux != NULL && capAux->next != NULL && capAux->next->infoUtil.clasaEnergetica != clasaEnergeticaCautata) {
//				capAux = capAux->next;
//			}
//			if (capAux->next != NULL) {
//				Nod* nodAux = capAux->next;
//				capAux->next = nodAux->next;
//				if (nodAux->infoUtil.producator != NULL) {
//					free(nodAux->infoUtil.producator);
//				}
//				if (nodAux->infoUtil.tehnologie != NULL); {
//					free(nodAux->infoUtil.tehnologie);
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
//float mediaPretTelevizoare(Nod* cap) {
//	float sumaTotala = 0;
//	int counter = 0;
//
//	while (cap != NULL) {
//		sumaTotala += cap->infoUtil.pretTV;
//		cap = cap->next;
//		counter++;
//		
//	}if (counter > 0) {
//		return sumaTotala / counter;
//	}
//	return  0;
//}
//
//int main()
//{
//	Nod* cap = citireListaTelevizoareFisier("televizoare.txt");
//	afisareListaTelevizoare(cap);
//
//	printf("\Afisare media preturi televizoare:%5.2f\n", mediaPretTelevizoare(cap));
//
//	printf("\nAfisare lista televizoare dupa stergerea televizoarele cu clasa energetica F:\n");
//	stergereNodDinLista(&cap, 'F');
//	afisareListaTelevizoare(cap);
//
//	printf("\nAfisare lista televizoare dupa stergerea televizoarele cu clasa energetica D:\n");
//	stergereNodDinLista(&cap, 'D');
//	afisareListaTelevizoare(cap);
//
//	printf("\nAfisare lista dupa dezalocare memoriei:\n");
//	dezalocareLista(&cap);
//	afisareListaTelevizoare(cap);
//
//	return 0;
//}