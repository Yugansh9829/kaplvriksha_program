#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Size 100
//add precedence wala loop in str[i]=="-" condition
struct digit{
    int value[Max_Size];
    int top;
};

struct operators{
    char operator[Max_Size];
    int top;
};

//push value in stack
void push_int(struct digit *obj, int val){
    obj->value[++obj->top]=val;
    printf("value pushed is : %d\n", obj->value[obj->top]);
}
void push_oper(struct operators *obj, char val){
    obj->operator[++obj->top]=val;
    printf("value pushed is : %c\n", obj->operator[obj->top]);
}

//pop value from stack(value at top)
int pop_int(struct digit *obj){
    if(obj->top<0){
        printf("\n*****Please enter correct expression*****\n\n"); 
        exit(EXIT_FAILURE);
        return 0;
    }
    printf("value poped is : %d\n", obj->value[obj->top]);
    return obj->value[obj->top--];
}
char pop_oper(struct operators *obj){
    if(obj->top==-1){
        printf("\n*****Please enter correct expression*****\n\n");
        exit(EXIT_FAILURE);
        return 0;
    }
    printf("value poped is : %c\n", obj->operator[obj->top]);
    return obj->operator[obj->top--];
}

//describing the precedence of operators
int precedence(char oper){
    if(oper=='+' || oper=='-')return 1;
    else if(oper=='*' || oper=='/')return 2;
    return 0;
}


//operation performing function
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


//solve function
int solve(char str[]){
    struct digit value;
    struct operators oper;
    value.top = -1;
    oper.top = -1;

    for(int i=0;i<strlen(str);i++){
        if(str[i]==' ')continue;

        else if(str[i]-'0'>=0 && str[i]-'0'<=9){
            //It is digit
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
                //first operate that previous operator
                int a = pop_int(&value);
                int b = pop_int(&value);
                char op = pop_oper(&oper);
                push_int(&value, perform(a,b,op));
            }
            //now we push the next value with -ve sign in stack.
            int val = 0;
            i++;
            while(str[i]==' ')i++;
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
                //first operate that previous operator
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

    //now we process all remaining operators with remaining values.
    while(oper.top!=-1){
        int a = pop_int(&value);
        int b = pop_int(&value);
        char op = pop_oper(&oper);
        push_int(&value, perform(a,b,op));
    }
    //returning the last value remaining.
    return pop_int(&value);
}

int main(void){

    char expression[Max_Size];
    printf("please Enter expression : ");
    fflush(stdin);
    gets(expression);

    printf("Result after calculation is : %d", solve(expression));

    return 0;
}