# Custom Filter Pattern String Questions

This is a collection of **custom filter pattern string questions** designed to develop problem-solving skills. These questions cover different types of string manipulations including frequency, repetition, index-based filters, case-based filters, and more.

## 🔁 **Frequency-Based Filters**

1. **Keep only characters that appear exactly once.**
   - Example:  
     Input: `"aabbccdd"`  
     Output: `" "` (Empty string, since all characters appear more than once.)

2. **Remove characters that appear more than once.**
   - Example:  
     Input: `"aabbcc"`  
     Output: `" "` (All characters appear more than once.)

3. **Keep characters that appear an odd number of times.**
   - Example:  
     Input: `"aabbbcc"`  
     Output: `"a"` (The character 'a' appears once, 'b' appears three times, and 'c' appears twice.)

4. **Remove characters that appear exactly twice.**
   - Example:  
     Input: `"aabbcc"`  
     Output: `" "` (All characters appear exactly twice.)

5. **Retain characters that appear more than twice.**
   - Example:  
     Input: `"aaabbcc"`  
     Output: `"a"` (Only 'a' appears more than twice.)

6. **Return the character that appears the most.**
   - Example:  
     Input: `"aabbbc"`  
     Output: `"b"` (Character 'b' appears 3 times, more than any other character.)

7. **Return the character that appears the least (but at least once).**
   - Example:  
     Input: `"aabbbc"`  
     Output: `"a"` (Character 'a' appears 2 times, which is the least.)

---

## 🔂 **Repetition and Order**

8. **Remove all duplicate characters (keep first occurrence only).**
   - Example:  
     Input: `"aabbcc"`  
     Output: `"abc"`

9. **Remove all duplicate characters (keep last occurrence only).**
   - Example:  
     Input: `"aabbcc"`  
     Output: `"abc"` (This example could be the same, as it’s the last occurrence of each character.)

10. **Keep only characters that appear in sorted order.**  
    - Example:  
      Input: `"acdbef"`  
      Output: `"abef"` (Characters in sorted order: a, b, e, f)

11. **Remove consecutive duplicate characters.**  
    - Example:  
      Input: `"aabbbccaa"`  
      Output: `"abc"`

12. **Keep at most two consecutive duplicates.**  
    - Example:  
      Input: `"aaabbccc"`  
      Output: `"aabbcc"`

13. **Keep only first and last occurrence of each character.**  
    - Example:  
      Input: `"aabbcc"`  
      Output: `"abc"`

14. **Keep only alternate occurrences of characters.**  
    - Example:  
      Input: `"aabbcc"`  
      Output: `"abc"`

---

## 🧬 **Index-Based Patterns**

15. **Keep characters at even indexes.**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"ace"`

16. **Keep characters at odd indexes.**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"bd"`

17. **Keep characters at prime indexes.**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"ac"`

18. **Reverse characters at even positions only.**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"fbdace"`

19. **Shift all vowels to even indexes.**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"aebcdf"`

20. **Interleave characters from front and back (zig-zag).**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"afbecd"`

---

## 🔣 **Case, Type, and Symbol Filters**

21. **Remove all uppercase characters.**  
    - Example:  
      Input: `"aAbBcCdD"`  
      Output: `"abcd"`

22. **Remove all lowercase characters.**  
    - Example:  
      Input: `"aAbBcCdD"`  
      Output: `"ABCD"`

23. **Remove all digits.**  
    - Example:  
      Input: `"a1b2c3"`  
      Output: `"abc"`

24. **Remove all special characters.**  
    - Example:  
      Input: `"abc!@#$%^"`  
      Output: `"abc"`

25. **Keep only alphanumeric characters.**  
    - Example:  
      Input: `"abc!@#123"`  
      Output: `"abc123"`

26. **Keep only vowels or only consonants.**  
    - Example:  
      Input: `"abcde"`  
      Output: `"ae"` (Vowels only)

27. **Keep only symbols (non-alphanumeric).**  
    - Example:  
      Input: `"abc!@#123"`  
      Output: `"!@#"`

28. **Swap case of all characters.**  
    - Example:  
      Input: `"AbCDe"`  
      Output: `"aBcDe"`

---

## 🔍 **Conditional/Custom Logic Filters**

29. **Keep only the first vowel and remove the rest.**  
    - Example:  
      Input: `"education"`  
      Output: `"e"`

30. **Remove all vowels that are followed by a consonant.**  
    - Example:  
      Input: `"education"`  
      Output: `"eua"`

31. **Replace every third character with `*`.**  
    - Example:  
      Input: `"abcdefg"`  
      Output: `"ab*de*f"`

32. **Keep characters that match the next character.**  
    - Example:  
      Input: `"aabbcc"`  
      Output: `"aabbcc"` (No change, as no characters match the next.)

33. **Keep characters that are different from both neighbors.**  
    - Example:  
      Input: `"abacdb"`  
      Output: `"d"`

34. **Remove all characters that repeat anywhere else.**  
    - Example:  
      Input: `"aabbcc"`  
      Output: `" "` (All characters repeat.)

35. **Keep characters in lexicographically increasing order.**  
    - Example:  
      Input: `"acbde"`  
      Output: `"abc"`

---

## 🎯 **Targeted Custom Patterns**

36. **Filter characters based on ASCII parity (even/odd).**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"ace"`

37. **Shift all spaces to the end without changing order.**  
    - Example:  
      Input: `"a b c d "`  
      Output: `"abcd    "` (Spaces are moved to the end.)

38. **Keep only characters that form a palindrome.**  
    - Example:  
      Input: `"abcdcbabcd"`  
      Output: `"abccba"`

39. **Retain characters that alternate in vowel/consonant pattern.**  
    - Example:  
      Input: `"abcde"`  
      Output: `"ace"`

40. **Print string skipping every 2nd and 3rd character repeatedly.**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"ace"`

41. **Keep every 3rd character starting from the 1st.**  
    - Example:  
      Input: `"abcdef"`  
      Output: `"ad"`

42. **Return characters forming an anagram of a given pattern.**  
    - Example:  
      Input: `"abcdef"`  
      Pattern: `"bad"`  
      Output: `"bad"`

43. **Replace only the first 2 vowels with `@`.**  
    - Example:  
      Input: `"education"`  
      Output: `"@d@cation"`

