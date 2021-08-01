/*
 * Payment.c
 *
 *  Created on: Jul 5, 2021
 *      Author: marco
 */

#include "Payment.h"

int accountNumber;

ST_accountBalance_t database[DATABASE_LENGHT] = {
	{100.00 , "123456789"},
	{6000.00 , "234567891"},
	{3250.25 , "567891234"},
	{1500.12 , "456789123"},
	{500.00 , "258649173"},
	{2100.00 , "654823719"},
	{0.00 , "971362485"},
	{1.00 , "793148625"},
	{10.12 , "123123456"},
	{0.55 , "456789321"}
};

void readCardData(ST_transaction* card) {
	sint8_t str[25];
	printf("\t\t\tPlease Enter Card Data\n");
	fflush(stdout);
	printf("Please Enter the Card Holder Name: ");
	fflush(stdout);
	gets(str);
	fflush(stdin);
	uint8_t i = 0;
	for (i = 0; str[i] != '\0'; i++) {
		card->cardHolderData.cardHolderName[i] = str[i];
	}
	card->cardHolderData.cardHolderName[i] = str[i];
	printf("Please Enter the Primary Account Number: ");
	fflush(stdout);
	gets(card->cardHolderData.primaryAccountNumber);
	fflush(stdin);
	printf("Please card Expire Date: ");
	fflush(stdout);
	gets(card->cardHolderData.cardExpirationDate);
	fflush(stdin);
}

void readTerminalData(ST_transaction* Terminal) {
	printf("\t\t\tPlease Enter Terminal Data\n");
	fflush(stdout);
	printf("Please Enter the transaction Amount: ");
	fflush(stdout);
	scanf("%f", &Terminal->transData.transAmount);
	fflush(stdin);
	printf("Please Enter transaction Date: ");
	fflush(stdout);
	scanf("%s", Terminal->transData.transactionDate);
	fflush(stdin);
}

EN_transStat_t checkPANFromServer(ST_transaction * data) {
	int flag = APPROVED;
	for (int i = 0; i < 10; i++) {
		int j = 0;
		while (j < 9) {
			if (database[i].primaryAccountNumber[j]
					== data->cardHolderData.primaryAccountNumber[j]){
				accountNumber = i;
				return APPROVED;
			}

			 else {
				flag = DECLINED;
				break;
			}
			j++;
		}
	}
	if(flag == DECLINED)
		return DECLINED;

	return DECLINED;


}

EN_transStat_t checkBalanceFromServer(ST_transaction * data) {
	if ((database[accountNumber].balance >= data->transData.transAmount)
			&& (data->transData.transAmount < MAXIMUM_AMOUNT ))
		return APPROVED;
	else
		return DECLINED;

}

EN_transStat_t checkExpirationDate(ST_transaction * data) {
	uint8_t cardExpirationYear = (data->cardHolderData.cardExpirationDate[3]
			- '0') * 10 + (data->cardHolderData.cardExpirationDate[4] - '0');
	uint8_t transactionYear = (data->transData.transactionDate[8] - '0') * 10
			+ (data->transData.transactionDate[9] - '0');
	uint8_t cardExpirationMonth = (data->cardHolderData.cardExpirationDate[0]
			- '0') * 10 + (data->cardHolderData.cardExpirationDate[1] - '0');
	uint8_t transactionMonth = (data->transData.transactionDate[3] - '0') * 10
			+ (data->transData.transactionDate[4] - '0');

	if ((cardExpirationYear >= transactionYear)
			&& (cardExpirationMonth >= transactionMonth))
		return APPROVED;
	return DECLINED;
}
