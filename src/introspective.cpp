#include "introspective.hh"
#include "quicksort.hh"
#include "functions.hh"

#include <cmath>

void sort_insertion(int rand_array[], int * begining, int * end)
{
    int l = begining - rand_array; // początek teblicy
    int r = end - rand_array; // koniec tablicy

    for(int i = l + 1; i <= r; i++)
    {
        int pointer = rand_array[i];
        int j = i - 1;
    /* Zamiana miejscami liczb tak długo, jak wartość poprzedzająca jest większa od następnej */
        while(j >= l && rand_array[j] > pointer)
        {
            rand_array[j+1] = rand_array[j];
            j--;
        }
        /*  */
        rand_array[j+1] = pointer;
    }
    return;

} // wykonanie funkcji sortowanie poprzez wstawianie

void heap(int rand_array[], int size, int pointer)
{
    int max = pointer; // wartość która znajdzie się na końcu aktualnej tablicy
    int l = 2 * (pointer) + 1; // przedostatni element tablicy
    int r = 2 * (pointer) + 2; // ostatni element tablicy
    /* Jeżeli wartość po lewej stronie jest większa od aktualnie największej */
    if(l < size && rand_array[l] > rand_array[max])
        max = l;
    /* Jeżeli wartość po prawej stronie jest większa od aktualnie największej */
    if(l < size && rand_array[r] > rand_array[max])
        max = r;
    /* Jeżeli zaszła zmiana największej wartości */
    if(max != pointer)
    {
        swap(&rand_array[pointer], &rand_array[max]);
    /* Wykonanie prówannia tak długo aż wartość największa znajdzie się na końcu (początku) tablicy */
        heap(rand_array, size, max);
    }
}

void sort_heap(int rand_array[], int size)
{

    if(size <= 0)
        return;

    for(int pointer = size/2 - 1; pointer >= 0; pointer--)
        heap(rand_array, size, pointer);

    /* Skrócenie tablicy o pozycje na której znajduje się już największa liczba */
    for(int pointer = size - 1; pointer >= 0; pointer--)
    {
        swap(&rand_array[0], &rand_array[pointer]);
    /* wykonanie heap ponownie, aż do momentu w którym wszystkie liczby znajdą się na właściwych pozycjach */
        heap(rand_array, pointer, 0);
    }
        
}

void sort_intro_choose(int rand_array[], int * begining, int * end, int depthLim)
{
    int size = end - begining;

    /* Dla bardzo małych tablic tzn. mniejszych od 16 najbardziej opłacalne jest sortowanie przez wstawianie */
   
     if(size < 16) // wykorzystane tylko przy testach funkcji
    {
        sort_insertion(rand_array, begining, end);
        return;
    }
    /* Dla tablic większych od 16 ale mniejszych od 2 * log(SIZE) najbardziej opłacalne jest sortowanie QUICKSORT */
    if(depthLim != 0)
    {
        
        sort_quick(rand_array, 0, size - 1);
        return;
    }
    /* Dla tablic większych od 2 * log(SIZE) najbardziej opłacalne jest sortowanie HEAP */
    else
    {

        sort_heap(rand_array, size);
        return;     
    }

} // wybór najbardziej opłacalnej obliczeniowo metody

void sort_Intro(int rand_array[], int * begining, int * end)
{
    int depthLim = 2 * log(end - begining);
    //std::cout << "to jest depth" << depthLim << std::endl;

    sort_intro_choose(rand_array, begining, end, depthLim);

    return;

} // wykonanie funkcji introsort