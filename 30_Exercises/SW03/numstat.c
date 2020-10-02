#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	float value1 = 0.0, value2=0.0, adifference = 0.0;
	if (argc != 3){		//controll of input arguments
		printf("You haven't entered the correct amount of Numbers.\nplease enter two numbers\n");
	}else{ 
		value1 = strtof (argv[1],NULL);
		value2 = strtof (argv[2],NULL);
		
		if (value1>value2){				//print values and calculate difference
			adifference =value1-value2;
			printf("smaler input: %.3f, biger input: %.3f\n\n",value2,value1);
		}else if(value1<value2){
			printf("smaler input %.3f, biger input %.3f\n\n",value1,value2);
			adifference= value2-value1;
		}
		
		printf("the sum is %.3f\n\n",value1+value2);	//calculate the sum
		
		printf("the absolute difference is %.3f\n\n",adifference);
		
		printf("the Product is %.3f\n\n", value1*value2);  //calculate the product
		
		printf("the ratio is %.3f\n\n",value2/value1);	//calculate the ratio
		
		
	}

	return 0;
}
