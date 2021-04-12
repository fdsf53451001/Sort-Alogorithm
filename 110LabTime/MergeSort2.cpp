
#include <iostream>
using namespace std;

void merge_sort(int *data, int len);
void merge_pass(int *from, int *dest, int len, int jump);
void merge(int *data, int *temp, int d1_start, int d1_end, int d2_start, int d2_end);
void copy_data(int* data,int* temp,int len);
/*
int main(){
    int len;
    cin >> len;
    int *data = new int[len];
    for (int i = 0; i < len;i++){
        cin >> data[i];
    }

    merge_sort(data, len);

    for (int i = 0; i < len;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
*/
void merge_sort(int* data,int len){
    int *temp = new int[len];
    for (int i = 0; i < len;i++){
        temp[i] = data[i];
    }
    for (int i = 1; i < len; i*=2){ //divide i items into a group
        merge_pass(data, temp, len, i);
        i *= 2;
        if(i>len){
            copy_data(data,temp,len);
        }
        merge_pass(temp, data, len, i);
    }
}

void merge_pass(int *from, int*dest ,int len,int jump){
    for (int i = 0; i+jump<len; i+=2*jump){
        int d2_end = i + 2 * jump - 1;
        if(d2_end>len-1){
            d2_end = len - 1;
        }
        merge(from, dest, i, i + jump - 1, i + jump, d2_end);
    }
}

void merge(int* data,int* temp,int d1_start,int d1_end,int d2_start,int d2_end){
    int count = d1_start;
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
}

void copy_data(int* data,int* temp,int len){
    for(int i=0;i<len;i++){
        data[i] = temp[i];
    }
}