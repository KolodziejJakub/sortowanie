#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void fastSort( T *arr, int *args ) {

    int l = args[0];
    int m = l / 2;

    while( m > 0 ) {

        int j = 0;

        for( int i = m; i < l; i++ ) {

            T tmp = arr[i];

            for( j = i; (j >= m) && (arr[j - m] > tmp); j -= m) {
                arr[j] = arr[j - m];
            }

            arr[j] = tmp;
        }

        m = m / 2;
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void bucketSort( T *arr, int *args ) {

    unsigned int lenght = args[0];
    unsigned int amount = args[1];

    float MAX_RATE = 1000000.0;
    string SET_HALT = "HALT";

    //  buckets from 0 to 9, offset by 1
    /*
        [0, 1], [1, 2], [2, 3], [3, 4], [4, 5], [5, 6], [6, 7], [7, 8], [8, 9], [9, 10]
    */

    //  dynamic array
    T **buckets = new T * [amount];
    for( unsigned int i = 0; i < amount; i++ ) {
        buckets[i] = new T [lenght];
    }

    //  entry fill
    for( unsigned int i = 0; i < amount; i++ ) {
        for( unsigned int j = 0; j < lenght; j++ ) {
            buckets[i][j].nazwa = SET_HALT;
            buckets[i][j].ranking = MAX_RATE;
        }
    }

    //  buckets fill
    for( unsigned int i = 0; i < amount; i++ ) {

        //  counter
        int counter = 0;

        //  comparator
        float min = (float) i;
        float max = min + 1;


        for( unsigned int j = 0; j < lenght; j++ ) {

            //  sets value to proper bucket
            if( arr[j].ranking >= min && arr[j].ranking < max ) {
                buckets[i][counter++] = arr[j];
            }
        }
    }

    //  final meter
    int meter = 0;
    
    //  GRAND TEST
    for( unsigned int i = 0; i < amount; i++ ) {

        int counter = 0;

        //  end of the bucket
        while( buckets[i][counter].ranking < MAX_RATE || buckets[i][counter].nazwa != SET_HALT ) {
            counter++;
        }

        int args_sort[] = { counter };
        fastSort<T>( buckets[i], args_sort );

        for( unsigned int j = 0; j < lenght; j++ ) {
            
            //  breaks loop
            if( buckets[i][j].ranking == MAX_RATE || buckets[i][j].nazwa == SET_HALT ) {
                break;
            }

            //  proper vaule on proper place
            arr[meter++] = buckets[i][j];
        }
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */