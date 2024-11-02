/*
kabir
24k-0927
question1
*/
#include <stdio.h>
main() 
{
    int arr[5], smallest, smallest2, i;

    printf("Enter 5 elements:\n");
    for(i=0; i<5; i++) 
	{
        scanf("%d", &arr[i]);
        while(arr[i]>=9999) 
		{
            printf("(Value out of range!). Enter a number less than 9999: ");
            scanf("%d", &arr[i]);
        }
    }
    smallest=smallest2=9999;
    for(i=0; i<5; i++) 
	{
        if(arr[i]<smallest) 
		{
            smallest2=smallest;
            smallest = arr[i];
        } 
		else if(arr[i]<smallest2 && arr[i]!=smallest) 
		{
            smallest2 = arr[i];
        }
    }
    if(smallest2==9999) 
	{
        printf("\nThere is no second smallest element (all elements are equal).\n");
    } 
	else 
	{
        printf("\nThe Second smallest element in the array is: %d\n", smallest2);
    }
}
