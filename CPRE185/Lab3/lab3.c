/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>



double mag (double ax, double ay, double az) {
	
	double rv = sqrt((ax*ax)+(ay*ay)+(az*az));
	
	
	
	return rv;
}

int minutes (int t) {
	
	t = (t / 60000);
	return t;
	
}
int seconds (int t) {
	t = (t / 1000) % 60;
return t;

}

int millis (int t) {
	
	
	return t % 1000;
	
	
}

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double  ax, ay, az;     


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az); 


		
		
        printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", t/1000.0, ax, ay, az);


        printf("At %d ms, the acceleration's magnitude was: %lf\n", 
            t, mag(ax, ay, az));  
            

        
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
        minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 

    }

return 0;
}




