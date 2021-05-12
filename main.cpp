#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

string imie, nazwisko;
int nr_tel;

int main() {
  cout << "Podaj imie: " << endl; 
  cin >> imie;
  cout << "Podaj nazwisko: " << endl; 
  cin >> nazwisko;
  cout << "Podaj nr telefony: " << endl; 
  cin >> nr_tel;
  
  fstream plik;
  plik.open("wizytowka.txt",ios::out | ios::app);
  
  plik << imie << endl;
  plik << nazwisko << endl;
  plik << nr_tel << endl;

  plik.close();

  plik.open("wizytowka.txt", ios::in);

  if(plik.good()==false)
  {
    cout << "Plik nie istnieje?";
    exit(0);
  }

  string linia;
  int nr_linii = 1;

  while(getline(plik,linia))
  {
    switch(nr_linii)
    {
      case 1: imie = linia; break;
      case 2: nazwisko = linia; break;
      case 3: nr_tel=atoi(linia.c_str()); break;
    }

    nr_linii = nr_linii + 1;
  }
  cout << imie << endl;
  cout << nazwisko << endl;
  cout << nr_tel << endl;

  return 0;
}