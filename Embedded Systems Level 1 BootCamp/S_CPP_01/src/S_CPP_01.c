/*
 ============================================================================
 Name        : S_CPP_01.c
 Author      : Marco
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Payment/Payment.h"

int main(void) {
	sint8_t key = 'y';
	while (key == 'y' || key == 'Y') {
		EN_transStat_t checkPAN, checkBalance, checkExpiration;
		ST_transaction data;
		readCardData(&data);
		readTerminalData(&data);
		checkPAN = checkPANFromServer(&data);
		checkBalance = checkBalanceFromServer(&data);
		checkExpiration = checkExpirationDate(&data);
		if ((checkPAN == APPROVED) && (checkBalance == APPROVED)
				&& (checkExpiration == APPROVED)) {
			printf("[INFO] Transaction Approved\n");
			fflush(stdout);
		} else if (checkPAN == DECLINED) {
			printf(
					"[INFO] Transaction Declined. Primary Account Number is invalid\n");
			fflush(stdout);
		} else if (checkBalance == DECLINED) {
			printf(
					"[INFO] Transaction Declined. Balance is insufficient\n");
			fflush(stdout);
		} else if (checkExpiration == DECLINED) {
			printf(
					"[INFO] Transaction Declined. Your card is expired\n");
			fflush(stdout);
		}
		printf(
				"Do you want to perform another transaction? for Yes (y) for No (n)?");
		fflush(stdout);
		scanf("%c", &key);
		fflush(stdin);
	}

	printf("Thank for using our Payment System");
}
