#include <algorithm>
#include <ctime>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <utility>
#include <sstream> 
#include <string>
#include <vector>

#include "source/Sort.hh"
#include "source/Movie.hh"

#include "sort/bucket.hh"
#include "sort/quick.hh"
#include "sort/merge.hh"


using namespace std;



int main() {

    //main spelniajacy funkcje drivera
    string nazwa_pliku ="milion.csv";
    int set =1;
 
    int rozmiar = 0;
    string linia;

    fstream rozmiar_pliku( nazwa_pliku );
    while( getline( rozmiar_pliku, linia ) ) {
         ++rozmiar;
     };
    rozmiar_pliku.close();
  

    Sort<Movie> sortuj_plik( rozmiar, set );

    cout<<"Sortowanie dla 10 wartosci"<<endl;



    
    //  bucket sort test
    sortuj_plik.wez_z_pliku(nazwa_pliku);
    int args_bucket[] = {sortuj_plik.wez_rozmiar_bazy(),11};
    sortuj_plik.dla_kazdego(  bucketSort<Movie>, args_bucket, "bucket sort");
    
    //  quick sort test
    sortuj_plik.wez_z_pliku( nazwa_pliku );
    int args_quick[] = { 0, sortuj_plik.wez_rozmiar_bazy() - 1 };
    sortuj_plik.dla_kazdego(  quickSort2<Movie>, args_quick, "quick sort" );


    //  merge sort test
    sortuj_plik.wez_z_pliku( nazwa_pliku );
    int args_merge[] = { 0, sortuj_plik.wez_rozmiar_bazy()-1 };
    sortuj_plik.dla_kazdego(  mergeSort<Movie>, args_merge, "merge sort" );
     

    cout<<"Srednia wynikow: "<<endl; 
     cout<<sortuj_plik.srednia();
    cout<<endl;
    cout<<"Mediana wynikow: "<<endl;

    cout<<sortuj_plik.mediana();
    cout<<endl;
    sortuj_plik.wyswietl(false);
    
}
