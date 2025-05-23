//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//struct informatiiDomiciliu {
//
//	int id;
//	char* judet;
//	char* localitate;
//	char* strada;
//	double nrStrada;
//	int nrBloc;
//	unsigned char scara;
//	float etaj;
//};
//typedef struct informatiiDomiciliu Domiciliu;
//
//struct Nod {
//	Domiciliu infoUtil;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//struct Coada {
//	Nod* prim;
//	Nod* ultim;
//};
//typedef struct Coada Coada;
//
//void afisareDomicilii(Domiciliu d) {
//
//	printf("Informatii domiciliu %d:\n", d.id);
//	printf("Judet: %s\n", d.judet);
//	printf("Localitate: %s\n", d.localitate);
//	printf("Strada: %s\n", d.strada);
//	printf("Nr strada: %.2f\n", d.nrStrada);
//	printf("Bloc: %d\n", d.nrBloc);
//	printf("Scara: %c\n", d.scara);
//	printf("Etaj: %5.2f\n\n", d.etaj);
//}
//
//Domiciliu citireDomiciliiFisier(FILE* file) {
//
//	Domiciliu d;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	d.id = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	d.judet = (char*)malloc(strlen(aux) + 1);
//	strcpy(d.judet, aux);
//	aux = strtok(NULL, sep);
//	d.localitate = (char*)malloc(strlen(aux) + 1);
//	strcpy(d.localitate, aux);
//	aux = strtok(NULL, sep);
//	d.strada = (char*)malloc(strlen(aux) + 1);
//	strcpy(d.strada, aux);
//	d.nrStrada = strtod(strtok(NULL, sep), NULL);
//	d.nrBloc = atoi(strtok(NULL, sep));
//	d.scara = strtok(NULL, sep)[0];
//	d.etaj = atof(strtok(NULL, sep));
//	
//	return d;
//}
//
//void afisareCoada(Coada c) {
//
//	Nod* temp = c.prim;
//	while (temp != NULL) {
//		afisareDomicilii(temp->infoUtil);
//		temp = temp->next;
//	}
//}
//
//void adaugareDomiciliuCoada(Coada* c, Domiciliu domiciliuNou) {
//
//		Nod* nou = (Nod*)malloc(sizeof(Nod)); 
//		nou->infoUtil = domiciliuNou;
//		nou->next = NULL;
//
//		if (c->ultim != NULL) {
//			c->ultim->next = nou;
//		}
//		else {
//			c->prim = nou;
//		}
//		c->ultim = nou;
//}
//
//void citireDomiciliiCoadaFisier(const char* numeFisier, Coada* c) {
//
//	FILE* file = fopen(numeFisier, "r");
//	while (!feof(file)) {
//		Domiciliu nou = citireDomiciliiFisier(file);
//		adaugareDomiciliuCoada(c, nou);
//	}
//	fclose(file);
//}
//
//void dezalocareCoada(Coada* c) {
//
//	Nod* temp = c->prim;
//	while (temp != NULL) {
//		if (temp->infoUtil.judet != NULL) {
//			free(temp->infoUtil.judet);
//		}
//		if (temp->infoUtil.localitate != NULL) {
//			free(temp->infoUtil.localitate);
//		}
//		if (temp->infoUtil.strada != NULL) {
//			free(temp->infoUtil.strada);
//		}
//		free(temp);
//	}
//	c->ultim = NULL;
//}
//
//int main() {
//
//	Coada c;
//	c.prim = NULL;
//	c.ultim = NULL;
//	citireDomiciliiCoadaFisier("domicilii.txt",&c);
//	afisareCoada(c);
//
//	printf("\n-------Afisare coada dupa dezalocare!------\n");
//	dezalocareCoada(&c);
//	afisareCoada(c);
//
//	return 0;
//}