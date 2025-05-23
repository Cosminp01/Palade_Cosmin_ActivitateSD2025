//#include<stdio.h>
//#include<stdlib.h>
//
//struct Programari {
//	int id;
//	char* data;
//	float pret;
//	double persoane;
//	char zi;
//};
//
//struct Programari initializareProgramare(int idProgramare, const char* dataProgramare, float pretServiciu, double persoaneProgramate, char ziProgramare) {
//	struct Programari p;
//	p.id = idProgramare;
//	p.data = (char*)malloc(sizeof(char) * (strlen(dataProgramare) + 1));
//	strcpy_s(p.data, strlen(dataProgramare) + 1, dataProgramare);
//	p.pret = pretServiciu;
//	p.persoane = persoaneProgramate;
//	p.zi = ziProgramare;
//	return p;
//}
//
//void afisare(struct Programari p) {
//	if (p.data != NULL) {
//		printf("Programarea cu id-ul %d, din data de %s si ziua %c pentru un nr de %.2f persoane, s-a realizat cu succes.\nSuma totala de plata este de %5.2f RON!\n",
//			p.id, p.data, p.zi, p.persoane, p.pret);
//	}
//	else {
//		printf("Nu mai sunt locuri disponibile!\n");
//	}
//}
//
//void afisareVectorProgramari(struct Programari* p, int nrProgramari) {
//	for (int i = 0; i < nrProgramari; i++) {
//		afisare(p[i]);
//	}
//}
//
//void dezalocare(struct Programari* p) {
//	if (p->data != NULL) {
//		free(p->data);
//		p->data = NULL;
//	}
//}
//
//void dezalocareVector(struct Programari** p, int* nrProgramari) {
//	for (int i = 0; i < (*nrProgramari); i++) {
//		if ((*p)[i].data != NULL) {
//			free((*p)[i].data);
//		}
//	}
//	free(*p);
//	*p = NULL;
//	*nrProgramari = 0;
//}
//
//struct Programari* copiereNrSpecificProgramari(struct Programari* p, int nrProgamarInitiale, int nrProgramariCopiate) {
//	struct Programari* pNou = NULL;
//	pNou = (struct Programari*)malloc(sizeof(struct Programari) * nrProgramariCopiate);
//
//	for (int i = 0; i < nrProgamarInitiale; i++) {
//		pNou[i] = p[i];
//		pNou[i].data = (char*)malloc(strlen(p[i].data) + 1);
//		strcpy_s(pNou[i], strlen(p[i].data) + 1, p[i].data);
//	}
//	return pNou;
//}
//
//void copiereProgramariNrPersoaneSpecific(struct Programari* p, int nrProgramariInitiale, double persoaneMinime, struct Programari** pNOU, int* dimensiune) {
//	*dimensiune = 0;
//	for (int i = 0; i < nrProgramariInitiale; i++) {
//		if (p[i].persoane >= persoaneMinime) {
//			(*dimensiune)++;
//		}
//	}
//
//	if ((*pNOU) != NULL) {
//		free(*pNOU);
//	}
//
//	*pNOU = (struct Programari*)malloc(sizeof(struct Programari) * (*dimensiune));
//
//	int k = 0;
//	for (int i = 0; i < nrProgramariInitiale; i++) {
//		if (p[i].persoane >= persoaneMinime) {
//			(*pNOU)[k] = p[i];
//			(*pNOU)[k].data = (char*)malloc(strlen(p[i].data) + 1);
//			strcpy_s((*pNOU)[k].data, strlen(p[i].data) + 1, p[i].data);
//			k++;
//		}
//	}
//	
//}
//
//int main()
//{
//	struct Programari p;
//
//	p = initializareProgramare(10, "10.10.2020", 10, 1, 'V');
//	afisare(p);
//	dezalocare(&p);
//	printf("\nAfisare dupa dezalocarea memoriei!\n");
//
//	struct Programari* programare = NULL;
//	int nrProgramari = 3;
//	programare = (struct Programari*)malloc(sizeof(struct Programari) * nrProgramari);
//
//	programare[0] = initializareProgramare(1, "22.05.2025", 65.5, 1, 'L');
//	programare[1] = initializareProgramare(2, "10.04.2025", 130, 2, 'V');
//	programare[2] = initializareProgramare(3, "3.05.2025", 195.5, 3, 'M');
//
//	printf("\n\nAfisarea programarilor de tip VECTOR:\n");
//	afisareVectorProgramari(programare, nrProgramari);
//
//	printf("\n\n Afisare programari copiate:\n");
//	struct Programari* programariCopiate = NULL;
//	int nrProgramariCopiate = 2;
//	copiereNrSpecificProgramari(programare, nrProgramari, nrProgramariCopiate);
//	afisareVectorProgramari(programare, nrProgramariCopiate);
//
//	printf("\nAfisare programari cu un nr minim de persoane de 2:\n");
//	struct Programari* programareMinPers = NULL;
//	int nrProgramariMinPers = 0;
//	copiereProgramariNrPersoaneSpecific(programare, nrProgramari, 2, &programareMinPers, &nrProgramariMinPers);
//	afisareVectorProgramari(programareMinPers, nrProgramariMinPers);
//
//	printf("\nAfisare programarilor de tip VECTOR dupa dezalocarea memoriei!\n");
//	dezalocareVector(&programare, &nrProgramari);
//
//	return 0;
//}