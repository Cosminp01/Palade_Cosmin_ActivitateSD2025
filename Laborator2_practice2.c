//#include<stdio.h>
//#include<stdlib.h>
//
//struct Medicamente {
//	int id;
//	float cantitate;
//	double pret;
//	char* farmacie;
//};
//
//struct Medicamente initializare(int idMedicament, float cantitateMedicamente, double pretMedicament, const char* farmacieMedicament) {
//	struct Medicamente m;
//	m.id = idMedicament;
//	m.cantitate = cantitateMedicamente;
//	m.pret = pretMedicament;
//	m.farmacie = (char*)malloc(sizeof(char) * (strlen(farmacieMedicament) + 1));
//	strcpy_s(m.farmacie, strlen(farmacieMedicament) + 1, farmacieMedicament);
//	return m;
//}
//
//void afisareMedicamente(struct Medicamente m) {
//	if (m.farmacie != NULL) {
//		printf("%d. Medicamentul se poate gasi la farmaica %s, intr-o cantitate de %5.2f cutii la pretul de %.2f RON!\n",
//			m.id, m.farmacie, m.cantitate, m.pret);
//	}
//	else {
//		printf("Medicamentul nu se afla in stoc!\n");
//	}
//}
//
//void afisareMedicamenteVector(struct Medicamente* m, int nrMedicamente) {
//	for (int i = 0; i < nrMedicamente; i++) {
//		afisareMedicamente(m[i]);
//	}
//}
//
//void dezalocareVector(struct Medicamente** m, int* nrMedicamente) {
//	for (int i = 0; i < (*nrMedicamente); i++) {
//		if ((*m)[i].farmacie != NULL) {
//			free((*m)[i].farmacie);
//		}
//	}
//	free(*m);
//	*m = NULL;
//	*nrMedicamente = 0;
//}
//
//struct Medicamente* copiereNrMedicamente(struct Medicamente* m, int nrMedicamente, int nrMedicamenteCopiate) {
//	struct Medicamente* mNou = NULL;
//	mNou = (struct Medicamente*)malloc(sizeof(struct Medicamente) * nrMedicamenteCopiate);
//	for (int i = 0; i < nrMedicamenteCopiate; i++) {
//		mNou[i] = m[i];
//		mNou[i].farmacie = (char*)malloc(strlen(m[i].farmacie) + 1);
//		strcpy_s(mNou[i].farmacie, strlen(m[i].farmacie) + 1, m[i].farmacie);
//	}
//	return mNou;
//}
//
////telefoane care au mai multi gbram fata de un nr
////telefoane care sunt mai ieftine/scumpe decat..
//
//
////in cazul nostru vom copia numai medicametnele care depasesc u anumite prag
//void copiazaMedicamenteScumpe(struct Medicamente* m, char nrElemente, float pretMinim, struct Medicamente** mNou, int* dimensiune) {
//	*dimensiune = 0;
//	for (int i = 0; i < nrElemente; i++) {
//		if (m[i].pret >= pretMinim) {
//			(*dimensiune)++;
//		}
//	}
//
//	if ((*mNou) != NULL) {
//		free(*mNou);
//	}
//	*mNou = (struct Medicamente*)malloc(sizeof(struct Medicamente) * (*dimensiune));
//
//	int k = 0;
//	for (int i = 0; i < nrElemente; i++) {
//		if (m[i].pret >= pretMinim) {
//			(*mNou)[k] = m[i];
//
//			(*mNou)[k].farmacie = (char*)malloc(strlen(m[i].farmacie) + 1);
//			strcpy_s((*mNou)[k].farmacie, strlen(m[i].farmacie) + 1, m[i].farmacie);
//			k++;
//		}
//	}
//}
//
//
//
//int main()
//{
//	struct Medicamente* medicament = NULL;
//	int nrMedicamente = 3;
//	medicament = (struct Medicamente*)malloc(sizeof(struct Medicamente) * nrMedicamente);
//
//	medicament[0] = initializare(123, 23.5, 32.45, "Catena");
//	medicament[1] = initializare(100, 10, 43.89, "DONA");
//	medicament[2] = initializare(007, 15, 12.5, "DrMAX");
//
//	afisareMedicamenteVector(medicament, nrMedicamente);
//
//	struct Medicamente* medicamenteNoi = NULL;
//	int nrMedicamenteNoi = 2;
//	copiereNrMedicamente(medicament, nrMedicamente, nrMedicamenteNoi);
//	printf("\nMedicamentele noi sunt:\n");
//	afisareMedicamenteVector(medicament, nrMedicamenteNoi);
//
//	//dezalocareVector(&medicament, &nrMedicamente);
//	afisareMedicamenteVector(medicament, nrMedicamente);
//
//	//copiere medicamente scumpe
//	struct Medicamente* medicamenteScumpe = NULL;
//	int nrMedicamenteScumpe = 0;
//	copiazaMedicamenteScumpe(medicament, nrMedicamente, 30.00, &medicamenteScumpe, &nrMedicamenteScumpe);
//	printf("\n\nMedicamentele scumpe sunt:\n");
//	afisareMedicamenteVector(medicamenteScumpe, nrMedicamenteScumpe);
//
//	dezalocareVector(&medicamenteScumpe, &nrMedicamenteScumpe);
//
//
//	return 0;
//}