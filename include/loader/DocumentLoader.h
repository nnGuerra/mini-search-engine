#pragma once

#include <string>
#include <vector>

struct Document {
    int id;
    std::string filename;
    std::string content;
};

class DocumentLoader {
public:
    std::vector<Document> load_documents(const std::string& directory);
};