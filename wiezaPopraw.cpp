/* wieża Hanoi
Napisz program do obliczania ilości przełożeń krążków n-piętrowej wieży Hanoi 
korzystając ze wzoru:
• rekurencyjnego: 𝐻𝑛= {  0       dla n=0
                         2𝐻𝑛−1+1 dla n>0
• zwartego: 𝐻𝑛=2𝑛−1 */

# include <iostream>   //dołączenie biblioteki iostream - obsługa strumieni I/O (wejścia/wyjścia)
# include <cmath>     //dołączenie biblioteki zawierającej deklaracje funkcji matematycznych 

using namespace std;   //używanie przestrzeni nazw standart

void przesunWieze(int kr, int p1, int p2, int p3); //nagłówek f-cji obrazującej
double rekurencja (int n);   //nagłówek f-cji rekurencyjnej

int main()  // funkcja główna
{
  int krazek;              //deklarowanie zmiennej lokalnej krazek

  do 
   {
     cout << "Podaj ilość krążków wieży Hanoi: ";
     cin >> krazek;          //wczytanie ilości krążków
     
     if (krazek<=0)
       { 
        cout <<"Liczba krążków musi być >0." << endl; //wyświetli komunikat gdy użytkownik wpisze l.krązków<=0
       }
   } 
  while (krazek<=0);          //by użytkownik podał ilość krążków>0
      
      cout <<"Ilość ruchów do wykonania to: "<< (pow(2, krazek))-1 <<endl; // zwarty, podaje ilość
     
  cout<<"Ilość przełożeń "<< krazek <<" krążków wieży Hanoi metodą rekurencji wynosi: "<< rekurencja(krazek)<< endl;   // rekurencyjna metoda

  przesunWieze(krazek, 1, 2, 3);   //wywołanie f-ji obrazującej ruchy
  getchar(); 

return 0;
}

void przesunWieze(int kr, int p1, int p2, int p3)  // f-cja obrazuje jakie ruchy musimy wykonać
{
   if (kr >= 1) 
     {
      przesunWieze(kr - 1, p1, p3, p2);
      cout << "Przesuń krążek z palika: " << p1 << " na palik: " << p2 << endl;
      przesunWieze(kr - 1, p3, p2, p1);
     }
} 

double rekurencja (int n)  // f-cja metody rekurencyjnej
{
   if (n==0)
     return 0; 
       else return (2*rekurencja(n-1)+1); 
}



/* Zadanie wykonane poprawnie:) Plusy za zastosowanie funkcji i komenatrze wyjaśniające poszczególne kroki.

Co można by ulepszyć?
1. Wprowadzenie przez użytkownika wartości <0 powoduje błąd. Warto by zabezpieczyć program na taką sytuację.
Przykładowy output:

Podaj ilość krążków wieży Hanoi: -1
Ilość ruchów do wykonania to: -0.5
Segmentation fault (core dumped)

2. Jeśli użytkownik poda ilość krążków <=0 może warto by zastosować pętlę do while, aż wprowadzi poprawną wartość.

3. Zmienna krazek jest wykorzystywana jedynie w funkcji main, więc warto, aby była tam zdefiniowana jako zmienna lokalna. 
Zmienna globalna jest usuwana dopiero po zakończeiu programu. Funkcja double rekurencja i tam przyjmuje jako argument 
jakąś zmienną typu int. Ona mogłaby mieć inną nazwę niż krazek.

Podsumowując zadanie uznaję za zaliczone :) */