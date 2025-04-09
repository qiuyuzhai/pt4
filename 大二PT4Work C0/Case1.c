#include "pt4.h"
//An integer in the range 1 to 7 is given. 
//Output the name of the respective day of week:
// 1 — "Monday", 2 — "Tuesday", …, 7 — "Sunday".

void Solve(void)
{
    Task("Case1");
    int m;
	char *k;
    GetN(&m);
    switch(m)
    {
    	case 1:k = "Monday";break;
    		
    	case 2:
    	    k = "Tuesday";break;
    	case 3:
    		k = "Wednesday";break;
    	case 4:
    		k = "Thursday";break;
    	case 5:
    		k = "Friday";break;
    	case 6:
    		k = "Saturday";break;
    	case 7:
    		k = "Sunday";break;
	}
    PutS(k);

}
