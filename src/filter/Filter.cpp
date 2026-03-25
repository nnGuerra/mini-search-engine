#include "..\include\filter\Filter.h"

StopwordFilter::StopwordFilter() {
    stopwords = {
        "the", "and", "of", "to", "in", "a", "is", "are", "on", "for",
        "o", "a", "de", "do", "da", "em", "para", "com",
    };
}

std::vector<std::string> StopwordFilter::filter(const std::vector<std::string>& tokens ) const {
    std::vector<std::string> result;

    for (const auto& token : tokens) {
        if (stopwords.find(token) == stopwords.end()) {
            result.push_back(token);
        }
    }

    return result;
}