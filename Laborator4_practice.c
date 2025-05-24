//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct InfoLaptop {
//	int id;
//	char* marca;
//	char* model;
//	unsigned char serie;
//	double RAM;
//	float pret;
//};
//typedef struct InfoLaptop Laptop;
//
//void afisareLaptop(Laptop laptop) {
//	printf("ID Laptop:%d\n",laptop.id);
//	printf("Marca:%s\n",laptop.marca);
//	printf("Model:%s\n",laptop.model);
//	printf("Serie model:%c\n",laptop.serie);
//	printf("Memorie RAM:%.2f\n",laptop.RAM);
//	printf("Pret laptop:%5.2f\n\n",laptop.pret);
//}
//
//Laptop citireLaptopFisier(FILE* file) {
//
//	Laptop l;
//	char buffer[100];
//	char sep[4] = ",;\n";
//	fgets(buffer, 100, file);
//
//	l.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	l.marca = (char*)malloc(strlen(aux) + 1);
//	strcpy(l.marca, aux);
//	aux = strtok(NULL, sep);
//	l.model = (char*)malloc(strlen(aux) + 1);
//	strcpy(l.model, aux);
//	l.serie = strtok(NULL, sep)[0];
//	l.RAM = strtod(strtok(NULL, sep), NULL);
//	l.pret = atof(strtok(NULL, sep));
//	return l;
//}
//
//struct Nod {
//	Laptop infoUtil;
//	struct Nod* next;
//};
//
//typedef struct Nod Nod;
//
//void afisareListaMasini(Nod* cap) {
//	while (cap != NULL) {
//		afisareLaptop(cap->infoUtil);
//		cap = cap->next;
//	}
//	
//}
//
//void adaugareNodLaFinalDeLista(Nod** cap, Laptop laptopNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = laptopNou;
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
//void adaugareNodLaInceputDeLista(Nod** cap, Laptop laptopNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = laptopNou;
//	nou->next = *cap;
//	*cap = nou;
//}
//
//
//Nod* citireListaDinFisier(const char* numeFisier) {
//	Nod* cap = NULL;
//
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareNodLaFinalDeLista(&cap, citireLaptopFisier(file));
//		}
//	}
//	fclose(file);
//	return cap;
//}
//
//void dezalocareListaLaptop(Nod** cap) {
//	while ((*cap) != NULL) {
//		Nod* capAux = (*cap);
//		(*cap) = (*cap)->next;
//		if ((*cap)->infoUtil.marca != NULL) {
//			free((*cap)->infoUtil.marca);
//		}
//		if ((*cap)->infoUtil.model != NULL) {
//			free((*cap)->infoUtil.model);
//		}
//		free(capAux);
//	}
//}
//
//void stergereLaptopDinListaProducator(Nod** cap, char producatorCautat) {
//	while ((*cap) != NULL && (strcmp((*cap)->infoUtil.marca,producatorCautat) == 0)) {
//		Nod* capAux = (*cap);
//		(*cap) = capAux->next;
//		if (capAux->infoUtil.marca != NULL) {
//			free(capAux->infoUtil.marca);
//		}
//		if (capAux->infoUtil.model != NULL) {
//			free(capAux->infoUtil.model);
//		}
//		free(capAux);
//	}
//	if (*cap != NULL) {
//		Nod* capAux = (*cap);
//		if (capAux != NULL) {
//			while (capAux != NULL && capAux->next != NULL && (strcmp(capAux->next->infoUtil.marca, producatorCautat) != 0)) {
//				capAux = capAux->next;
//			}
//			if (capAux->next != NULL) {
//				Nod* nodAux = capAux->next;
//				capAux->next = nodAux->next;
//				if (nodAux->infoUtil.marca != NULL) {
//					free(nodAux->infoUtil.marca);
//				}
//				if (nodAux->infoUtil.model != NULL) {
//					free(nodAux->infoUtil.model);
//				}
//				free(nodAux);
//			}
//		}
//		else {
//			capAux = NULL;
//		}
//	}
//}
//
//
//
//int main()
//{
//	Nod* cap = citireListaDinFisier("laptopuri.txt");
//	afisareListaMasini(cap);
//
//	printf("\nAfisarea listei de laptop fara producatorul Lenovo:\n");
//	stergereLaptopDinListaProducator(&cap, "Lenovo");
//	afisareListaMasini(cap);
//
//	dezalocareListaLaptop(&cap);
//	return 0;
//}