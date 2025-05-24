//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
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
//struct Coada {
//	Nod* prim;
//	Nod* ultim;
//};
//typedef struct Coada Coada;
//
//void afisareBilete(Bilet b) {
//	printf("Informatiile biletului cu id-ul %d, sunt: \n", b.id);
//	printf("Titlu: %s\n", b.titlu);
//	printf("Data lansare: %s\n", b.dataLansare);
//	printf("Rand: %c\n", b.rand);
//	printf("Loc: %.2f\n", b.loc);
//	printf("Pret bilet: %5.2f\n\n", b.pretBilet);
//}
//
//Bilet citireBileteFisier(FILE* file) {
//
//	Bilet b;
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, sep, file);
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
//void afisareBileteCoada(Coada c) {
//	
//	Nod* temp = c.prim;
//	while (temp != NULL) {
//		afisareBilete(temp->infoUtil);
//		temp = temp->next;
//	}
//}
//
//void adaugareBileteCoada(Coada* c, Bilet biletNou) {
//
//	Nod* nou = (Nod*)malloc(sizeof(Nod));
//	nou->infoUtil = biletNou;
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
//void citireBileteCoadaFisier(const char* numeFisier, Coada* c) {
//
//	FILE* file = fopen(numeFisier, "r");
//	while (!feof(file)) {
//		Bilet b = citireBileteFisier(file);
//		adaugareBileteCoada(c, b);
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
//		if (temp->infoUtil.titlu != NULL) {
//			free(temp->infoUtil.titlu);
//		}
//		if (temp->infoUtil.dataLansare != NULL) {
//			free(temp->infoUtil.dataLansare);
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
//
//	citireBileteCoadaFisier("bilete_film.txt", &c);
//	afisareBileteCoada(c);
//
//	return 0;
//}