#include <stdio.h>

double CalculateTotalAmountPaid(double loan,double interestrate,double installment,int year,int currentYear){

    if(year==0 || loan<=0){
        return 0;
    }
    loan=loan*(loan*interestrate/100.0);
    printf("\nYear: %d Remaining Loan: %.2f",currentYear,loan);
    loan=loan-installment;

    return installment + CalculateTotalAmountPaid(loan,interestrate,installment,year-1,currentYear+1);
}

int main(){
    double loan = 100000;
    double interestrate = 5;
    int year = 3;
    double installment = 30000;

    double totalPaid = CalculateTotalAmountPaid(loan, interestrate,installment,year, 1);

    printf("\nTotal repayment over %d years = %.2f\n", year, totalPaid);

    return 0;
}
