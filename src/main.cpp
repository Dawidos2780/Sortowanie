/* Dawid Szymczyna 252920 14.04.2021 Projekt 1 "Sortowanie" */
/* Program wykonuje sortowanie tablic, przy użyciu 3 sposobów (quicksort, scalanie oraz introspective). Możliwe jest wywołanie tych sortowań osobno w celu
wykonania testu poprawności ich działania, ale program napisany został z myślą o przeprowadzeniu testu efektywności. Wykonuje się testy dla każdego z sortowan
osobno, a dane uzyskane w ten sposób znajdują sie w plikach (test_scal.txt, test_intorspecitve.txt, test_quicksort.txt). Uzyskane w ten sposób dane informują
o wielkości tablicy, czasie wykonywania sortowania oraz sposobie posortowania tablicy (-1 oznacza tablice posortowaną odwrotnie). */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <math.h>
 
#include "scalanie.hh"
#include "quicksort.hh"
#include "introspective.hh"
#include "functions.hh"
#include "test.hh"

using namespace std;

/* Nalezy zdefiniowac sposób sortowania
 * r - oznacza scalanie
 * l - oznacza quicksort
 * s - oznacza introspective
 */

int main()
{
   
    char type;
    cout << "podaj typ" << endl;
    cin >> type;

    switch(type)
    {
        case 'r':
        array_sort_test_scal(type);
        break;

        case 'l':
        array_sort_test_quick(type);
        break;

        case 's':
        array_sort_test_introspective(type);
        break;

        case 'e':
        return 0;
    }

    /* Testy poprawnego działania */

    /*int size = 500;
    int begining = 0;

    int rand_array[size];

    generate_array(rand_array, size, begining);

    display_array(rand_array, size);

    sort_insertion(rand_array, rand_array, rand_array + size - 1);
    //sort_quick(rand_array, begining, size - 1);

    cout << "Posortowana " << endl;

    display_array(rand_array, size);*/
/*
    //generate_array(rand_array, size, 2, begining);

    //display_array(rand_array, size);

    cout << "Posortowana tablica:" << endl;

    //sort_merge(rand_array, 0, size-1);
    
    //sort_insertion(rand_array, rand_array, rand_array + size - 1);

    //sort_Intro(rand_array, rand_array, rand_array + size);

     //display_array(rand_array, size);*/

    return 0;
}
