/*
 * CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
    "jode4557",
   /* Student name 1: Replace with the full name of first team member */
   "Jordan Deitsch",
   /* Login ID 1: Replace with the login ID of first team member */
   "jode4557",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "",
   /* Login ID 2: Login ID of the second team member */
   ""
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//
// 15 problems, 40 points
// 2 - rating 1
// 5 - rating 2
// 4 - rating 3
// 4 - rating 4
// rating 1
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  /*
   * To perform ~(x|y), the following results are desired:
   * 0 from (x,y) = (1,1), (1,0), (0,1)
   * 1 from (x,y) = (0,0)
   * This is achieved by (x&y) if x and y are inverted,
   * therefore use (~x & ~y)
  */
  return (~x & ~y);
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /*
   * Maximum number at all 1's except for left-most bit (011...111) for positivity
   * Therefore invert 0 to get all 1's, then right shift 31 and invert again
  */
  return ~(1<<31);
}
// rating 2
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /* Begin by finding the absolute value of x (used code from abs(int x))
   * Shift this absolute value by n-1 bits
   * Result should be zero if the number would fit in n bits
   * Corner case: if x equals the minimum possible number allowed by n bits
   * Catch this corner case by checking for equality with minimum value
   */

  // Code to find abs(x), see explanation in later function
  int neg1 = ~0;
  int negX = (~x) + 1;
  int signX = x>>31;
  int absX = (x & (~signX)) + (negX & signX);

  // Find result of shifting now positive value of x n-1 bits
  int nMin1 = n + neg1;
  int temp = absX>>nMin1;

  // to catch corner case of x equal to minimum possible number of n bits
  int low = (neg1)<<nMin1;
  int exact = !(low ^ x);

  // add 1 to result if x is equal to the minum possible for n bits
  return !(temp) + exact;
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /* Must first determine the sign of the number
   * Negative numbers must be rounded up, not down (x>>n always floors)
   * Determine if any of the divisions will require rounding
   * This is any of the shifts from 1 - n that have a non-zero remainder
   * If this remainder exists, add it on to negative results after the division
   */
  int sign = !((x>>31) + 1);  // 0 if positive, 1 if negative
  int temp = ~((~0)<<n);      // 00 ... 011  (zeros with n 1's)
  int rem = !(!(temp & x));   // 0 if no rounding, 1 if needs rounding
  return ((x>>n) + (sign & rem));
}
/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  /*
   * must first check if each bit in x is equal to its corresponding bit in y
   * if all are equal, the result is 0...000, which is desired
   * if not all equal, result is something random, force it to zero with !()
   * use !() once more to convert back to 0 for true, 1 for false
   */
  int temp = !(x ^ y);
  return (!temp);
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
  /*
   * First create truth table for (~x & y), (x & ~y)
   * Write table now for and of inverses: ~(~x & y) & ~(x & ~y)
   * Finally, write table for the inverse of the above
   * This yeilds the desired table for the x^y with only ~ and &
   */
  int temp1 = ~(~x & y);
  int temp2 = ~(x & ~y);
  return ~(temp1 & temp2);
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  /*
   * First must find state of least significant bit with x & 1
   * Then set temporary result to all 1's with ~0
   * Add current state of LSB, will wrap to all zeros iif LSB = 1
   * Switch all bits with ~() for final result
   */
  int result = ~0;
  int LSB = x & 1;
  return ~(result + LSB);
}
// rating 3
/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  /* Begin by creating a mask for the first byte, 00..0011111111
   * Separate original bytes with the mask and proper shifts
   * Set bytes to new locations with proper shifts
   * Use inclusive or (|) to combine all bytes into result
   */
  int mask = ~((~0)<<8);
  int a = x & mask;
  int b = x & (mask << 8);
  int c = x & (mask << 16);
  int d = x & (mask << 24);

  int newA = a << 24;
  int newB = b << 8;
  int newC = c >> 8;
  int newD = (d >> 24) & mask; // incase negative

  return (newA | newB | newC | newD);
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int logicalShift(int x, int n) {
  /*
   * Begin by shifting one right, will be used to only pad with zeros
   * Calculate remaining number of shifts as n-1 = n + (~0)
   * Set MSB of number to zero, so all remaining padding is zeros
   * Shift remining number of bits (n-1)
   */
  int temp = x>>1;
  int nMin1 = n + (~0);
  temp = ~(1<<31) & temp;

  return (temp >> nMin1);
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /* Begin by finding the difference between x and y
   * If difference > 0, then x > y, as x - y >0
   * If equal, set difference to -1 (to avoid confusion)
   * Check for possible cases of wrapping
   * Occurs when x>0, y<0, diff<0 (diff should be > 0)
   * Also when x<0, y>0, diff>0 (diff should be < 0)
   * Use these exceptions to correct difference if either are true
   */
  int diff;
  int temp;
  int signX;
  int signY;
  int signDiff;
  int wrap1;
  int wrap2;
  int result;

  diff = x + ((~y) + 1);  // add x + (-y)
  temp = (~(!diff)) + 1;  // if diff = 0, temp = -1, else temp = 0
  diff = diff + temp;         // if diff = 0, set to -1, else diff unchanged

  signX = !(x>>31);
  signY = !(y>>31);
  signDiff = !(diff>>31);

  wrap1 = (signX) & (!signY) & (!signDiff);  // 1 = wrapped to negative
  wrap2 = (!signX) & (signY) & (signDiff);   // 1 = wrapped to positive
  result = signDiff + wrap1 + ((~wrap2) + 1);

  return result;
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
  /*
   * Begin with -1 (all 1's)
   * Shift all ones over by lowest bit first: 11111000
   * Then shift all ones over by highest bit: 11100000
   * Must shift by one more bit (cannot do it immediately if highbit = 32)
   * Invert bits for the high bit shift: 00111111
   * Simply & the two numbers, all overlapping 1's will create mask
   */
  int temp1 = (~0) << lowbit;
  int temp2 = (~0) << (highbit);
  temp2 = ~(temp2<<1);
  return (temp1 & temp2);
}
// rating 4
/*
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  /*
   * Begin by finding the negative value of the current x
   * Note: do not know which, x or negX, is actually negative
   * Determine sign of each x, negX
   * Set signs such that if positive, all 0's, negative, all 1's
   * Finally & the value with sign (x & signX), add these & statements
   * This will effectively zero out the negative and add the positive
   */
  int negX = (~x) + 1;
  int signX = x>>31;  // 11...111 if negative, 00...000 if non-negative
  return (x & (~signX)) + (negX & signX);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* Begin by creating a mask with 1's only at the right edge of each byte
   * Use shifts and & to check for 1's in each element of each byte
   * Add up all eight numbers that contain 1's at edge of byte if a 1 existed
   * Now each byte contains the number of 1's in that byte
   * Use a second mask to right shift each byte down to the edge
   * Add up each byte after it has been shifted for final answer
   */

  int mask1;
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  int h;
  int temp;
  int mask2;
  int A;
  int B;
  int C;
  int D;
  int result;


  mask1 = (1) | (1<<8);
  mask1 = mask1 | (mask1<<16);  // 1's at end of every byte: [00000001]

  a = (x) & mask1;
  b = (x>>1) & mask1;
  c = (x>>2) & mask1;
  d = (x>>3) & mask1;
  e = (x>>4) & mask1;
  f = (x>>5) & mask1;
  g = (x>>6) & mask1;
  h = (x>>7) & mask1;
  temp = a + b + c + d + e + f + g + h;

  mask2 = ~((~0)<<8);      // only last byte is 1: 00...0011111111
  A = mask2 & temp;
  B = mask2 & (temp>>8);
  C = mask2 & (temp>>16);
  D = mask2 & (temp>>24);

  result = (A + B + C + D);
  return result;
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {
  /*
   * Begin by flipping sign on x, zero remains zero, with (~x)+1
   * Ensure that MSB is 1 only if x was originally zero
   * Shift MSB to ensure that all bits are 0 or 1
   * Now if non-zero, temp = -1, if zero, temp = 0
   * Flip previous statement so if non-zero, temp = 0
   * Return temp + 1
   */
  int temp = (~x) + 1;
  temp = temp | x;
  return (~(temp>>31) + 1);
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
  /* Could use previous function methods (modified), but this way is fun!
   * For each shift any ones are copied into the next chunk
   * By the temp<<16, any existing 1/s are copied to the MSB
   * Use temp>>31 to set all bits to 1 (only if a 1 originally existed)
   * Add one to result, so -1 is now 0 and 0 is 1, as desired
   */
  int temp = x | (x<<1);
  temp = temp | (temp<<2);
  temp = temp | (temp<<4);
  temp = temp | (temp<<8);
  temp = temp | (temp<<16);
  return ((temp>>31) + 1);
  return 2;
}
