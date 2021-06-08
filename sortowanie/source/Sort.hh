#include <algorithm>
#include <ctime>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>


using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename T>
class Sort {

    private:

        unsigned int rozmiar_bazy;
        unsigned int rozmiar_set;

        T **set_danych;

        vector<pair<string, float>> wyjscie;  //  wektor preznaczony do zbierania danych

    /*   *   *   *   *   *   *   *   *   *   */

    public:
        
        Sort( unsigned int rozmiar_bazy, unsigned int rozmiar_set );
        ~Sort();

        int wez_rozmiar_bazy() {return this->rozmiar_bazy;}
        int wez_rozmiar_set() {return this->rozmiar_set;}

        bool czy_jest_mozliwe( unsigned int index );

        void wez_z_pliku( string fileName );
        void dla_kazdego( function<void( T *, int * )> callback, int *args, string name );
        void wyswietl( bool printAll );
        void daj_dane( string name, long unsigned int time, bool czy_jest );
        void odwrotnosc();
        float srednia();
        float mediana();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename T>
Sort<T>::Sort( unsigned int rozmiar_bazy, unsigned int rozmiar_set ) {
    
    this->rozmiar_bazy = rozmiar_bazy;
    this->rozmiar_set = rozmiar_set;

    this->set_danych = new T *[rozmiar_set];

    for( unsigned int i = 0; i < rozmiar_set; i++ ) {
        this->set_danych[i] = new T [rozmiar_bazy];
    }
}

template<typename T>
Sort<T>::~Sort() {

    for( unsigned int i = 0; i < rozmiar_set; i++ ) {
        delete [] this->set_danych[i];
    }

    delete [] this->set_danych;
}



template<typename T>
bool Sort<T>::czy_jest_mozliwe( unsigned int index ) {

    for( unsigned int i = 1; i < this->rozmiar_bazy; i++ ) {
        if( this->set_danych[index][i - 1] > this->set_danych[index][i] ) { return false; }
    }

    return true;
}


template<typename T>
void Sort<T>::wez_z_pliku( string fileName ) {

    for( unsigned int i = 0; i < this->rozmiar_set; i++ ) {

        fstream file( fileName );

        for( unsigned int j = 0; j < this->rozmiar_bazy; j++ ) {
            file >> this->set_danych[i][j];
        }

        file.close();
    }
}

template<typename T>
void Sort<T>::dla_kazdego( function<void( T *, int * )> callback, int *args, string name ) {

    bool czy_jest = true;
    clock_t start, stop;
    
    start = clock();

    for( unsigned int i = 0; i < this->rozmiar_set; i++ ) {
        callback( this->set_danych[i], args );
    }

    stop = clock();

    
    for( unsigned int i = 0; i < this->rozmiar_set; i++ ) {
        czy_jest = this->czy_jest_mozliwe(i);
        if(!czy_jest) {break;}
    }

    long unsigned int time = stop - start;
    this->daj_dane( name, time, czy_jest );
}

template<typename T>
void Sort<T>::wyswietl( bool printAll) {

    if( printAll ) {

        for( unsigned int i = 0; i < this->rozmiar_set; i++ ) {
            for( unsigned int j = 0; j < this->rozmiar_bazy; j++ ) {
                cout << this->set_danych[i][j] << ((j+1)%1==0?"\n":" ");
            }
            cout << endl << endl;
        }
    }

   // cout << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << endl << endl;

    for( unsigned int i = 0; i < this->wyjscie.size(); i++ ) {
        cout << this->wyjscie[i].first << this->wyjscie[i].second/CLOCKS_PER_SEC << " s"<< endl;
    }



 
}

template<typename T>
void Sort<T>::daj_dane( string name, long unsigned int time, bool czy_jest ) {

    string save = name + (czy_jest ? " - DA SIĘ - " : " - NIE DA SIĘ - ");
    this->wyjscie.push_back( make_pair( save, time ));
}

template<typename T>
void Sort<T>::odwrotnosc() {

    for( unsigned int i = 0; i < this->rozmiar_set; i++ ) {
        for( unsigned int j = 0; j < this->rozmiar_bazy; j++ ) {
            this->set_danych[i][j] = this->rozmiar_bazy - j - 1;
        }
    }
}

template<typename T>
float Sort<T>::srednia() {
    float sr=0;
    for( unsigned int i = 0; i < this->rozmiar_set; i++ ) {
        for( unsigned int j = 0; j < this->rozmiar_bazy; j++ ) {
            T tmp=this->set_danych[i][j] ;
            sr=sr+tmp.ranking;
        }
    }
    float rozm=this->rozmiar_bazy;
    float r= sr/rozm;
    return r;
}


template<typename T>
float Sort<T>::mediana() {
    float zn=0;
    float znpl=0;
    int srodek=this->rozmiar_bazy/2;
    int j=srodek+1;
    for( unsigned int i = 0; i < this->rozmiar_set; i++ ) {
            T tmp=this->set_danych[i][srodek] ;
            zn=zn+tmp.ranking;
            T tm=this->set_danych[i][j] ;
            znpl=znpl+tmp.ranking;
        }
    
    float r= (zn+znpl)/2;
    return r;
}