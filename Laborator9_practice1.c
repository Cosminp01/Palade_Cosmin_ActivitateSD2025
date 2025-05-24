//#define _CRT_SECURE_NO_WARNINGS
//#include<string.h>
//#include<stdio.h>
//#include<stdlib.h>
//
//struct InformatiiBilet {
//	int id;
//	char* titlu;
//	char* dataLansare;
//	unsigned char rand;
//	double loc;
//	float pretBilet;
//};
//typedef struct InformatiiBilet Bilet;
//
//struct Nod {
//	Bilet infoUtil;
//	struct Nod* next;
//};
//typedef struct Nod Nod;
//
//void afisareBilete(Bilet bilet) {
//	printf("Biletul cu id-ul %d, are urmatoarele informatii:\n", bilet.id);
//	printf("Titlu film: %s\n", bilet.titlu);
//	printf("Data lansare: %s\n", bilet.dataLansare);
//	printf("Serie rand: %c\n", bilet.rand);
//	printf("Locul in sala: %.2f\n", bilet.loc);
//	printf("Pret bilet: %5.2f\n\n", bilet.pretBilet);
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
//	b.titlu = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.titlu, aux);
//	aux = strtok(NULL, sep);
//	b.dataLansare = (char*)malloc(strlen(aux) + 1);
//	strcpy(b.dataLansare, aux);
//	b.rand = strtok(NULL, sep)[0];
//	b.loc = strtod(strtok(NULL, sep), NULL);
//	b.pretBilet = atof(strtok(NULL, sep));
//
//	return b;
//}
//
//void afisareStiva(Nod* varf) {
//	while (varf != NULL) {
//		afisareBilete(varf->infoUtil);
//		varf = varf->next;
//	}
//}
//
//void adaugareBiletStiva(Nod** varf, Bilet biletNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = biletNou;
//	nou->next = *varf;
//	*varf = nou;
//}
//
//Bilet* citireBileteStivaFisier(const char* numeFisier, Nod** varf) {
//	FILE* file = fopen(numeFisier, "r");
//	while (!feof(file)) {
//		Bilet nou = citireBileteFisier(file);
//		adaugareBiletStiva(varf, nou);
//	}
//	fclose(file);
//	return NULL;
//}
//
//void dezalocareStiva(Nod** varf) {
//	
//	while (*varf != NULL) {
//		Nod* temp = *varf;
//		*varf = (*varf)->next;
//		if (temp->infoUtil.titlu != NULL) {
//			free(temp->infoUtil.titlu);
//		}
//		if (temp->infoUtil.dataLansare != NULL) {
//			free(temp->infoUtil.dataLansare);
//		}
//		free(temp);
//	}
//}
//
//void stergereBiletStiva(Nod** varf, int idCautat) {
//
//	while (*varf != NULL && (*varf)->infoUtil.id == idCautat) {
//		Nod* temp = *varf;
//		*varf = (*varf)->next;
//		if (temp->infoUtil.titlu != NULL) {
//			free(temp->infoUtil.titlu);
//		}
//		if (temp->infoUtil.dataLansare != NULL) {
//			free(temp->infoUtil.dataLansare);
//		}
//		free(temp);
//	}
//
//	if (*varf != NULL) {
//		Nod* varfAux = *varf;
//		while (varfAux != NULL && varfAux->next != NULL) {
//			if (varfAux->next->infoUtil.id == idCautat) {
//				Nod* temp = varfAux->next;
//				varfAux->next = temp->next;
//
//				if (temp->infoUtil.titlu != NULL) {
//					free(temp->infoUtil.titlu);
//				}
//				if (temp->infoUtil.dataLansare != NULL) {
//					free(temp->infoUtil.dataLansare);
//				}
//				free(temp);
//			}
//			else {
//				varfAux = varfAux->next;
//			}
//		}
//	}
//}
//
//int main() {
//
//	Nod* varf = NULL;
//	citireBileteStivaFisier("bilete_film.txt", &varf);
//	afisareStiva(varf);
//
//	printf("\n------Afisare stiva dupa stergere!------\n");
//	stergereBiletStiva(&varf, 10);
//	afisareStiva(varf);
//
//	printf("\n--------Afisare stiva dupa dezalocare!------\n");
//	dezalocareStiva(&varf);
//	afisareStiva(varf);
//
//	return 0;
//}