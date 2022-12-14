#include <unistd.h> //open() close ()
#include <stdlib.h> // free()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "libftprintf.h"
#include "minunit.h"

#define SIZE 100

static unsigned int expected_int[SIZE];
static unsigned int result_int[SIZE];
static char *expected_str[SIZE];
//static const char* result_str;
static int fd;

void test_setup_1(void) // setup at the start of a test suit
{	
	char *tmp;
	fd = open("test_output.txt", O_RDONLY);
	expected_str[0] = get_next_line(fd);
	expected_str[1] = get_next_line(fd);
	expected_int[0] = 4;
	expected_int[1] = 20;
	expected_int[2] = 12;
	expected_int[3] = 15;
	expected_int[4] = 34;
	expected_str[5] = get_next_line(fd);
	tmp = get_next_line(fd);
	expected_int[5] = atoi(tmp);
	free(tmp);
}

void test_teardown_1(void) // closing down at the end of a test suit
{
	int n = 2;
	int i = 0;
	while (i < n)
	{
		free (expected_str[i]);
		i++;
	}
	close(fd);
}

/* test 01 */
MU_TEST(test_print_char) 
{
	result_int[0] = ft_printf("%c%c%c\n", 'G', 'U', 'I');
	mu_assert_int_eq(expected_int[0], result_int[0]);
	mu_assert_string_eq(expected_str[0], "GUI\n");
}
/* test 02 */
MU_TEST(test_print_str) 
{
	result_int[1] = ft_printf("%s%s%s\n", "Gui", " Coelho", " Oliveira");
	mu_assert_int_eq(expected_int[1], result_int[1]);
	mu_assert_string_eq(expected_str[1], "Gui Coelho Oliveira\n");
}
/* test 03 */
MU_TEST(test_print_percentage) 
{
	result_int[2] = ft_printf("%%%c%s\n", 'P', "ercentage");
	mu_assert_int_eq(expected_int[2], result_int[2]);
}
/* test 04 */
MU_TEST(test_print_int) 
{
	result_int[3] = ft_printf("%d %i%s\n", 42, 37, " anthopos");
	mu_assert_int_eq(expected_int[3], result_int[3]);
}
/* test 05 */
MU_TEST(test_print_uint) 
{
	result_int[4] = ft_printf("Largest unsigned int: %u!\n", INT_MAX + (-1) * INT_MIN);
	mu_assert_int_eq(expected_int[4], result_int[4]);
}
/* test 06 */
MU_TEST(test_print_pointer) 
{
	int a = ft_printf("%p\n", result_int);
	result_int[5] = ft_printf("%p\n", result_int);
	mu_assert_int_eq(a, result_int[5]);
}

MU_TEST_SUITE(mandatorio) // static void test_suit_1(void)
{
	MU_SUITE_CONFIGURE(&test_setup_1, &test_teardown_1); 

	MU_RUN_TEST(test_print_char);
	MU_RUN_TEST(test_print_str); 
	MU_RUN_TEST(test_print_percentage);
	MU_RUN_TEST(test_print_int);
	MU_RUN_TEST(test_print_uint);
	MU_RUN_TEST(test_print_pointer);
}

// --- Tests for bonus part --- 

void test_setup_bonus(void) // setup at the start of a test suit
{
	fd = open("test_output_bonus.txt", O_RDONLY);
	expected_str[0] = get_next_line(fd);
	expected_int[0] = 4;
	expected_int[1] = 11;
	expected_int[2] = 2;
	expected_int[3] = 11;
	expected_int[4] = 4;
	expected_int[5] = 11;
	expected_int[6] = 4;
	expected_int[7] = 10;
	expected_int[8] = 10;
	expected_int[9] = 8;
	expected_int[10] = 14;
	expected_int[11] = 14;
	expected_int[12] = 16;
	expected_int[13] = 14;
	expected_int[14] = 16;
	expected_int[15] = 9;
	expected_int[16] = 14;
	expected_int[17] = 12;
	expected_int[18] = 12;
	expected_int[19] = 33;
	expected_int[20] = 36;
	expected_int[21] = 33;
	expected_int[22] = 9;
	expected_int[23] = 11;
	expected_int[24] = 16;
	expected_int[25] = 8;
	expected_int[26] = 10;
	expected_int[27] = 16;
	expected_int[28] = 19;
	expected_int[29] = 8;
	expected_int[30] = 19;
	expected_int[31] = 11;
	expected_int[32] = 13;
	expected_int[33] = 15;
	expected_int[34] = 11;
	expected_int[35] = 13;
	expected_int[36] = 15;
	expected_int[37] = 11;
	expected_int[38] = 20;
	expected_int[39] = 14;
	expected_int[40] = 10;
	expected_int[41] = 23;
	expected_str[42] = get_next_line(fd);
	expected_str[43] = get_next_line(fd);
	expected_int[42] = atoi(expected_str[43]);
	free(expected_str[43]);
	//expected_str[43] = get_next_line(fd);
	//expected_str[44] = get_next_line(fd);
	//expected_int[43] = atoi(expected_str[43]);
	//free(expected_str[44]);
}

