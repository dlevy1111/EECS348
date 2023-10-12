#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Reading in data */
	float number;
	float sales[12];
	char *months[12] = {"January  ", "February ", "March    ",
						"April    ", "May      ", "June     ", "July     ",
						"August   ", "September", "October  ",
						"November ", "December "};

	FILE *file = fopen("monthly_sales.txt", "r");
	if (!file)
	{
		printf("file wasn't read");
		exit(1);
	}

	/* Hijacking this loop to calculate some other important values */
	int lowest_index = 0;
	int highest_index = 0;
	float sales_average = 0;

	int index = 0;
	while (fscanf(file, "%f", &number) == 1)
	{
		sales[index] = number;
		if (sales[index] < sales[lowest_index])
		{
			lowest_index = index;
		}

		if (sales[index] > sales[highest_index])
		{
			highest_index = index;
		}
		sales_average = sales_average + sales[index];

		index++;
	}
	sales_average /= 12.0;

	fclose(file);

	/* Printing monthly sales */

	printf("Monthly Sales Report for 2022\n");
	for (int i = 0; i < 12; i++)
	{
		printf("%s \t $%0.2f\n", months[i], sales[i]);
	}

	/* Sales summary */

	printf("\nSales Summary: \n");
	printf("Lowest Sales:\t$%0.2f (%s)\n", sales[lowest_index], months[lowest_index]);
	printf("Highest Sales:\t$%0.2f (%s)\n", sales[highest_index], months[highest_index]);
	printf("Average Sales:\t$%0.2f\n", sales_average);

	/* Calculating moving averages */
	float moving_averages[7];
	for (int i = 0; i <= 6; i++)
	{
		float temp = 0;
		for (int j = i; j < i + 6; j++)
		{
			temp += sales[j];
		}
		moving_averages[i] = temp / 6;
	}

	printf("\nSix-Month Moving Average Report\n");

	for (int i = 0; i <= 6; i++)
	{
		printf("%s \t-\t %s \t $%0.2f\n", months[i], months[i + 5], moving_averages[i]);
	}

	/* Sorting by Monthly Sales (using bubble sort because it is easy and c is already efficient enough) */

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (sales[i] > sales[j])
			{
				float temp_sales = sales[i];
				char *temp_month = months[i];
				sales[i] = sales[j];
				months[i] = months[j];
				sales[j] = temp_sales;
				months[j] = temp_month;
			}
		}
	}

	printf("\nSales Report (Highest to Lowest)\n");
	printf("Month\t\tSales\n");
	for (int i = 0; i < 12; i++)
	{
		printf("%s\t$%0.2f\n", months[i], sales[i]);
	}

	return 0;
}
