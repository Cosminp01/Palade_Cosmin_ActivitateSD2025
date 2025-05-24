#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ComplexBlocuri {
	int bloc;
	unsigned char scara;
	float pret;
	int an;
	char* proprietar;
};
typedef struct ComplexBlocuri Complex;

void afisareBlocuri(Complex c) {
	printf("Blocul:%d\n", c.bloc);
	printf("Scara:%c\n", c.scara);
	printf("Pret imobil:%5.2f\n", c.pret);
	printf("Anul constructiei:%d\n", c.an);
	printf("Proprietar:%s\n\n", c.proprietar);
}

void afisareBlocuriVector(Complex* c, int nrBlocuri) {
	for (int i = 0; i < nrBlocuri; i++) {
		afisareBlocuri(c[i]);
	}
}

void adaugareBlocNou(Complex** c, int* nrBlocuri, Complex blocNou) {
	Complex* vectorAux = (Complex*)malloc(sizeof(Complex) * ((*nrBlocuri) + 1));
	for (int i = 0; i < (*nrBlocuri); i++) {
		vectorAux[i] = (*c)[i];
	}
	vectorAux[(*nrBlocuri)] = blocNou;
	free(*c);
	(*c) = vectorAux;
	(*nrBlocuri)++;
}

Complex citireBlocuriFisier(FILE* file) {
	Complex c;
	char buffer[100];
	char sep[4] = ",;\n";
	fgets(buffer, 100, file);

	c.bloc = atoi(strtok(buffer, sep));
	c.scara = strtok(NULL, sep)[0];
	c.pret = atof(strtok(NULL, sep));
	c.an = atoi(strtok(NULL, sep));
	char* aux;
	aux = strtok(NULL, sep);
	c.proprietar = (char*)malloc(strlen(aux) + 1);
	strcpy(c.proprietar, aux);
	return c;
}

Complex* citireBlocuriVector(const char* numeFisier, int* nrBlocuri) {
	FILE* file = fopen(numeFisier, "r");
	Complex* vectorAux = NULL;
	(*nrBlocuri) = 0;

	while (!feof(file)) {
		adaugareBlocNou(&vectorAux, nrBlocuri, citireBlocuriFisier(file));
	}
	fclose(file);
	return vectorAux;
}

void dezalocareVector(Complex** c, int* nrBlocuri) {
	for (int i = 0; i < (*nrBlocuri); i++) {
		if ((*c)[i].proprietar != NULL) {
			free((*c)[i].proprietar);
		}
	}
	free(*c);
	(*c) = NULL;
	(*nrBlocuri) = 0;
}

void copiereNrBlocuriSpecific(Complex* vector, int nrBlocuri) {
	Complex* vectorNou = NULL;
	vectorNou = (Complex*)malloc(sizeof(Complex) * nrBlocuri);
	for (int i = 0; i < nrBlocuri; i++) {
		vectorNou[i] = vector[i];
		vectorNou[i].proprietar = (char*)malloc(strlen(vector[i].proprietar) + 1);
		strcpy(vectorNou[i].proprietar, vector[i].proprietar);
	}
}

void copiereBlocuriPretSpecific(Complex* vector, int nrBlocuri, float pretMin, Complex** vectorNou, int* dimensiune) {
	*dimensiune = 0;
	for (int i = 0; i < nrBlocuri; i++) {
		if (vector[i].pret >= pretMin) {
			(*dimensiune)++;
		}
	}

	if ((*vectorNou) != NULL) {
		free(*vectorNou);
	}
	int k = 0;

	*vectorNou = (Complex*)malloc(sizeof(Complex) * (*dimensiune));
	for (int i = 0; i < nrBlocuri; i++) {
		if (vector[i].pret >= pretMin) {
			(*vectorNou)[k] = vector[i];
			(*vectorNou)[k].proprietar = (char*)malloc(strlen(vector[i].proprietar) + 1);
			strcpy((*vectorNou)[k].proprietar, vector[i].proprietar);
			k++;
		}
	}
}

int main() 
{
	int nrBlocuri = 0;
	Complex* c = citireBlocuriVector("blocuri.txt", &nrBlocuri);
	afisareBlocuriVector(c, nrBlocuri);

	printf("\nAfisare nr blocuri specific:\n");
	Complex* cCopiate = NULL;
	int nrBlocuriCopiate = 1;
	copiereNrBlocuriSpecific(c, nrBlocuriCopiate);
	afisareBlocuriVector(c, nrBlocuriCopiate);

	printf("\nAfisare blocuri cu pret mai mare de:\n");
	Complex* blocuriPretMin = NULL;
	int nrBlocuriPretMin = 0;
	copiereBlocuriPretSpecific(c, nrBlocuri, 100000, &blocuriPretMin, &nrBlocuriPretMin);
	afisareBlocuriVector(blocuriPretMin, nrBlocuriPretMin);

	dezalocareVector(&c, &nrBlocuri);

	return 0;
}