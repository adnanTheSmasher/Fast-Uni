#include<iostream>
using namespace std;

class LoanHelper
{
	private:
		const float interest_rate = 0.005;
		float loan_Amount;
		float remaining;
		float monthly_payment;
		float interest_pay;
		int months;
	
	public:
		LoanHelper(float loanAmount, int month) 
		{
			loan_Amount = loanAmount;
			months = month;			
		}
		
		void calculate_loan()
		{
			monthly_payment = (loan_Amount/months);
			interest_pay = monthly_payment * interest_rate;
			remaining = monthly_payment + interest_pay;

		}
		
		float getRem()
		{
			return remaining;
		}
		
		int getMonths()
		{
			return months;
		}
};

int main()
{
	LoanHelper l1(1000, 10);
	l1.calculate_loan();
	cout<< "You have to Pay " << l1.getRem() << " every month for " << l1.getMonths() << " months to repay your loan";
	
}