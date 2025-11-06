#include "PizzaBuilder.h"
#include <iostream>
#include "CheeseRepository.h"
#include <stdexcept>
#include <string>

PizzaBuilder::PizzaBuilder() {
}

void PizzaBuilder::BuildPizza() {
    std::cout << "=== Pizza Builder ===" << std::endl;
    std::cout << "Let's build your pizza!" << std::endl;

    SelectTomatoes();   // tomates
    SelectCheese();     // queso
    //SelectHerbs();    // hierbas (futuro)
    //SelectMeats();    // carnes (futuro)
}

void PizzaBuilder::DisplayFinalPizza() const {
    std::cout << "\n=== Your Pizza ===" << std::endl;
    if (selectedIngredients_.empty()) {
        std::cout << "No ingredients selected." << std::endl;
    }
    else {
        std::cout << "Your pizza contains:" << std::endl;
        for (const auto& ingredient : selectedIngredients_) {
            std::cout << "- " << ingredient << std::endl;
        }
    }
}

void PizzaBuilder::SelectTomatoes() {
    std::cout << "\n--- Selecting Tomatoes ---" << std::endl;

    IngredientSelector<TomatoesRepository> selector(tomatoRepo_, availableTomatoes_, "tomato");

    while (true) {
        selector.DisplayAvailableIngredients();

        std::cout << "\nEnter tomato type (or 'done' to finish): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "done" || userChoice == "DONE") {
            break;
        }

        selector.AddIngredientToPizza(userChoice, selectedIngredients_);
    }
}

void PizzaBuilder::SelectCheese() {
    std::cout << "\n--- Selecting Cheese ---" << std::endl;

    IngredientSelector<CheeseRepository> selector(cheeseRepo_, availableCheeses_, "cheese");

    while (true) {
        selector.DisplayAvailableIngredients();

        std::cout << "\nEnter cheese type (or 'done' to finish): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "done" || userChoice == "DONE") {
            break;
        }

        selector.AddIngredientToPizza(userChoice, selectedIngredients_);
    }
}

 

    

    




// TODO:  Crear cada uno su parte. ☝️ toma el ejemplo de  SelectTomatoes y crea tu propia implementación.


//void PizzaBuilder::SelectCheese() {
// // Resolver.    
//}
//
//void PizzaBuilder::SelectHerb() {
//    // Resolver.    
//}
//
//void PizzaBuilder::SelectMeat() {
//    // Resolver.    
//}