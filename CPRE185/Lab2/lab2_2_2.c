/*-----------------------------------------------------------------------------
-					          CPRE 185 Lab 02
-	Name:
- 	Section:
-	NetID:
-	Date:
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
-							 Implementation
-----------------------------------------------------------------------------*/
int main()
{

    /* Put your code after this line */

printf("Omran Shareef\n");
printf("CPRE 185\n");
printf("09/09/2022\n");

int x, y, z;

printf("Enter a width: ");
scanf("%d", &x);

printf("Enter a height: ");
scanf("%d", &y);

printf("Enter a length: ");
scanf("%d", &z);
 
printf("A %d by %d by %d rectangular prism's volume is %d\n", x,y,z, x*y*z);
   

    return 0;

}

