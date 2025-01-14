#include<stdio.h>

int cal_size(char str[]){
    char *ptr = str;
    int length = 0;
    while(*ptr!='\0'){
        ptr++;
        length++;
    }

    return length;
}

int is_contained(char str[], char str2[], int i, int j, int s2){

    int visited_str[26] = {0};

    for(int itr=i;itr<=j;itr++){
        visited_str[str[itr]-'A']+=1;
    }

    for(int itr=0;itr<s2;itr++){
        if(visited_str[str2[itr]-'A']==0){
            return 0;
        }else{
            visited_str[str2[itr]-'A']--;
        }
    }

    return 1;
}

void find_smallest_window(char str[], char str2[], int s1, int s2){
    int sp = -1;
    int ep = -1;
    int i=0;
    for(int j=s2-1;j<s1;j++){
            if(is_contained(str, str2, i, j, s2)){
                sp = i;
                ep = j;
                break;
            }
    }
    while(str[sp]!=str2[0])sp++;
    if(sp==-1){
        printf("not found any substring");
        return;
    }
    for(int itr = sp;itr<=ep;itr++){
        printf("%c", str[itr]);
    }
}

int main(){


    char str[100];
    scanf("%s", str);
    int size = cal_size(str);

    char str2[100];
    scanf("%s", str2);
    int size2 = cal_size(str2);

    // for(int i=0;i<size2;i++) visited_str2[str2[i]-'A']+=1;

    find_smallest_window(str, str2, size, size2);
}