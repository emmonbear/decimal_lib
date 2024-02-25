# decimal_lib

Implementation of own decimal.h library.

The russian version of the task can be found in the repository.

This project implements the decimal.h library in the C programming language. This library adds the ability to work with the type "decimal", which is absent in the language standard. This type is critical for, for example, financial calculations, where calculation errors inherent to floating-point types are inadmissible. This project will familiarize you with the tasks of processing financial information, dive into the internal representation of different data types, and reinforce the structural approach.

## Contents

1. [Getting started](#getting-started)
   1. [Install](#install)
   2. [Utilization](#utilization)
2. [Project description](#project-description)
   1. [Description of user type decimal_t](#description-of-user-type-decimal_t)
   2. [Binary representation of decimal_t](#binary-representation-of-decimal_t)
3. [Functions](#functions)
   1. [Arithmetic Operators](#arithmetic-operators)
   2. [Comparison Operators](#comparison-operators)
   3. [Convertors and parsers](#convertors-and-parsers)
   4. [Another functions](#another-functions)
4. [License](#license)

## Getting started

This section contains instructions for getting started with the decimal.h library.

### Install

To start using the decimal.h library, follow these steps:

1. Clone the repository:

```bash
    git clone https://github.com/emmonbear/decimal_lib.git
```

2. Go to the catalog with the project:

```bash
    cd decimal_lib/src
```

3. Build the library using the Makefile command:

```bash
    make decimal.a
```
4. Run tests:

```bash
    make test
```
*The Check.h library must be installed.*


5. Generate a test coverage report:

```bash
    make gcov_report
```
*It is necessary to install gcovr.*

6. Run tests for memory leaks:

```bash
    make valgrind
```
*It is necessary to install valgrind.*

7. Generate documentation:

```bash
    make dvi
```
*The documentation is generated using doxygen. You need to install it beforehand.*

[Contents](#contents)

### Utilization

Once the library has been successfully built, you can start using it in your projects. Include the decimal.h header file in your code and start using the library's functions and data types.

[Contents](#contents)

## Project description

- The library is developed in C11 C language using gcc compiler 
- The library code is located in the src folder in the develop branch  
- Obsolete and obsolete language constructs and library functions are not used.
- When writing the code I followed Google Style
- The solution is designed as a static library (with decimal.h header file).
- The library was developed in accordance with the principles of structural programming
- Full coverage of unit-tests of library functions is prepared with the help of Check library.  
- Unit-tests cover at least 80% of each function  
- Makefile for building the library and tests (with targets all, clean, test, decimal.a, gcov_report).  
- The gcov_report target generates a gcov report as an html page. For this purpose unit-tests are run with gcov flags  
- Use of __int128 type is prohibited
- The defined type supports numbers from -79,228,162,514,264,337,593,543,950,335 to +79,228,162,514,264,337,593,543,950,335.

[Contents](#contents)

### Description of user type decimal_t

The decimal type represents decimal numbers ranging from positive 79,228,162,514,264,337,593,543,950,335 to negative 79,228,162,514,264,337,593,543,950,335. The default value of Decimal is 0. Decimal is suitable for financial calculations that require a large number of significant whole and fractional digits and no rounding errors. This type does not eliminate the need for rounding. Rather, it minimizes the number of errors due to rounding.

When the result of division and multiplication is passed to the rounding method, the result does not suffer from loss of precision.

A Decimal number is a floating-point value consisting of a sign, a numeric value where each digit ranges from 0 to 9, and a scaling factor that indicates the position of the decimal point that separates the integer and fractional parts of the numeric value.

The Decimal binary representation consists of a 1-digit sign, a 96-digit integer, and a scaling factor used to divide the 96-digit integer and indicate which part of it is a decimal fraction. The scaling factor is implicitly equal to the number 10 raised to a degree between 0 and 28. Hence, the binary representation of Decimal is ((-2^96 to 2^96) / 10^(0 to 28)), where -(2^96-1) equals the minimum value and 2^96-1 equals the maximum value.

The scaling factor can also store any finite zeros in Decimal. These end zeros do not affect the value in arithmetic or comparison operations.

[Contents](#contents)

### Binary representation of decimal_t

The binary representation of a Decimal number consists of a 1-bit sign, a 96-bit integer number, and a scaling factor used to divide the integer number and specify what portion of it is a decimal fraction. The scaling factor is implicitly the number 10, raised to an exponent ranging from 0 to 28.

Decimal number can be implemented as a four-element array of 32-bit signed integers (`int bits[4];`).

`bits[0]`, `bits[1]`, and `bits[2]` contain the low, middle, and high 32 bits of the 96-bit integer number accordingly.

`bits[3]` contains the scale factor and sign, and consists of following parts:
- Bits 0 to 15, the lower word, are unused and must be zero.
- Bits 16 to 23 must contain an exponent between 0 and 28, which indicates the power of 10 to divide the integer number.
- Bits 24 to 30 are unused and must be zero.
- Bit 31 contains the sign; 0 meaning positive, and 1 meaning negative.

Note that the bit representation differentiates between negative and positive zero. These values can be treated as being equal in all operations.

Example:

```c
typedef struct 
{
    int bits[4];
} decimal_t;
```

[Contents](#contents)

## Functions
### Arithmetic Operators

| Operator name | Operators  | Function                                                                           | 
| ------ | ------ |------------------------------------------------------------------------------------|
| Addition | + | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Subtraction | - | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Multiplication | * | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) | 
| Division | / | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

The functions return the error code:
- 0 - OK
- 1 - the number is too large or equal to infinity
- 2 - the number is too small or equal to negative infinity
- 3 - division by 0

*Note on the numbers that do not fit into the mantissa:*
- *Bank rounding was used to obtain numbers that do not fit into the mantissa in arithmetic operations (e.g., 79,228,162,514,264,337,593,543,950,335 - 0.6 = 79,228,162,514,264,337,593,543,950,334)*

[Contents](#contents)

### Comparison Operators

| Operator name | Operators  | Function | 
| ------ | ------ | ------ |
| Less than | < | int s21_is_less(s21_decimal, s21_decimal) |
| Less than or equal to | <= | int s21_is_less_or_equal(s21_decimal, s21_decimal) | 
| Greater than | > |  int s21_is_greater(s21_decimal, s21_decimal) |
| Greater than or equal to | >= | int s21_is_greater_or_equal(s21_decimal, s21_decimal) | 
| Equal to | == |  int s21_is_equal(s21_decimal, s21_decimal) |
| Not equal to | != |  int s21_is_not_equal(s21_decimal, s21_decimal) |

Return value:
- 0 - FALSE
- 1 - TRUE

[Contents](#contents)

### Convertors and parsers

| Convertor/parser | Function | 
| ------ | ------ |
| From int  | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| From float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| To int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| To float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Return value - code error:
- 0 - OK
- 1 - convertation error

*Note on the conversion of a float type number:*
- *If the numbers are too small (0 < |x| < 1e-28), an error and a value equal to 0 is returned*
- *If the numbers are too large (|x| > 79,228,162,514,264,337,593,543,950,335) or equal to infinity, error 1* is returned*
- *When processing a number with float type, convert all significant decimal digits contained in it. If such digits are more than 7, the value of the number is rounded to the nearest one that does not have more than 7 significant digits.*

*Note on the conversion from decimal type to int:*
- *If a number of decimal type has a fractional part, it is discarded (e.g. 0.9 is converted to 0).*

[Contents](#contents)

### Another functions

| Description | Function                                                         | 
| ------ |------------------------------------------------------------------|
| Rounds a specified Decimal number to the closest integer toward negative infinity. | int s21_floor(s21_decimal value, s21_decimal *result)            |	
| Rounds a decimal value to the nearest integer. | int s21_round(s21_decimal value, s21_decimal *result)    |
| Returns the integral digits of the specified Decimal; any fractional digits are discarded, including trailing zeroes. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Returns the result of multiplying the specified Decimal value by negative one. | int s21_negate(s21_decimal value, s21_decimal *result)   |

Return value - code error:
- 0 - OK
- 1 - calculation error

[Contents](#contents)

## License

Copyright (c) Moskalev Ilya and Gabilov Pervin. All rights reserved.

Licensed under the [MIT License](./LICENSE).

[Contents](#contents)
