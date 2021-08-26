#include <stdio.h>
#include <stdbool.h>
#include <math.h>
             /*
            author: Ricki Barragan
            description: User will provide the following: 
                            -	Principal (original sum of money borrowed in a loan)
                            -	Annual interest Rate (also known as APR ‘annual percent rate’)
                            -	Period (total years)

                        The mortgage payments will be displayed, along with a payment schedule. 
                        The breakdown of interest, as well as the number of monthly payments will be outputted.
            */

const short int MONTHS_IN_YEAR = 12; // avoid magic numbers
const short int PERCENT = 100;

// function declarations
void printMortgage(int principal, float annual_interest, int years);
void printPaymentSchedule(int principal, float annualInterest, int years);
double calculateBalance(int principal,float annualInterest,int years, int numberOfPaymentsMade);
double calculateMortgage(int principal,float annualInterest,int years);

int main(void){
    int principal; 
    float annual_interest;
    float monthly_interest;
    int number_of_payments;
    int years;
    bool loop = true;

    while(loop){
        printf("Principal: ");
        scanf("%d", &principal);
        if(principal >= 1000 && principal <= 1000000){
            break;
        } 
        printf("Enter a value bewteen 1,000 and 1,000,000\n");
    }
    
    while(loop){
        printf("Annual Interest Rate: ");
        scanf("%f", &annual_interest);
        monthly_interest = annual_interest /PERCENT/ MONTHS_IN_YEAR;
        if(annual_interest > 0 && annual_interest <= 30)
            break;
        printf("Enter a value between 0 and 30\n");
    }

    while (loop){
        printf("Period (Years): ");
        scanf("%d", &years);
        number_of_payments = years * MONTHS_IN_YEAR; // total monthly payments
        if(years > 0 && years <= 30)
            break;
        printf("Enter a value between 1 and 30\n");
    }

    double mortgage = calculateMortgage(principal,annual_interest,years);
    double total_interest = (mortgage*number_of_payments) - principal; 

    printMortgage(principal,annual_interest,years);

    printf("\nTotal Number of Payments: %d \n", number_of_payments); // total # of payments
    printf("Total Interest: $%.2lf", total_interest);

    printPaymentSchedule(principal,annual_interest,years);

    return 0;
}


void printMortgage(int principal, float annual_interest, int years){
    double mortgage = calculateMortgage(principal, annual_interest, years);
    printf("\nMORTGAGE");
    printf("\n-----------");
    printf("\nMortgage Payments: $%.2lf", mortgage);
}

void printPaymentSchedule(int principal, float annualInterest, int years){
    double mortgage = calculateMortgage(principal, annualInterest, years);
    printf("\nPAYMENT SCHEDULE");
    printf("\n-------------------");
    for(int month = 1; month <= years * MONTHS_IN_YEAR; month++){
        double balance = calculateBalance(principal, annualInterest, years, month);
        printf("\n$%.2lf", balance);
    }
}

double calculateBalance(int principal,float annualInterest,int years, int numberOfPaymentsMade){
    float monthlyInterest = (annualInterest/PERCENT/MONTHS_IN_YEAR);
    int numberOfPayments = years * MONTHS_IN_YEAR; // monthly
    double balance = principal
                    * (pow(1+monthlyInterest,numberOfPayments)-pow(1+monthlyInterest, numberOfPaymentsMade))
                    / (pow(1+monthlyInterest,numberOfPayments)-1);
    
    return balance;
}

double calculateMortgage(int principal,float annualInterest,int years){

    float monthlyInterest = (annualInterest / PERCENT / MONTHS_IN_YEAR);
    int numberOfPayments = years * MONTHS_IN_YEAR; // monthly
    double mortgage = principal
                        * (monthlyInterest * pow(1 + monthlyInterest, numberOfPayments))
                        / (pow(1 + monthlyInterest, numberOfPayments) - 1);

    return mortgage;
}