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
    int t, b1, b2, b3, b4, ori;
	ori = 0;
	b1 = 0;
    double ax, ay, az, gx, gy, gz;
	
        


    while (b1 < 1) {
        scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );
		
        
		/*
		printf("X = %lf, Y = %lf, Z = %lf\n",gx, gy, gz);
	 
		printf("At %d minutes, %d seconds, and %d milliseconds \nThe magnitude was: %lf\n\n", minutes(t), seconds(t), millis(t), mag(ax,ay,az));
		
		printf("buttons pressed: %d, %d, %d, %d\n", b1, b2, b3, b4);
		*/
		
	
		if (close_to(0.25, 1, gy) == 1) {
			if (ori == 1) {
			}
			else{
			printf("Top\n");
			ori = 1;	
			}
		}
		if (close_to(0.25, -1, gy) == 1) {
			if (ori == 2) {
			}
			else{
			printf("Bottom\n");
			ori = 2;
			}
		}
		if (close_to(0.25, 1, gx) == 1) {
			if (ori == 3) {
			}
			else{
			printf("Right\n");
			ori = 3;
			}
		}
		if (close_to(0.25, -1, gx) == 1) {
			if (ori == 4) {
			}
			else{
			printf("Left\n");
			ori = 4;
			}
		}
		if (close_to(0.25, -1, gz) == 1) {
			if (ori == 5) {
			}
			else{
			printf("Front\n");
			ori = 5;
			}
		}
		if (close_to(0.25, 1, gz) == 1) {
			if (ori == 6) {
			}
			else{
			printf("Back\n");
			ori = 6;
				}
			
		
		}

    
    
	}

		printf("Program terminated");

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


