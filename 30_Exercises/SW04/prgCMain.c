#include <stdio.h>

typedef enum {
	MAIN_MENU = 1,
	NUMSTAT,
	CUBIC,
	FACTORIAL,
	NCHOOSEK,
	PRINTBINARY,
	EXIT = 99
} MenuItem;


// function declarations
MenuItem PrintMainMenu( void );
long int ComputeCubic( long int x );
long Factorial( long n );
long Choosek( long n, long m );
void PrintinBinary( int n ); 			//beachten von Zahlengrösse!!
 


int main( int argc, char* argv[] )
{

	MenuItem menuSelected = MAIN_MENU;
	int run = 1;
	long int input = 0;
	long int input1 = 0;
	long result = 0;
	while(run)
	{
		switch(menuSelected){
			case MAIN_MENU:
				menuSelected = PrintMainMenu();
				break;
	
			case NUMSTAT:
				// get user input:
				
				printf("executing NumStat\n");
				menuSelected = MAIN_MENU;
				break;

			case CUBIC:
				printf("Enter a 'long int' number: ");
				scanf("%ld", &input);
				result = ComputeCubic(input);
				printf("%ld cubed is %ld\n\n", input, result);
				menuSelected = MAIN_MENU;
				break;
			
			case FACTORIAL:
				printf("Enter a 'long int' number: ");
				scanf("%ld", &input);
				result = Factorial(input),
				printf("%ld factored is %ld\n\n", input, result );
				menuSelected = MAIN_MENU;
				break;
				
			case NCHOOSEK:
				printf("Enter the high 'long int' number: ");
				scanf("%ld", &input);
				printf("Enter the low 'long int' number: ");
				scanf("%ld", &input1);
				result = Choosek(input,input1),
				printf("%ld tief %ld betraegt %ld\n\n", input, input1, result );
				menuSelected = MAIN_MENU;
				break;
			
			case PRINTBINARY:
				printf("Enter a Number:  ");
				scanf("%ld", &input);
				PrintinBinary(input);
				menuSelected = MAIN_MENU;
				break;

			case EXIT:	
				run = 0;
				printf("\n\nWas a plesure, good bye\n\n");
				break;

			default:		
				printf("invalid menu selection\n");
				break;
		}
	}

 	return 0;
}


// function implementations:

//Menu Function
MenuItem PrintMainMenu( void )
{
	MenuItem selection = MAIN_MENU;
	printf("***********************************\n");
	printf("Main Menu\n");
	printf("***********************************\n\n");
	printf("Select from the following options:\n");
	printf("%d - NumStat\n", NUMSTAT);
	printf("%d - Cubic\n", CUBIC);
	printf("%d - Factorial\n", FACTORIAL);
	printf("%d - Nchoosek\n", NCHOOSEK);
	printf("%d - Print in Binary\n", PRINTBINARY);
	printf("%d - Exit\n", EXIT);
	printf("--> ");
	scanf("%d", (int*)&selection);
	return selection;
}	
//Cubic Function

long int ComputeCubic( long int x ){
	long int result = 0 ; //why declaration here? tryed to declare it in main. didn't work...
	result = x*x*x;
	return result;
}

//factorial function
long Factorial( long n ){
	
	long result=0;
	if (n>= 1){
		result = n*Factorial(n-1);
	}else{
		result =1;
	}
	return result;
}

//nchoosek function
long Choosek( long n, long k ){
	
	long factorialn=0;
	long factorialk=0;
	long factorialnk = 0;
	long result =0;
	if (n>k){
		factorialn=Factorial(n);
		factorialk=Factorial(k);
		factorialnk=Factorial(n-k);
		result = factorialn/(factorialk*factorialnk);
	}else{
		printf("\n\nThe first number has to be bigger than the second. Result invalid!!\n\n");
		result=999999999;
	}
	return result;
}

//Print in Binary function
void PrintinBinary( int n ){

	printf(" n : %d ==> ",n);
	int numbits = sizeof(n) * 8;
	while (--numbits >= 0){
		printf("%c", (1&(n >> numbits)) ? '1' : '0');
	}
	printf("\n\n");

	return;
	
}





























