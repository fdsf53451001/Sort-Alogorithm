#include <iostream>
#include <cmath>
using namespace std;

void merge_sort(int *data, int start, int end);
void merge(int *data, int d1_start, int d1_end, int d2_start, int d2_end);
/*
int main(){
    int len;
    cin >> len;
    int *data = new int[len];
    for (int i = 0; i < len;i++){
        cin >> data[i];
    }

    merge_sort(data, 0,len-1);

    for (int i = 0; i < len;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
*/
void merge_sort(int* data,int start,int end){
    if(end-start>=1){
        merge_sort(data, start, start+((end-start)/2));
        merge_sort(data, start+((end-start)/2)+1, end);
        merge(data, start,start+((end-start)/2),start+((end-start)/2)+1, end);
    }
}

void merge(int* data,int d1_start,int d1_end,int d2_start,int d2_end){
    int *temp = new int[d2_end-d1_start+1];
    int count = 0;
    int start = d1_start;
    while((d1_start<=d1_end) && (d2_start<=d2_end)){
        if(data[d1_start]>data[d2_start]){
            temp[count] = data[d2_start];
            d2_start++;
            count++;
        }else if(data[d1_start]==data[d2_start]){
            temp[count] = data[d1_start];
            temp[count+1] = data[d2_start];
            d1_start++;
            d2_start++;
            count += 2;
        }else{ //d2>d1
            temp[count] = data[d1_start];
            d1_start++;
            count++;
        }
    }

    while(d2_start<=d2_end){
        temp[count] = data[d2_start];
        d2_start++;
        count++;
    }
    
    while(d1_start<=d1_end){
        temp[count] = data[d1_start];
        d1_start++;
        count++;
    }
    for (int i = 0; i < count;i++){
        data[start + i] = temp[i];
    }
}
