
#include <stdio.h>
#include "structs.h"

int experience(Worker w){
    return 2025 - w.year;
}

double salaryAfterTax(Worker w){
    return w.salary * 0.67;
}

int main(){
    Worker w={"Ivan","Dev",2020,1000};

    printf("Exp: %d\n",experience(w));
    printf("Salary: %.2f\n",salaryAfterTax(w));

    return 0;
}
