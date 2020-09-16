#include<iostream>
#include<fstream>
#include<string>
#include"Nag³ówek.h"
using namespace std;
unsigned width, length;
lista** loadARK;
bool enterVALUE(lista** tab) {
    int a, b;
    bool check;
    cout << "Podaj numer komurki w pionie" << endl;
    cin >> a;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || a > width)return false;
    cout << "Podaj numer komurki w poziomie" << endl;
    cin >> b;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || b > length)return false;
    double y;
    cout << "Podaj wartoœæ ktora chcesz wpisac do komurki" << endl;
    cin >> y;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true)return false;
    tab[a][b].wartosc = y;
    tab[a][b].pnk = NULL;
    tab[a][b].op = NULL;
    tab[a][b].znak = NULL;
}
void clear(lista** tab) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            tab[i][j].op = NULL;
            tab[i][j].pnk = NULL;
            tab[i][j].wartosc = NULL;
            tab[i][j].znak = NULL;
            tab[i][j].pion = i;
            tab[i][j].poz = j;

        }
    }
}
bool poitingTO(lista** tab) {
    int a, b, x, y;
    bool check;
    cout << "Podaj numer komurki w pionie" << endl;
    cin >> a;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || a > width)return false;

    cout << "Podaj numer komurki w poziomie" << endl;
    cin >> b;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || b > length)return false;
    cout << "Podaj numer komurki w pionie na ktora ma wskazywac" << endl;
    cin >> x;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || x > width)return false;
    cout << "Podaj numer komurki w poziomie na ktora ma wskazywac" << endl;
    cin >> y;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || y > length)return false;
    tab[a][b].pnk = &tab[x][y];
    if (a == x && b == y)tab[a][b].pnk = NULL;
    tab[a][b].op = NULL;
    tab[a][b].wartosc = NULL;
    tab[a][b].znak = NULL;
}
void checkOP(lista** tab) {
    double w1, w2;
    lista* temp = NULL;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            if (tab[i][j].pnk != NULL && tab[i][j].op != NULL)
            {
                temp = tab[i][j].pnk;
                while (temp->pnk != NULL) {
                    temp = temp->pnk;
                }
                w1 = temp->wartosc;


                temp = tab[i][j].op;
                while (temp->pnk != NULL) {
                    temp = temp->pnk;
                }
                w2 = temp->wartosc;

                if (tab[i][j].znak == '+') {
                    tab[i][j].wartosc = w1 + w2;
                }
                if (tab[i][j].znak == '-') {
                    tab[i][j].wartosc = w1 - w2;
                }
                if (tab[i][j].znak == '*') {
                    tab[i][j].wartosc = w1 * w2;
                }
                if (tab[i][j].znak == '/') {

                    if (w2 != 0)tab[i][j].wartosc = w1 / w2;
                    else tab[i][j].wartosc = 0;
                }

            }
        }
    }
}
void draw(lista** tab) {
    cout << " ";
    for (int i = 0; i < width; i++) {
        cout << "|" << i << "|";
    }
    lista* temp = NULL;
    cout << endl;
    for (int i = 0; i < length; i++) {
        cout << i;
        for (int j = 0; j < width; j++) {
            if (tab[i][j].pnk == NULL && tab[i][j].op == NULL && tab[i][j].wartosc == NULL)cout << "|" << " " << "|";
            if (tab[i][j].pnk != NULL && tab[i][j].op == NULL && tab[i][j].wartosc == NULL) {
                temp = &tab[i][j];
                while (temp->pnk != NULL) {
                    temp = temp->pnk;
                }
                if (temp->wartosc != NULL)cout << "|" << temp->wartosc << "|";
                else cout << "|" << "0" << "|";
            }
            if (tab[i][j].pnk != NULL && tab[i][j].op != NULL) {
                if (tab[i][j].wartosc != NULL)cout << "|" << tab[i][j].wartosc << "|";
                else cout << "|0|";
            }
            if (tab[i][j].pnk == NULL && tab[i][j].op == NULL && tab[i][j].wartosc != NULL)cout << "|" << tab[i][j].wartosc << "|";

        }
        cout << endl;
    }
}
bool matOP(lista** tab) {
    unsigned int a, b, c, d, e, f;
    unsigned int dzialanie;
    bool check;
    lista* temp = NULL;

    cout << "wybierz dzialanie" << endl << "0=dodawanie" << endl << "1=odejmowanie" << endl << "2=mnozenie" << endl << "3=dzielenie" << endl;
    cin >> dzialanie;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || dzialanie > 3)return false;
    cout << "Podaj numer komurki w pionie w ktorej ma zostac wykonane dzialanie" << endl;
    cin >> a;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true)return false;
    cout << "Podaj numer komurki w poziomie w ktorej ma zostac wykonane dzialanie" << endl;
    cin >> b;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || a >= length || b >= width)return false;
    cout << "Podaj numer pierwszej komurki w pionie ktora dodasz" << endl;
    cin >> c;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true)return false;
    cout << "Podaj numer pierwszej komurki w poziomie ktora dodasz" << endl;
    cin >> d;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || c >= length || d >= width)return false;
    cout << "Podaj numer drugiej komurki w pionie ktora dodasz" << endl;
    cin >> e;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true)return false;
    cout << "Podaj numer drugiej komurki w poziomie ktora dodasz" << endl;
    cin >> f;
    check = cin.fail();
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
    if (check == true || e >= length || f >= width)return false;
    if ((a == c && b == d) || (c == e && d == f) || (a == e && b == f))return false;

    double w1 = 0, w2 = 0;
    temp = &tab[c][d];
    if (temp->wartosc != NULL)w1 = temp->wartosc;
    while (temp->pnk != NULL) {
        if (temp->pnk != NULL)temp = temp->pnk;

    }
    w1 = temp->wartosc;
    temp = &tab[e][f];
    if (temp->wartosc != NULL)w2 = temp->wartosc;
    while (temp->pnk != NULL) {

        if (temp->pnk != NULL)temp = temp->pnk;

    }
    w2 = temp->wartosc;
    if (dzialanie == 0) {
        tab[a][b].znak = '+';
        tab[a][b].pnk = &tab[c][d];
        tab[a][b].op = &tab[e][f];
        tab[a][b].wartosc = w1 + w2;
    }
    if (dzialanie == 1) {
        tab[a][b].znak = '-';
        tab[a][b].pnk = &tab[c][d];
        tab[a][b].op = &tab[e][f];
        tab[a][b].wartosc = w1 - w2;
    }
    if (dzialanie == 2) {
        tab[a][b].znak = '*';
        tab[a][b].pnk = &tab[c][d];
        tab[a][b].op = &tab[e][f];
        tab[a][b].wartosc = w1 * w2;
    }
    if (dzialanie == 3) {


        if (w2 != 0) {
            tab[a][b].pnk = &tab[c][d];
            tab[a][b].op = &tab[e][f];
            tab[a][b].znak = '/';
            tab[a][b].wartosc = w1 / w2;
        }
        else {
            cout << "dzialanie nie poprawne" << endl;
            return false;
        }
    }
    return true;
}
void save_bin(lista** tab, const char* nazwa) {

    fstream file(nazwa, ios::out | ios::binary);
    if (file.is_open()) {
        file.write((char*)&width, sizeof(unsigned));
        file.write((char*)&length, sizeof(unsigned));
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {

                double nul = 0;
                int nine = 99;
                char a = 'a';

                file.write((char*)&tab[i][j].pion, sizeof(unsigned));
                file.write((char*)&tab[i][j].poz, sizeof(unsigned));
                if (tab[i][j].wartosc != NULL) {
                    double x = tab[i][j].wartosc;
                    file.write((char*)&x, sizeof(double));
                    
                }
                if (tab[i][j].wartosc == NULL) file.write((char*)&nul, sizeof(double));
                if (tab[i][j].pnk != NULL && tab[i][j].op == NULL) {
                    file.write((char*)&tab[i][j].pnk->pion, sizeof(unsigned));
                    file.write((char*)&tab[i][j].pnk->poz, sizeof(unsigned));
                    file.write((char*)&nine, sizeof(unsigned));
                    file.write((char*)&nine, sizeof(unsigned));
                    file.write(&a, sizeof(char));

                }
                if (tab[i][j].pnk != NULL && tab[i][j].op != NULL) {
                    file.write((char*)&tab[i][j].pnk->pion, sizeof(unsigned));
                    file.write((char*)&tab[i][j].pnk->poz, sizeof(unsigned));
                    file.write((char*)&tab[i][j].op->pion, sizeof(unsigned));
                    file.write((char*)&tab[i][j].op->poz, sizeof(unsigned));
                    file.write(&tab[i][j].znak, sizeof(char));
                }
                if (tab[i][j].pnk == NULL && tab[i][j].op == NULL) {

                    file.write((char*)&nine, sizeof(unsigned));
                    file.write((char*)&nine, sizeof(unsigned));
                    file.write((char*)&nine, sizeof(unsigned));
                    file.write((char*)&nine, sizeof(unsigned));
                    file.write(&a, sizeof(char));
                }





            }
        }

    }
    file.close();

}
lista** creatTAB(unsigned width, unsigned length) {

    lista** tab = new lista * [length];
    for (int i = 0; i < width; i++)tab[i] = new lista[width];
    return tab;
}
bool load_bin(const char* nazwa) {
    fstream file(nazwa, ios::binary | ios::in);
    unsigned y, x, z;
    double c;



    if (file.is_open()) {
        file.read((char*)&width, sizeof(unsigned));
        file.read((char*)&length, sizeof(unsigned));
        loadARK = new lista * [length];
        for (int i = 0; i < width; i++)loadARK[i] = new lista[width];


        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < length; j++) {

                file.read((char*)&x, sizeof(unsigned));
                loadARK[i][j].pion = x;
                file.read((char*)&x, sizeof(unsigned));
                loadARK[i][j].poz = x;
                file.read((char*)&c, sizeof(double));
                loadARK[i][j].wartosc = c;
                file.read((char*)&x, sizeof(unsigned));
                file.read((char*)&y, sizeof(unsigned));
                if (x != 99 && y != 99) {
                    loadARK[i][j].pnk = &loadARK[x][y];
                }
                if (x == 99 && y == 99) {
                    loadARK[i][j].pnk = NULL;
                }
                file.read((char*)&x, sizeof(unsigned));
                file.read((char*)&y, sizeof(unsigned));
                file.read(&loadARK[i][j].znak, sizeof(char));
                if (x != 99 && y != 99) {
                    loadARK[i][j].op = &loadARK[x][y];
                }
                if (x == 99 && y == 99 && loadARK[i][j].znak == 'a') {
                    loadARK[i][j].op = NULL;
                    loadARK[i][j].znak = NULL;
                }
                if (loadARK[i][j].pnk != NULL && loadARK[i][j].op == NULL)loadARK[i][j].wartosc == NULL;
                if (loadARK[i][j].wartosc == 0)loadARK[i][j].wartosc = NULL;




                if (file.eof())
                    break;
            }
        }
    }
    else return false;
    file.close();
    
}