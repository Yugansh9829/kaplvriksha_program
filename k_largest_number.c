#include<stdio.h>

void solve(int arr[], int size, int k){
    
    int visited[100000] = {0};

    for(int i=0;i<size;i++) visited[arr[i]]++;

    for(int i=100000;i>=0;i--){
        if(visited[i]>0){

            while(visited[i]!=0){
                
                if(k==0){
                    printf("%d", i);
                }
                k--;
                visited[i]--;
            }
            
        }
    }


}

int main(){
    int size;
    int k;
    scanf("%d", &size);

    scanf("%d", &k);

    int arr[size];

    for(int i=0;i<size;i++) scanf("%d", &arr[i]);

    solve(arr, size, k);
}