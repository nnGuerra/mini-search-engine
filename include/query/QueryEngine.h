#pragma once

#include <string>
#include <vector>

#include "../index/InvertedIndex.h"

struct SearchResult {
    int doc_id;
    int score;
};

class QueryEngine {
public:
    QueryEngine(const InvertedIndex& index);

    std::vector<SearchResult> search(
        const std::vector<std::string>& terms
    );

private:
    const InvertedIndex& index;
};