#include <iostream>

#include "loader/DocumentLoader.h"
#include "tokenizer/Tokenizer.h"

int main() {
    DocumentLoader loader;
    Tokenizer tokenizer;

    auto documents = loader.load_documents("data/docs");

    for (const auto& doc : documents) {
        std::cout << "Documento: " << doc.filename << "\n";

        auto tokens = tokenizer.tokenize(doc.content);

        for (const auto& token : tokens) {
            std::cout << token << " ";
        }

        std::cout << "\n\n";
    }

    return 0;
}