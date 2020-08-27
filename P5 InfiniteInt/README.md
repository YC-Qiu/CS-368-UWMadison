# Description of My Program
## Yucheng (YC) Qiu
### CS @ UW-Madison

The program includes functions that are related to overloaded operators. **InfiniteInt** is a class which represents a non-negative number with an "unlimited" number of digits. Each digit will be stored as a separate int in an STL vector.

# Code Organization
There are 17 operators, 4 constructors, and 1 destructor.

**std::vector<unsigned int>* getDigits()** A getter function for the digits member variable.

**InfiniteInt()** A default constructor for InfiniteInt that sets the value to a default value of 0.

**InfiniteInt(unsigned long long val)** Create a parameterized constructor for InfiniteInt that
sets the starting value to val.

**explicit InfiniteInt(std::vector<unsigned int>* new_digits)** A parameterized constructor
for InfiniteInt that sets the starting value equal to the digits pointed to by new_digits.

**InfiniteInt(const InfiniteInt &obj)** A copy constructor for InfiniteInt that allocates
new memory for digits and then copies each digit from the obj vector to the newly allocated
vector.

**InfiniteInt& operator=(const InfiniteInt &)** Overload the copy-assignment operator.

**~InfiniteInt()** A destructor for InfiniteInt which frees any allocated heap memory.

**operator<< InfiniteInt** An overloaded operator << for ostream and InfiniteInt. This will
display the integer value of the InfiniteInt as if it was a regular unsigned int.

**operator>> InfiniteInt** An overloaded operator >> for istream and InfiniteInt. This operator
will wait for the user to enter a single string of numbers, which will then be parsed into
the vector of digits. If the user enters any characters other than valid digit numbers (0-9) in
their input string, it'll print "Invalid entry" with an endl character to cout and return
without modifying the digits of the InfiniteInt.

**InfiniteInt < InfiniteInt** An overloaded operator < that returns whether or not the value
of the left hand side InfiniteInt is less than the other InfiniteInt.

**InfiniteInt > InfiniteInt** An overloaded operator > that returns whether or not the value
of the left hand side InfiniteInt is greater than the other InfiniteInt.

**InfiniteInt <= InfiniteInt** An overloaded operator <= that returns whether or not the
value of the left hand side InfiniteInt is less than or equal to the other InfiniteInt.

**InfiniteInt >= InfiniteInt** An overloaded operator >= that returns whether or not the
value of the left hand side InfiniteInt is greater than or equal to the other InfiniteInt.

**InfiniteInt == InfiniteInt** An overloaded operator == that returns whether or not the
value of the left hand side InfiniteInt is equal to the other InfiniteInt.

**InfiniteInt != InfiniteInt** An overloaded operator != that returns whether or not the
value of the left hand side InfiniteInt is not equal to the other InfiniteInt.

**InfiniteInt + InfiniteInt** An overloaded operator + that returns a InfiniteInt that is the sum of two InfiniteInts. Make sure to carry out and create a new most significant digit when necessary.

**InfiniteInt - InfiniteInt** An overloaded operator - that returns a InfiniteInt that is the
difference of two InfiniteInts. The result of this subtraction would return an InfiniteInt with a value of 0 if it creates a negative number.

**InfiniteInt += InfiniteInt** An overloaded operator += that adds the right operand and
the left operand and stores the new value in the left operand.

**InfiniteInt -= InfiniteInt** An overloaded operator -= that subtracts the right operand
from the left operand and stores the new value in the left operand.

**++InfiniteInt** An overloaded pre-increment operator, ++, that adds 1 to the current InfiniteInt and returns the changed InfiniteInt.

**--InfiniteInt** An overloaded pre-decrement operator, --, that subtracts 1 from the current
InfiniteInt and returns the changed InfiniteInt.

**InfiniteInt++** An overloaded post-increment operator, ++, that adds 1 to the current InfiniteInt and returns the original InfiniteInt.

**InfiniteInt--** An overloaded post-decrement operator, --, that subtracts 1 from the current
InfiniteInt and returns the original InfiniteInt.

**Compile instruction**
g++ -o demo -c demo.cpp InfiniteInt.h InfiniteInt.cpp