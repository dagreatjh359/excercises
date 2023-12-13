#include <iostream>
#include <unordered_map>
#include <vector>

int romanToInt(const std::string& s) {
    // Dictionary mapping Roman numeral prefixes to their integer values
    std::unordered_map<std::string, int> dictionary1 = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000},
    };
    std::unordered_map<std::string, int> dictionary2 ={
        {"IX", 9},
        {"IV", 4},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
    };

    // Lambda function to find the longest matching prefix in the dictionary
    auto find_prefix = [&dictionary1,&dictionary2](const std::string& str) -> std::string {
        for (const auto& entry : dictionary2) {
            const std::string& key = entry.first;
            if (str.compare(0, key.length(), key) == 0) {
                return key;
            }
        }
        for (const auto& entry : dictionary1) {
            const std::string& key = entry.first;
            if (str.compare(0, key.length(), key) == 0) {
                return key;
            }
        }
        throw std::invalid_argument("Invalid Roman numeral");
    };

    // Vector to store the Roman numeral tokens
    std::vector<std::string> tokens;
    // String to store the remaining part of the input
    std::string remaining = s;

    // Loop to find and process Roman numeral tokens
    while (!remaining.empty()) {
        std::string prefix = find_prefix(remaining);
        tokens.push_back(prefix);
        remaining = remaining.substr(prefix.length());
    }

    // Calculate the result by summing the values of the Roman numeral tokens
    int result = 0;
    for (const std::string& token : tokens) {
        if(token.size() != 1)
            result += dictionary2[token];
        else
            result += dictionary1[token];
    }

    // Return the final result
    return result;
}

// Main function to demonstrate the usage of romanToInt
int main() {
    // Input Roman numeral
    std::string romanNumeral = "CM";
    // Call the romanToInt function to convert the Roman numeral to an integer
    int result = romanToInt(romanNumeral);
    // Output the result
    std::cout << "The integer representation of " << romanNumeral << " is: " << result << std::endl;

    // Return 0 to indicate successful execution
    return 0;
}
