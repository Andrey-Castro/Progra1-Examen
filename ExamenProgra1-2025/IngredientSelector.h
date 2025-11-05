#pragma once
#include <string>
#include <vector>

template<typename TRepository>
class IngredientSelector {
public:
    IngredientSelector(TRepository& repository, const std::vector<std::string>& availableItems, const std::string& ingredientType);

    void DisplayAvailableIngredients();
    bool AddIngredientToPizza(const std::string& ingredientName, std::vector<std::string>& selectedIngredients);

private:
    TRepository& repository_;
    const std::vector<std::string>& availableItems_;
    const std::string ingredientType_;
};