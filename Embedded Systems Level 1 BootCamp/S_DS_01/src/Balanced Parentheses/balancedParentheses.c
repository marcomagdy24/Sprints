#include "balancedParentheses.h"


int isMatching(char char1, char char2) {
	if (char1 == '(' && char2 == ')')
		return 1;
	else if (char1 == '{' && char2 == '}')
		return 1;
	else if (char1 == '[' && char2 == ']')
		return 1;
	else
		return 0;
}

uint8_t *balancedParentheses(uint8_t *expression) {
	uint8_t exp_index = 0;
	while (expression[exp_index]) {
		if ((expression[exp_index] == '{') || (expression[exp_index] == '(')
				|| (expression[exp_index] == '['))
			push(expression[exp_index]);
		if ((expression[exp_index] == '}') || (expression[exp_index] == ')')
				|| (expression[exp_index] == ']')) {
			if (head == NULL) {
//				printf("[Debug1] Not Balance\n");
				return Not_Balance ;
			} else if (!(isMatching(pull(), expression[exp_index]))){
				// *result = BALANCED;
//				printf("[Debug2] Not Balance\n");
				return Not_Balance ;
			}
		}

		exp_index++;
	}
	if (head == NULL) {
		// *result = BALANCED;
//		printf("[Debug3] Balance\n");
		return Balance ;
	} else {
		// *result = NOT_BALANCED;
//		printf("[Debug4] Not Balance\n");
		return Not_Balance ;
	}
}
