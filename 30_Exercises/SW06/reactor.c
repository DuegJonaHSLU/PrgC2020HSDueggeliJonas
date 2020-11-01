#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



//Variabeln
 long int nop = 0; 		//number of measure Points
 int i = 0;			//count variable for reading
 int n = 0;			//count variable for searching
 long long avp = 0;		//avergae pressure for exercise 2
 float avpb = 0;		//average pressure in bar for exercise 2
 bool pressure250 = false;	//pressure over 250 bar marker
 bool flag = false;		//flag for alarmstate warning
 bool severe = false;		//flag for alarmstate severe exercise 5
 int warningPoint = 0 ;	//marks Point for first Warning
 int severePoint = 0 ; 	//marks Point for first Severe State


//Stukturen
struct measurePoint{
	long long timeStamp;
	int pressure;
	char systemState;
	char alarmState;
	}measurePoint;
	

//Funktionen
void WriteText(struct measurePoint data[], int nop, FILE* pointer);
void readint(int state, int* adressP);




int main(int argc, char* argv[]){
	
	FILE* fPtr;
	fPtr = fopen("pressureSpike.bin","rb");
	FILE* txtP;
	txtP = fopen("pressureSpike.txt","w");
	
	if (fPtr == NULL){			//check for error in FILE* Pointers
		printf("error occured by Filepointer to read\n");
		return 1;
	}else if(txtP == NULL){
		printf("error occured by Filepointer to write\n");
		return 1;
	}
	
	fseek(fPtr,0, SEEK_END);		//counting data Points
	nop = ftell(fPtr)/14;
	fseek(fPtr,0,SEEK_SET);
	
	struct measurePoint data[nop];
	
	
	printf("%ld\n",sizeof(data[0].timeStamp));
	printf("%ld\n",sizeof(data[0].pressure));
	printf("%ld\n",sizeof(data[0].systemState));
	printf("%ld\n",sizeof(data[0].alarmState));
	printf("%ld\n",sizeof(data[0]));
	printf("%ld\n",sizeof(struct measurePoint));
	printf("%ld\n",nop);
		
	
	while(!feof(fPtr)){			//read data in to struct array
		struct measurePoint* P = data+i;
		fread(&P->timeStamp, sizeof(long long),1,fPtr);
		fread(&P->pressure, sizeof(int),1,fPtr);
		fread(&P->systemState, sizeof(char),1,fPtr);
		
		fread(&P->alarmState, sizeof(char),1,fPtr);
		i++;
	}

	

	WriteText(data, nop, txtP);		//write data to .txt file
	
	
	fclose(txtP);

/*----------------------------------------------------------------------------
////////////////////////////////Aufgabe1//////////////////////////////////////
----------------------------------------------------------------------------*/
	time_t rawtime = data[0].timeStamp/1000;
	time_t rawtime1 = data[nop-1].timeStamp/1000;
	printf("first Data: %.24s\nlast Data : %.24s\n",\
		ctime(&rawtime),\
		ctime(&rawtime1));
	
/*----------------------------------------------------------------------------
////////////////////////////////Aufgabe2//////////////////////////////////////
----------------------------------------------------------------------------*/
	printf("The elapsed time between the first 300 Datapoints is: %llds\n"\
		,data[300].timeStamp/1000 - data[0].timeStamp/1000);
		
		
	avp = data[0].pressure;
	for(int i = 0; i<300 ; i++){
		avp=((i+1)*avp+data[i+1].pressure)/((i+1)+1); //recursive average
	}
	avpb = avp/100000;
	printf("The average pressure during the first 300 Datapoints was: %.3fbar\n"\
		,avpb);
	
	printf("The System State was 0111\n");
	printf("The alarmstate was 0 in the first 300 Points\n");

/*----------------------------------------------------------------------------
////////////////////////////////Aufgabe3//////////////////////////////////////
----------------------------------------------------------------------------*/

	while(!pressure250){
		if(data[n].pressure/100000<250){
			if(n<nop){
				n++;
			}else{
				printf("The pressure never exceeded 250bar");
				pressure250=true;
			}
		}else if(data[n].pressure/100000>=250){
			time_t rawtime = data[n].timeStamp/1000;
			printf("the pressure exceeded 250 bar at %.24s\n",\
				ctime(&rawtime));
			pressure250=true;
		}
	
	}
	
	printf("the pressure was %d bar before the colapse\n",\
		data[nop-1].pressure/100000);

/*----------------------------------------------------------------------------
////////////////////////////////Aufgabe4//////////////////////////////////////
----------------------------------------------------------------------------*/

printf("the infomation about the rise of the pressure is to look up in the excell\n");


/*----------------------------------------------------------------------------
////////////////////////////////Aufgabe5//////////////////////////////////////
----------------------------------------------------------------------------*/
	n = 0;
	while(!severe){
		
		if(data[n].alarmState<2){
			if(data[n].alarmState<1 || flag == true){
				if(n<nop){
					n++;
				}else{
					if (flag == true){
						printf("severe was never reached");
						severe = true;
					}else{
						printf("there was never a warning");
						severe = true;
					}
				}
			}else if (data[n].alarmState == 1 && flag == false){
				time_t rawtime = data[n].timeStamp/1000;
				printf("The Warning was given at %.24s\n",\
					ctime(&rawtime));
				warningPoint=n;
				flag = true;
			}
		}else if(data[n].alarmState==2){
			time_t rawtime = data[n].timeStamp/1000;
			printf("The Alarmstate reached severe at %.24s\n",\
				ctime(&rawtime));
			severePoint = n;
			severe=true;
		}
	}
	printf("the Personell had %llds time to react\n",\
		(data[severePoint].timeStamp-data[warningPoint].timeStamp)/1000);


/*----------------------------------------------------------------------------
////////////////////////////////Aufgabe6//////////////////////////////////////
----------------------------------------------------------------------------*/


	return 0;
}


/*----------------------------------------------------------------------------
///////////////////////////Write Text/////////////////////////////////////////
----------------------------------------------------------------------------*/
void WriteText(struct measurePoint data[], int nop, FILE* pointer){
	for(int i=0; i<nop; i++){
		time_t rawtime = data[i].timeStamp/1000;
		int systs[4];			//System State Array
		int* systsP;
		systsP = systs;
		readint(data[i].systemState, systsP);
		fprintf(pointer, "%.24s; %d ; %d ; %d ; %d ; %d ; %d  \n",\
			ctime(&rawtime),\
			data[i].pressure,\
			systs[3],\
			systs[2],\
			systs[1],\
			systs[0],\
			data[i].alarmState);
		}
	return;
}
		
		
		
/*----------------------------------------------------------------------------
////////////////////write systemstate in Array////////////////////////////////
----------------------------------------------------------------------------*/
void readint(int state,int* adressP){
	for(int i=0 ; i<4 ; i++){
	
		if(state&1){
			*adressP = 1;
		}else{
			*adressP = 0;
		}
		state >>=1;
		adressP++;
	}

	return;
}





















		








