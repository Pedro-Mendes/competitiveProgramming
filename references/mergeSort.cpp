#include<bits/stdc++>
using namespace std;

void merge(int input[], int start, int mid, int end) {
    
}

void mergeSort(int input[], int start, int end) {
    if(start < end) {
        int mid = end - (end-start)/2;
        mergeSort(input, start, mid);
        mergeSort(input, mid+1, end);
        merge(input, start, mid, end);
    }
}



int main() {
    int input[] = {12,11,13,5,6,7};
    int inputSize = sizeof(input)/sizeof(input[0]);


    return 0;
}