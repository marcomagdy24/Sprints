/*
 * Payment.h
 *
 *  Created on: Jul 5, 2021
 *      Author: marco
 */

#ifndef Payment_H_
#define Payment_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../types.h"

/****************** Used Macros ************/
#define PAN (uint8_t) 2
#define DATABASE_LENGHT (uint8_t) 10
#define MAXIMUM_AMOUNT (float) 5000.0

/****************** Card Data Structure ************/
typedef struct ST_cardData_t {
	uint8_t cardHolderName[25];
	sint8_t primaryAccountNumber[20];
	sint8_t cardExpirationDate[6];
} ST_cardData_t;

/****************** Terminal Data Structure ************/
typedef struct ST_terminalData_t {
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
} ST_terminalData_t;

/****************** Transaction State enum ************/
typedef enum EN_transStat_t {
	DECLINED, APPROVED
} EN_transStat_t;

/****************** Structure of all data ************/
typedef struct ST_transaction_t {
	ST_cardData_t cardHolderData;
	ST_terminalData_t transData;
	EN_transStat_t transStat;
} ST_transaction;

/****************** Server Content Structure ************/
typedef struct ST_accountBalance_t {
	float balance;
	sint8_t primaryAccountNumber[20];
} ST_accountBalance_t;

/****************** User Functions ************/
void readCardData(ST_transaction* card);
void readTerminalData(ST_transaction* terminal);
EN_transStat_t checkPANFromServer(ST_transaction * data);
EN_transStat_t checkBalanceFromServer(ST_transaction * data);
EN_transStat_t checkExpirationDate(ST_transaction * data);

#endif /* Payment_H_ */
