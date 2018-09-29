#define LIM_PRODUCT_H_

long digitCount()
{
	long value;
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
		printf("Counter %d and Value %ld\n");
	}
	printf("Counter %d and Value %ld\n");
	return counter;
	
/*
	while(countDigit_2>0)
	{
		countDigit_2=countDigit_2/10;
		count_2++;
	}
	printf("Number of Digits for Digit 2: %d\n", count_2);
*/
}
