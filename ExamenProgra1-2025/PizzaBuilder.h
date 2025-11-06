#include "MeatsRepository.h"
#include "TomatoesRepository.h"
#include <map>
#include <vector>
#include <string>

class PizzaBuilder {
public:
    PizzaBuilder();
    void BuildPizza();
    void DisplayFinalPizza() const;
    void SelectTomatoes();
    void SelectMeats();

private:
    std::vector<std::string> selectedIngredients_;
    TomatoesRepository tomatoRepo_;
    MeatsRepository meatRepo_;
    std::map<std::string, std::vector<std::string>> availableTomatoes_;
    std::map<std::string, std::vector<std::string>> availableMeats_;
};
