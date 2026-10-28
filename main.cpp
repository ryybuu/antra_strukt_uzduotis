#include <iostream>
#include <string>
#include <format>
using namespace std;

void stars() {
    for (int i = 1; i < 50; i++) {
        cout << "*";
    }
    cout << endl;
}

void main_menu() {
    cout << endl;
    stars();
    cout << "                     MENIU" << endl;
    stars();
    cout << "1. Ivesti mokini ir jo pazymius." << endl;
    cout << "2. Perziureti visu mokiniu pazymius" << endl;
    cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
    cout << "4. Atnaujinti pazymi" << endl;
    cout << "5. Apskaiciuoti mokinio vidurki" << endl;
    cout << "6. Pasalinti mokini" << endl;
    cout << "7. Iseiti." << endl;
    stars();
    cout << "Pasirinkima iveskite cia:" << endl;
}


int main() {
    string mokiniai[100] = {};
    int pazymiai[100][10] = {};
    int ivestis;
    int ivestu_mokiniu_kiekis = 0;


    do {
        main_menu();
        cin >> ivestis;

        switch (ivestis) {
            case 1: {
                string vardas;
                int mokinio_indeksas = -1;
                int pazymiu_kiekis;
                int pazymys = 0;
                cout << "Iveskite mokinio varda" << endl;
                cin >> vardas;
                for (int i = 0; i < 100; i++) {
                    if (mokiniai[i] == "") {
                        mokiniai[i] = vardas;
                        mokinio_indeksas = i;
                        ivestu_mokiniu_kiekis++;
                        break;
                    }
                }

                if (mokinio_indeksas == -1) {
                    cout << "Mokiniu sarasas pilnas. Naujo mokinio prideti negalima" << endl;
                    break;
                }

                do {
                    cout << "Kiek pazymiu noresite ivesti? (1-10)" << endl;
                    cin >> pazymiu_kiekis;
                    if (pazymiu_kiekis > 10 || pazymiu_kiekis < 1)
                        cout << "Neteisinga ivestis. Kiekis turi buti sveikas skaicius nuo 1 iki 10" << endl;
                } while (pazymiu_kiekis > 10 || pazymiu_kiekis < 1);

                for (int j = 0; j < pazymiu_kiekis; j++) {
                    do {
                        cout << format("Iveskite {} pazymi", j + 1) << endl;
                        cin >> pazymys;
                        if (pazymys > 10 || pazymys < 1) {
                            cout << "Pazymys turi buti sveikas skaicius nuo 1 iki 10" << endl;
                        }
                    } while (pazymys > 10 || pazymys < 1);
                    pazymiai[mokinio_indeksas][j] = pazymys;
                }
                break;
            }
            case 2:
                cout << "Mokiniu vardai ir ju pazymiai:" << endl;
                for (int i = 0; i < ivestu_mokiniu_kiekis; i++) {
                    cout << mokiniai[i] << " ";
                        for (int j = 0; j < 10; j++) {
                            if (pazymiai[i][j] == 0) {
                                break;
                            }
                            cout << pazymiai[i][j] << " ";
                        }
                    cout << endl;
                }
                break;
            case 3:
                if (ivestu_mokiniu_kiekis == 0) {
                    cout << "Sarasas yra tuscias, mokiniu patikrinti negalima. Griztama i pagrindini meniu..." << endl;
                    break;
                }

                cout << "Iveskite mokinio numeri arba 0 jeigu norite grizti i pagrindini meniu " << endl;
                int mokinio_numeris;

                do {
                    cin >> mokinio_numeris;
                    if (mokinio_numeris == 0) {
                        break;
                    } else if (mokinio_numeris < 1 || mokinio_numeris > 100) {
                            cout << "Neteisinga ivestis. Mokinio numeris turi buti nuo 1 iki 100. Bandykite dar karta arba iveskite 0, kad iseiti" << endl;
                        } else if(mokiniai[mokinio_numeris-1] == "") {
                                cout << "Mokinys tokiu numeriu negzistuoja. Bandykite dar karta arba iveskite 0, kad iseiti"  << endl;
                            } else {
                                    cout << "Mokinys " << mokiniai[mokinio_numeris-1] << endl << "Pazymiai: ";
                                    for (int i = 0; i < 10; i++) {
                                        if (pazymiai[mokinio_numeris-1][i] != 0)
                                            cout << pazymiai[mokinio_numeris-1][i] << " ";
                                    }
                                    cout << endl;
                                break;
                            }
                } while (true);
                break;
        }
    } while (ivestis != 7);


    return 0;
}
