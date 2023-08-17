#include <stdio.h>
#include "3-calc.h"
/**
 * op_add - returns the sum of a and b
 * @a: 1st param
 * @b: 2nd param
 * Return: sum
 */
int op_add(int a, int b)
{
	return (a + b);
}
/**
 * op_sub - returns the difference of a and b
 * @a: 1st param
 * @b: 2nd param
 * Return: difference
 */
int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - returns the product of a and b
 * @a: 1st param
 * @b: 2nd param
 * Return: product
 */
int op_mul(int a, int b)
{
	return (a * b);
}
/**
 * op_div - returns the division of a by b
 * @a: 1st param
 * @b: 2nd param
 * Return: division
 */
int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - returns the remainder of the division of a by b
 * @a: 1st param
 * @b: 2nd param
 * Return: modulo
 */
int op_mod(int a, int b)
{
	return (a % b);
}
