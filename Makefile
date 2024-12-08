# TARGET = jeu


# CXX = g++
# CXXFLAGS = -std=c++17
# LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# SRC = Cellule.cpp Grille.cpp JeuDeLaVieController.cpp main.cpp Cellule_Suivante.cpp Vue_Console.cpp Vue_Graphique.cpp

# all: $(TARGET)

# $(TARGET):
# 	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# clean:
# 	rm -f $(TARGET)

# .PHONY: all clean


TARGET = jeu

CXX = g++
CXXFLAGS = -std=c++17
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = Cellule.cpp Grille.cpp JeuDeLaVieController.cpp main.cpp Cellule_Suivante.cpp Vue_Console.cpp Vue_Graphique.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