void test_teardown_bonus(void) // closing down at the end of a test suit
{
	int n = 1;
	int i = 0;
	while (i < n)
	{
		free (expected_str[i]);
		i++;
	}
	close (fd);
}

/* test 07 */
MU_TEST(test_alt) 
{
	result_int[0] = ft_printf("%#x\n", 10);
	mu_assert_int_eq(expected_int[0], result_int[0]);
	result_int[1] = ft_printf("%#x\n", 2147483647);
	mu_assert_int_eq(expected_int[1], result_int[1]);
	result_int[2] = ft_printf("%#x\n", 0);
	mu_assert_int_eq(expected_int[2], result_int[2]);
	result_int[3] = ft_printf("%#x\n", -1);
	mu_assert_int_eq(expected_int[3], result_int[3]);
	result_int[4] = ft_printf("%#X\n", 10);
	mu_assert_int_eq(expected_int[4], result_int[4]);
	result_int[5] = ft_printf("%#X\n", UINT_MAX);
	mu_assert_int_eq(expected_int[5], result_int[5]);
	result_int[6] = ft_printf("%#o\n", 10);
	mu_assert_int_eq(expected_int[6], result_int[6]);
}

/* test 08 */
MU_TEST(test_space)
{
	result_int[7] = ft_printf("% d |% i\n", 10, 234);
	mu_assert_int_eq(expected_int[7], result_int[7]);
	result_int[8] = ft_printf("% d |% i\n", -10, -234);
	mu_assert_int_eq(expected_int[8], result_int[8]);
}

/* test 09 */
MU_TEST(test_width)
{
	result_int[9] = ft_printf("%2d |%3i\n", 1, -1);
	mu_assert_int_eq(expected_int[9], result_int[9]);
	result_int[10] = ft_printf("%5d |%6i\n", 1, -1);
	mu_assert_int_eq(expected_int[10], result_int[10]);
	result_int[11] = ft_printf("%+5d |%+6i\n", 1, -1);
	mu_assert_int_eq(expected_int[11], result_int[11]);
	result_int[12] = ft_printf("%+6d |%+7i\n", 2345, -3456);
	mu_assert_int_eq(expected_int[12], result_int[12]);
	result_int[13] = ft_printf("% 5d |% 6i\n", 1, -1);
	mu_assert_int_eq(expected_int[13], result_int[13]);
	result_int[14] = ft_printf("% 6d |% 7i\n", 2345, -3456);
	mu_assert_int_eq(expected_int[14], result_int[14]);
	result_int[15] = ft_printf("%2c |%2c |\n", 'a', 'b');
	mu_assert_int_eq(expected_int[15], result_int[15]);
	result_int[16] = ft_printf("%4s |%5s |\n", "abc", "CASA");
	mu_assert_int_eq(expected_int[16], result_int[16]);
	result_int[17] = ft_printf("%0s |%0s |\n", "abc", "CASA");
	mu_assert_int_eq(expected_int[17], result_int[17]);
	result_int[18] = ft_printf("%1s |%1s |\n", "abc", "CASA");
	mu_assert_int_eq(expected_int[18], result_int[18]);
/*
	result_int[19] = ft_printf("%14p |%14p |\n", &result_int, &expected_int);
	mu_assert_int_eq(expected_int[19], result_int[19]);
	result_int[20] = ft_printf("%15p |%16p |\n", &result_int, &expected_int);
	mu_assert_int_eq(expected_int[20], result_int[20]);
	result_int[21] = ft_printf("%1p |%1p |\n", &result_int, &expected_int);
	mu_assert_int_eq(expected_int[21], result_int[21]);
*/
	result_int[22] = ft_printf("%1o |%1o |\n", 10, 8);
	mu_assert_int_eq(expected_int[22], result_int[22]);
	result_int[23] = ft_printf("%3o |%3o |\n", 10, 8);
	mu_assert_int_eq(expected_int[23], result_int[23]);
	result_int[24] = ft_printf("%#5o |%#6o |\n", 10, 8);
	mu_assert_int_eq(expected_int[24], result_int[24]);
	result_int[25] = ft_printf("%1x |%1x |\n", 10, 18);
	mu_assert_int_eq(expected_int[25], result_int[25]);
	result_int[26] = ft_printf("%2x |%3x |\n", 10, 18);
	mu_assert_int_eq(expected_int[26], result_int[26]);
	result_int[27] = ft_printf("%#5x |%#6x |\n", 10, 18);
	mu_assert_int_eq(expected_int[27], result_int[27]);
	result_int[28] = ft_printf("%3u |%11u |\n", 10, UINT_MAX);
	mu_assert_int_eq(expected_int[28], result_int[28]);
}

