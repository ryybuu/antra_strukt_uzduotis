#include <iostream>
#include <string>
#include <format>
using namespace std;

bool nera_mokiniu(int ivestu_mokiniu_kiekis) {
   return ivestu_mokiniu_kiekis == 0;
}

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
    int ivestu_pazymiu_kiekis[100] = {};


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
                    cout << "Kiek pazymiu noresite ivesti? (0-10)" << endl;
                    cin >> pazymiu_kiekis;
                    if (pazymiu_kiekis > 10 || pazymiu_kiekis < 0)
                        cout << "Neteisinga ivestis. Kiekis turi buti sveikas skaicius nuo 0 iki 10" << endl;
                } while (pazymiu_kiekis > 10 || pazymiu_kiekis < 0);

                if (pazymiu_kiekis == 0) cout << "Mokinys pridetas be pazymiu" << endl;


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
                ivestu_pazymiu_kiekis[mokinio_indeksas] = pazymiu_kiekis;
                break;
            }
            case 2:
                cout << "Mokiniu vardai ir ju pazymiai:" << endl;
                for (int i = 0; i < ivestu_mokiniu_kiekis; i++) {
                    cout << i+1 << "." << mokiniai[i] << " ";
                    if (ivestu_pazymiu_kiekis[i] == 0) {
                        cout << "neturi pazymiu" << endl;
                    } else {
                        for (int j = 0; j < ivestu_pazymiu_kiekis[i]; j++) {
                            cout << pazymiai[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
                break;
            case 3:
                if (nera_mokiniu(ivestu_mokiniu_kiekis)) {
                    cout << "Sarasas yra tuscias, mokiniu patikrinti negalima. Griztama i pagrindini meniu..." << endl;
                    break;
                }

                cout << format(
                    "Iveskite mokinio numeri nuo 1 iki {} arba 0 jeigu norite grizti i pagrindini meniu.",
                    ivestu_mokiniu_kiekis) << endl;
                int mokinio_numeris;

                do {
                    cin >> mokinio_numeris;
                    if (mokinio_numeris == 0) {
                        break;
                    } else if (mokinio_numeris < 1 || mokinio_numeris > ivestu_mokiniu_kiekis) {
                        cout << format(
                            "Neteisinga ivestis. Mokinio numeris turi buti nuo 1 iki {}. Bandykite dar karta arba iveskite 0, kad iseiti",
                            ivestu_mokiniu_kiekis) << endl;
                    } else if (ivestu_pazymiu_kiekis[mokinio_numeris - 1] == 0) {
                            cout << mokinio_numeris << "." << mokiniai[mokinio_numeris - 1] << " neturi pazymiu" << endl;
                            break;
                        } else {
                            cout << "Mokinys " << mokiniai[mokinio_numeris - 1] << endl << "Pazymiai: ";

                            for (int i = 0; i < ivestu_pazymiu_kiekis[mokinio_numeris-1]; i++) {
                                cout << pazymiai[mokinio_numeris - 1][i] << " ";
                            }
                            cout << endl;
                            break;
                        }
                } while (true);
                break;
            case 4:
                if (nera_mokiniu(ivestu_mokiniu_kiekis)) {
                    cout << "Sarasas yra tuscias, pazymiu atnaujinti negalima. Griztama i pagrindini meniu..." << endl;
                    break;
                }
                int mokinio_ivestis;
                cout << format("Iveskite mokinio numeri nuo 1 iki {} arba 0 jeigu norite grizti i pagrindini meniu.", ivestu_mokiniu_kiekis) << endl;
                do {
                    cin >> mokinio_ivestis;
                    if (mokinio_ivestis < 0 || mokinio_ivestis > ivestu_mokiniu_kiekis) {
                        cout << format("Iveskite mokinio numeri nuo 1 iki {} arba 0 jeigu norite grizti i pagrindini meniu", ivestu_mokiniu_kiekis) << endl;
                    }
                } while (mokinio_ivestis < 0 || mokinio_ivestis > ivestu_mokiniu_kiekis);

                if (mokinio_ivestis == 0) break;

                if (ivestu_pazymiu_kiekis[mokinio_ivestis - 1] == 0) {
                    cout << "Mokinys neturi pazymiu, todel ju atnaujinti negalima." << endl;
                    break;
                } else {
                    // Prideti logika pazymio pakeitimui
                }

                break;
            case 5:
                if (nera_mokiniu(ivestu_mokiniu_kiekis)) {
                    cout << "Sarasas yra tuscias, vidurkiu suskaiciuoti negalima. Griztama i pagrindini meniu..." << endl;
                    break;
                }

                int mokinio_numerio_ivestis;
                double mokinio_pazymiu_suma = 0;

                cout << format("Iveskite mokinio numeri nuo 1 iki {} arba 0 jeigu norite grizti i pagrindini meniu", ivestu_mokiniu_kiekis) << endl;
                do {
                    cin >> mokinio_numerio_ivestis;
                    if (mokinio_numerio_ivestis < 0 || mokinio_numerio_ivestis > ivestu_mokiniu_kiekis) {
                        cout << format("Iveskite mokinio numeri nuo 1 iki {} arba 0 jeigu norite grizti i pagrindini meniu", ivestu_mokiniu_kiekis) << endl;
                    }
                } while (mokinio_numerio_ivestis < 0 || mokinio_numerio_ivestis > ivestu_mokiniu_kiekis);

                if (mokinio_numerio_ivestis == 0) break;

                if (ivestu_pazymiu_kiekis[mokinio_numerio_ivestis - 1] == 0) {
                    cout << format("{} neturi pazymiu, vidurkio apskaiciuoti negalima", mokiniai[mokinio_numerio_ivestis - 1]) << endl;
                } else {
                    for (int i = 0; i < ivestu_pazymiu_kiekis[mokinio_numerio_ivestis - 1]; i++) {
                        mokinio_pazymiu_suma += pazymiai[mokinio_numerio_ivestis - 1][i];
                    }
                    cout << format("Mokinio(es) {0} pazymiu vidurkis yra {1:.2f}.", mokiniai[mokinio_numerio_ivestis-1], mokinio_pazymiu_suma / ivestu_pazymiu_kiekis[mokinio_numerio_ivestis - 1]) << endl;
                }
                break;
        }
    } while (ivestis != 7);


    return 0;
}
