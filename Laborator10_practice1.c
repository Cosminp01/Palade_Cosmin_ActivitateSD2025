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
//	struct Nod* fiuStanga;
//	struct Nod* fiuDreapta;
//};
//typedef struct Nod Nod;
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
//void adaugareDomiciliuInArbore(Nod** radacina, Domiciliu domiciliuNou) {
//
//	if (*radacina != NULL) {
//		if (domiciliuNou.id < (*radacina)->infoUtil.id) {
//			adaugareDomiciliuInArbore(&(*radacina)->fiuStanga, domiciliuNou);
//		}
//		else {
//			adaugareDomiciliuInArbore(&(*radacina)->fiuDreapta, domiciliuNou);
//		}
//	}
//	else {
//		Nod* nou = (Nod*)malloc(sizeof(Nod));
//		nou->fiuStanga = NULL;
//		nou->fiuDreapta = NULL;
//		nou->infoUtil = domiciliuNou;
//		/*nou->infoUtil.id = domiciliuNou.id;
//		nou->infoUtil.nrStrada = domiciliuNou.nrStrada;
//		nou->infoUtil.nrBloc = domiciliuNou.nrBloc;
//		nou->infoUtil.scara = domiciliuNou.scara;
//		nou->infoUtil.etaj = domiciliuNou.etaj;*/
//
//		nou->infoUtil.judet = (char*)malloc(sizeof(char) * (strlen(domiciliuNou.judet) + 1));
//		strcpy(nou->infoUtil.judet, domiciliuNou.judet);
//		nou->infoUtil.localitate = (char*)malloc(sizeof(char) * (strlen(domiciliuNou.localitate) + 1));
//		strcpy(nou->infoUtil.localitate, domiciliuNou.localitate);
//		nou->infoUtil.strada = (char*)malloc(sizeof(char) * (strlen(domiciliuNou.strada) + 1));
//		strcpy(nou->infoUtil.strada, domiciliuNou.strada);
//
//		(*radacina) = nou;
//	}
//}
//
//Nod* citireDomiciliiArboreFisier(const char* numeFisier) {
//
//	FILE* file = fopen(numeFisier, "r");
//	Nod* nou = NULL;
//	while (!feof(file)) {
//		Domiciliu domiciliuNou = citireDomiciliiFisier(file);
//		adaugareDomiciliuInArbore(&nou, domiciliuNou);
//		free(domiciliuNou.judet);
//		free(domiciliuNou.localitate);
//		free(domiciliuNou.strada);
//	}
//	fclose(file);
//	return nou;
//}
//
//void afisareDomiciliiDinArbore(Nod* radacina) { //RSD
//
//	if (radacina != NULL) {
//		afisareDomicilii(radacina->infoUtil);
//		afisareDomiciliiDinArbore(radacina->fiuStanga);
//		afisareDomiciliiDinArbore(radacina->fiuDreapta);
//	}
//}
//
//void afisareInOrdine(Nod* radacina) {//SRD preordine
//
//	if (radacina != NULL) {
//		afisareInOrdine(radacina->fiuStanga);
//		afisareDomicilii(radacina->infoUtil);
//		afisareInOrdine(radacina->fiuDreapta);
//	}
//}
//
//void afisareArborePostOrdine(Nod* radacina) {//SDR inordine
//
//	if (radacina != NULL) {
//		afisareArborePostOrdine(radacina->fiuStanga);
//		afisareArborePostOrdine(radacina->fiuDreapta);
//		afisareDomicilii(radacina->infoUtil);
//	}
//}
//
//void dezalocareArbore(Nod** radacina) {//postordine
//
//	if (*radacina != NULL) {
//		dezalocareArbore((*radacina)->fiuStanga);
//		dezalocareArbore((*radacina)->fiuDreapta);
//		free((*radacina)->infoUtil.judet);
//		free((*radacina)->infoUtil.localitate);
//		free((*radacina)->infoUtil.strada);
//		free(*radacina);
//
//		(*radacina) = NULL;
//	}
//}
//
//int main() {
//
//	Nod* nou;
//	//nou->fiuStanga = NULL;
//	//nou->fiuDreapta = NULL;
//	nou = citireDomiciliiArboreFisier("domicilii_arbore.txt");
//	printf("\n--------Afisare arbore preordine!-------\n");
//	afisareDomiciliiDinArbore(nou);
//	printf("\n--------Afisare arbore inordine!-------\n");
//	afisareInOrdine(nou);
//
//	return 0;
//}