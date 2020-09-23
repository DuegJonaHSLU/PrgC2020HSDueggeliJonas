#include <stdio.h>
int main(int argc, char* argv[]){
	int cycleCount = 0;
	int readValue = 1 ;
	while (cycleCount<1){
		printf("Enter a number between i(ncluding)0 and 9 to display the numer as text. Enter 10 to stop the programm:  ");
		scanf("%d", &readValue);
		
		if (readValue == 10){
			printf("thank you. Good bye\n");
			break;
		}else if (readValue < 0 || readValue > 9){
			printf("invalid -> try again\n");
		}else if (readValue == 1){
			printf("1 as test is 'one\n'");
		}else if (readValue == 2){
			printf("2 as test is 'two'\n");
		}else if (readValue == 3){
			printf("3 as test is 'three'\n");
		}else if (readValue == 4){
			printf("4 as test is 'four'\n");
		}else if (readValue == 5){
			printf("5 as test is 'five'\n");
		}else if (readValue == 6){
			printf("6 as test is 'six'\n");
		}else if (readValue == 7){
			printf("7 as test is 'seven'\n");
		}else if (readValue == 8){
			printf("8 as test is 'eight'\n");
		}else if (readValue == 5){
			printf("9 as test is 'nine'\n");
		}


	}
	return 0;
}
