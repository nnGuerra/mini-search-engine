#pragma once

#include <string>
#include <unordered_map>

struct DocumentMetadata {
    int id;
    std::string filename;
};

class DocumentStore {
public:
    void add_document(int id, const std::string& filename);

    const DocumentMetadata* get_document(int id) const;

private:
    std::unordered_map<int, DocumentMetadata> documents;
};