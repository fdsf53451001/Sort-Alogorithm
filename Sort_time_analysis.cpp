#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "HeapSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort2.cpp"
#include "QuickSort.cpp"

#include "time_analysis_clock.cpp"

using namespace std;

void print_data(int* data,int start,int end);
int get_rand_int();

int main(){
    srand(time(NULL));
    int number_size,min_num,max_num;
    cout << "Input Number Size : " << endl;
    cin >> number_size;
    
    int *data = new int[number_size];
    int *data2 = new int[number_size+1];
    int *data3 = new int[number_size];
    int *data4 = new int[number_size];
    for (int i = 0; i < number_size;i++){
        data[i] = get_rand_int();
        data2[i+1] = data[i];
        data3[i] = data[i];
        data4[i] = data[i];
    }

    time_analysis_clock *t = new time_analysis_clock();
    t->start();
    merge_sort(data,number_size);
    double t1 = t->end();

    t->start();
    heap_sort(data2, number_size);
    double t2 = t->end();

    t->start();
    insertion_sort(data3, number_size);
    double t3 = t->end();

    t->start();
    quick_sort(data4, 0, number_size - 1);
    double t4 = t->end();

    print_data(data,0,number_size);
    print_data(data2,1,number_size+1);
    print_data(data3,0,number_size);
    print_data(data4,0,number_size);

    cout << t1 << endl;
    cout << t2 << endl;
    cout << t3 << endl;
    cout << t4 << endl;
}

void print_data(int* data,int start,int end){
    for (int i = start; i < end;i++){
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "-------------------------------------------------" << endl;
}

int get_rand_int(){
    int total_num = 0;
    for(int i=0;i<4;i++){
        total_num += rand()%10 * pow(10,i);
    }
    total_num += rand()%5 * pow(10,4);
    total_num += 1;
    return total_num;
}