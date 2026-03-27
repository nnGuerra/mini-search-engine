#pragma once

#include <string>
#include <unordered_map>
#include <vector>

struct Posting {
    int doc_id;
    int term_frequency;
};

class InvertedIndex {
public:
    int get_total_docs() const;
    void add_document(int doc_id,const std::vector<std::string>& tokens);
    const std::vector<Posting>& get_postings(const std::string& term) const;
    int total_docs = 0;

private:
    std::unordered_map<
        std::string,
        std::vector<Posting>
    > index;
};