#include<stdio.h>
#include<stdlib.h>

//we can solve it using thte concept of binary exponentiation.
//implementing divide and conquer approach to get our result and using multiplication property of mudular with recursion.
int solve(int base, int power, int M){
    if(power==0) return 1;

    int sol = (solve(base, power/2, M)%M);

    if(power%2==0){
        return (sol * sol)%M;
    }
    return (((sol * sol)%M)*base)%M;

}

int main(){

    int base,power,mod_value;
    scanf("%d%d%d", &base, &power, &mod_value);

    printf("answer is : %d", solve(base, power, mod_value));

    return 0;
}