/*-----------------------------------------------------------------------------
-					         SE/CprE 185 Lab 04
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-	                            Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-	                            Defines
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-	                            Prototypes
-----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
-							  Implementation
-----------------------------------------------------------------------------*/


//===============================================================
int close_to (double tolerance, double point, double value);

double mag (double ax, double ay, double az);

int buttons (int b1, int b2, int b3, int b4);

int minutes(int t);

int seconds(int t);

int millis(int t);
//================================================================

int main(void) {
    double t;
    double ax, ay, az;
	int counter = 0;
	int falling = 0;
	double starttime = 0;
	double endtime = 0;
	double finaltime = 0;
	double distance = 0;
 

    printf("Omran Shareef\n");
	printf("shareef\n");
	scanf("%lf, %lf, %lf, %lf", &t, &ax, &ay, &az); 
	printf("Ok, I'm receiving data.\n");
	printf("I'm waiting");

	
	
	while(falling == 0) { //WHEN CONTROLLER NOT FALLING
		
		scanf("%lf, %lf, %lf, %lf", &t, &ax, &ay, &az);
		counter += 1;
		fflush(stdout);
		
		if(close_to(.4, 1, mag(ax, ay, az)) == 1) {
			
			if (counter == 10) {
				
			printf(".");
			counter = 0;
			fflush(stdout);
			
			}
		}
		else {
			
			falling = 1;
			starttime = t;
		}
			
			
	}
	
		if (falling == 1) {
			printf("\n\n	    Help me! I'm falling");
		}
		
	while(falling == 1) { //WHEN CONTROLLER FALLING

		scanf("%lf, %lf, %lf, %lf", &t, &ax, &ay, &az);
		counter += 1;
		fflush(stdout);
		
		if(close_to(.4, 1, mag(ax, ay, az)) == 0) {
			
			if (counter == 10) {
				
			printf("!");
			counter = 0;
			fflush(stdout);
			}
		}
		
			else {
			falling = 3;
			endtime = t;
		}
	
	}
		if (falling == 3) {
			finaltime = (endtime - starttime) / 1000;
			distance = (.5 * 9.8 * finaltime * finaltime);
			
			printf("\n\n	     	  Ouch! I fell %.3lf meters in %.3lf seconds", distance, finaltime);
		}
	return 0;

	}

	
	
	

	


 
//FUNCTIONS=====================================================
int close_to (double tolerance, double point, double value) {

	int error;
	double min = point - tolerance;
	double max = point + tolerance;
	
	if(value > min && value < max) {
	error = 1;
	
	}
	
	else {
	error = 0;
	
	}
	
	return error;

}



double mag (double x, double y, double z) {
	
	double rv = sqrt((x*x)+(y*y)+(z*z));
	
	
	return rv;
}

int minutes(int t) {
	return t / 60000;
}

int seconds(int t) {
	return (t / 1000) % 60;
}

int millis(int t) {
	return t % 1000;
}


int buttons(int b1, int b2, int b3, int b4) {
return b1 + b2 + b3 + b4;
}


