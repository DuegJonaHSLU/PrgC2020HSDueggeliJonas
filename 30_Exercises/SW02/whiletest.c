#include <stdio.h>
int main(int argc, char* argv[]){

	int limitValue = 5;
	int counter = 0;
	int maxLoopExecutions = 100;
	while( counter<limitValue )
	{
		counter--;
		printf("# of while loop executions; %d\n",counter);
		if( counter> maxLoopExecutions){
			printf("max # executions exceeded! aborting.n");
			break;
		}	
	}




	return 0;
}
