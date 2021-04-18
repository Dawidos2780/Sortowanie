#include "quicksort.hh"
#include "functions.hh"

#include <iostream>

void swap(int *l, int *r)
{
    int temp;

    temp = *l;
    *l = *r;
    *r = temp;

}

void sort_quick(int  rand_array[], int begining, int end)
{
    if(begining >= end)
        return;

    int pivot = rand_array[(begining + end)/2];
    int l = begining - 1, r = end + 1;

    while(1)
    {
        /* Szukam elementu większego od pivota po lewej stronie tablicy */
        while(pivot > rand_array[++l]);
        /* Szukam elementu mniejszego od pivota po prawej stronie tablicy */
        while(pivot < rand_array[--r]);
        /* Zamieniam ze sobą elementy, które stoją po niewłaściwej stronie pivota */
        if(l <= r)
            swap(&rand_array[l], &rand_array[r]);
        else
            break;
    }
 
    /* Wykonywanie quicksort (dzielenie na pomniejsze tablice) tak długo jak wskaźnik na 'prawą' stonę tablicy będzie większy od początku sortowanej tablicy */
    if(r > begining)
        sort_quick(rand_array, begining, r);
    /* Wykonywanie quicksort (dzielenie na pomniejsze tablice) tak długo jak wskaźnik na 'lewą' stonę tablicy nie będzie większy od końca sortowanej tablicy */
    if(l < end)
        sort_quick(rand_array, l, end);

    //display_array(rand_array, end - begining);
} // wykonanie funkcji quicksort

