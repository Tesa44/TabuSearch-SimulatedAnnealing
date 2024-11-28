//
// Created by Mateusz on 25.11.2024.
//

#include "App.h"

#include <iostream>

#include "Helpers.h"


void App::run()
{
    try {
        TabuSearch solver(10, 100, 20.0);
        solver.loadFromFile("ftv55.atsp");
        solver.setNeighborhood(3); // Wybór sąsiedztwa: 1 - swap, 2 - insert, 3 - reverse

        int* solution = solver.solve();
        //std::cout << solver.getNumCities() << std::endl;
        std::cout << "Najlepsza trasa: ";
        for (int i = 0; i < solver.getNumCities() + 1; ++i) {
            std::cout << solution[i] << " ";
        }
        std::cout << '\n';
        solver.saveResultToFile("wynik.txt",solution,solver.getNumCities());
        std:: cout << solver.calculateCostFromFile("wynik.txt",solver.getDistanceMatrix(),solver.getNumCities()) << std::endl;
        Helpers helpers;
        //helpers.displayMatrix(solver.getDistanceMatrix(),solver.getNumCities());
        delete[] solution;
    } catch (const std::exception& e) {
        std::cerr << "Błąd: " << e.what() << '\n';
    }
}
