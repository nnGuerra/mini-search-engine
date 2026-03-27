#include "../include/query/QueryEngine.h"

#include <unordered_map>
#include <cmath>

QueryEngine::QueryEngine(const InvertedIndex& idx)
    : index(idx) {}

std::vector<SearchResult> QueryEngine::search(const std::vector<std::string>& terms) {
    std::unordered_map<int, double> scores;
    int total_docs = index.get_total_docs();
    for (const auto& term : terms) {
        const auto& postings = index.get_postings(term);
        if (postings.empty()) continue;
        int df = postings.size();
        double idf = std::log(1.0 + (double) total_docs / (1 + df));
        for (const auto& p : postings) {
            double tf = p.term_frequency;
            scores[p.doc_id] += tf * idf;
        }
    }
    std::vector<SearchResult> results;
    for (const auto& [doc_id, score] : scores) {
        results.push_back({doc_id, score});
    }

    return results;
}