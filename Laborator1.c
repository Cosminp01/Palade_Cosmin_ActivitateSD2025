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
//	/*in cazul nostru cum avem char * ,prin acest pointer transmitem adresa unde este stocata acea informatie, in acest sens putem modifica inputul, noi nu vrem asta 
//	si altfel in declaram ca fiind o constanta*/
//{
//	struct Telefon t;
//	t.id = ID;
//	t.RAM = NrRAM;
//	producator fiind un pointer, trebuie sa-i alocam spatiu de memorie
//	t.producator = (char*)malloc(sizeof(char) * (strlen(NumeProducator) + 1));
//		/*va returna atatea caractere cate va gasi
//		1 este sfarsitul sirului de caractere
//		alocam memorie si adresa de inceput acelui bloc de memorie o returneaza si o salvez in acest pointer "Producator"*/
//	strcpy_s(t.producator, strlen(NumeProducator) + 1, NumeProducator);
//		functia strcpy primeste 3 atribute, primul este locatia unde vreau sa copiez, apoi cate caractere vreau sa coppiez, si al 3 lea este sursa de unde vreau sa copiez
//	t.pret = PretTelefon;
//	t.serie = SerieTelefon;
//	return t;
//}
//
//void afisare(struct Telefon t) {
//	aici trebuie sa verificam daca atributul este diferit de NULL, deoarece daca nu se face verificare la consola se va afisa valoarea NULL
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
//void modificarePret(struct Telefon* t, float pretNou) {/*acest t s-a transmis prin valoare, adica s - a copiat valoarea telefonului t declarat in functia main, din stiva de memorie a functiei
//	main, in stiva de memorie a functiei modificarePret*/
//	pentru acest lucru noi trebuie sa transmitem prin adresa acest obiect , folosindu-ne de pointeri
//	if (pretNou > 0) {	//prima data trebuie sa verificam inputul
//		t->pret = pretNou; //(*t) se numeste dereferentiere sau putem folosi operatorul sageta
//	}
//}
//
//void dezalocare(struct Telefon* t) {//am transmis direct prin pointer deoarece trebuie sa-i fac o modificare
//	if (t->producator != NULL) {
//		free(t->producator);
//		am sters spatiul de memorie a blocului meu dar pointerul meu retine in continuare adresa catre acel bloc, care acum este sters
//		dupa ce facem stergerea este recomandat sa si initializam si 
//		t->producator = NULL;//dam valoarea null, astfel incat sa nu mai aiba o adresa in el
//	}
//}
//
//int main() {
//	struct Telefon t;
//	t = initializare(10, 128, "Apple", 3501.5, 'S');
//	afisare(t);
//	modificarePret(&t, 2500);//pentru apelare in functia mai, avand in vedere ca obiectul a fost transmis prin pointer, aici trebuie sa-i dam o adresa, altfel obtin adresa lui t si i-o dau ca parametru
//	in acest moment in stiva de memorie a fucntiei modificarePret voi retine numai o adresa
//	in momentul in care vreau sa modificam pretul fac dereferentiere, adica ma duc la adresa respectiva...si acolo accesez atributul pret, si pe acesta il modific(modificarea se face direct in stiva de memorie a functiei main)
//	in momemntul in care functia modificaPret se va termina, stiva de memorie se sterge a functiei se sterge, dar telefonul meu ramane cu pretul modificat(transmiterea parametrului telefon, s-a facut prin adresa)
//	afisare(t);
//	dezalocare(&t);
//	afisare(t);
//	return 0;
//}//aici se va sterge stiva lui main
//
//
///*NOTES*/
///*malloc returneaza un void pointer(*), un pointer generic, nu stie ca eu voi aloca un pointer la char, sau int si tot asa
//din acest motiv functia returneaza un pointer generic
//in cazul nostru trebuie sa specificam ca va fi un pointer la char deoarece asa l-am declarat, practic facem CAST(EXPLICIT) deoarece transformam din pointer la void, la pointer la char*/
//prin functia malloc noi declaram cati octeti trebuie sa-mi aloce in memorie
//ghilimele sunt folosite pentru siruri de caractere iar un caracter intre apostrof