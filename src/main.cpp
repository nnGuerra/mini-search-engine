#include <iostream>

#include "loader/DocumentLoader.h"
#include "tokenizer/Tokenizer.h"
#include "filter/Filter.h"
#include "index/InvertedIndex.h"

void search(std::string query,InvertedIndex index){
    auto postings = index.get_postings(query);
    std::cout << "Resultados para: " << query << "\n";
    for (const auto& p : postings) {
        std::cout << "Doc ID: " << p.doc_id
                << " freq: " << p.term_frequency << "\n";
    }
}

int main() {
    DocumentLoader loader;
    Tokenizer tokenizer;
    StopwordFilter filter;
    InvertedIndex index;

    auto documents = loader.load_documents("data/docs");

    for (const auto& doc : documents){
        auto tokens = tokenizer.tokenize(doc.content);
        auto filtered = filter.filter(tokens);

        index.add_document(doc.id, filtered);
    }
    search("motores",index);
    return 0;
}