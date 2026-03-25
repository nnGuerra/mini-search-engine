#include "../include/store/DocumentStore.h"

void DocumentStore::add_document(int id, const std::string& filename) {
    documents[id] = {id, filename};
}

const DocumentMetadata* DocumentStore::get_document(int id) const {
    auto it = documents.find(id);

    if (it != documents.end()) {
        return &it->second;
    }

    return nullptr;
}