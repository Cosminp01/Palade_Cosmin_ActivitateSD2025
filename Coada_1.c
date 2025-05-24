//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct informatiiVacanta {
//	int idVacanta;
//	char* destinatie;
//	unsigned char pachetTuristic;
//	float pretVacanta;
//	int nrZile;
//	double distantaKm;
//};
//typedef struct informatiiVacanta Vacanta;
//
//struct Nod {
//	Vacanta infoUtil;
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
//void afisareVacante(Vacanta v) {
//	printf("Informatii pentru vacanta cu nr. %d: \n", v.idVacanta);
//	printf("Destinatie: %s \n", v.destinatie);
//	printf("Pachet turistic: %c \n", v.pachetTuristic);
//	printf("Pret vacanta: %5.2f RON\n", v.pretVacanta);
//	printf("Zile: %d zile\n", v.nrZile);
//	printf("Distanta destinatie: %.2f km\n\n", v.distantaKm);
//}
//
//Vacanta citireVacanteFisier(FILE* file) {
//
//	Vacanta v;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//
//	v.idVacanta = atoi(strtok(buffer, sep));
//	char* aux;
//	aux = strtok(NULL, sep);
//	v.destinatie = (char*)malloc(strlen(aux) + 1);
//	strcpy(v.destinatie, aux);
//	v.pachetTuristic = strtok(NULL, sep)[0];
//	v.pretVacanta = atof(strtok(NULL, sep));
//	v.nrZile = atoi(strtok(NULL, sep));
//	v.distantaKm = strtod(strtok(NULL, sep), NULL);
//
//	return v;
//}
//
//void afisareCoada(Coada c) {
//
//	Nod* temp = c.prim;
//	while (temp != NULL) {
//		afisareVacante(temp->infoUtil);
//		temp = temp->next;
//	}
//}
//
//void adaugareVacantaCoada(Coada* c, Vacanta vacantaNoua) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = vacantaNoua;
//	nou->next = NULL;
//
//	if (c->ultim != NULL) {
//		c->ultim->next = nou;
//	}
//	else {
//		c->prim = nou;
//	}
//	c->ultim = nou;
//}
//
//void citireHeapFisier(const char* numeFisier, Coada* c) {
//
//	FILE* file = fopen(numeFisier, "r");
//	while (!feof(file)) {
//		Vacanta vacantaNoua = citireVacanteFisier(file);
//		adaugareVacantaCoada(c, vacantaNoua);
//	}
//	fclose(file);
//}
//
//void dezalocareCoada(Coada* c) {
//
//	while (c->prim != NULL) {
//		Nod* temp = c->prim;
//		c->prim = c->prim->next;
//
//		if (temp->infoUtil.destinatie != NULL) {
//			free(temp->infoUtil.destinatie);
//		}
//		free(temp);
//	}
//	c->ultim = NULL;
//}
//
//float sumaTotalaVacante(Coada c) {
//
//	float sumaTotala = 0;
//	Nod* temp = c.prim;
//	while (temp != NULL) {
//		sumaTotala += temp->infoUtil.pretVacanta;
//		temp = temp->next;
//	}
//	
//	return sumaTotala;
//}
//
//Vacanta vacantaCuPretMaxim(Coada c) {
//	Nod* temp = c.prim;
//	Vacanta max;
//
//	if (temp != NULL) {
//		max = temp->infoUtil;
//		temp = temp->next;
//		while (temp != NULL) {
//			if (temp->infoUtil.pretVacanta > max.pretVacanta) {
//				max = temp->infoUtil;
//			}
//			temp = temp->next;
//		}
//	}
//	return max;
//}
//
//int main() {
//
//	Coada c;
//	c.prim = NULL;
//	c.ultim = NULL;
//	citireHeapFisier("vacante.txt", &c);
//	afisareCoada(c);
//
//	printf("\n-----Afisare cost VACANTE!-----\n");
//	printf("\n-----Costul vacantelor este: %5.2f-----\n", sumaTotalaVacante(c));
//
//	printf("\n-----Vacanta cu pretul cel mai mare-----\n");
//	Vacanta vMax = vacantaCuPretMaxim(c);
//	afisareVacante(vMax);
//
//	return 0;
//}