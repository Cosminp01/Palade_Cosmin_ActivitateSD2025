//#include<stdio.h>
//#include<stdlib.h>
//
//struct Avioane {
//	int id;
//	float rezervor;
//	char* companie;
//	double locuri;
//	char serie;
//};
//
//struct Avioane initializare(int idAvion, float capacitateRezervor, const char* numeCompanie, double nrLocuri, char serieAvion) {
//	struct Avioane a;
//	a.id = idAvion;
//	a.rezervor = capacitateRezervor;
//	a.companie = (char*)malloc(sizeof(char) * (strlen(numeCompanie) + 1));
//	strcpy_s(a.companie, strlen(numeCompanie) + 1, numeCompanie);
//	a.locuri = nrLocuri;
//	a.serie = serieAvion;
//	return a;
//}
//
//void afisareAvioane(struct Avioane a) {
//	if (a.companie != NULL) {
//		printf("Avionul cu nr %d din seria %c, din cadrul companiei %s are o capacitate maxima de persone de %.2f si un rezervor de %5.2f litri!\n",
//			a.id, a.serie, a.companie, a.locuri, a.rezervor);
//	}
//	else {
//		printf("Avionul cu nr %d, este scos din uz!\n", a.id);
//	}
//}
//
//void afisareAvioaneVector(struct Avioane* vector, int nrElemente) {
//	for (int i = 0; i < nrElemente; i++) {
//		afisareAvioane(vector[i]);
//	}
//}
//
//struct Avioane* copiereNAvioane(struct Avioane* vector, int nrAvioane, int nrAvioaneCopiate) {
//	struct Avioane* avionNou = NULL;
//	avionNou = (struct Avion*)malloc(sizeof(struct Avioane) * nrAvioaneCopiate);
//	for (int i = 0; i < nrAvioaneCopiate; i++) {
//		avionNou[i] = vector[i];
//		avionNou[i].companie = (char*)malloc(strlen(vector[i].companie) + 1);
//		strcpy_s(avionNou[i].companie, strlen(vector[i].companie) + 1, vector[i].companie);
//	}
//	return avionNou;
//}
//
//void dezalocareVector(struct Avioane** vector, int* nrAvioane) {
//	for (int i = 0; i < (*nrAvioane); i++) {
//		if ((*vector)[i].companie != NULL) {
//			free((*vector)[i].companie);
//		}
//	}
//	free(*vector);
//	*vector = NULL;
//	*nrAvioane = 0;
//}
//
//int main() 
//{
//	struct Avioane* avion = NULL;
//	int nrAvioane = 5;
//	avion = (struct Avioane*)malloc(sizeof(struct Avioane) * nrAvioane);
//
//	avion[0] = initializare(111, 1532.78, "WizzAir", 120, 'A');
//	avion[1] = initializare(222, 1090.21, "Tarom", 101, 'B');
//	avion[2] = initializare(333, 980.01, "BlueAir", 78, 'C');
//	avion[3] = initializare(444, 1980.31, "Luftansa", 231, 'D');
//	avion[4] = initializare(555, 1230.55, "TurkishAir", 109, 'E');
//
//	afisareAvioaneVector(avion, nrAvioane);
//
//	struct Avioane* avionNou = NULL;
//	int avioaneCopiate = 2;
//	copiereNAvioane(avion, nrAvioane, avioaneCopiate);
//	printf("\nAvioanele copiate sunt:\n");
//	afisareAvioaneVector(avion, avioaneCopiate);
//
//	dezalocareVector(&avionNou, &avioaneCopiate);
//	afisareAvioaneVector(avion, avioaneCopiate);
//
//	return 0;
//}