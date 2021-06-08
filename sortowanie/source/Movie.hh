#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

struct Movie {

    float ranking;     //  ranking filmu
    string nazwa;    //   nazwa/tytul filmu

   
    
    void pokaz();
    void laduj( string );

    int getRanking();

    void operator = ( Movie );
    bool operator > ( Movie );
    bool operator < ( Movie );

    bool operator == ( Movie );
    bool operator >= ( Movie );
    bool operator <= ( Movie );
};

int Movie::getRanking()
{
    return this->ranking;
}

void Movie::pokaz() {
    cout << "( " << this->nazwa << " | " << this->ranking << " )";
}

void Movie::laduj( string data ) {

    char test = data.back();
    float ranking = 0;

    if( test > 47 && test < 58) {   // znaki ASCI od 0 do 9 
        ranking = stof( data.substr( data.rfind( ',' ) +1, data.size() - 1 ) );
    }


    this->nazwa = data;
    this->ranking = ranking;
}


void Movie::operator = ( Movie data ) {
    
    this->nazwa = data.nazwa;
    this->ranking = data.ranking;
}



bool Movie::operator > ( Movie data ) {
     if( this->ranking > data.ranking )
      { return true; } 
      else { return false; } }
bool Movie::operator < ( Movie data ) {
     if( this->ranking < data.ranking )
      { return true; } 
      else { return false; } }
bool Movie::operator == ( Movie data ) { 
    if( this->ranking == data.ranking ) 
    { return true; }
     else { return false; } }
bool Movie::operator >= ( Movie data ) { 
    if( this->ranking >= data.ranking )
     { return true; } 
     else { return false; } }
bool Movie::operator <= ( Movie data ) {
     if( this->ranking <= data.ranking ) 
     { return true; }
      else { return false; } }



istream & operator >> ( istream & str, Movie & data ) {

    string tmp;
    getline( str, tmp );

    data.laduj( tmp );

    return str;
}

ostream & operator << ( ostream & str, Movie & data ) {
    data.pokaz();
    return str;
}