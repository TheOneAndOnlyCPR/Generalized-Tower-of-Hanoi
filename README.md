# Generalized-Tower-of-Hanoi
Generalized Tower of Hanoi solver - Takes any starting and ending configuration and outputs the steps needed to rearrange the tower

Most likely incredibly inefficient, and there are definitely better ways to do this, but it works.

Usage should be self-explanatory, use the C++ compiler of your choice.
The program will ask for 2 inputs, the first being the initial position of the rings in the tower, and the second being the desired final
position of the rings in the tower. Both strings should be the same length and use only A, B, and C to define the configuration.

For example, valid inputs include AAA, CBA, AABBCC, and CBBACBA. Tower CBA would have the smallest ring on A, the second ring on B, and the largest ring on C.
