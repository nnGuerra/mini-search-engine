#include <iostream>

#include "loader/DocumentLoader.h"
#include "tokenizer/Tokenizer.h"
#include "filter/Filter.h"

int main() {
    DocumentLoader loader;
    Tokenizer tokenizer;
    StopwordFilter filter;

    auto documents = loader.load_documents("data/docs");

    for (const auto& doc : documents) {
        std::cout << "Documento: " << doc.filename << "\n";

        auto tokens = tokenizer.tokenize(doc.content);
        auto filtered = filter.filter(tokens);

        for (const auto& token : filtered) {
            std::cout << token << " ";
        }

        std::cout << "\n\n";
    }
    return 0;
}