#include "Vue_Console.h"






void Vue_Console::affichage(const vector<vector<int>>& grid) {
        for (const auto& row : grid) {
            for (int cell : row) {
                cout << (cell ? "#" : ".") << " ";
            }
            cout << endl;
        }
        cout << endl;
    }