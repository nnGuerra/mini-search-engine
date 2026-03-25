#include "../include/query/QueryEngine.h"

#include <unordered_map>

QueryEngine::QueryEngine(const InvertedIndex& idx)
    : index(idx) {}

std::vector<SearchResult> QueryEngine::search(const std::vector<std::string>& terms){
    std::unordered_map<int, int> scores;

    for (const auto& term : terms) {
        const auto& postings = index.get_postings(term);

        for (const auto& p : postings) {
            scores[p.doc_id] += p.term_frequency;
        }
    }

    std::vector<SearchResult> results;

    for (const auto& [doc_id, score] : scores) {
        results.push_back({doc_id, score});
    }

    return results;
}