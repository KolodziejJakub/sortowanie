#include <iostream>

using namespace std;

//sortowanie szybkie



template <typename T>
int zamiana( T *arr, int *args ) { 

    int left = args[0];
    int right = args[1];

    int i, j;

    i = left; //ustawienie licznika i na pierwszy element tablicy
    j = right; // ustawienie j na ostatni element tablicy

    T tmp = arr[left];

    do {

        while( arr[i] < tmp ) {
            i++;
        }

        while( arr[j] > tmp ) {
            j--;
        }

        if( i < j ) {
            
            swap( arr[i], arr[j] ); //zamiana liczb ktore sa po niewlasciwej stronie
            i++;
            j--;

        } else { //w tym wypadku nastepuje miniecie licznikow
            
            //  kończy pętlę
            return j;  //ustalenie pivota
          
        }

    } while( true );
}


template <typename T>
void quickSort2( T *arr, int *args ) {

    int left = args[0];
    int right = args[1];

    if( left < right ) {

        int m_args[] = { left, right };
        int mid = zamiana<T>( arr, m_args );
    
        int args_1[] = { left, mid };
        quickSort2<T>( arr, args_1 ); //rekurencyjne wywolanie funkcji, posortowanie mniejszych wartosci

        int args_2[] = { mid + 1, right };
        quickSort2<T>( arr, args_2 ); //rekurencyjne wywolanie funkcji, posortowanie większych wartosci
    }
}

