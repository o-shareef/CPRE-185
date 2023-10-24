// 185 Lab 7
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}
	
	/* PUT YOUR CODE HERE */

	int t;
	double gx, gy, gz;
	double avgx, avgy, avgz;
	double xmin, ymin, zmin;
	double xmax, ymax, zmax; 
	int b1, b2, b3, b4;
	
	


	while (b4 == 0) {

		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &gx, &gy, &gz, &b1, &b2, &b3, &b4);
	
		updatebuffer(x, lengthofavg, gx);
		updatebuffer(y, lengthofavg, gy);
		updatebuffer(z, lengthofavg, gz);

		avgx = avg(x, lengthofavg);
		avgy = avg(y, lengthofavg);
		avgz = avg(z, lengthofavg);

		maxmin(x, lengthofavg, &xmax, &xmin);
		maxmin(y, lengthofavg, &ymax, &ymin);
		maxmin(z, lengthofavg, &zmax, &zmin);

		printf("gx: %lf, gy: %lf, gz: %lf, avg x: %lf, avg y: %lf, avg z: %lf, x_min: %lf, x_max: %lf, y_min: %lf, y_max: %lf, z_min: %lf, z_max: %lf\n", gx, gy, gz, avgx, avgy, avgz, xmin, xmax, ymin, ymax, zmin, zmax);
		fflush(stdout);

		


	}

	return 0;
}

double avg(double buffer[], int num_items) {
	int i;
	
	double total = 0.0;
	for (i = 0; i < num_items; ++i) {
		total = total + buffer[i];
	}
	return total / num_items;
}

void maxmin(double array[], int num_items, double* max, double* min) {
	int i;
	*max = array[0];
	*min = array[0];
	for (i = 0; i < num_items; ++i) {
	
		if (array[i] > *max) {
			*max = array[i];
		}
	}
	for (i = 0; i < num_items; ++i) {
		if (array[i] < *min) {
			*min = array[i];
		}
	}
}

void updatebuffer(double buffer[], int length, double new_item) {
	int i;
	for (i = 0; i < length - 1;++i) {
		buffer[i] = buffer[i + 1];
	}
	buffer[length - 1] = new_item;
}



