# Description of My Program
## Yucheng (YC) Qiu
### CS @ UW-Madison
This programs implements many math functions such as pow(), gcd(), ceiling(), etc...

**E absVal(E)** This function should take a number and return the absolute value of that number, where E is the data type. Your library should have an int, long, and double version.

**long ceiling(double)** This function returns the ceiling of the double parameter.

**long floor(double)** This function returns the floor of the double parameter.

**long round(double, RoundingRule)** This function will require you to define an enum datatype called RoundingRule. The values in the enum are: ROUND_DOWN, ROUND_UP, ROUND_TO_ZERO,
ROUND_AWAY_ZERO, ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_HALF_TO_ZERO, ROUND_HALF_AWAY_ZERO,
ROUND_HALF_TO_EVEN, ROUND_HALF_TO_ODD. The default RoundingRule should be ROUND_HALF_UP.
This function will round the double parameter based on the RoundingRule as follows:
ROUND_DOWN (resp. UP) The floor (resp. ceiling) of the double.
ROUND_TO_ZERO (resp. AWAY_ZERO) Round to the integer closer to (resp. further from) zero.
ROUND_HALF_* Rounds to the nearest integer, e.g. 5.x becomes 5 when x < 0.5 and 6 when
x > 0.5, but requires a tie-breaker when x = 0.5. The tie-breaking being:
DOWN (resp. UP) Floor (resp. ceiling).
TO_ZERO (resp. AWAY_ZERO) Closer to (further from) zero.
TO_EVEN (resp. TO_ODD) Round to the nearest even (resp. odd) integer.
double pow(double, long) Raises the double value to the long exponent.
std::string toString(int num, unsigned int radix, bool) This function builds a std::string
representation of the int (first) parameter using the unsigned int (second) parameter as the
radix (i.e. numerical base). The string representation of the int will use the digits from 0 - 9
followed by a - z as needed. Negative numbers are prefixed with ’-’.
If the radix is greater than 36, return a string containing "Radix too large.". The radix
should have a default value of 10.
The bool parameter indicates if the returned number contains lower case (true) or upper case
(false) letters. This only applies when the radix is less than 37. It should have a default
value of true.
Remember that this should be done without prebuilt functions like printf or streams.
int gcd(int, int) Return the greatest common divisor of the two parameters.E absVal(E) This function should take a number and return the absolute value of that number,
where E is the data type. Your library should have an int, long, and double version.

**long ceiling(double)** This function returns the ceiling of the double parameter.

**long floor(double)** This function returns the floor of the double parameter.

**long round(double, RoundingRule)** This function will require you to define an enum datatype
called RoundingRule. The values in the enum are: ROUND_DOWN, ROUND_UP, ROUND_TO_ZERO,
ROUND_AWAY_ZERO, ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_HALF_TO_ZERO, ROUND_HALF_AWAY_ZERO,
ROUND_HALF_TO_EVEN, ROUND_HALF_TO_ODD. The default RoundingRule should be ROUND_HALF_UP.
This function will round the double parameter based on the RoundingRule as follows:

ROUND_DOWN (resp. UP) The floor (resp. ceiling) of the double.

ROUND_TO_ZERO (resp. AWAY_ZERO) Round to the integer closer to (resp. further from) zero.

ROUND_HALF_* Rounds to the nearest integer, e.g. 5.x becomes 5 when x < 0.5 and 6 when
x > 0.5, but requires a tie-breaker when x = 0.5. The tie-breaking being:

DOWN (resp. UP) Floor (resp. ceiling).

TO_ZERO (resp. AWAY_ZERO) Closer to (further from) zero.

TO_EVEN (resp. TO_ODD) Round to the nearest even (resp. odd) integer.

**double pow(double, long)** Raises the double value to the long exponent.

**std::string toString(int num, unsigned int radix, bool)** This function builds a std::string
representation of the int (first) parameter using the unsigned int (second) parameter as the
radix (i.e. numerical base). The string representation of the int will use the digits from 0 - 9

followed by a - z as needed. Negative numbers are prefixed with ’-’.

If the radix is greater than 36, return a string containing "Radix too large.". The radix
should have a default value of 10.

The bool parameter indicates if the returned number contains lower case (true) or upper case
(false) letters. This only applies when the radix is less than 37. It should have a default
value of true.

Remember that this should be done without prebuilt functions like printf or streams.

**int gcd(int, int)** Return the greatest common divisor of the two parameters.



