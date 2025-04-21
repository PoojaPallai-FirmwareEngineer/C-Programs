# Bit Manipulation - Interview Questions & Concepts

Bit manipulation is a powerful technique for optimizing code, especially when working with low-level operations such as setting, clearing, or flipping individual bits. Below is a comprehensive list of bit manipulation questions and the concepts required to solve them, covering basic to advanced topics.

## **Table of Contents**
1. [Basic Concepts](#basic-concepts)
2. [Intermediate Concepts](#intermediate-concepts)
3. [Advanced Concepts](#advanced-concepts)

---

## **Basic Concepts**

1. **Check if a number is even or odd using bit manipulation**
   - **Hint**: Use the `&` operator with `1`.

2. **Swap two numbers without using a temporary variable**
   - **Hint**: Use XOR (`^`) operation.

3. **Set the i-th bit of a number**
   - **Hint**: Use `|` with `1 << i`.

4. **Clear the i-th bit of a number**
   - **Hint**: Use `&` with `~(1 << i)`.

5. **Toggle the i-th bit of a number**
   - **Hint**: Use `^` with `1 << i`.

6. **Check if the i-th bit is set**
   - **Hint**: Use `&` with `1 << i`.

7. **Turn off the rightmost set bit**
   - **Hint**: Use `num & (num - 1)`.

8. **Find the rightmost set bit of a number**
   - **Hint**: Use `num & -num`.

9. **Reverse the bits of an integer**
   - **Hint**: Shift the bits from left to right.

10. **Find if two numbers have opposite signs**
    - **Hint**: Use XOR (`^`), as XORing numbers with different signs gives a negative result.

---

## **Intermediate Concepts**

11. **Count the number of set bits in an integer (Hamming Weight)**
    - **Hint**: Use a loop with `n & (n - 1)` to count the 1s.

12. **Check if a number is a power of two**
    - **Hint**: A power of two has only one set bit, use `(n & (n - 1)) == 0`.

13. **Find the only non-repeating element in an array where every other element repeats twice**
    - **Hint**: Use XOR to cancel out the repeating numbers.

14. **Find two non-repeating elements in an array where every other element repeats twice**
    - **Hint**: Use XOR to differentiate the two non-repeating numbers.

15. **Find the number that appears only once in an array where every other element appears three times**
    - **Hint**: Track counts of bits at every position.

16. **Find the position of the most significant set bit**
    - **Hint**: Use logarithmic techniques or bit shifts.

17. **Determine if a number is a palindrome in its binary form**
    - **Hint**: Reverse the bits and compare.

18. **Add two numbers without using arithmetic operators**
    - **Hint**: Use XOR for sum and AND for carry, repeat until carry becomes 0.

19. **Find the XOR of all numbers from 1 to n**
    - **Hint**: Use the pattern formed by XOR from 1 to n.

20. **Find the Hamming distance between two integers**
    - **Hint**: XOR the two numbers and count the set bits.

21. **Check if a number has alternating 0 and 1 bits (Binary Alternating Bits)**
    - **Hint**: Use XOR and check if the result is all `1`s.

---

## **Advanced Concepts**

22. **Multiply a number by 7 using bit manipulation**
    - **Hint**: Use shifts, i.e., `(x << 3) - x`.

23. **Divide a number by 2 without using the division operator**
    - **Hint**: Right shift the number by 1 (`num >> 1`).

24. **Implement a bitwise AND of numbers in a given range `[m, n]`**
    - **Hint**: Clear the rightmost bits that differ between `m` and `n`.

25. **Find the next power of 2 greater than or equal to a given number**
    - **Hint**: Use a bit manipulation trick to shift bits.

26. **Convert a decimal number to binary without using a built-in method**
    - **Hint**: Use division and modulus operations in a loop.

27. **Check if a number is a multiple of 3 using bit manipulation**
    - **Hint**: Sum bits in odd and even positions, check the difference.

28. **Determine if a number is divisible by 4 using bit manipulation**
    - **Hint**: Check the last two bits using `n & 3 == 0`.

29. **Find the parity (even or odd number of 1s) of a number**
    - **Hint**: XOR all bits and check the result.

30. **Check if a number is a sparse number (no two consecutive 1s in binary representation)**
    - **Hint**: Use `num & (num >> 1)`.

31. **Find the largest power of two less than or equal to a given number**
    - **Hint**: Use a technique to clear all bits except the most significant one.

32. **Find the number of bits needed to convert one number to another**
    - **Hint**: XOR the two numbers and count the set bits.
    **Find the minimum number of bit flips required to convert `A` to `B`**
    - **Hint**: XOR `A` and `B`, then count the set bits.

33. **Count the number of trailing zeros in a binary number**
    - **Hint**: Use `num & -num` to isolate the rightmost set bit.

34. **Calculate the logarithm base 2 of a number using bitwise operations**
    - **Hint**: Count the shifts needed to reduce the number to 1.

35. **Implement a function to swap all odd and even bits in an integer**
    - **Hint**: Mask odd and even bits, shift and combine them.

36. **Rotate bits of a number to the left or right**
    - **Hint**: Use shifts and `|` to wrap bits around.

37. **Merge two numbers by combining their bits using bitwise operations**
    - **Hint**: Use shifts and masks to merge specific bit segments.

38. **Find the closest integer with the same number of 1s in binary representation**
    - **Hint**: Swap the lowest set bit and the rightmost unset bit.

39. **Generate all possible subsets of a set using bitwise manipulation**
    - **Hint**: Use the binary representation of numbers to represent subsets.

40. **Create a function to count how many bits are set to 1 in an integer**
    - **Hint**: Implement popcount using bitwise tricks. -- "The PDF is available since it covers four methods we can use."

41. **Implement a method to reverse only a portion of the bits within a number**
    - **Hint**: Mask the portion, reverse it, and merge back.

42. **Subtract two numbers using only bitwise operations**
    - **Hint**: Use two’s complement and addition logic.

---

### **Conclusion**

Mastering these bit manipulation techniques will help you solve complex problems efficiently, and they are often asked in technical interviews, especially for system programming, embedded systems, and competitive programming.

