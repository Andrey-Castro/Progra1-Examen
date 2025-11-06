#include "HerbsRepository.h"

HerbsRepository::HerbsRepository(const std::string& dataFilePath) {
    LoadFromFile(dataFilePath);
}

void HerbsRepository::LoadFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + filePath);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string herbName;
        int quantity;

        if (ss >> herbName >> quantity) {
            data_[herbName] = quantity;
        }
    }

    file.close();
}

int HerbsRepository::GetAvailableQuantity(const std::string& herbType) const {
    auto it = data_.find(herbType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de hierba desconocido: " + herbType);
    }
    return it->second;
}

void HerbsRepository::UpdateQuantity(const std::string& herbType, int newQuantity) {
    auto it = data_.find(herbType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de hierba desconocido: " + herbType);
    }
    it->second = newQuantity;
}
