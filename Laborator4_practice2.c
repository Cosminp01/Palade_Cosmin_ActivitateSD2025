//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct InfoTablouArta {
//	int id;
//	char* pictor;
//	char* anRealizat;
//	float valoareTablou;
//	double dimensiuneInch;
//	unsigned char serieTablou;
//};
//
//typedef struct InfoTablouArta Tablou;
//
//void afisareTablouri(Tablou t) {
//	printf("Info cu privire la tabloul %d:\n", t.id);
//	printf("A fost realizat de pictorul:%s\n", t.pictor);
//	printf("In anul:%s\n", t.anRealizat);
//	printf("Valoarea tabloului este de:%5.2f\n", t.valoareTablou);
//	printf("Dimensiune tablou:%0.2f inch\n", t.dimensiuneInch);
//	printf("Serie tablou:%c\n\n", t.serieTablou);
//}
//
//Tablou citireTablouriDinFisier(FILE* file) {
//	
//	Tablou t;
//	char buffer[100];
//	char sep[4] = ",;\n";
//	fgets(buffer, 100, file);
//
//	t.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	t.pictor = (char*)malloc(strlen(aux) + 1);
//	strcpy(t.pictor, aux);
//	aux = strtok(NULL, sep);
//	t.anRealizat = (char*)malloc(strlen(aux) + 1);
//	strcpy(t.anRealizat, aux);
//	t.valoareTablou = atof(strtok(NULL, sep));
//	t.dimensiuneInch = strtod(strtok(NULL, sep), NULL);
//	t.serieTablou = strtok(NULL, sep)[0];
//	return t;
//}
//
//struct Nod {
//	Tablou infoUtil;
//	struct Nod* next;
//};
//
//typedef struct Nod Nod;
//
//void afisareTablouriLista(Nod* cap) {
//	while (cap != NULL) {
//		afisareTablouri(cap->infoUtil);
//		cap = cap->next;
//	}
//}
//
//void adaugareNodSfarsitDeLista(Nod** cap, Tablou tablouNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = tablouNou;
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
//void adaugareNodInceputDeLista(Nod** cap, Tablou tablouNou) {
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = tablouNou;
//	nou->next = *cap;
//	*cap = nou;
//}
//
//Tablou* citireTablouriListaFisier(const char* numeFisier) {
//	Nod* cap = NULL;
//	FILE* file = fopen(numeFisier, "r");
//	if (file != NULL) {
//		while (!feof(file)) {
//			adaugareNodSfarsitDeLista(&cap, citireTablouriDinFisier(file));
//		}
//	}
//	fclose(file);
//	return cap;
//}
//
//void dezalocareLista(Nod** cap) {
//	if ((*cap) != NULL) {
//		Nod* capAux = *cap;
//		(*cap) = (*cap)->next;
//		if ((*cap)->infoUtil.pictor != NULL) {
//			free((*cap)->infoUtil.pictor);
//		}
//		if ((*cap)->infoUtil.anRealizat != NULL) {
//			free((*cap)->infoUtil.anRealizat);
//		}
//		free(capAux);
//	}
//}
//
//void stergereTablouriDinLista(Nod** cap, char serieCautata) {
//	while ((*cap) != NULL && (*cap)->infoUtil.serieTablou == serieCautata) {
//		Nod* capAux = (*cap);
//		(*cap) = capAux->next;
//		if (capAux->infoUtil.pictor != NULL) {
//			free(capAux->infoUtil.pictor);
//		}
//		if (capAux->infoUtil.anRealizat != NULL) {
//			free(capAux->infoUtil.anRealizat);
//		}
//		free(capAux);
//	}
//
//	if (*cap != NULL) {
//		Nod* capAux = *cap;
//		if (capAux != NULL) {
//			while (capAux != NULL && capAux->next != NULL && capAux->next->infoUtil.serieTablou != serieCautata) {
//				capAux = capAux->next;
//			}
//			if (capAux->next != NULL) {
//				Nod* nodAux = capAux->next;
//				capAux->next = nodAux->next;
//				if (nodAux->infoUtil.pictor != NULL) {
//					free(nodAux->infoUtil.pictor);
//				}
//				if (nodAux->infoUtil.anRealizat != NULL) {
//					free(nodAux->infoUtil.anRealizat);
//				}
//				free(nodAux);
//			}
//		}
//		else {
//			*cap = NULL;
//		}
//	}
//}
//
//float valoareaTuturorTablourilor(Nod* cap) {
//	
//	float valoareTotala = 0;
//	while (cap != NULL) {
//		valoareTotala += cap->infoUtil.valoareTablou;	
//		cap = cap->next;
//	}
//	
//	return valoareTotala;
//}
//
//int contorTablouriPictorSpecific(Nod* cap, char pictorSpecific) {
//	int contor = 0;
//	while (cap != NULL) {
//		if (strcmp(cap->infoUtil.pictor, pictorSpecific) == 0) {
//			contor++;
//		}
//		cap = cap->next;
//	}
//	return contor;
//}
//
//int main()
//{
//	Nod* cap = citireTablouriListaFisier("tablouri.txt");
//	afisareTablouriLista(cap);
//
//	printf("\nValoarea tuturor tablourilor este:%5.2f\n", valoareaTuturorTablourilor(cap));
//
//	//printf("\nPictorul %s are un nr de:%0.2f tablouri", "Picasso", contorTablouriPictorSpecific(cap, "Picasso"));
//
//	printf("\nAfisare lista tablouri dupa sterge tablouri seria A:\n");
//	stergereTablouriDinLista(&cap, 'A');
//	afisareTablouriLista(cap);
//
//	printf("\nAfisare lista tablouri dupa sterge tablouri seria C:\n");
//	stergereTablouriDinLista(&cap, 'C');
//	afisareTablouriLista(cap);
//
//
//	dezalocareLista(&cap);
//	return 0;
//}