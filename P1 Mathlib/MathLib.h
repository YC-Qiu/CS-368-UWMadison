// Author:          Yucheng Qiu
// Wisc id:         yqiu56
// Description:     This file tests functions in mathlib.h

#ifndef MATHLIB_CS368
#define MATHLIB_CS368
// An enum variable that controls the rule of rounding.
enum RoundingRule {ROUND_DOWN, ROUND_UP, ROUND_TO_ZERO,
    ROUND_AWAY_ZERO, ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_HALF_TO_ZERO, ROUND_HALF_AWAY_ZERO,
    ROUND_HALF_TO_EVEN, ROUND_HALF_TO_ODD};

/**
 * This function converts an int number to its absolute value.
 * @num - the number to convert
 * @return absolute value of num
 */
int absVal(int num);

/**
 * This function converts a float number to its absolute value.
 * @num - the number to convert
 * @return absolute value of num
 */
long absVal(long num);

/**
 * This function converts a double type number to its absolute value.
 * @num - the number to convert
 * @return absolute value of num
 */
double absVal(double num);

/**
 * This function returns the ceiling of the double parameter.
 * @param num - number to find its ceiling integer
 * @return the ceiling of the double parameter.
 */
long ceiling(double num);

/**
 * This function returns the floor of the double parameter.
 * @param num - number to find its ceiling integer
 * @return the floor of the double parameter.
 */
long floor(double num);

/**
 * This function will require you to define an enum datatype 
 * called RoundingRule. The values in the enum are: ROUND_DOWN, ROUND_UP, ROUND_TO_ZERO,
 * ROUND_AWAY_ZERO, ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_HALF_TO_ZERO, ROUND_HALF_AWAY_ZERO,
 * ROUND_HALF_TO_EVEN, ROUND_HALF_TO_ODD. The default RoundingRule should be ROUND_HALF_UP.
 * This function will round the double parameter based on the RoundingRule as follows:
 * ROUND_DOWN (resp. UP) The floor (resp. ceiling) of the double.
 * ROUND_TO_ZERO (resp. AWAY_ZERO) Round to the integer closer to (resp. further from) zero.
 * ROUND_HALF_* Rounds to the nearest integer, e.g. 5.x becomes 5 when x < 0.5 and 6 when
 * x > 0.5, but requires a tie-breaker when x = 0.5. The tie-breaking being:
 * DOWN (resp. UP) Floor (resp. ceiling).
 * TO_ZERO (resp. AWAY_ZERO) Closer to (further from) zero.
 * TO_EVEN (resp. TO_ODD) Round to the nearest even (resp. odd) integer.
 * @param num - the number to round
 * @param rule - the rule round by
 * @return the rounding result
 */
long round(double num, RoundingRule rule);

/**
 * Find the greatest common divisor of the two parameters a and b.
 * @param a,b - two integers
 * @return the greatest common divisor of a and b.
 */
int gcd(int a, int b);

/**
 * This function builds a std::string representation of the int (first) parameter
 * using the unsigned int (second) parameter as the radix (i.e. numerical base). 
 * The string representation of the int will use the digits from 0 - 9 followed
 * by a- z as needed. Negative numbers are prefixed with ’-’. If the radix is greater
 * than 36, return a string containing "Radix too large.". The radix should have a
 * default value of 10. The bool parameter indicates if the returned number contains
 * lower case (true) or upper case (false) letters. This only applies when the radix is
 * less than 37. It should have a default value of true. Remember that this should be
 * done without prebuilt functions like printf or streams.
 * @param num - number to convcert
 * @param radix - numerical base
 * @param IS_LOWER_CASE - if the converted characters are in lower case.
 * @return a string that contains the converted number
 */
std::string toString(int num, unsigned int radix, bool IS_LOWER_CASE);

/**
 * Raises the double value to the long exponent.
 * @param num - base number
 * @param power - power
 * @return the value to the exponent
 */
double pow(double num, long power);
#endif //MATHLIB_CS368