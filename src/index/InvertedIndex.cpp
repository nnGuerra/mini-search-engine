#include "../include/index/InvertedIndex.h"

#include <unordered_map>

void InvertedIndex::add_document(int doc_id,const std::vector<std::string>& tokens) {
    std::unordered_map<std::string, int> term_count;
    for (const auto& token : tokens) {
        term_count[token]++;
    }
    for (const auto& [term, freq] : term_count) {
        index[term].push_back({doc_id, freq});
    }
    total_docs += 1;
}

const std::vector<Posting>& InvertedIndex::get_postings(const std::string& term) const {
    static const std::vector<Posting> empty;
    auto it = index.find(term);
    if (it != index.end()) {
        return it->second;
    }

    return empty;
}

int InvertedIndex::get_total_docs() const {
    return total_docs;
}