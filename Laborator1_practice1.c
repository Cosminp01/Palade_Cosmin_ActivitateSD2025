//#include<stdio.h>
//#include<stdlib.h>
//
//
//struct Electrocasnice {
//	int id;
//	float pretElectrocasnic;
//	char* marca;
//	int cantitate;
//	char* expeditor;
//};
//
//struct Electrocasnice initializare(int idElectrocasnic, float Pret, const char* firma, int nrProduse, const char* courier) {
//	struct Electrocasnice e;
//	e.id = idElectrocasnic;
//	e.pretElectrocasnic = Pret;
//	e.marca = (char*)malloc(sizeof(char) * (strlen(firma) + 1));
//	strcpy_s(e.marca, strlen(firma) + 1, firma);
//	e.cantitate = nrProduse;
//	e.expeditor = (char*)malloc(sizeof(char) * (strlen(courier) + 1));
//	strcpy_s(e.expeditor, strlen(courier) + 1, courier);
//	return e;
//}
//
//void afisareElectrocasnice(struct Electrocasnice e)
//{
//	if (e.marca != NULL && e.expeditor != NULL) {
//		printf("%d. Produsul de la %s va fi expediat prin intermediul %s intr-o cantitate de %d. Valoarea coletului este de %5.2f RON.\n",
//			e.id, e.marca, e.expeditor, e.cantitate, e.pretElectrocasnic);
//	}
//	else {
//		printf("Probleme la livrarea produsului!");
//	}
//}
//
//void modificareCantitateProdus(struct Electrocasnice* e, int nouaCantitate) {
//	if (nouaCantitate > 0) {
//		e->cantitate = nouaCantitate;
//	}
//}
//
//void dezalocare(struct Electrocasnice* e) {
//	if (e->marca != NULL && e->marca != NULL)
//	{
//		free(e->marca);
//		e->marca = NULL;
//		free(e->expeditor);
//		e->expeditor = NULL;
//
//	}
//}
//
//int main()
//{
//	struct Electrocasnice e;
//	e = initializare(10, 1928.98, "Electrolux", 1, "FanCourier");
//	afisareElectrocasnice(e);
//	modificareCantitateProdus(&e, 3);
//	printf("Noua cantitate pentru comanda este: %d\n");
//	printf("COMANDA A FOST MODIFICATE CU SUCCES!\n");
//	afisareElectrocasnice(e);
//	dezalocare(&e);
//	return 0;
//}
