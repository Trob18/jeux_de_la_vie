TARGET = jeu


CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = Cellule.cpp Grille.cpp JeuDeLaVieController.cpp main.cpp Cellule_Suivante.cpp Vue_Console.cpp Vue_Graphique.cpp

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean

