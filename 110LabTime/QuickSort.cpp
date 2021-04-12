/*
#include <iostream>
using namespace std;
*/

void quick_sort(int *data, int start, int end);
/*
int main(){
    int len;
    cin >> len;
    int *data = new int[len+1];
    for (int i = 0; i < len;i++){
        cin >> data[i];
    }
    data[len] = 999999999;

    quick_sort(data,0,len-1);

    for (int i = 0; i < len;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
*/
void quick_sort(int *data,int start,int end){
    if(end-start<=0){
        return;
    }

    int pivot = data[start];
    int i = start+1;
    int j = end;
    while(true){
        while(data[j]>pivot){
            j--;
        }
        while(data[i]<=pivot){
            i++;
        }

        if(i>=j){
            break;
        }
        
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    int temp = data[start];
    data[start] = data[j];
    data[j] = temp;

    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}
