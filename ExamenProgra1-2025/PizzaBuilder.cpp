#include "PizzaBuilder.h"
#include "MeatsRepository.h"
#include "IngredientSelector.h"
#include <iostream>
#include "HerbsRepository.h" 
#include "IngredientSelector.h"

PizzaBuilder::PizzaBuilder() {
}

void PizzaBuilder::BuildPizza() {
    SelectHerb();
    std::cout << "=== Pizza Builder ===" << std::endl;
    std::cout << "Let's build your pizza!" << std::endl;

    SelectTomatoes();
    SelectMeats();

    // TODO
    //SelectCheese();
    //SelectHerbs();

    TomatoesRepository tomatoRepo_;
    HerbsRepository herbRepo_{ "herbs.txt" }; // 🌿 Crea el repositorio de hierbas

    std::vector<std::string> availableTomatoes_ = { "roma", "cherry" };
    std::vector<std::string> availableHerbs_ = { "basil", "oregano", "rosemary", "parsley" }; // 🌿 Lista de hierbas

    std::vector<std::string> selectedIngredients_;

    void SelectTomatoes();
  
    //SelectMeats();
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

    // TODO: Reusar esta línea, pero con su propio Repositorio.
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
void PizzaBuilder::SelectHerb() {
    std::cout << "\n--- Selecting Herbs ---" << std::endl;

    // Crea un selector para hierbas, usando tu repositorio y lista de ingredientes disponibles
    IngredientSelector<HerbsRepository> selector(herbsRepo_, availableHerbs_, "herb");

    while (true) {
        selector.DisplayAvailableIngredients();

        std::cout << "\nEnter herb type (or 'done' to finish): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        // Si el usuario termina, salir del bucle
        if (userChoice == "done" || userChoice == "DONE") {
            break;
        }

        // Agregar la hierba seleccionada a la pizza
        selector.AddIngredientToPizza(userChoice, selectedIngredients_);
    }
}

void PizzaBuilder::SelectMeats() {

    std::cout << "\n--- Selecting Meats ---" << std::endl;

    // Usamos el repositorio de carnes
    IngredientSelector<MeatsRepository> selector(meatRepo_, availableMeats_, "meat");

    while (true) {
        selector.DisplayAvailableIngredients();

        std::cout << "\nEnter meat type (or 'done' to finish): ";
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

   // Resolver.    
//}
//
//void PizzaBuilder::SelectMeat() {
//    // Resolver.    
//}