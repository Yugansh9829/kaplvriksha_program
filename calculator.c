#include<stdio.h>
#include <stdlib.h>
#include<string.h>
//we will implement the solution using stack approach 


struct values
{
    int val[100];
    int top;
};

struct operators
{
    char operator[100];
    int top;
};

//for pushing numeric values in values stack.
void push_int(struct values *obj, int val){
    //we increase it first as we initialize top as -1 in our main function.
    obj->val[++obj->top]=val;
    return;
}

//for pushing operators in operators stack.
void push_value(struct operators *obj, char operator){
    obj->operator[++obj->top]=operator;
    return;
}

//for removing numeric values from top of stack.
int pop_int(struct values *obj){
    if(obj->top>=0){
        //return that value from val array which is at index top.
        return obj->val[obj->top--];
    }
    return 0;
}

//for removing operator from top of stack.
char pop_value(struct operators *obj){
    if(obj->top>=0){
        return obj->operator[obj->top--];
    }
    return 0;
}

//now we will set the precedence of operators
int precedence(char str){
    if(str=='*' || str=='/') return 2;
    else if(str=='+' || str=='-') return 1;
    return 0;
}


//function to perform operation based on sign.
int perform(int a, int b, char op){
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            return b / a;
        default: return 0;
    }
}


int calculate(char str[]){

    //declaring stacks of values and opeators
    struct values val;
    struct operators oper;

    val.top = oper.top = -1;

    for(int i=0;i<strlen(str);i++){
        if(str[i]==' ') continue;

        else if(str[i]-'0'>=0 && str[i]-'0'<=9){
            //if character is numeric value(isdigit is inbuild function)
            int value = 0;
            while(i<strlen(str) && str[i]-'0'>=0 && str[i]-'0'<=9){
                value = (value*10) + (str[i]-'0');
                i++;
            }
            //after coming out we need to adjust position to back as we increase index in for loop.
            i--;
            push_int(&val, value); 
        }
        else if(str[i]=='-'){
            //if we encounter -ve value than we first take out next element and push the negative value in value stack and + operand in operator stack to maintain consistency.
                int value = 0;
                i++;
                while(i<strlen(str) && str[i]==' '){
                    i++;
                }
                while(i<strlen(str) && str[i]-'0'>=0 && str[i]-'0'<=9){
                    value = (value*10) + (str[i]-'0');
                    i++;
                }
                //after coming out we need to adjust position to back as we increase index in for loop.
                i--;
                value = value*(-1);
                push_int(&val,value);
                push_value(&oper,'+');
        }
        else if(str[i]=='+' || str[i]=='*' || str[i]=='/'){
         
            if(oper.top!=-1 && precedence(oper.operator[oper.top]) >= precedence(str[i])){
                //if precedence of previous character is more than current character than solve that first.
    
                //now we take previous two values
                int prev_first = pop_int(&val);
                int prev_second = pop_int(&val);
                char operate = pop_value(&oper);
                push_int(&val , perform(prev_first, prev_second, operate));
            }
            //now push current operand into operand stack.
            push_value(&oper, str[i]);
            
        }
        else {
            //if we encounter any other character than show error.
            printf("Error: Invalid expression.\n");
            exit(EXIT_FAILURE);
        }
    }

    //apply remaining operators on numbers.
        while(oper.top != -1){
            int a = pop_int(&val);
            int b = pop_int(&val);
            char op = pop_value(&oper);

            push_int(&val, perform(a, b, op));
        }

        // printf("result is : %d", val.val[0]);
        //result
        return (val.val[val.top]);
}

int main(){

    char str[100];
    printf("please enter the string here : ");
    //take input string
    gets(str);
    printf("result after calculation is : %d", calculate(str));

    return 0;
}
