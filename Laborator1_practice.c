//#include<stdio.h>
//#include<stdlib.h>
//
//struct Avion {
//	int id; //%d
//	char* companie;  //%s
//	float vitezaMax;  //%5.2f
//	int nrLocuri;   //%d
//	char serieModel;  //%c
//};
//
//struct Avion initializare(int idAvion, const char* numeCompanie, float vitexaMaxAvion, int locuri, char serie) {
//	struct Avion a;
//	a.id = idAvion;
//	a.companie = (char*)malloc(sizeof(char) * (strlen(numeCompanie) + 1));
//	strcpy_s(a.companie, strlen(numeCompanie) + 1, numeCompanie);
//	a.vitezaMax = vitexaMaxAvion;
//	a.nrLocuri = locuri;
//	a.serieModel = serie;
//	return a;
//}
//
//void afisareAvioane(struct Avion a) {
//	if (a.companie != NULL) {
//		printf("%d. Avionul din seria %c, de la compania %s are o capacitate maxima de %d de persoane si merge cu o viteza maxima de %5.2f km.\n",
//			a.id, a.serieModel, a.companie, a.nrLocuri, a.vitezaMax);
//	}
//	else
//	{
//		printf("%d. Avionul cu seria %c de la compania %s, nu se afla in baza de date!\n",
//			a.id, a.serieModel, a.companie);
//	}
//}
//
//void modifareAvioane(struct Avion* a, int nrLocuriNou) {
//	if (nrLocuriNou > 0) {
//		a->nrLocuri = nrLocuriNou;
//	}
//}
//
//
//void dezalocare(struct Avion* a) // am transmis direct prin pointer deoarece trebuie sa i fac o modificare
//{
//	if (a->companie != NULL) {
//		free(a->companie);
//		//am sters spatiul de memorie a blocului meu dar pointerul retine in continuare adresa catre acel bloc, care acum este sters
//		//dupa ce facem stergerea este recomandat sa si initializam, dam o valoare NULL astefel incat sa nu mai aiba o adresa in el
//		a->companie = NULL;
//	}
//}
//
//int main() {
//	struct Avion a;
//	a = initializare(777, "WizzAir", 650.25, 78, 'A');
//	afisareAvioane(a);
//	modifareAvioane(&a, 60);
//	printf("Afisare avion cu nr de locuri modificat\n");
//	afisareAvioane(a);
//	dezalocare(&a);
//	return 0;
//}