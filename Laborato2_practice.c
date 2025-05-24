//#include<stdio.h>
//#include<stdlib.h>
//
//struct Telefon {
//	int id;
//	int RAM;
//	char* producator;
//	float pret;
//	char serie;
//};
//
//struct Telefon initializare(int ID, int NrRAM, const char* NumeProducator,float PretTelefon, char SerieTelefon)
//	
//{
//	struct Telefon t;
//	t.id = ID;
//	t.RAM = NrRAM;
//	t.producator = (char*)malloc(sizeof(char) * (strlen(NumeProducator) + 1));
//	strcpy_s(t.producator, strlen(NumeProducator) + 1, NumeProducator);
//	t.pret = PretTelefon;
//	t.serie = SerieTelefon;
//	return t;
//}
//
//void afisare(struct Telefon t) {
//	if (t.producator != NULL) {
//		printf("%d. Telefonul modelul %s din seria %c are %d Gb RAM, are pretul de %5.2f RON.\n",
//			t.id, t.producator, t.serie, t.RAM, t.pret);
//	}
//	else {
//		printf("%d. Telefonul din seria %c are %d Gb RAM, are pretul de %5.2f RON.\n",
//			t.id, t.serie, t.RAM, t.pret);
//	}
//}
//
//void afisareVector(struct Telefon* vector, int nrElemente)
////primeste vectorul de telefoane respectiv nr de elemente
//{
//	for (int i = 0; i < nrElemente; i++) {
//		afisare(vector[i]); //luam elementul de pe pozitia i, il dam functiei de afisare care l va afisa
//	}
//}
//
////daca avem un vector cu mai multe elemente si vreau saa copiez un element din acel vector primele n elemente
////pentru asta trebuie sa stiu vectorul initial, cate elemente contine si cate elemente vreau sa copiez
////cele 2 elemente care vor fi extrase din vectorul principal vor fi copiate intr-un nou vector, pnetur acet lucru ne folosim de un pointer care retine adresa elementelor din primul vector
//struct Telefon* copiazaPrimeleNElemente(struct Telefon* vector, int nrElemente, int nrElementeCopiate) {
//	//definim noul vector
//	struct Telefon* vectorNou = NULL;
//	//acum alocam spatiu noului vectro definit
//	vectorNou = (struct Telefon*)malloc(sizeof(struct Telefon) * nrElementeCopiate); //acum este gol
//	//pentru a umple pozitiile noului vector trebuie sa parcurgem in cadurl vectorului pe care l am primit ca parametru, pana la cate nrElementeCopiate vrem, folosind un loop
//	for (int i = 0; i < nrElementeCopiate; i++) {
//		vectorNou[i] = vector[i];
//		//facem deeepcopy
//		vectorNou[i].producator = (char*)malloc(strlen(vector[i].producator) + 1);
//		strcpy_s(vectorNou[i].producator, strlen(vector[i].producator) + 1, vector[i].producator);
//	}
//	return vectorNou;
//}
//
//void dezalocareVector(struct Telefon** vector, int* nrElemente) {
//	//se apeleaza prin pointer nr de elemente deoarece dupa ce le voi sterge va fi zero iar la vector rl va fi NULL, deci trebuie sa l modificam
//	//trebuie sa parcurgem intreg vectorul pentru a sterge sirul de caractere
//	for (int i = 0; i < (*nrElemente); i++) {// am facut dereferentiere
//		//stergem elementele char*
//		if ((*vector)[i].producator != NULL) {
//			free((*vector)[i].producator);
//		}
//	}//acum stergem vectorul dupa for
//	free(*vector);
//	*vector = NULL;
//	*nrElemente = 0;
//}
//
//void copiazaTelefoaneScumpe(struct Telefon* vector, char nrElemente, float pretMinim, struct Telefon** vectorNou, int* dimensiune) {
//	//o sa returnez prin parametru de aceeas avem acel pointer Telefon** in care noi vom avea vectorul pe care il vom aloca noi aici
//	//ne cream un vector care vor indeplini acea conditie si dimensiunea acestuia
//
//	//pas 1.prima oara trebuie sa determinam aceasta dimensiune, adica cate telefoane vor indeplini conditia noastra
//	*dimensiune = 0;
//	for (int i = 0; i < nrElemente; i++) {//parcurgem elementele noastre
//		//odata ce le parcurgem noi trebuie sa le verific pe fiecare in parte
//		if (vector[i].pret >= pretMinim) {
//			(*dimensiune)++;//indeplineste conditia si astfel crestem conditia
//		}
//	}
//
//	//pas 2. acum trebuie sa alocam spatiu vectorului NOU
//	if ((*vectorNou) != NULL) {//trebuie sa l verificam inainte pentru a sterge daca avea ceva inainte pentru a evia memory leak
//		free(*vectorNou);
//	}
//	*vectorNou = (struct Telefon*)malloc(sizeof(struct Telefon) * (*dimensiune)); //aici am alocat spatiu
//
//	int k = 0;//folosit pentru a pozitiona elementul nou in vectul nou
//	for (int i = 0; i < nrElemente; i++) {//parcurgem inca o data veectorul nostru
//		if (vector[i].pret >= pretMinim) {//verificam inca o data conditiile
//			(*vectorNou)[k] = vector[i];// pana aici avem shallor copy
//
//			//deep copy
//			(*vectorNou)[k].producator = (char*)malloc(strlen(vector[i].producator) + 1);
//			strcpy_s((*vectorNou)[k].producator, strlen(vector[i].producator) + 1, vector[i].producator);
//			k++;
//		}
//	}
//}
//
//int main() {
//	//ne declaram un vector de telefoane
//	//pentru asta ne declaram un pointer la structura noastra de tip telefoane si apoi trebuie sa i alocam spatiu
//	struct Telefon* telefoane = NULL;
//	int nrTelefoane = 3;
//	telefoane = (struct Telefon*)malloc(sizeof(struct Telefon) * nrTelefoane);//alocare spatiu pentru vector
//	//acum trebuie sa initializam fiecare pozitie
//	telefoane[0] = initializare(1, 256, "Samsung", 2000, 'S');
//	telefoane[1] = initializare(2, 128, "Motorola", 1500, 'M');
//	telefoane[2] = initializare(3, 512, "Apple", 2200, 'A');
//
//	afisareVector(telefoane, nrTelefoane);
//
//	struct Telefon* primeleTelefoane = NULL;
//	int nrPrimeleTelefoane = 2;
//	primeleTelefoane = copiazaPrimeleNElemente(telefoane, nrTelefoane, nrPrimeleTelefoane);
//	printf("\nPrimele telefoane:\n");
//	afisareVector(primeleTelefoane, nrPrimeleTelefoane);
//
//	dezalocareVector(&primeleTelefoane, &nrPrimeleTelefoane);
//	afisareVector(primeleTelefoane, nrPrimeleTelefoane);
//
//	//copiaza telefoane scumpe
//	struct Telefon* telefoaneScumpe = NULL;
//	int nrTelefoaneScumpe = 0;
//	copiazaTelefoaneScumpe(telefoane, nrTelefoane, 2000, &telefoaneScumpe, &nrTelefoaneScumpe);
//	printf("\n\nTelefoane mai scumpe de 2000 ron:\n");
//	afisareVector(telefoaneScumpe, nrTelefoaneScumpe);
//
//	dezalocareVector(&telefoaneScumpe, &nrTelefoaneScumpe);
//
//	return 0;
//}
//
