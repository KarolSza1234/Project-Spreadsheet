#include<iostream>
#include<fstream>
#include<string>
#include"Nag³ówek.h"


int main()
{
    bool loop = true;
    int swt = 99;
    int all = 4;

    bool a = true, b = true, program = true, program_loop = true;
    lista** arkuszKAL = NULL;///tablica dynamiczna arkuszKAL
    while (all > 1) {
        cout << "Wybierz co bedziesz robil" << endl << "0=stworz nowy akrusz" << endl << "1=wczytaj arkusz" << endl;
        cin >> all;
    }
    while (program_loop) {///fukcja sterujaca programem

        switch (all) {
        case 0:
            while (a && b) {

                cout << "Podaj szerokosc arkusza" << endl;
                cin >> width;
                a = cin.fail();
                cin.clear();
                cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
                cout << "Podaj dlugosc arkusza" << endl;
                cin >> length;
                b = cin.fail();
                cin.clear();
                cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');


            }
            arkuszKAL = creatTAB(width, length);
            clear(arkuszKAL);
            break;
        case 1:cout << "Podaj nazwe pliku" << endl;

            string plik_n;
            cin >> plik_n;

            load_bin(plik_n.c_str());
            arkuszKAL = loadARK;

            break;
        }
        while (loop) {///zmiena sterujaca praca na arkuszu kalkulacyjnym
            checkOP(arkuszKAL);

            bool checkCIN = true;
            draw(arkuszKAL);
            while (checkCIN || swt < 0 || swt > 6) {
                cout << "Co chcesz zrobic?\n1=Operacja matematyczna\n2=Wpisz wartosc\n3=Wskaz na inna komurke\n4=Zapisz i wyjdz\n5=wyjdz";
                cin >> swt;
                checkCIN = cin.fail();
                cin.clear();
                cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');

            }
            bool checkOP = false;
            string pk_name;
            switch (swt) {
            case 1:while (!checkOP) {
                checkOP = matOP(arkuszKAL);
                if (checkOP == false)cout << "wpisales zla wartosc" << endl;
            } break;
            case 2:while (!checkOP) {
                checkOP = enterVALUE(arkuszKAL);
                if (checkOP == false)cout << "wpisales zla wartosc" << endl;
            } break;
            case 3:while (!checkOP) {
                checkOP = poitingTO(arkuszKAL); break;
                if (checkOP == false)cout << "wpisales zla wartosc" << endl;
            } break;
            case 4:cout << "Podaj nazwe" << endl;
                cin >> pk_name;

                save_bin(arkuszKAL, pk_name.c_str());
                loop = false;
                program_loop = false;
                break;
            case 5:loop = false; program_loop = false; break;

            }
            system("cls");
            swt = 0;
        }
        for (int i = 0; i < width; ++i)
            delete[] arkuszKAL[i]; //uwolnienie pamieci
        delete[] arkuszKAL; //uwolnienie pamieci
        arkuszKAL = NULL;


    }
}
