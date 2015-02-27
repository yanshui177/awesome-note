#include <stdio.h>

int main()
{
	double fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while(fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		// 3.0f fahr 宽度至少为3,小数宽度为1
		printf("%3.0f\t %6.1f\n", fahr, celsius);
		fahr += step; 
	}
}
