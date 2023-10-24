
#include <stdio.h>
#include <math.h>

int buttons (int b1, int b2, int b3, int b4);
	

	int main(void) {
	
	int b1, b2, b3, b4;
	

	while (1) {
		scanf("%d, %d, %d, %d", &b1, &b2, &b3, &b4);
		
		printf("Number of buttons pressed: %d\n", buttons(b1, b2, b3, b4));
		
	fflush(stdout);
	}

				return 0;
}


int buttons(int b1, int b2, int b3, int b4) {
return b1 + b2 + b3 + b4;
}