#include "Story1.h"

/*
Story 01 - As a company that provides services. 
I want to know the total amount of the
following withhold taxes: IR, PIS, COFINS, CSLL. 
That way I know how much money will be discounted when a customer pays my invoice. 
*/


int main()
{
	struct invoice in;
	struct withhold_taxes wt;
    struct taxes t = rates();
	int choice;
	time_t time_date;
	time(&time_date);
	
	do
	{

		system("cls");
		system("color 1f");

		printf("/*************************************/\n");		
		printf("/*      NF-e Withheld Taxes - V1     */\n");
		printf("/*************************************/\n");		
		printf("\n\n1- Calculate Withheld Taxes");
		printf("\n\n2- Exit");
		printf("\n\n-> ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
					system("cls");
					printf("Invoice Amount: ");
					scanf("%f", &in.invoice_amount);
					
					//Display the current date and time according to O.S
					printf("\n\n%sThe current tax rates are: ", ctime(&time_date));
					printf("\n\nIR: %f", t.ir);
					printf("\n\nPIS: %.", t.pis);
					printf("\n\nCOFINS: %f", t.cofins);
					printf("\n\nCSLL: %f", t.csll);
					wt = calculate(in, t);
					
					printf("\n\nGovern Amount: %f", wt.govern_amount);
					printf("\n\nAssumed Profit: %f", wt.assumed_profit);
					printf("\n\n");
					system("pause");
					break;
			
			case 2:
					printf("\nBye!\n\n");
					break;
					
			default: printf("\n\nOption Invalid!\nPlease try Again!\n\n");
		             system("pause");
	                 break;				
					
		}
	}while(choice != 2);

	printf("\n\n");
}
