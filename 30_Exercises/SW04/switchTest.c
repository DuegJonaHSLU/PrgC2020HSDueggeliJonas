#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	
	int input = atoi(argv[1]);
	
	switch(input){
	case 1:
		printf("1\n");
	case 2:
		printf("2\n");
		break;
	default:
		printf("neither 1 or 2\n");
		break;
	}




	return 0;
}