/* test 10 */

MU_TEST(test_padding)
{
	result_int[29] = ft_printf("%02d |%03i\n", 1, -1);
	mu_assert_int_eq(expected_int[29], result_int[29]);
	result_int[30] = ft_printf("%03u |%011u |\n", 10, UINT_MAX);
	mu_assert_int_eq(expected_int[30], result_int[30]);
	result_int[31] = ft_printf("%03o |%03o |\n", 10, 20);
	mu_assert_int_eq(expected_int[31], result_int[31]);
	result_int[32] = ft_printf("%#04o |%#04o |\n", 10, 20);
	mu_assert_int_eq(expected_int[32], result_int[32]);
	result_int[33] = ft_printf("%0#5o |%0#5o |\n", 10, 20);
	mu_assert_int_eq(expected_int[33], result_int[33]);
	result_int[34] = ft_printf("%03x |%03x |\n", 10, 20);
	mu_assert_int_eq(expected_int[34], result_int[34]);
	result_int[35] = ft_printf("%#04x |%#04x |\n", 10, 20);
	mu_assert_int_eq(expected_int[35], result_int[35]);
	result_int[36] = ft_printf("%0#5x |%0#5x |\n", 10, 20);
	mu_assert_int_eq(expected_int[36], result_int[36]);
}

/* test 11 */
MU_TEST(test_precision)
{
	result_int[37] = ft_printf("%.3d |%.3i |\n", 1, 12);
	mu_assert_int_eq(expected_int[37], result_int[37]);
	result_int[38] = ft_printf("%.3u |%.12u |\n", 1, UINT_MAX);
	mu_assert_int_eq(expected_int[38], result_int[38]);
	result_int[39] = ft_printf("%.4o |%.5o |\n", 10, 100);
	mu_assert_int_eq(expected_int[39], result_int[39]);
	result_int[40] = ft_printf("%.2x |%.3x |\n", 10, 17);
	mu_assert_int_eq(expected_int[40], result_int[40]);
	result_int[41] = ft_printf("|%20.10d!\n", 10);
	mu_assert_string_eq(expected_str[0], "|          0000000010!\n");
	mu_assert_int_eq(expected_int[41], result_int[41]);
	result_int[42] = ft_printf("|%10.10d!\n", 10);
	mu_assert_string_eq(expected_str[42], "|0000000010!\n");
	mu_assert_int_eq(expected_int[42], result_int[42]);
}

MU_TEST_SUITE(bonus) 
{
	MU_SUITE_CONFIGURE(&test_setup_bonus, &test_teardown_bonus); 

	MU_RUN_TEST(test_alt);
	MU_RUN_TEST(test_space);
	MU_RUN_TEST(test_width);
	MU_RUN_TEST(test_padding);
	MU_RUN_TEST(test_precision);
}

int main(void) 
{
	MU_RUN_SUITE(mandatorio);
	MU_RUN_SUITE(bonus);
	MU_REPORT();
	return MU_EXIT_CODE; // exit conde = minunit_fail 
}
