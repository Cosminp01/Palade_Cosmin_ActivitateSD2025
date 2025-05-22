#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct informatiiDomiciliu {

	int id;
	char* judet;
	char* localitate;
	char* strada;
	double nrStrada;
	int nrBloc;
	unsigned char scara;
	float etaj;
};
typedef struct informatiiDomiciliu Domiciliu;

struct Nod {
	Domiciliu infoUtil;
	struct Nod* next;
};
typedef struct Nod Nod;

void afisareDomicilii(Domiciliu d) {

	printf("Informatii domiciliu %d:\n", d.id);
	printf("Judet: %s\n", d.judet);
	printf("Localitate: %s\n", d.localitate);
	printf("Strada: %s\n", d.strada);
	printf("Nr strada: %.2f\n", d.nrStrada);
	printf("Bloc: %d\n", d.nrBloc);
	printf("Scara: %c\n", d.scara);
	printf("Etaj: %5.2f\n\n", d.etaj);
}

Domiciliu citireDomiciliiFisier(FILE* file) {

	Domiciliu d;
	char buffer[100];
	char sep[3] = ",\n";
	fgets(buffer, 100, file);

	d.id = atoi(strtok(buffer, sep));
	char* aux;
	aux = strtok(NULL, sep);
	d.judet = (char*)malloc(strlen(aux) + 1);
	strcpy(d.judet, aux);
	aux = strtok(NULL, sep);
	d.localitate = (char*)malloc(strlen(aux) + 1);
	strcpy(d.localitate, aux);
	aux = strtok(NULL, sep);
	d.strada = (char*)malloc(strlen(aux) + 1);
	strcpy(d.strada, aux);
	d.nrStrada = strtod(strtok(NULL, sep), NULL);
	d.nrBloc = atoi(strtok(NULL, sep));
	d.scara = strtok(NULL, sep)[0];
	d.etaj = atof(strtok(NULL, sep));
	
	return d;
}

void afisareDomiciliiStiva(Nod* varf) {

	while (varf != NULL) {
		afisareDomicilii(varf->infoUtil);
		varf = varf->next;
	}
}

void push(Nod** varf, Domiciliu domiciliuNou) {

	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->infoUtil = domiciliuNou;
	nou->next = *varf;
	*varf = nou;
}

Domiciliu* citireDomiciliiStivaFisier(const char* numeFisier, Nod** varf) {

	FILE* file = fopen(numeFisier, "r");
	while (!feof(file)) {
		Domiciliu nou = citireDomiciliiFisier(file);
		push(varf, nou);
	}
	return NULL;
}

void dezalocareStiva(Nod** varf) {

	while (*varf != NULL) {
		Nod* temp = *varf;
		*varf = (*varf)->next;
		if (temp->infoUtil.judet != NULL) {
			free(temp->infoUtil.judet);
		}
		if (temp->infoUtil.localitate != NULL) {
			free(temp->infoUtil.localitate);
		}
		if (temp->infoUtil.strada != NULL) {
			free(temp->infoUtil.strada);
		}
		free(temp);
	}
}

void stergereDomiciliuStiva(Nod** varf, int idCautat) {

	while (*varf != NULL && (*varf)->infoUtil.id == idCautat) {
		Nod* temp = *varf;
		*varf = (*varf)->next;
		if (temp->infoUtil.judet != NULL) {
			free(temp->infoUtil.judet);
		}
		if (temp->infoUtil.localitate != NULL) {
			free(temp->infoUtil.localitate);
		}
		if (temp->infoUtil.strada != NULL) {
			free(temp->infoUtil.strada);
		}
		free(temp);
	}

	if (*varf != NULL) {
		Nod* varfAux = *varf;
		while (varfAux !=NULL && varfAux->next !=NULL) {
			if (varfAux->next->infoUtil.id == idCautat) {
				Nod* temp = varfAux->next;
				varfAux->next = temp->next;

				if (temp->infoUtil.judet != NULL) {
					free(temp->infoUtil.judet);
				}
				if (temp->infoUtil.localitate != NULL) {
					free(temp->infoUtil.localitate);
				}
				if (temp->infoUtil.strada != NULL) {
					free(temp->infoUtil.strada);
				}
				free(temp);
			}
			else {
				varfAux = varfAux->next;
			}
		}
	}
}

int domiciliiEtajSpecific(Nod* varf, float etajCautat) {

	int nrTotal = 0;
	while (varf != NULL) {
		if (varf->infoUtil.etaj == etajCautat) {
			nrTotal++;
			
		}
		varf = varf->next;
	}
	return nrTotal;
}


int main() {

	Nod* varf = NULL;
	citireDomiciliiStivaFisier("domicilii.txt", &varf);
	afisareDomiciliiStiva(varf);

	printf("\n---------Afisare nr total de domicilii la un etaj specific!--------\n");
	printf("Nr de domicilii la etajul 1, este %d! \n", domiciliiEtajSpecific(varf, 1));
	

	printf("\n--------Afisare stiva dupa stergere!---------\n");
	stergereDomiciliuStiva(&varf, 5);
	afisareDomiciliiStiva(varf);


	printf("\n--------Afisare stiva dupa dezalocare!---------\n");
	dezalocareStiva(&varf);
	afisareDomiciliiStiva(varf);

	return 0;
}
