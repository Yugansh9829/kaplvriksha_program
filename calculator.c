#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Size 100

struct digit{
    int value[Max_Size];
    int top;
};

struct operators{
    char operator[Max_Size];
    int top;
};

void push_int(struct digit *obj, int val){
    obj->value[++obj->top]=val;
}

void push_oper(struct operators *obj, char val){
    obj->operator[++obj->top]=val;
}

int pop_int(struct digit *obj){
    if(obj->top<0){
        printf("\n*****Please enter correct expression*****\n\n"); 
        exit(EXIT_FAILURE);
        return 0;
    }
    return obj->value[obj->top--];
}

char pop_oper(struct operators *obj){
    if(obj->top==-1){
        printf("\n*****Please enter correct expression*****\n\n");
        exit(EXIT_FAILURE);
        return 0;
    }
    return obj->operator[obj->top--];
}

int precedence(char oper){
    if(oper=='+' || oper=='-')return 1;
    else if(oper=='*' || oper=='/')return 2;
    return 0;
}

int perform(int a, int b, char op){
    switch(op){
        case '+' : 
            return a+b;
            break;
        case '-' :
            return a-b;
            break;
        case '*':
            return  a*b;
            break;
        case '/':
            if (a == 0) {
                printf("Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            return b / a;
            break;
        default : 
            return 0;
    }
}

int solve(char str[]){
    struct digit value;
    struct operators oper;
    value.top = -1;
    oper.top = -1;

    for(int i=0;i<strlen(str);i++){
        if(str[i]==' ')continue;

        else if(str[i]-'0'>=0 && str[i]-'0'<=9){
            int val = 0;
            while(i<strlen(str) && (str[i]-'0'>=0 && str[i]-'0'<=9)){
                val = (val*10) + (str[i]-'0');
                i++;
            }
            i--;
            push_int(&value,val);

        }
        else if(str[i]=='-'){
            if(oper.top!=-1 && (precedence(oper.operator[oper.top]) >= precedence(str[i]))){
                int a = pop_int(&value);
                int b = pop_int(&value);
                char op = pop_oper(&oper);
                push_int(&value, perform(a,b,op));
            }
            int val = 0;
            i++;
            while(str[i]==' ')i++;

            if(!(str[i]-'0'>=0 && str[i]-'0'<=9)){
                printf("*****Please Enter Valid Expression*****");
                exit(EXIT_FAILURE);
            }
            while(i<strlen(str) && (str[i]-'0'>=0 && str[i]-'0'<=9)){
                val = (val*10) + (str[i]-'0');
                i++;
            }
            i--;
            val = (-1)*val;
            push_int(&value,val);
            push_oper(&oper,'+');
        }
        else if(str[i]=='+' || str[i]=='*' || str[i]=='/'){
            if(oper.top!=-1 && (precedence(oper.operator[oper.top]) >= precedence(str[i]))){
                int a = pop_int(&value);
                int b = pop_int(&value);
                char op = pop_oper(&oper);
                push_int(&value, perform(a,b,op));
            }
            push_oper(&oper, str[i]);
        }else{
            printf("\n*****Please enter correct expression*****\n");
            exit(EXIT_FAILURE);
            return 0;
        }
    }

    while(oper.top!=-1 ){
        int a = pop_int(&value);
        int b = pop_int(&value);
        char op = pop_oper(&oper);
        push_int(&value, perform(a,b,op));
    }
    if(value.top>0){
        printf("\n******Please enter valid string as input*******");
        exit(EXIT_FAILURE);
    }
    return pop_int(&value);
}

int main(void){

    char expression[Max_Size];
    printf("please Enter expression : ");
    fflush(stdin);
    scanf("%[^\n]s", expression);

    printf("Result after calculation is : %d", solve(expression));
    
    return 0;
}