#pragma once
#include <vector>
#include <string>
#include "TomatoesRepository.h"
#include "IngredientSelector.h"
#include "HerbsRepository.h" 

class PizzaBuilder {
public:
    PizzaBuilder();

    void BuildPizza();
    void DisplayFinalPizza() const;

private:
    void SelectTomatoes();
    void SelectCheese();
    void SelectHerb();
    void SelectMeat();

    TomatoesRepository tomatoRepo_;
    std::vector<std::string> selectedIngredients_;
    HerbsRepository herbsRepo_{ "herbs.txt" };

    const std::vector<std::string> availableTomatoes_ = {"Cherry", "Roma", "Beefsteak", "Heirloom", "Grape"};
    const std::vector<std::string> availableCheeses_ = {"Mozzarella", "Cheddar", "Parmesan", "Cream Cheese", "Gouda", "Blue Cheese", "Feta"};
    const std::vector<std::string> availableHerbs_ = { "Basil", "Oregano", "Rosemary", "Parsley", "Thyme", "Mint" };
};