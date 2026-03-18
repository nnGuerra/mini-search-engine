#pragma once

#include <string>
#include <vector>

class Tokenizer {
public:
    std::vector<std::string> tokenize(const std::string& text);

private:
    std::string normalize(const std::string& text);
};