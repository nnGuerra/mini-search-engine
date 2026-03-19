#pragma once

#include <string>
#include <unordered_set>
#include <vector>

class StopwordFilter {
public:
    StopwordFilter();
    std::vector<std::string> filter(const std::vector<std::string>& tokens);
private:
    std::unordered_set<std::string> stopwords;
};