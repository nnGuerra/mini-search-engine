#include <iostream>
#include "loader/DocumentLoader.h"

int main() {
    DocumentLoader loader;

    auto documents = loader.load_documents("data/docs");
    
    std::cout << "Documentos carregados:\n\n";
    
    for (const auto& doc : documents) {
        std::cout << doc.filename << std::endl;
    }
    
    return 0;
}