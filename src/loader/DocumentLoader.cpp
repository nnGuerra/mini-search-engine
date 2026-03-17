#include "include/loader/DocumentLoader.h"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

std::vector<Document> DocumentLoader::load_documents(const std::string& directory) {
    
    std::vector<Document> documents;
    int id = 0;

    for (const auto& entry : fs::directory_iterator(directory)) {

        if (entry.path().extension() == ".txt") {

            std::ifstream file(entry.path());
            if (!file.is_open()) {
                std::cerr << "Não foi possivel abrir o arquivo: " << entry.path() << std::endl;
                continue;
            }

            std::string content(
                (std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>()
            );

            Document doc;
            doc.id = id++;
            doc.filename = entry.path().filename().string();
            doc.content = content;

            documents.push_back(doc);
        }
    }

    return documents;
}