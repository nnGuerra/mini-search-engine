#include "../include/tokenizer/Tokenizer.h"

#include <sstream>
#include <algorithm>
#include <cctype>

std::string Tokenizer::normalize(const std::string& text) const{
    std::string result;

    for (char c : text) {
        if (std::isalnum(c) || std::isspace(c)) {
            result += std::tolower(c);
        }
    }

    return result;
}

std::vector<std::string> Tokenizer::tokenize(const std::string& text) const{
    std::vector<std::string> tokens;

    std::string clean = normalize(text);

    std::istringstream stream(clean);
    std::string word;

    while (stream >> word) {
        tokens.push_back(word);
    }

    return tokens;
}