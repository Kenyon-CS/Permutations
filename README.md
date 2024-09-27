# Permutations
C++ program to find permutations

1. Headers Included
  - `iostream`: For input/output operations.
  - `string`: To use `std::string`.
  - `vector`: To store permutations.
  - `algorithm`: For `std::swap` and `std::sort`.
  - `unordered_set`: To handle duplicates efficiently during recursion.
2. Recursive Function generatePermutations
  - Parameters:
    - `std::string& str`: The string being permuted.
    - `int left`: The starting index for permutation.
    - `int right`: The ending index of the string.
    - `std::vector<std::string>& permutations`: A vector to store the permutations.
  - Base Case:
    - When `left == right`, we've reached the end of the string and have a complete permutation. We add it to the permutations vector.
  - Recursive Case:
    - We use an `unordered_set<char>` called `used` to keep track of characters we've already placed at the `left` position to avoid duplicates.
    - We loop from `left` to `right` and swap each character with the character at the `left` index if it hasn't been used yet.
    - After swapping, we recursively call `generatePermutations` with `left + 1` to fix the next character.
    - We perform a swap again to backtrack and restore the original string for the next iteration.
3. Main Function
Input:
Prompts the user to enter a string.
  - Permutation Generation:
    - Calls `generatePermutations` with initial indices `0` and `input.length() - 1`.
  - Sorting:
    - After generating permutations, we sort them to present the results in a consistent order.
  - Output:
    - Prints all unique permutations.
    - Displays the total number of unique permutations.
4. Avoiding Duplicate Permutations
  - By using the `unordered_set<char>` in the recursive function, we ensure that we skip over duplicate characters at each recursion level.
  - This prevents generating duplicate permutations when the input string contains repeating characters.
