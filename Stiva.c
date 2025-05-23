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
//void afisareStiva(Nod* varf) {
//
//	while (varf != NULL) {
//		afisareVacante(varf->infoUtil);
//		varf = varf->next;
//	}
//}
//
//void adaugareVacantaInStiva(Nod** varf, Vacanta vacantaNoua) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = vacantaNoua;
//	nou->next = *varf;
//	*varf = nou;
//}
//
//void citireVacanteStivaFisier(const char* numeFisier, Nod** varf) {
//
//	FILE* file = fopen(numeFisier, "r");
//	while (!feof(file)) {
//		Vacanta vacantaNoua = citireVacanteFisier(file);
//		adaugareVacantaInStiva(varf, vacantaNoua);
//	}
//	fclose(file);
//	//return NULL;
//}
//
//void dezalocareStiva(Nod** varf) {
//
//	while (*varf != NULL) {
//		Nod* temp = *varf;
//		*varf = (*varf)->next;
//		if (temp->infoUtil.destinatie != NULL) {
//			free(temp->infoUtil.destinatie);
//		}
//		free(temp);
//	}
//}
//
//void stergereVacantaDinStiva(Nod** varf, int idCautat) {
//
//	while (*varf != NULL && (*varf)->infoUtil.idVacanta == idCautat) {
//		Nod* temp = *varf;
//		*varf = (*varf)->next;
//		if (temp->infoUtil.destinatie != NULL) {
//			free(temp->infoUtil.destinatie);
//		}
//		free(temp);
//	}
//
//	if (*varf != NULL) {
//		Nod* varfAux = *varf;
//		while (varfAux != NULL && varfAux->next != NULL) {
//			if (varfAux->infoUtil.idVacanta == idCautat) {
//				Nod* temp = varfAux->next;
//				varfAux->next = temp->next;
//
//				if (temp->infoUtil.destinatie != NULL) {
//					free(temp->infoUtil.destinatie);
//				}
//				free(temp);
//			}
//			varfAux = varfAux->next;
//		}
//	}
//}
//
//int main() {
//
//	Nod* varf = NULL;
//	citireVacanteStivaFisier("vacante.txt", &varf);
//	afisareStiva(varf);
//
//	printf("\n--------Afisare stiva dupa stergere!------\n");
//	stergereVacantaDinStiva(&varf, 10);
//	afisareStiva(varf);
//
//	printf("\n--------Afisare stiva dupa stergere!------\n");
//	stergereVacantaDinStiva(&varf, 6);
//	afisareStiva(varf);
//
//	printf("\n-------Afisare stiva dupa dezalocare!-----\n");
//	dezalocareStiva(&varf);
//	afisareStiva(varf);
//
//	return 0;
//}