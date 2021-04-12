/*
#include <iostream>
using namespace std;
*/
void heap_sort(int* data,int len);
void adjust(int *data, int r, int n);
/*
int main(){
    int len;
    cin >> len;
    int *data = new int[len+1];
    for (int i = 1; i < len+1;i++){
        cin >> data[i];
    }
    heap_sort(data, len);
    for (int i = 1; i < len+1;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
*/
void heap_sort(int* data,int n){
    // build up a max-heap tree
    for (int i = n / 2;i >= 1;i--){
        adjust(data, i, n);
    }
    // each max element will be moved to last position
    for (int i = n; i > 1; i--){
        int temp = data[1];
        data[1] = data[i];
        data[i] = temp;
        adjust(data, 1, i - 1);
    }
}

void adjust(int*data,int r,int n){
    int temp = data[r];
    int i;
    for (i = 2*r; i <= n;i*=2){
        if(i<n && data[i+1]>data[i]){
            // calculate which leaf is bigger
            i++;
        }
        if(temp>data[i]){
            // if leaf is less than temp, than break
            break;
        }
        data[i / 2] = data[i];
    }
    data[i / 2] = temp;
}