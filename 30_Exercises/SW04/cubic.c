#include <stdio.h>
#include<stdlib.h>

long ComputeCubic(long X){
	long xCubed=0;
	xCubed = X*X*X;
	return xCubed;
	}



int main(int argc, char* argv[]){

	long input = atoi(argv[1]);
	long xCubed = 0;
	
	printf("Input value: %ld\n",input);
	xCubed = ComputeCubic( input );
	printf("Cubic Value: %ld\n", xCubed);


	return 0;
}
