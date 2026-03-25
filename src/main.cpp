#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "loader/DocumentLoader.h"
#include "tokenizer/Tokenizer.h"
#include "filter/Filter.h"
#include "index/InvertedIndex.h"
#include "store/DocumentStore.h"
#include "query/QueryEngine.h"

void search(const std::string& query,const Tokenizer& tokenizer,const StopwordFilter& filter,QueryEngine& engine,const DocumentStore& store){
    auto tokens = tokenizer.tokenize(query);
    auto filtered = filter.filter(tokens);

    if (filtered.empty()) {
        std::cout << "Nenhum termo válido.\n";
        return;
    }

    auto results = engine.search(filtered);

    if (results.empty()) {
        std::cout << "Nenhum resultado encontrado.\n";
        return;
    }

    std::sort(results.begin(), results.end(),
        [](const auto& a, const auto& b) {
            return a.score > b.score;
        }
    );

    std::cout << "Resultados para: " << query << "\n\n";
    for (const auto& r : results) {
        auto doc = store.get_document(r.doc_id);

        if (doc) {
            std::cout << doc->filename
                      << " | score: " << r.score
                      << "\n";
        }
    }

    std::cout << "\n";
}

int main() {
    DocumentLoader loader;
    Tokenizer tokenizer;
    StopwordFilter filter;
    InvertedIndex index;
    DocumentStore store;

    auto documents = loader.load_documents("data/docs");

    std::cout << "Indexando documentos...\n\n";

    for (const auto& doc : documents) {
        auto tokens = tokenizer.tokenize(doc.content);
        auto filtered = filter.filter(tokens);

        index.add_document(doc.id, filtered);
        store.add_document(doc.id, doc.filename);

        std::cout << "Indexado: " << doc.filename << "\n";
    }

    std::cout << "\nIndexação concluída.\n\n";
    QueryEngine engine(index);
    std::string query;

    while (true) {
        std::cout << "Digite a busca (ou 'exit'): ";
        std::getline(std::cin, query);

        if (query == "exit") {
            break;
        }

        search(query, tokenizer, filter, engine, store);
    }

    return 0;
}