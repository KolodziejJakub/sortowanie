#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void merge( T *arr, int l, int m, int r ) {   

    T * help = new T [r - l + 1];
    int i, j, k;

    i = l;
    j = m + 1;
    k = 0;

    /*   *   *   *   *   *   *   *   *   *   */

    while( i <= m && j <= r ) {

        if( arr[j] < arr[i] ) {
            
            help[k] = arr[j];
            j++;

        } else {

            help[k] = arr[i];
            i++;
        }

        k++;
    }

    if( i <= m ) {
        while( i <= m ) {

            help[k] = arr[i];
            i++;
            k++;
        }

    } else {
        while( j <= r ) {

            help[k] = arr[j];
            j++;
            k++;
        }
    }

    /*   *   *   *   *   *   *   *   *   *   */

    //  final rewrite
    for( i = 0; i <= r - l; i++ ) {
        arr[ l + i ] = help[i]; 
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void mergeSort( T *arr, int *args ) {

    int l = args[0];
    int r = args[1];

    /*   *   *   *   *   *   *   *   *   *   */

    if( l != r ) {

        int m  = ( l + r ) / 2;

        int args_1[] = { l, m };
        int args_2[] = { m + 1, r };

        mergeSort<T>( arr, args_1 );
        mergeSort<T>( arr, args_2 );

        merge<T>( arr, l, m, r );
    }
}