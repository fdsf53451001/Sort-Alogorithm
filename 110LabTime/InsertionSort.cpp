/*
#include <iostream>
using namespace std;
*/

void insertion_sort(int* data,int len);
void insert(int *data, int temp, int last);
/*
int main(){    
    int len;
    cin >> len;
    int *data = new int[len+1];
    for (int i = 0; i < len;i++){
        cin >> data[i];
    }
    insertion_sort(data,len);
    for (int i = 0; i < len;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
*/
void insertion_sort(int* data,int len){
    for (int i = 1; i < len; i++){
        insert(data, data[i], i - 1);
    }
}

void insert(int* data,int temp,int last){
    int i = last;
    while(i>=0 && data[i]>temp){
        data[i + 1] = data[i];
        i--;
    }    
    data[i + 1] = temp;
}
