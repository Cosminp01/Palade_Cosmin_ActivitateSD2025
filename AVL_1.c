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
//	struct Nod* fiuStanga;
//	struct Nod* fiuDreapta;
//	int inaltime;
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
///*int max(int a, int b) {
//	return (a > b) ? a : b;
//}*/
//
//// Returnează valoarea maximă dintre două numere întregi (variantă clasică)
//int maxim(int a, int b) {
//	if (a > b) {
//		return a;
//	}
//	else {
//		return b;
//	}
//}
//
//int getInaltime(Nod* n) {
//	if (n == NULL)
//		return 0;
//	return n->inaltime;
//}
//
//int getEchilibru(Nod* n) {
//	if (n == NULL)
//		return 0;
//	return getInaltime(n->fiuStanga) - getInaltime(n->fiuDreapta);
//}
//
//// Rotație simplă la dreapta
//Nod* rotatieDreapta(Nod* nodPivot) {
//	Nod* nodStanga = nodPivot->fiuStanga;
//	Nod* subarboreDreaptaStanga = nodStanga->fiuDreapta;
//
//	// Rotim
//	nodStanga->fiuDreapta = nodPivot;
//	nodPivot->fiuStanga = subarboreDreaptaStanga;
//
//	// Actualizăm înălțimile
//	nodPivot->inaltime = maxim(getInaltime(nodPivot->fiuStanga), getInaltime(nodPivot->fiuDreapta)) + 1;
//	nodStanga->inaltime = maxim(getInaltime(nodStanga->fiuStanga), getInaltime(nodStanga->fiuDreapta)) + 1;
//
//	return nodStanga;
//}
//
//// Rotație simplă la stânga
//Nod* rotatieStanga(Nod* nodPivot) {
//	Nod* nodDreapta = nodPivot->fiuDreapta;
//	Nod* subarboreStangaDreapta = nodDreapta->fiuStanga;
//
//	// Rotim
//	nodDreapta->fiuStanga = nodPivot;
//	nodPivot->fiuDreapta = subarboreStangaDreapta;
//
//	// Actualizăm înălțimile
//	nodPivot->inaltime = maxim(getInaltime(nodPivot->fiuStanga), getInaltime(nodPivot->fiuDreapta)) + 1;
//	nodDreapta->inaltime = maxim(getInaltime(nodDreapta->fiuStanga), getInaltime(nodDreapta->fiuDreapta)) + 1;
//
//	return nodDreapta;
//}
//
//
//// Inseră o vacanță în arborele AVL și îl echilibrează dacă este necesar
//Nod* adaugareVacantaInArbore(Nod* nodCurent, Vacanta vacantaNoua) {
//	// Cazul de bază: nodul este NULL, deci creăm unul nou
//	if (nodCurent == NULL) {
//		Nod* nodNou = (Nod*)malloc(sizeof(Nod));
//		nodNou->fiuStanga = NULL;
//		nodNou->fiuDreapta = NULL;
//		nodNou->inaltime = 1;
//		nodNou->infoUtil = vacantaNoua;
//
//		// Alocare și copiere text pentru destinație
//		nodNou->infoUtil.destinatie = (char*)malloc(strlen(vacantaNoua.destinatie) + 1);
//		strcpy(nodNou->infoUtil.destinatie, vacantaNoua.destinatie);
//
//		return nodNou;
//	}
//
//	// Inserare în subarborele stâng
//	if (vacantaNoua.idVacanta < nodCurent->infoUtil.idVacanta) {
//		nodCurent->fiuStanga = adaugareVacantaInArbore(nodCurent->fiuStanga, vacantaNoua);
//	}
//	// Inserare în subarborele drept
//	else if (vacantaNoua.idVacanta > nodCurent->infoUtil.idVacanta) {
//		nodCurent->fiuDreapta = adaugareVacantaInArbore(nodCurent->fiuDreapta, vacantaNoua);
//	}
//	// Valoare duplicat – nu inserăm nimic
//	else {
//		return nodCurent;
//	}
//
//	// Actualizăm înălțimea nodului curent
//	nodCurent->inaltime = 1 + maxim(
//		getInaltime(nodCurent->fiuStanga),
//		getInaltime(nodCurent->fiuDreapta)
//	);
//
//	// Calculăm factorul de echilibru
//	int balans = getEchilibru(nodCurent);
//
//	// 🔄 1. Caz LL (stânga-stânga)
//	if (balans > 1 && vacantaNoua.idVacanta < nodCurent->fiuStanga->infoUtil.idVacanta) {
//		return rotatieDreapta(nodCurent);
//	}
//
//	// 🔄 2. Caz RR (dreapta-dreapta)
//	if (balans < -1 && vacantaNoua.idVacanta > nodCurent->fiuDreapta->infoUtil.idVacanta) {
//		return rotatieStanga(nodCurent);
//	}
//
//	// 🔄 3. Caz LR (stânga-dreapta)
//	if (balans > 1 && vacantaNoua.idVacanta > nodCurent->fiuStanga->infoUtil.idVacanta) {
//		nodCurent->fiuStanga = rotatieStanga(nodCurent->fiuStanga);
//		return rotatieDreapta(nodCurent);
//	}
//
//	// 🔄 4. Caz RL (dreapta-stânga)
//	if (balans < -1 && vacantaNoua.idVacanta < nodCurent->fiuDreapta->infoUtil.idVacanta) {
//		nodCurent->fiuDreapta = rotatieDreapta(nodCurent->fiuDreapta);
//		return rotatieStanga(nodCurent);
//	}
//
//	// Dacă arborele este deja echilibrat, returnăm nodul curent
//	return nodCurent;
//}
//
//
//Nod* citireArboreFisier(const char* numeFisier) {
//	FILE* file = fopen(numeFisier, "r");
//	Nod* nou = NULL;
//
//	while (!feof(file)) {
//		Vacanta vacantaNoua = citireVacanteFisier(file);
//		nou = adaugareVacantaInArbore(nou, vacantaNoua);
//		free(vacantaNoua.destinatie);
//	}
//	fclose(file);
//	return nou;
//}
//
//void afisareArboreInordine(Nod* radacina) {
//
//	if (radacina != NULL) {
//		afisareArboreInordine(radacina->fiuStanga);
//		afisareVacante(radacina->infoUtil);
//		afisareArboreInordine(radacina->fiuDreapta);
//	}
//}
//
//void afisareArborePostOrdine(Nod* radacina) {
//
//	if (radacina != NULL) {
//		afisareArborePostOrdine(radacina->fiuStanga);
//		afisareArborePostOrdine(radacina->fiuDreapta);
//		afisareVacante(radacina->infoUtil);
//	}
//}
//
//void dezalocarePostordine(Nod** radacina) {
//
//	if (*radacina != NULL) {
//		dezalocarePostordine((*radacina)->fiuStanga);
//		dezalocarePostordine((*radacina)->fiuDreapta);
//		free((*radacina)->infoUtil.destinatie);
//		free(*radacina);
//
//		*radacina = NULL;
//	}
//}
//
//int main() {
//
//	Nod* radacina;
//	//radacina->fiuDreapta = 0;
//	//radacina->fiuStanga = 0;
//
//	radacina = citireArboreFisier("vacante_arbore.txt");
//	afisareArboreInordine(radacina);
//
//	printf("\n-------Afisare arbore PREORDINE!------\n");
//	//afisareArborePreordine(radacina);
//
//	//printf("\n------Inaltimea arborelui este: %d------- \n", inaltimeArbore(radacina));
//
//	//printf("\n------Nr de noduri ale arborelui sunt: %d-------- \n ", nrNoduriArbore(radacina));
//
//	//printf("\n------Pretul pentru toate vacantele este de: %5.2f RON------\n", sumaTotalaVacante(radacina));
//
//	//printf("\n------Pretul pentru o vacanta specifica este de: %5.2f------\n", sumaVacantaSpecifica(radacina, "Barcelona"));
//
//	return 0;
//}