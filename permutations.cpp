#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

// Recursive function to generate permutations
void generatePermutations(std::string& str, int left, int right, std::vector<std::string>& permutations) {
    if (left == right) {
        permutations.push_back(str);
    } else {
        std::unordered_set<char> used;
        for (int i = left; i <= right; ++i) {
            // Skip duplicate characters
            if (used.find(str[i]) != used.end()) {
                continue;
            }
            used.insert(str[i]);

            // Swap the current character with the leftmost character
            std::swap(str[left], str[i]);

            // Recurse for the next character
            generatePermutations(str, left + 1, right, permutations);

            // Backtrack (undo the swap)
            std::swap(str[left], str[i]);
        }
    }
}

int main() {
    std::string input;
    std::cout << "Enter a string to generate its permutations: ";
    std::getline(std::cin, input);

    std::vector<std::string> permutations;

    generatePermutations(input, 0, input.length() - 1, permutations);

    // Sort permutations for consistent ordering
    std::sort(permutations.begin(), permutations.end());

    std::cout << "\nAll unique permutations of the string \"" << input << "\":\n";
    for (const auto& perm : permutations) {
        std::cout << perm << std::endl;
    }

    std::cout << "\nTotal unique permutations: " << permutations.size() << std::endl;

    return 0;
}
