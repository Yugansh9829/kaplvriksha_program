#include<stdio.h>
#include<stdlib.h>

//we can solve it using thte concept of binary exponentiation.
//implementing divide and conquer approach to get our result and using multiplication property of mudular with recursion.

int Modular_Exponentiation(int base, int power, int mod_value){
    if(power==0) return 1;

    int sol = (Modular_Exponentiation(base, power/2, mod_value)%mod_value);

    if(power%2==0){
        return (sol * sol)%mod_value;
    }
    return (((sol * sol)%mod_value)*base)%mod_value;

}

int main(){

    int base,power,mod_value;
    printf("Please enter the base : ");
    scanf("%d", &base);

    printf("Please enter the power : ");
    scanf("%d", &power);
    
    printf("Please enter the modular value : ");
    scanf("%d", &mod_value);

    printf("answer is : %d\n", Modular_Exponentiation(base, power, mod_value));

    return 0;

}
