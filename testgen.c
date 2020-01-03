/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testgen.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 14:12:52 by mjiam          #+#    #+#                */
/*   Updated: 2020/01/03 20:41:41 by mjiam         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	g_var = 5;

int	ptrtest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, i = 0;
	FILE	*out;
	char	test[2][200] =
	{	"0. Basic p test: [%p]\n",
		"1. P with 12 width: [%12p]\n"};

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== Pointer test ====\n");
	fprintf(out, "==== Pointer test ====\n");
	alarm(5);
	while (i < 2)
	{
		ret = function(test[i], &g_var);
		ret2 = fprintf(out, test[i], &g_var);
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int modtest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, i = 0;
	FILE	*out;
	char	test[20][100] =
	{	"0. d with h, 20 width, value int max: [%20hd]\n",
		"1. d with h, left align, 20 width, value int max: [%-20hd]\n",
		"2. d with h, left align, 20 width, value int min: [%-20hd]\n",
		"3. d with h, 20 width, value short max: [%20hd]\n",
		"4. d with hh, 20 width, value int max: [%20hhd]\n",
		"5. d with l, 20 width, value int max: [%20ld]\n",
		"6. d with l, 20 width, value int min: [%20ld]\n",
		"7. d with l, 20 width, value long min: [%20ld]\n",
		"8. d with l, 20 width, value u long max: [%20lu]\n",
		"9. d with ll, 20 width, value int max: [%20lld]\n",
		"10. d with ll, 20 width, value long min: [%20lld]\n",
		"11. d with ll, 20 width, value u long max: [%20llu]\n",
		"12. u with l, 42 width, value u long max: [%42lu]\n",
		"13. u with ll, 42 width, value u long max: [%42llu]\n",
		"14. u with h, 20 width, value u long max: [%20hu]\n",
		"15. u with hh, 20 width, value u long max: [%20hhu]\n",
		"16. x with l, 20 width, value u long max: [%20lx]\n",
		"17. x with ll, 20 width, value u long max: [%20llx]\n",
		"18. x with h, 20 width, value u long max: [%20hx]\n",
		"19. x with hh, 20 width, value u long max: [%20hhx]\n"};

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== Modifier test ====\n");
	fprintf(out, "==== Modifier test ====\n");
	alarm(5);
	while (i < 20)
	{
		if (i == 2 || i == 6)
		{
			ret = function(test[i], INT_MIN);
			ret2 = fprintf(out, test[i], INT_MIN);
		}
		else if (i == 3)
		{
			ret = function(test[i], SHRT_MAX);
			ret2 = fprintf(out, test[i], SHRT_MAX);
		}
		else if (i == 7 || i == 10)
		{
			ret = function(test[i], LONG_MIN);
			ret2 = fprintf(out, test[i], LONG_MIN);
		}
		else if (i == 8 || i > 10)
		{
			ret = function(test[i], ULONG_MAX);
			ret2 = fprintf(out, test[i], ULONG_MAX);
		}
		else
		{
			ret = function(test[i], INT_MAX);
			ret2 = fprintf(out, test[i], INT_MAX);
		}
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int ntest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, nptr = 10, nptr2 = 10;
	FILE	*out;

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== N test ====\n");
	fprintf(out, "==== N test ====\n");
	alarm(5);
	function("Starting value of ptr: %d\n", nptr);
	fprintf(out, "Starting value of ptr: %d\n", nptr2);
	ret = function("Basic n test: Hello%nworld\n", &nptr);
	ret2 = fprintf(out, "Basic n test: Hello%nworld\n", &nptr2);
	if (ret < 0 || ret2 < 0)
		return (-1);
	function("Ret: %d\n", ret);
	fprintf(out, "Ret: %d\n", ret2);
	ret = function("Value of ptr in previous test: %d\n", nptr);
	ret2 = fprintf(out, "Value of ptr in previous test: %d\n", nptr2);
	if (ret < 0 || ret2 < 0)
		return (-1);
	function("Ret: %d\n", ret);
	fprintf(out, "Ret: %d\n", ret2);
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int	uinttest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, i = 0;
	FILE	*out;
	char	test[20][100] =
	{	"0. Number precision 4 test: [%.4u], [%.4u]\n",
		"1. Number zero pad, 5 width: [%05u], [%05u]\n",
		"2. Number zero pad, left: [%-04u], [%-04u]\n",
		"3. Number 5 width, precision 0 with non-zero value test: [%5.0u], [%5.0u]\n",
		"4. Number 5 width precision 0 with value 0 test: [%5.0u], [%5.0u]\n",
		"5. Number 5 width, 3 precision test: [%5.3u], [%5.3u]\n",
		"6. Number 5 width, 4 precision test: [%5.4u], [%5.4u]\n",
		"7. Number with left, 6 width, 4 precision test: [%-6.4u], [%-6.4u]\n",
		"8. Number with * (5) width: [%*u], [%*u]\n",
		"9. Number with * (-5) width: [%*u], [%*u]\n",
		"10. Number with * (-5) precision: [%.*u], [%.*u]\n",
		"11. Number with * (-5) precision, zero value: [%.*u], [%.*u]\n",
		"12. Number with * (0) precision, zero value: [%.*u], [%.*u]\n",
		"13. Int min test, 12 width, 11 precision: [%12.11u]\n",
		"14. Int max test, 12 width, 11 precision: [%12.11u]\n",
		"Bonus - Number space flag  test: [% u], [% u]\n",
		"Bonus - Number with plus, 5 width test: [%+5u], [%+5u]\n",
		"Bonus - Number with plus 6 width, 4 precision test: [%+6.4u], [%+6.4u]\n",
		"Bonus - Number with space 6 width, 4 precision test: [% 6.4u], [% 6.4u]\n",
		"Bonus - Apostrophe test with u: [%'u]\n"};

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== Unsigned Decimal test ====\n");
	fprintf(out, "==== Unsigned Decimal test ====\n");
	alarm(5);
	while (i < 15)
	{
		if (i == 4){
			ret = function(test[i], 0, 0);
			ret2 = fprintf(out, test[i], 0, 0);
		}
		else if (i == 8){
			ret = function(test[i], 5, 456, 5, -456);
			ret2 = fprintf(out, test[i], 5, 456, 5, -456);
		}
		else if (i == 9){
			ret = function(test[i], -5, 456, -5, -456);
			ret2 = fprintf(out, test[i], -5, 456, -5, -456);
		}
		else if (i == 10){
			ret = function(test[i], -5, 456, -5, -456);
			ret2 = fprintf(out, test[i], -5, 456, -5, -456);
		}
		else if (i == 11){
			ret = function(test[i], -5, 0, -5, 0);
			ret2 = fprintf(out, test[i], -5, 0, -5, 0);
		}
		else if (i == 12){
			ret = function(test[i], 0, 0, 0, 0);
			ret2 = fprintf(out, test[i], 0, 0, 0, 0);
		}
		else if (i == 13){
			ret = function(test[i], 0);
			ret2 = fprintf(out, test[i], 0);
		}
		else if (i == 14){
			ret = function(test[i], UINT_MAX);
			ret2 = fprintf(out, test[i], UINT_MAX);
		}
		else{
			ret = function(test[i], 456, -456);
			ret2 = fprintf(out, test[i], 456, -456);
		}
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	while (i < 20)
	{
		if (i == 19)
		{
			ret = function(test[i], UINT_MAX);
			ret2 = fprintf(out, test[i], UINT_MAX);
		}
		else
		{
			ret = function(test[i], 456, -456);
			ret2 = fprintf(out, test[i], 456, -456);
		}
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int	hextest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, i = 0;
	FILE	*out;
	char	test[8][200] =
	{	"0. Basic hex test, x & X: [%x] [%X]\n",
		"1. Basic hex test, negative values: [%x] [%X]\n",
		"2. Hex with 8 width, 5 precision, value zero: [%8.5x] [%8.5X]\n",
		"3. Hex with 8 width, 0 precision, value zero: [%8.0x] [%8.0X]\n",
		"Bonus - Hex with # flag, 10 width: [%#10x] [%#10X]\n",
		"Bonus - Hex with # flag, value zero: [%#x] [%#X]\n",
		"Bonus - Hex with # flag, 12 width, left justified: [%-#12x] [%-#12X]\n",
		"Bonus - Hex with # flag, 12 width, 11 width: [%#12.11x] [%#12.11X]\n"};

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== Hex test ====\n");
	fprintf(out, "==== Hex test ====\n");
	alarm(5);
	while (i < 8)
	{
		if (i == 2 || i == 3 || i == 5){
			ret = function(test[i], 0, 0);
			ret2 = fprintf(out, test[i], 0, 0);
		}
		else{
			ret = function(test[i], 456, -456);
			ret2 = fprintf(out, test[i], 456, -456);
		}
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int	stringtest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, i = 0;
	FILE	*out;
	char 	str1[] = "Hello World";
	char	test[12][200] =
	{	"0. String 1 width 3 precision test: [%1.3s]\n",
		"1. String 3 width test: [%3s]\n",
		"2. String 15 width test: [%15s]\n",
		"3. String 9 width 7 precision test: [%9.7s]\n",
		"4. String precision 0 test: [%.s]\n",
		"5. String * (4) precision: [%.*s]\n",
		"6. String * (10) width * (5) precision: [%*.*s]\n",
		"7. String * (-1) width * (-1) precision: [%*.*s]\n",
		"8. String * (-3) precision: [%.*s]\n",
		"9. String * (0) width * (0) precision: [%*.*s]\n",
		"10. Empty string test: [%s]\n"
		"11. String with /\0/ char"};

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== String test ====\n");
	fprintf(out, "==== String test ====\n");
	alarm(5);
	while (i < 5)
	{
		ret = function(test[i], str1);
		ret2 = fprintf(out, test[i], str1);
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	while (i < 12)
	{
		if (i == 5)
		{
			ret = function(test[i], 4, str1);
			ret2 = fprintf(out, test[i], 4, str1);
		}
		if (i == 6)
		{
			ret = function(test[i], 10, 5, str1);
			ret2 = fprintf(out, test[i], 10, 5, str1);
		}
		if (i == 7)
		{
			ret = function(test[i], -1, -1, str1);
			ret2 = fprintf(out, test[i], -1, -1, str1);
		}
		if (i == 8)
		{
			ret = function(test[i], -3, str1);
			ret2 = fprintf(out, test[i], -3, str1);
		}
		if (i == 9)
		{
			ret = function(test[i], 0, 0, str1);
			ret2 = fprintf(out, test[i], 0, 0, str1);
		}
		if (i == 10)
		{
			ret = function(test[i], "");
			ret2 = fprintf(out, test[i], "");
		}
		if (i == 11)
		{
			ret = function(test[i], "\0");
			ret2 = fprintf(out, test[i], "\0");
		}
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int	percenttest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, i = 0;
	FILE	*out;
	char	test[3][100] =
	{	"0. Percent with width: [%5%]\n",
		"1. Percent zero pad + width: [%05%]\n",
		"2. Percent left: [%-5%]\n"};

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== Percent test ====\n");
	fprintf(out, "==== Percent test ====\n");
	alarm(5);
	while (i < 3)
	{
		ret = function(test[i]);
		ret2 = fprintf(out, test[i], 0);
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int	chartest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, i = 0;
	FILE	*out;
	char	test[6][100] =
	{   "0. Basic char test: [%c]\n",
		"1. Char 5 width: [%5c]\n",
		"2. Char zero pad, 5 width: [%05c]\n",
		"3. Char left align, 5 width: [%-5c]\n",
		"4. Char test with 2 width, null value: [%2c]\n",
		"5. Char test with null [%c] and text after\n"};

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== Char test ====\n");
	fprintf(out, "==== Char test ====\n");
	alarm(5);
	while (i < 6)
	{
		if (i == 4 || i == 5)
		{
			ret = function(test[i], 0);
			ret2 = fprintf(out, test[i], 0);
		}
		else
		{
			ret = function(test[i], 'a');
			ret2 = fprintf(out, test[i], 'a');
		}
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int	decimaltest(int function(const char *input, ...))
{
	int		ret = 0, ret2 = 0, i = 0;
	FILE	*out;
	char	test[22][100] =
	{	"0. Number precision 4 test: [%.4d], [%.4d]\n",
		"1. Number zero pad, 5 width: [%05d], [%05d]\n",
		"2. Number zero pad, left: [%-04d], [%-04d]\n",
		"3. Number 5 width, precision 0 with non-zero value test: [%5.0d], [%5.0d]\n",
		"4. Number 5 width precision 0 with value 0 test: [%5.0d], [%5.0d]\n",
		"5. Number 5 width, 3 precision test: [%5.3d], [%5.3d]\n",
		"6. Number 5 width, 4 precision test: [%5.4d], [%5.4d]\n",
		"7. Number with left, 6 width, 4 precision test: [%-6.4d], [%-6.4d]\n",
		"8. Number with * (5) width: [%*d], [%*d]\n",
		"9. Number with * (-5) width: [%*d], [%*d]\n",
		"10. Number with * (-5) precision: [%.*d], [%.*d]\n",
		"11. Number with * (-5) precision, zero value: [%.*d], [%.*d]\n",
		"12. Number with * (0) precision, zero value: [%.*d], [%.*d]\n",
		"13. Int min test, 12 width, 11 precision: [%12.11d]\n",
		"14. Int max test, 12 width, 11 precision: [%12.11d]\n",
		"Bonus - Number space flag  test: [% d], [% d]\n",
		"Bonus - Number with plus, 5 width test: [%+5d], [%+5d]\n",
		"Bonus - Number with plus 6 width, 4 precision test: [%+6.4d], [%+6.4d]\n",
		"Bonus - Number with space 6 width, 4 precision test: [% 6.4d], [% 6.4d]\n",
		"Bonus - Apostrophe test with d and i: [%'d] [%'i]\n",
		"Bonus - Apostrophe test with less than 3 figures: [%'d] [%'i]\n",
		"Bonus - Number with plus, 0 precision, value zero: [%+.d] [%+.i]\n"};

	if ((out = fopen("printf.txt", "a")) == NULL)
		return (-1);
	function("==== Decimal test ====\n");
	fprintf(out, "==== Decimal test ====\n");
	alarm(5);
	while (i < 15)
	{
		if (i == 4){
			ret = function(test[i], 0, 0);
			ret2 = fprintf(out, test[i], 0, 0);
		}
		else if (i == 8){
			ret = function(test[i], 5, 456, 5, -456);
			ret2 = fprintf(out, test[i], 5, 456, 5, -456);
		}
		else if (i == 9){
			ret = function(test[i], -5, 456, -5, -456);
			ret2 = fprintf(out, test[i], -5, 456, -5, -456);
		}
		else if (i == 10){
			ret = function(test[i], -5, 456, -5, -456);
			ret2 = fprintf(out, test[i], -5, 456, -5, -456);
		}
		else if (i == 11){
			ret = function(test[i], -5, 0, -5, 0);
			ret2 = fprintf(out, test[i], -5, 0, -5, 0);
		}
		else if (i == 12){
			ret = function(test[i], 0, 0, 0, 0);
			ret2 = fprintf(out, test[i], 0, 0, 0, 0);
		}
		else if (i == 13){
			ret = function(test[i], INT_MIN);
			ret2 = fprintf(out, test[i], INT_MIN);
		}
		else if (i == 14){
			ret = function(test[i], INT_MAX);
			ret2 = fprintf(out, test[i], INT_MAX);
		}
		else{
			ret = function(test[i], 456, -456);
			ret2 = fprintf(out, test[i], 456, -456);
		}
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	while (i < 22)
	{
		if (i == 19)
		{
			ret = function(test[i], INT_MAX, INT_MAX);
			ret2 = fprintf(out, test[i], INT_MAX, INT_MAX);
		}
		else if (i == 21)
		{
			ret = function(test[i], 0, 0);
			ret2 = fprintf(out, test[i], 0, 0);
		}
		else
		{
			ret = function(test[i], 456, -456);
			ret2 = fprintf(out, test[i], 456, -456);
		}
		if (ret < 0 || ret2 < 0)
			return (-1);
		function("Ret: %d\n", ret);
		fprintf(out, "Ret: %d\n", ret2);
		i++;
	}
	alarm(0);
	function("\n");
	fprintf(out, "\n");
	fclose(out);
	return (0);
}

int	main(int ac, char **av)
{
	av++;
	if (ac == 2)
	{
		setlocale(LC_ALL, "en_US.UTF-8");
		if (strcmp(*av, "decimal") == 0)
		{
			if (decimaltest(ft_printf) < 0)
				return (-1);
		}
		if (strcmp(*av, "char") == 0)
		{
			if (chartest(ft_printf) < 0)
				return (-1);
		}
		if (strcmp(*av, "percent") == 0)
		{
			if (percenttest(ft_printf) < 0)
				return (-1);
		}
		if (strcmp(*av, "string") == 0)
		{
			if (stringtest(ft_printf) < 0)
				return (-1);
		}
		if (strcmp(*av, "hex") == 0)
		{
			if (hextest(ft_printf) < 0)
				return (-1);
		}
		if (strcmp(*av, "uint") == 0)
		{
			if (uinttest(ft_printf) < 0)
				return (-1);
		}
		if (strcmp(*av, "ptr") == 0)
		{
			if (ptrtest(ft_printf) < 0)
				return (-1);
		}
		if (strcmp(*av, "nstore") == 0)
		{
			if (ntest(ft_printf) < 0)
				return (-1);
		}
		if (strcmp(*av, "mod") == 0)
		{
			if (modtest(ft_printf) < 0)
				return (-1);
		}
	}
	return (0);
}
