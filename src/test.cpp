#include "test.hh"

#include "scalanie.hh"
#include "quicksort.hh"
#include "introspective.hh"
#include "functions.hh"

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int size_tab[] = {10000, 50000, 100000, 500000, 1000000};
//int size_tab[] = {10, 50, 100, 500, 1000};

void array_sort_test_scal(char type)
{

        ofstream file;
        file.open("test_scal.txt");
    for(int i = 0; i < 5; i++)
        {
            file << size_tab[i] << " " << endl;

            double beg_tab[] = {0, 0.25 * size_tab[i], 0.50 * size_tab[i], 0.75 * size_tab[i], 0.95 * size_tab[i], 0.99 * size_tab[i], 0.997 * size_tab[i], -1};

            for(int j = 0; j < 8; j++)
            {
                file << beg_tab[j] << " ";

                auto start = high_resolution_clock::now();

                for(int k = 0; k < 100; k++)
                {
                     int rand_array[size_tab[i]];

                    generate_array(rand_array, size_tab[i], beg_tab[j]);
                //display_array(rand_array, size_tab[i]);
                    //std::cout << "posortowana" << std::endl;
                    sort_scal(rand_array, 0, size_tab[i] - 1); 
                //display_array(rand_array, size_tab[i]);
                }
                
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "czas" << duration.count() << endl;
                file << duration.count() << " ";
                file << endl;
            }
             file << endl;
        }
    file.close();
    cout << "Zakonczono wpisywanie do pliku" << endl;
}

void array_sort_test_quick(char type)
{
    ofstream file;
    file.open("test_quick.txt");
    
    for(int i = 0; i < 5; i++)
        {
            file << size_tab[i] << " " << endl;

            double beg_tab[] = {0, 0.25 * size_tab[i], 0.50 * size_tab[i], 0.75 * size_tab[i], 0.95 * size_tab[i], 0.99 * size_tab[i], 0.997 * size_tab[i], -1};

            for(int j = 0; j < 8; j++)
            {
                file << beg_tab[j] << " ";
                
                auto start = high_resolution_clock::now();
                for(int k = 0; k < 100; k++)
                {
                    int rand_array[size_tab[i]];

                    generate_array(rand_array, size_tab[i], beg_tab[j]);
                //display_array(rand_array, size_tab[i]);

                //std::cout << "beg" << size_tab[i] - 1 << std::endl;
                    
                    sort_quick(rand_array, 0, size_tab[i] - 1);
                //display_array(rand_array, size_tab[i]);
                
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                    std::cout << "Time" << duration.count() << std::endl;

                file << duration.count() << " ";
                file << endl;
            }
            file << endl;
        }
    file.close();
    cout << "Zakonczono wpisywanie do pliku" << endl;
}


void array_sort_test_introspective(char type)
{
    ofstream file;
    file.open("test_introspective.txt");
    
    for(int i = 0; i < 5; i++)
        {
            file << size_tab[i] << " " << endl;

            double beg_tab[] = {0, 0.25 * size_tab[i], 0.50 * size_tab[i], 0.75 * size_tab[i], 0.95 * size_tab[i], 0.99 * size_tab[i], 0.997 * size_tab[i], -1};

            for(int j = 0; j < 8; j++)
            {
                file << beg_tab[j] << " ";
                
                auto start = high_resolution_clock::now();
                for(int k = 0; k < 100; k++)
                {
                    int rand_array[size_tab[i]];

                    generate_array(rand_array, size_tab[i], beg_tab[j]);
                //display_array(rand_array, size_tab[i]);

                //std::cout << "beg" << size_tab[i] - 1 << std::endl;
                    
                   sort_Intro(rand_array, rand_array, rand_array + size_tab[i]);
                //display_array(rand_array, size_tab[i]);
                
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                    std::cout << "Time" << duration.count() << std::endl;

                file << duration.count() << " ";
                file << endl;
            }
            file << endl;
        }
    file.close();
    cout << "Zakonczono wpisywanie do pliku" << endl;
}