#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept> 
#include <filesystem>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <random>

std::vector<std::vector<int>> randomizer(int sizeX, int sizeY, int numMines) {
    std::vector<std::vector<int>> output;
    output.resize(sizeX);
    for (int i = 0; i < numMines; i++) {
        
        int xvar = rand() % sizeX;
        output[i].push_back(xvar);
        int yvar = rand() % sizeY;
        output[i].push_back(yvar);
    }
    std::cout << "here";
    return output;

}


//Reads config file to see board state 1st line is X cord, 2 line is Y cord, 3rd is number of mines.
std::vector<int> loadFile(std::string filePath) {
    std::ifstream file;
    std::string temp;
    std::vector<std::string> lines;
    file.open(filePath);
    if (!file) {
        throw std::runtime_error("File Not Found: " + filePath);
    }
    while (std::getline(file, temp)) {
        lines.push_back(temp);
    }
    std::vector<int> mineMine;

    mineMine.push_back(std::stoi(lines[0]));
    std::cout << lines[0] << '\n';
    mineMine.push_back(std::stoi(lines[1]));
    std::cout << lines[1] << '\n';
    mineMine.push_back(std::stoi(lines[2]));
    std::cout << lines[2] << '\n';
    std::cout << mineMine[0];
    std::cout << mineMine[1];
    std::cout << mineMine[2];
    return mineMine;

}
//Reads the board tiles and puts them into a 2D vector try and translate what needs to be done.
std::vector<std::vector<int>> boardReader(std::string filePath) {
    std::ifstream file;
    std::string temp;
    std::vector<std::string> lines;
    file.open(filePath);
    if (!file) {
        throw std::runtime_error("File Not Found: " + filePath);
    }
    while (std::getline(file, temp)) {
        lines.push_back(temp);
    }
    std::vector<std::vector<int>> characters;

    for (int i = 0; i < lines.size(); i++) {
        std::vector<int> tempo;
        for (char c : lines[i]) {
            int mineMine = c - '0';
            tempo.push_back(mineMine);

        }
        characters.push_back(tempo);
    }
    return characters;
}

int main()
{
    int gridX;
    int gridY;
    int mines;
    std::vector<int> randomConfig;
    randomConfig = loadFile("../resource/config.cfg");
    std::vector<std::vector<int>> testBoard1;
    testBoard1 = boardReader("../resource/testboard1.brd");
    std::vector<std::vector<int>> testBoard2;
    testBoard2 = boardReader("../resource/testboard2.brd");
    std::vector<std::vector<int>> testBoard3;
    testBoard3 = boardReader("../resource/testboard3.brd");
    std::vector<std::vector<int>> lotsOMines;
    lotsOMines = boardReader("../resource/lots_o_mines.brd");
    std::vector<std::vector<int>> recursionTest;
    recursionTest = boardReader("../resource/recursion_test.brd");
 
    std::vector<std::vector<int>> startingState;
    //gridX = randomConfig[0];
    //gridY = randomConfig[1];
    //mines = randomConfig[2];
    //startingState = randomizer(gridX, gridY, mines);
    //for (int p = 0; p < startingState.size(); p++) {
    //    std::cout << startingState[p][0];
    //   std::cout << startingState[p][1];
//  }
    
    
    
    /*
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        
        
        
        
        
        
        
        
        
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }




        window.clear();
        sf::CircleShape shape(495.f);
        shape.setFillColor(sf::Color(150, 50, 250));

        // set a 10-pixel wide orange outline
        shape.setOutlineThickness(10.f);
        shape.setOutlineColor(sf::Color(250, 150, 100));
        window.draw(shape);
        window.display();
        
    }
    */
    
}

/*try {

    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }*/