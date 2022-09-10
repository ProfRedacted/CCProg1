/*
 Description: Virtual Trading Game
 Programmed by: Wesley King Uy S16A
 Last modified: 2/7/2022
 [Acknowledgements: 
 #include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>]
*/
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

/*	This function generates random Normal Prices for the buying and selling of different items
	
	@param nLowerBound is the lower bound of the price
	@param nUpperBound is the upper bound of the price
	
	@return random price that was generated
*/

float NormalPrice()
{
	float nBounded;
	float nUpperbound = 200;float nLowerbound = 180;
	do
	{
		nBounded = fmod((float)rand()/100 , (nUpperbound - nLowerbound + 1)) + nLowerbound;
	}
	while (nBounded > 200);
	return (nBounded);
}
/*	This function generates random Special Prices for the buying and selling of different items
	
	@param nLowerBound is the lower bound of the price
	@param nUpperBound is the upper bound of the price
	
	@return random price that was generated
*/
float SpecialPrice()
{
	float nBounded;
	float nUpperbound = 150;float nLowerbound = 100;
	do
	{
		nBounded = fmod((float)rand()/100 , (nUpperbound - nLowerbound + 1)) + nLowerbound;
	}
	while (nBounded > 150);
	return (nBounded);
}
/*	This function assign the prices Normal Prices and Special price and assign the prices for the different items depending on the City

	@param nCityPartner get the City ID and give it special price for the cities
	@param fPrice[] Assign the Normal prices for the Cities
*/
void CalculatePrices(int nCityPartner,float fPrice[])
{
	fPrice[0] = NormalPrice();
	fPrice[1] = NormalPrice()+100;
	fPrice[2] = NormalPrice()+200;
	fPrice[3] = NormalPrice()+300;
	fPrice[4] = NormalPrice()+400;
	fPrice[5] = NormalPrice()+500;
	fPrice[6] = NormalPrice()+600;
	fPrice[7] = NormalPrice()+700;
	switch (nCityPartner)
	{
		case 1: fPrice[1]=SpecialPrice()+100;break;
		case 2: fPrice[3]=SpecialPrice()+300;break;
		case 3: fPrice[2]=SpecialPrice()+200;fPrice[5]=SpecialPrice()+500;break;
		case 4: fPrice[4]=SpecialPrice()+400;break;
		case 5: fPrice[6]=SpecialPrice()+600;fPrice[7]=SpecialPrice()+700;break;
		case 6: fPrice[0]=SpecialPrice();break;
	}
}
/*	The function check and deposit cash to the Savings.fBankSaving Increase by the amount of fCashDeposit while fPlayerGold decrease by the amount fCashDeposit 

	Precondition: fPlayerGold must be greater than fCashDeposit and Cash Deposit must be more than 0

	@param *fPlayerGold is the amount of Gold the Player has currently
	@param *fBankSavings is the amount of Gold Store in the Bank Currently
	@param fCashDeposit is amount of transaction he is willing to deposit, and changes the *fBankSavings and *fPlayerGold
	@param cNothing is an useless intenger to let the program stop and then running
*/
void BankDeposit(float *fPlayerGold, float *fBankSavings)
{
	float fGoldDeposit;
	char cNothing;
	printf("Teller: Okay, How Much do you want to deposit?\n");
	printf("You:I would like to deposit ");
	scanf("%f",&fGoldDeposit);
	if (*fPlayerGold < fGoldDeposit || fGoldDeposit < 0)
	//return a 1 if fGoldDeposit is a negative number and fGoldDeposit is more than *fPlayerGold (because you can't deposit more than the gold you have)
	{
		printf("Teller: Sorry, We cannot do the transaction\n");
		printf("Enter any number to continue\n");
		scanf(" %c",&cNothing);
	}
	else
	//if this line is reaach it will make necessary to the according values; increases *fBankSavings and decreases *fPlayerGold
	{
		*fBankSavings += fGoldDeposit;
		*fPlayerGold -= fGoldDeposit;
		printf("Teller: You have Deposited %.2f amount of GD. Thank you for your patronage!\n",fGoldDeposit);
		printf("Enter any key to continue\n");
		scanf(" %c",&cNothing);
	}
}
/*	The function check and withdraw cash to the player.fBankSaving decrease by the amount of fGoldWithdraw while fPlayerGold increase by the amount fGoldDeposit 

	Precondition: fGoldWithdraw must be less than fSavings and fGoldWithdraw must be more than 0
	
	@param *fPlayerGold is the amount of Gold the Player has currently
	@param *fBankSavings is the amount of Gold Store in the Bank Currently
	@param fGoldWithdraw is amount of transaction he is willing to withdraw, and changes the *fBankSavings and *fPlayerGold
	@param cNothing is an useless intenger to let the program stop and then running
*/
void BankWithdraw(float *fPlayerGold, float *fBankSavings)
{
	float fGoldWithdraw;
	char cNothing;
	printf("Teller: Okay, How Much do you want to withdraw?\n");
	printf("You:I would like to withdraw ");
	scanf("%f",&fGoldWithdraw);
	if (*fBankSavings < fGoldWithdraw || fGoldWithdraw < 0)
	//return a 1 if fGoldWithdraw is a negative number or *fBankSavings is less than fGoldwithdraw (because you can't withdraw more than the gold the bank have)
	{
		printf("Teller: Sorry, We cannot do the transaction\n");
		printf("Enter any key to continue\n");
		scanf(" %c",&cNothing);
	}
	else
	//if this line is reach it will make necessary to the according values; decreases *fBankSavings and increases *fPlayerGold
	{
		*fBankSavings -= fGoldWithdraw;
		*fPlayerGold += fGoldWithdraw;
		printf("Teller: You have Withdraw %.2f amount of GD. Thank you for your patronage!\n",fGoldWithdraw);
		printf("Enter any key to continue\n");
		scanf(" %c",&cNothing);
	}
}
/*	The function check and withdraw cash to the player.*fDebt increase by the amount of fCashLoans

	Precondition: fGoldLoans must be greater than 0
	
	@param *fPlayerGold is the amount of Gold the Player has currently
	@param *fDebt is the amount of Gold Store in the Bank Currently
	@param fGoldLoans is amount of loans he will be receiving from the bank, and changes the *fBankSavings and *fPlayerGold
	@param cNothing is an useless intenger to let the program stop and then running
*/
void BankLoans(float *fPlayerGold, float *fDebt)
{
	float fGoldLoans;
	char cNothing;
	printf("Teller: Okay, How Much do you want to Loan Today?\n");
	printf("You:I would like to loan ");
	scanf("%f",&fGoldLoans);
	if (fGoldLoans < 0)
	//return a 1 if fGoldLoans is a negative number	
	{
		printf("Teller: Sorry, We cannot give you your loans\n");
		printf("Enter any number to continue\n");
		scanf(" %c",&cNothing);
	}
	else
	//if this line is reaach it will make necessary to the according values; increases *fDebt and increases *fPlayerGold
	{
		*fDebt += fGoldLoans;
		*fPlayerGold += fGoldLoans;
		printf("Teller: You have Loan %.2f amount of GD. Thank you for your patronage!\n",fGoldLoans);
		printf("Enter any key to continue\n");
		scanf(" %c",&cNothing);
	}
}
/*	The function check and remove cash to the player to pay to the bank.*fDebt decrease by the amount of fCashPayback

	Precondition: fGoldPayback is greater than 0 and must be less than current player gold (*fPlayerGold) and make sure than fGoldPayback is less than the debt(fDebt)
	
	@param *fPlayerGold is the amount of Gold the Player has currently
	@param *fDebt is the amount of Debt the player has to the store
	@param fGoldPayback is amount of transaction he is willing to pay back to the bank, and changes the *fBankSavings and *fPlayerGold
	@param cNothing is an useless intenger to let the program stop and then running
*/
void BankPayback(float *fPlayerGold, float *fDebt)
{
	float fGoldPayback;
	char cNothing;
	printf("Teller: Okay, How Much do you want to Pay to the Bank Today?\n");
	printf("You:I would like to payback the bank by");
	scanf("%f",&fGoldPayback);
	if (fGoldPayback < 0 || fGoldPayback > *fPlayerGold || fGoldPayback > *fDebt)
	/*return a 1 if fGoldPayback is a negative number or fGoldPayback is more than *fPlayerGold (because you can't payback the gold you don't have) or
	 fGoldPayback is more than your *fDebt(because you can't Payback gold when you don't have debts)*/
	{
		printf("Teller: Sorry, We cannot do the transaction\n");
		printf("Enter any key to continue");
		scanf(" %c",&cNothing);
	}
	else
	//if this line is reach it will make necessary to the according values; decreases *fDebt and decreasing *fPlayerGold
	{
		*fDebt -= fGoldPayback;
		*fPlayerGold -= fGoldPayback;
		printf("Teller: You have Payback %.2f amount of GD. Thank you for your patronage!\n",fGoldPayback);
		printf("Enter any key to continue");
		scanf(" %c",&cNothing);
	}
}
/*	Display the UI of the Iron Bank
	
	Precondition: fPlayerGold must be greater than Deposited Amount and Cash Deposit must be more than 0
	
	@param fPlayerGold get and display the value of fPlayerGold
	@param fBankSavings get and display the value of fBankSavings
	@param fDebts get and display the value of fDebts
	
	@return cBankChoice character that was chosen
*/
char BankTransaction(float fPlayerGold, float fBankSavings, float fDebts)
{
	char cBankChoice = '&';
	//system("cls");
	printf("-------------------------------------------------------------\n");
	printf("  $$$	\n");
	printf(" $$$$$		\n");
	printf("$$$$$$$		Welcome to the\n");
	printf("$$$$$$$		Iron Bank of Braavos\n");
	printf(" $$$$$		Your GD:%.2f\n",fPlayerGold);
	printf("  $$$		Your Savings: %.2f	Your Debt:%.2f\n",fBankSavings,fDebts);
	printf("_____________________________________________________________\n");
	printf("	Teller: What do you want to do Today?\n");
	printf("_____________________________________________________________\n");
	printf("[D] Deposit	[W] Withdraw	[L] Loan	[P] Payback	[X] Exit\n");
	printf("Choice:");
	scanf(" %c",&cBankChoice);
	return (cBankChoice);
}
/*	The function buy Item, Remove Gold, and Increase and check capacity, increase Equipment Count
	
	Precondition: nItem must be within line of 0 - 8; the Quantity must not satisfy all 3 of the problems below
	
	@param *fPrice is the Price of the different items
	@param *fPlayerGold get the amount of Gold the Player have and increase it
	@param *nCapacity check the amount of Capacity the player have and increase it
	@param nMaxCapacity check the Max Capacity of the Player have and make sure it doesn't go over it
	@param *nEquipmentCount get how many specific item does the player have and increase it
	@param nItem check the values of input to ensure it is between 0 - 8
	@param nQty is the quantity of the item being purchase
	@param cNothing is an useless intenger to let the program stop and then running
*/
void Buy(float *fPrice , float *fPlayerGold, int *nCapacity, int nMaxCapacity, int *nEquipmentCount)
{
	int nItem = 10;
	int nQty = 0;
	int nTest = 0;
	char cNothing = '&';
	printf("\nBuy what?\n[0] Back\n");
	nTest = scanf("%d",&nItem);
	if (nTest != 0)
	//Check if the %d is an integer or a char
	{
		if (nItem > -1 && nItem < 9) 
		//Check if the nItem is within the range
		{
			if (nItem != 0) 
			//if it 0 skip this part
			{	
				switch(nItem)
				//show the item you selected depending on nItem
				{
					case 1:printf("You selected SweetBeet. How many?\n");
							printf("       _   _\n");	
							printf("       <\\^/>\n");
							printf("       ^\\|/^\n");
							printf("	)|(\n");
							printf("       <###> \n");
							printf("      (#####)\n");
							printf("       -###-\n");
							printf("	\\#/ \n");
							printf("	 V\n");
							break;
					case 2:printf("You selected Timber. How many?\n");
							printf("          ___________\n");	
							printf("         /  \\________\\\n");
							printf("        _\\__/________/\n");
							printf("       /  \\/  \\_______\\\n");
							printf("       \\__/\\__/_______/\n");
							break;
					case 3:printf("You selected Intricate Lace. How many?\n");
							printf("<>============<> \n");	
							printf("||\\/\\/\\/\\/\\/\\/||\n");
							printf("||<> <> <> <> ||\n");
							printf("||/\\/\\/\\/\\/\\/\\||\n");
							printf("<>============<>\n");
							break;
					case 4:printf("You selected Intoxicating Perfume. How many?\n");
							printf("    _ \n");	
							printf("   (_)\n");
							printf("   |_|\n");
							printf("  /___\\\n");
							printf(" ( _P_ )\n");
							printf("  \\___/\n");
							break;
					case 5:printf("You selected Pale Amber Wine. How many?\n");
							printf("   ________\n");	
							printf("  /========\\\n");
							printf(" / / |  | \\ \\\n");
							printf("|/==========\\|  \n");
							printf("|    WINE    |\n");
							printf("|\\==========/| \n");
							printf(" \\_\\_|__|_/_/\n");
							printf("  \\________/\n");
							break;
					case 6:printf("You selected Marish Eye. How many?\n");
							printf("      _.=-=._\n");	
							printf("     (_ (0) _)\n");
							printf("       '=-='\n");
							break;
					case 7:printf("You selected Qohorik Tapestry. How many?\n");
							printf("//==========\\\\\n");	
							printf("||XxxXxxXxxX|| \n");
							printf("||xXXxXXxXXx||\n");
							printf("||XxxXxxXxxX||\n");
							printf("\\\\==========//\n");	
							break;
					case 8:printf("You selected Valyarian Steel. How many?\n");
							printf("	____\n");	
							printf("       /   /\\\n");
							printf("      /   / /\n");
							printf("     /   / /\n");
							printf("    /___/ / \n");
							printf("   /____\\/\n");
							break;
				}			
				do
				//this function will keep on looping until nQty is valid number
				{
					scanf("%d",&nQty);	
					if (nQty <= -1 || nQty * fPrice[nItem - 1] >= *fPlayerGold || nQty + *nCapacity > nMaxCapacity)
					//Check the Qty, price * quantity to be less than player gold, and check if the player still has capacity left
					{
						printf("Invalid Amount of Quantity\n");
						printf("Enter any key to continue");
						scanf(" %c",&cNothing);
					}
					else //if the result is 0, it goes here it subtract the gold from the player and increase the capacity
					{
						*fPlayerGold -= nQty * fPrice[nItem - 1];
						*nCapacity += nQty;	
						nEquipmentCount[nItem - 1] += nQty;
						printf("Thank you! You have bought %d pieces\n",nQty);
						printf("Enter any key to continue");
						scanf(" %c",&cNothing);
					}
				}
				while (nQty <= -1 || nQty * fPrice[nItem - 1] >= *fPlayerGold || nQty + *nCapacity > nMaxCapacity);
			}
		}
		else
		// this will be printed if nItem isn't in the range
		{
			printf("\nInvalid Item Number\n");
			Buy(fPrice , &*fPlayerGold, &*nCapacity, nMaxCapacity, &*nEquipmentCount);
		}
	}
	else
	//this will be printed if the value of nItem isn't an integer
	{
		printf("Merchant: Sorry, I didn't hear correctly\n");
		scanf(" %c",&cNothing);
		printf("Enter any key to continue\n");
		scanf(" %c",&cNothing);
	}		
}
/*	The function sells Item, increases Gold, and decreases and Check Capacity, decreases EquipmentCount

	Precondition: nItem must be within line of 0 - 8; the Quantity must not satisfy all 2 of the problems below
	
	@param *fPrice is the Price of the different items
	@param *fPlayerGold get the amount of Gold the Player have and increases it
	@param *nCapacity check the amount of Capacity the player have and decrease it
	@param nMaxCapacity check the Max Capacity of the Player have 
	@param *nEquipmentCount get how many specific item and check if player have it and decrease it
	@param nItem check the values of input to ensure it is between 0 - 8
	@param nQty is the quantity of the item being purchase
	@param cNothing is an useless intenger to let the program stop and then running
*/
void Sell(float *fPrice , float *fPlayerGold, int *nCapacity, int nMaxCapacity, int *nEquipmentCount)
{
	int nItem = 10;
	int nQty = 0;
	int nTest = 0;
	char cNothing = '&';
	printf("\nSell what?\n[0] Back\n");
	nTest = scanf("%d",&nItem);
	if (nTest != 0)
	//test the value if it is an integer, then allow this function to run
	{
		if (nItem > -1 && nItem < 9)
		 //Check if the item is within the range
		{
			if (nItem != 0) 
			//if it 0 skip this part
			{	
				switch(nItem)
				//show the item you have selected using nItem
				{
					case 1:printf("You selected SweetBeet. How many?\n");
							printf("       _   _\n");	
							printf("       <\\^/>\n");
							printf("       ^\\|/^\n");
							printf("	)|(\n");
							printf("       <###> \n");
							printf("      (#####)\n");
							printf("       -###-\n");
							printf("	\\#/ \n");
							printf("	 V\n");
							break;
					case 2:printf("You selected Timber. How many?\n");
							printf("          ___________\n");	
							printf("         /  \\________\\\n");
							printf("        _\\__/________/\n");
							printf("       /  \\/  \\_______\\\n");
							printf("       \\__/\\__/_______/\n");
							break;
					case 3:printf("You selected Intricate Lace. How many?\n");
							printf("<>============<> \n");	
							printf("||\\/\\/\\/\\/\\/\\/||\n");
							printf("||<> <> <> <> ||\n");
							printf("||/\\/\\/\\/\\/\\/\\||\n");
							printf("<>============<>\n");
							break;
					case 4:printf("You selected Intoxicating Perfume. How many?");
							printf("    _ \n");	
							printf("   (_)\n");
							printf("   |_|\n");
							printf("  /___\\\n");
							printf(" ( _P_ )\n");
							printf("  \\___/\n");
							break;
					case 5:printf("You selected Pale Amber Wine. How many?\n");
							printf("   ________\n");	
							printf("  /========\\\n");
							printf(" / / |  | \\ \\\n");
							printf("|/==========\\|  \n");
							printf("|    WINE    |\n");
							printf("|\\==========/| \n");
							printf(" \\_\\_|__|_/_/\n");
							printf("  \\________/\n");
							break;
					case 6:printf("You selected Marish Eye. How many?\n");
							printf("      _.=-=._\n");	
							printf("     (_ (0) _)\n");
							printf("       '=-='\n");
							break;
					case 7:printf("You selected Qohorik Tapestry. How many?\n");
							printf("//==========\\\\\n");	
							printf("||XxxXxxXxxX|| \n");
							printf("||xXXxXXxXXx||\n");
							printf("||XxxXxxXxxX||\n");
							printf("\\\\==========//\n");
							break;
					case 8:printf("You selected Valyarian Steel. How many?\n");
							printf("	____\n");	
							printf("       /   /\\\n");
							printf("      /   / /\n");
							printf("     /   / /\n");
							printf("    /___/ / \n");
							printf("   /____\\/\n");
							break;
				}			
				do
				//this action will continue the user input is valid
				{
					scanf("%d",&nQty);	
					if (nQty > nEquipmentCount[nItem-1] || nQty <= -1|| *nCapacity < 0) 
					//Check if Equipment Count is greater than nQty, and nQty is valid, and *nCapacity must not be 0
					{
						printf("Invalid amount of Quantity\n");
						printf("Enter any key to continue");
						scanf(" %c",&cNothing);
					}
					else 
					//if the result give a 0 you are able to decrease the item quantity and increase the player gold
					{
						*fPlayerGold += nQty * fPrice[nItem - 1];
						*nCapacity -= nQty;	
						nEquipmentCount[nItem - 1] -= nQty;
						printf("Thank you! You have sold %d Pieces\n",nQty);
						printf("Enter any key to continue");
						scanf(" %c",&cNothing);
					}
				}
				while (nQty <= -1 || nQty <= nEquipmentCount[nItem-1]);
			}
		}
		else 
		//this will print if the value isn't within range
		{
			printf("\nInvalid Item Number\n");
			Sell(fPrice , &*fPlayerGold, &*nCapacity, nMaxCapacity, &*nEquipmentCount);
		}
	}
	else
	//this will print if the value of nItem is not a integer
	{
		printf("Merchant: Sorry, I didn't hear correctly\n");
		scanf(" %c",&cNothing);
		printf("Enter any key to continue\n");
		scanf(" %c",&cNothing);
	}
}
/*	The function is to show the UI of the different prices and the items of the city

	@param cCityName is name of different city and is assign depending on the city
	@param fPrice[] get the different prices show it on the UI
	@param nDay, fPlayerGold, fDebts, fSavings, nCapacity,nMaxCapacity shows the stats of the player in the UI below
	
	@return cAction is the character that was chosen by the player
*/
char DisplayMenu(char* cCityName, float fPrice[], int nDay, float fPlayerGold, float fDebts, float fSavings,int nCapacity, int nMaxCapacity)
{
	system("cls");
	char cAction = '&';
	printf("-------------------------------------------------------------\n");
	printf("			%s\n",cCityName);
	printf("-------------------------------------------------------------\n");
	printf("Item		Wares and Goods  	Selling/Buying Price\n");
	printf("_____________________________________________________________\n");
	printf("[1]		SweetBeet			%.2f\n",fPrice[0]);
	printf("[2]		Timber				%.2f\n",fPrice[1]);
	printf("[3]		Intricate Lace			%.2f\n",fPrice[2]);
	printf("[4]		Intoxicating Perfume		%.2f\n",fPrice[3]);
	printf("[5]		Pale Amber Wine			%.2f\n",fPrice[4]);
	printf("[6]		Myrish Eye			%.2f\n",fPrice[5]);
	printf("[7]		Qohorik Tapestry		%.2f\n",fPrice[6]);
	printf("[8]		Valyrian Steel 			%.2f\n",fPrice[7]);
	printf("_____________________________________________________________\n\n");

	printf("Day Remaining:		%d Days\n",nDay);
	printf("GD:			%.2f GD\n",fPlayerGold);
	printf("Debts:			%.2f GD\n",fDebts);
	printf("Savings:		%.2f GD\n",fSavings);
	printf("Capacity:		%d/%d\n\n", nCapacity , nMaxCapacity);
	printf("[B] Buy	[S] Sell	[W] Wheelbarrow	[I] Iron Bank [E] Equipment [Q] Quit \nChoice:");
	scanf(" %c",&cAction);
	return cAction;
}
/*	The function to determe whether the player meets a carpenter that will upgrade its Max Capacity for a Price
	
	Precondition: nResult must be 0 in order for the player to meet carpenter otherwise he will continue as normal
	
	@param cAnswer allows the player to input its answer and be scan
	@param nResult will the be modulo 10 and determine whether he meet the carpenter or not
	
	@return 1 or 0 depending on the rand()
*/
int UpgradeWheelbarrow(char* aCity)
{
	char cAnswer ='&';
	int nResult;
	nResult = rand() % 10;
	if (nResult== 0) 
	// if rand() managed to hit a factor of 10, you will be able to meet the carpenter in your journey
	{
		printf("On your way to %s, you met a Carpenter along the way\n",aCity);
		printf("Traveling Carpenter: That is nice wheelbarrow, you know I could your Cart for 200 GD?\n");
		printf("[Y] Yes		[N] No\n");
		scanf(" %c",&cAnswer);
		while (cAnswer != 'y' && cAnswer != 'Y' && cAnswer != 'N' && cAnswer != 'n')
		//this while loop will loop your answer until cAnswer is one of 4 variable above
		{
			printf("What do you mean by %c\n",cAnswer);
			scanf(" %c",&cAnswer);
		}
		if (cAnswer == 'Y'|| cAnswer == 'y')
		//if you answer 'y' or 'Y' this int will return 0
			return 1;		
		else 
		//if you answer 'n' or 'N' this int will return 0
			return 0;
	}
}
/*	The function shows what city he can travel to and the days remaining

	@param nDay shows the days left
	@param nChoice store the player's answer and return it
	
	@return number of choice by the player
*/
int ChooseCityPartner(int nDay)
{	
	system("cls");
	int nChoice;
	printf("===Trading Partner===\n\n");
	printf("	[1] Winterfell\n");
	printf("	[2] Lys\n");
	printf("	[3] Myr\n");
	printf("	[4] Pentos\n");
	printf("	[5] Qohor\n");
	printf("	[6] Volantis\n\n");
	printf("	[9] Quit");
	printf("\n\nDays Left:%d",nDay);
	printf("\n\nChoose City:");
	scanf("%d",&nChoice);
	return nChoice;
}
/*	The function shows the equipment the player have and allows him to back to the menu

	@param nEquipmentCount show how many equipment each item have
	@param cBack allows your player to go back to the city action
*/
void DisplayEquipment(int nEquipmentCount[])
{
	system("cls");
	char cBack = '&';
	printf("%d SweetBeet\n",nEquipmentCount[0]);
	printf("%d Timber\n",nEquipmentCount[1]);
	printf("%d Intricate Lace\n",nEquipmentCount[2]);
	printf("%d Intoxicating Perfume\n",nEquipmentCount[3]);
	printf("%d Pale Amber Wine\n",nEquipmentCount[4]);
	printf("%d Marish Eye\n",nEquipmentCount[5]);
	printf("%d Qohorik Tapestry\n",nEquipmentCount[6]);
	printf("%d Valyrian Steel\n",nEquipmentCount[7]);
	while (cBack != 'X' && cBack !='x')
	{
		printf("Press [X] to Exit:");
		scanf(" %c",&cBack);
	}
}
/*	The function will just display the final result of the game

	@param nDays show how many day left
	@param fPlayerGold show how many gold does the player have
	@param fPlayerSavings have in the bank
	@param fDebt is the debt the player has
	@param nCapacity is how many item does the player have
	@param nEquipmentCount is the number of each Equipment/item player have
*/
void Quit(int nDays,float fPlayerGold,float fPlayerSavings, float fDebt, int nCapacity, int nEquipmentCount[])
	{
		{
		float fFinalScore = 0;
		printf("Day Remaining:%d\n",nDays);
		printf("Golden Dragons(GD):%.2f\n",fPlayerGold);
		printf("Savings:%.2f\n",fPlayerSavings);
		printf("Debt:%.2f\n",fDebt);
		printf("Capacity:%d\n",nCapacity);
		printf("%d SweetBeet\n",nEquipmentCount[0]);
		printf("%d Timber\n",nEquipmentCount[1]);
		printf("%d Intricate Lace\n",nEquipmentCount[2]);
		printf("%d Intoxicating Perfume\n",nEquipmentCount[3]);
		printf("%d Pale Amber Wine\n",nEquipmentCount[4]);
		printf("%d Marish Eye\n",nEquipmentCount[5]);
		printf("%d Qohorik Tapestry\n",nEquipmentCount[6]);
		printf("%d Valyrian Steel\n",nEquipmentCount[7]);
		
		fFinalScore = fPlayerGold - fDebt;
		printf("Your Score is %.2f",fFinalScore); 
		}
	}
