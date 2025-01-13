#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int compress(char* chars, int charsSize) {
    char *ans = (char *)malloc((charsSize+1)*sizeof(char));
    int idx = 0;
    for(int i=0;i<charsSize;i++){
        int count = 1;
        ans[idx++] = chars[i];
        while(i+1<charsSize && chars[i]==chars[i+1]){
            count++;i++;
        }

        if(count>1){
            int s = idx;
            while(count>0){
                ans[idx++]=((count%10)+'0');
                count = count/10;
            }
            int restore_idx = idx-1;
            while(s<restore_idx){
                int temp = ans[s];
                ans[s] = ans[restore_idx];
                ans[restore_idx] = temp;
                restore_idx--;
                s++;
            }
        }
    }
    ans[idx]='\0';

    printf("%s", ans);

}

int main(){
    char *str = (char *)malloc(100*sizeof(char));
    scanf("%[^\n]s", str);
    int size = strlen(str);

    compress(str, size);
    
}