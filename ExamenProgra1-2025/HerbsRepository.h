#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>

class HerbsRepository {
public:
    // Constructor: carga los datos desde el archivo .txt
    HerbsRepository(const std::string& dataFilePath);

    // Retorna la cantidad disponible de una hierba específica
    int GetAvailableQuantity(const std::string& herbType) const;

    // Actualiza la cantidad de una hierba específica
    void UpdateQuantity(const std::string& herbType, int newQuantity);

private:
    mutable std::unordered_map<std::string, int> data_;

    // Carga los datos desde el archivo
    void LoadFromFile(const std::string& filePath);
};
