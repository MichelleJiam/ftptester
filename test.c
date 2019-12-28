#include "test.h"

int	outputcompare(FILE *input, FILE *comp, int *linenum, char **fnline, char **printfline)
{
	size_t linesize1, linesize2, linebufsize1 = 0, linebufsize2 = 0;

	*linenum += 1;
	linesize1 = getline(fnline, &linebufsize1, input);
	linesize2 = getline(printfline, &linebufsize2, comp);
	if (strcmp(*fnline, *printfline) != 0)
		return (-1);
	while (**fnline != '\0' && **printfline != '\0')
	{
		linesize1 = getline(fnline, &linebufsize1, input);
		linesize2 = getline(printfline, &linebufsize2, comp);
		if (strcmp(*fnline, *printfline) == 0)
			*linenum += 1;
		else
			return (-1);
	}
	return (0);
}

int main()
{
	FILE *input = fopen("ft_printf.txt", "r");
	FILE *comp = fopen("printf.txt", "r");
	int diff = 0;
	int linenum = 1;
	char *fnline = NULL;
	char *printfline = NULL;

	if (!input || !comp)
	{
		printf("File open error\n");
		return (-1);
	}
	diff = outputcompare(input, comp, &linenum, &fnline, &printfline);
	if (diff == 0)
		printf("---- Output is identical. ----\n\n");
	else
	{
		printf("---- Output is not equal. ----\n");
		printf("Line number: %d\nFunction output: %s\nPrintf output: %s\n",
		linenum, fnline, printfline);
	}
	free(fnline);
	free(printfline);
	fclose(input);
	fclose(comp);
	return (0);
}