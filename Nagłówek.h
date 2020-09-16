#pragma once
#ifndef NAGLÓWEK_H_INCLUDED
#define NAGLÓWEK_H_INCLUDED
using namespace std;
struct lista {
    double wartosc;
    unsigned pion;
    unsigned poz;
    lista* pnk;
    char znak;
    lista* op;
}; ///structura potrzebna do tablicy

   extern unsigned width, length;///zmiena szerokosc i dlugosc
   extern lista** loadARK;/// zmiana do ktorej wczytuje plik




bool enterVALUE(lista** tab);/**fukcja *ktora wczytuje wartosc do tablicy
                             @parama1 tablica
                             @return zwraca czy urzytkownik wprowadzil prawidlowe dane
                             **/
void clear(lista** tab);/**fukcja *ktora czysci tablice ¿eby zostala pusta ¿eby nie wczytywac blednych danych
                                      @parama1 tablica
                                      **/
bool poitingTO(lista** tab);/**fukcja w ktorej urzytkownik wybiera ktora komorka ma na ktora wskazywac
                                      @parama1 tablica
                                      @return zwraca czy urzytkownik wprowadzil prawidlowe dane
                                      **/

void checkOP(lista** tab);/**fukcja ktora sprawdza operacje matemtyczne czy dane zostaly zmienione w jednej
                                                 z komorek i poprawia jesli tak  
                                      @parama1 tablica
                                      @return zwraca czy urzytkownik wprowadzil prawidlowe dane
                                      **/

void draw(lista** tab);/**fukcja ktora rysuje arkusz
                                              @param 1 tab**/
bool matOP(lista** tab);/**fukcja ktora uzytkownik wybiera jaka operacje chce uzyc i z ktorych komorek
                                              @param 1 tab
                                              @return zwraca czy zostaly wprowadzone poprawne dane**/
void save_bin(lista** tab, const char* nazwa);/**fukcja ktora zapisuje do pliku binarnego
                                              @param 1 tab
                                              @param 2 nazwa pliku**/
lista** creatTAB(unsigned width, unsigned length);/**fukcja ktora tworzy tablice dynamiczna o podanej szerokosci i dlugosci                                           
                                              @param 1 szerokosc
                                              @param 2 dlugosc
                                              @return zwraca tablice**/
bool load_bin(const char* nazwa);/**fukcja wczytuje plik binarny
                                              @param 1 nazwa pliku**/

#endif