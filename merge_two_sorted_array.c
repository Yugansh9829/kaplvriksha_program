#include<stdio.h>

void merge(int arr[], int arr_[], int n, int m){
    int i=0;
    int j=0;

    for(int i=0;i<(m);i++){
        arr[(n-m)+i] = arr_[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i=0;i<(n);i++){
        printf("%d", arr[i]);
    }
}


int main(){
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);

    int arr[n];
    int arr_[m];

    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    for(int i=0;i<m;i++) scanf("%d", &arr_[i]);

    merge(arr, arr_, n, m);


    return 0;
}