int main()
{
	int nCityPartner = 0;
	int nDay = 15;
	int nCapacity = 0;
	int nMaxCapacity =50;
	int nUpgrade = 0;
	int nEquipmentCount[8] = {0,0,0,0,0,0,0,0};
	int nPlaceholder = 0;
	float fPrice[8] = {0,0,0,0,0,0,0,0};
	float fBankSavings = 0;
	float fDebt = 0;
	float fPlayerGold = 2000;
	char cAction = '&';
	char cBankAction = '&';
	char cTrash = '&';
	char aCity[6][15];
	strcpy(aCity[0],"Winterfell");
	strcpy(aCity[1],"Lys");
	strcpy(aCity[2],"Myr");
	strcpy(aCity[3],"Pentos");
	strcpy(aCity[4],"Qohor");
	strcpy(aCity[5],"Volantis");
	char aEquipment[7][30];
	strcpy(aEquipment[0],"SweetBeet");
	strcpy(aEquipment[1],"Timber");
	strcpy(aEquipment[2],"Intricate Lace");
	strcpy(aEquipment[3],"Intoxicating Perfume");
	strcpy(aEquipment[4],"Pale Amber Wine");
	strcpy(aEquipment[5],"Myrish Eye");
	strcpy(aEquipment[6],"Qohorik Tapestry");
	strcpy(aEquipment[7],"Valyrian Steel");


	srand(time(0));
	while (nCityPartner != 9 && nDay >= 1)
	//keep running until nDay is greater than 0 and nCityPartner is not 9
	{
		nCityPartner = ChooseCityPartner(nDay);
		//check the player input
		if (nCityPartner > 0 && nCityPartner < 7 || nCityPartner == 9) 
		//Check if city number is within the value given and if it 9
		{
			nUpgrade = UpgradeWheelbarrow(aCity[nCityPartner - 1]);
			//run the RNG check for the wheelbarrow upgrade
			if (nUpgrade == 1)
			 //Check value of nUpgrade, when it is 1 this part of program runs
			{
				if (fPlayerGold >= 200) 
				//Check if the player has enough gold to purchase the wheelbarrow upgrade
				{
					fPlayerGold -= 200;
					nMaxCapacity += 50;
					printf("Your new Capacity is %d\n",nMaxCapacity);
				}
				else 
				//if the person doesn't meet the requirement it fails
					printf("Traveling Carperter: You can't afford this.");
			}
			if (nCityPartner < 7 && nCityPartner > 0) 
			//Check if the nCityPartner is a valid number
			{	
				CalculatePrices(nCityPartner, fPrice);
				while (cAction != 'w' && cAction !='W' && cAction !='Q' && cAction !='q')
				 //Break the loop when cAction is w ,W , q or Q
				{
					cAction = DisplayMenu( aCity[nCityPartner - 1] , fPrice , nDay , fPlayerGold , fDebt, fBankSavings, nCapacity, nMaxCapacity);
		
					switch (cAction) 
					//Detect cAction based on the DisplayMenu()
					{
						case 'B':
						case 'b': Buy(fPrice, &fPlayerGold, &nCapacity, nMaxCapacity, nEquipmentCount);break;
						case 'S':
						case 's': Sell(fPrice, &fPlayerGold, &nCapacity, nMaxCapacity, nEquipmentCount);break;
						case 'E':
						case 'e': DisplayEquipment(nEquipmentCount);break;
						case 'I':
						case 'i':
								while (cBankAction != 'x' && cBankAction != 'X') 
								// Display the bank and break the loop of the bank cBankAction is not 'x' or 'X'
								{	
									cBankAction = BankTransaction(fPlayerGold, fBankSavings,fDebt);
									switch (cBankAction)
									//Available action of the Bank
									{
										case 'D':
										case 'd': BankDeposit(&fPlayerGold, &fBankSavings);break;
										case 'w':
										case 'W': BankWithdraw(&fPlayerGold, &fBankSavings);break;
										case 'L':
										case 'l': BankLoans(&fPlayerGold, &fDebt);break;
										case 'P':
										case 'p': BankPayback(&fPlayerGold, &fDebt);break;
										case 'x':
										case 'X':break;
									}
								}
								cBankAction = '&';
								break;
						case 'w':
						case 'W':break;
						case 'Q':
						case 'q':break;
						default: printf("You cannot do %c\n",cAction);
					}
				}
				if (cAction == 'q' || cAction == 'Q') 
				//if cAction is q it will set the nCityPartner to 9 ending the loop
				{
					nCityPartner = 9;
				}
				nDay--;
				fBankSavings *= 1.10;
				fDebt *= 1.05;
			}
		}
		else 
		//If the value is wrong of nCityPartner it will print this and print the city again
		{
			printf("\nInvalid City Number\n");
			printf("Enter Any Number\n");
			scanf(" %c",&cTrash);
		}
		cAction = '&';
	}
	Quit(nDay , fPlayerGold , fBankSavings , fDebt , nCapacity , nEquipmentCount);
	return 0;
}
