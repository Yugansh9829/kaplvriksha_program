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

void push_int(struct digit *obj, int value){
    obj->value[++obj->top]=value;

    return;
}

void push_oper(struct operators *obj, char value){
    obj->operator[++obj->top]=value;

    return;
}

int pop_int(struct digit *obj){
    if(obj->top<0) return 1e7;
    
    return obj->value[obj->top--];
}

char pop_oper(struct operators *obj){
    if(obj->top==-1) return 'f';
    
    return obj->operator[obj->top--];
}

int precedence(char operator){
    if(operator=='+' || operator=='-')return 1;
    else if(operator=='*' || operator=='/')return 2;
    return 0;
}

int perform(int operand_1, int operand_2, char operator){
    switch(operator){
        case '+' : 
            return operand_1+operand_2;
            break;
        case '-' :
            return operand_1-operand_2;
            break;
        case '*':
            return operand_1*operand_2;
            break;
        case '/':
            if (operand_1 == 0) {
                return 1e7;
            }
            return operand_2 / operand_1;
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
                if(a == 1e7 || b== 1e7){
                    printf("\n******Please enter valid expression*******\n");
                    return 0;
                }
                char op = pop_oper(&oper);
                if(op=='f'){
                    printf("\n******Please enter valid expression*******\n");
                    return 0;
                }
                int ans = perform (a,b,op);
                if(ans == 1e7){
                    printf("\n*********Division by zero***********\n");
                    return 0;
                }
                push_int(&value, ans);
            }
            int val = 0;
            i++;
            while(str[i]==' ')i++;

            if(!(str[i]-'0'>=0 && str[i]-'0'<=9)){
                printf("\n******Please enter valid expression*******\n");
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
                if(a == 1e7 || b== 1e7){
                    printf("\n******Please enter valid expression*******\n");
                    return 0;
                }
                char op = pop_oper(&oper);
                if(op=='f'){
                    printf("\n******Please enter valid expression*******\n");
                    return 0;
                }
                int ans = perform(a,b,op);
                if(ans == 1e7){
                    printf("\n*********Division by zero***********\n");
                    return 0;
                }
                push_int(&value, ans);
            }
            push_oper(&oper, str[i]);
        }else{
            printf("\n******Please enter valid expression*******\n");
            return 0;
        }
    }

    while(oper.top!=-1 ){
        int a = pop_int(&value);
        int b = pop_int(&value);
        if(a == 1e7 || b== 1e7){
            printf("\n******Please enter valid expression*******\n");
            return 0;
        }
        char op = pop_oper(&oper);
        if(op=='f'){
            printf("\n******Please enter valid expression*******\n");
        }
        int ans = perform(a,b,op);
        if(ans == 1e7){
            printf("\n*********Division by zero***********\n");
            return 0;
        }
        push_int(&value, ans);
    }
    if(value.top>0){
        printf("\n******Please enter valid expression*******\n");
        return 0;
    }
    return pop_int(&value);
}

int main(void){

    char expression[Max_Size];
    printf("please Enter expression : ");
    fflush(stdin);
    scanf("%[^\n]s", expression);

    printf(" \n Result after calculation is : %d", solve(expression));
    
    return 0;
}