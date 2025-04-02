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
#include <ctime>
#include <chrono>
#include <thread>
#include <set>
#include "Tile.h"










//Set Random cordinates for mines.
std::vector<std::vector<int>> randomizer(int sizeX, int sizeY, int numMines) {
    std::vector<std::vector<int>> output;
    output.resize(numMines);
    std::cout << '\n';
    srand(time(0));
    for (int t = 0; t < numMines; t++) {
        int x = rand() % sizeX;
        int y = rand() % sizeY;
        output[t].push_back(x);
        output[t].push_back(y);
        std::cout << output[t][0] << ", " << output[t][1] << '\n';
    }
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
    mineMine.push_back(std::stoi(lines[1]));
    mineMine.push_back(std::stoi(lines[2]));
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
    std::vector<std::vector<int>> startingState;
    int gridX;
    int gridY;
    int mines;
    std::vector<int> randomConfig;
    std::string gameOn = "game";
    randomConfig = loadFile("../resource/config.cfg");
    
    gridX = randomConfig[0];
    gridY = randomConfig[1];
    mines = randomConfig[2];
    
    
    
    
    std::vector<std::vector<Tiles>> board;
    board.resize(gridX);
    startingState = randomizer(gridX, gridY, mines);
    for (int f = 0; f < gridX; f++) {
        for (int j = 0; j < gridY; j++) {
            
            bool show = false;
            int prox = 0;
            bool flag = false;
            

            //Iterates through the randomized minefield to set the tiles actively to true if its a mine or false if not.
            
            bool boomBoom = false;
            for (int n = 0; n < mines; n++) {
                if ((f == startingState[n][0]) && (j == startingState[n][1])) {
                    boomBoom = true;

                }
                
            }
            Tiles tile(boomBoom, show, prox, flag);
            board[f].push_back(tile);
        }
    }
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
    /*
    sf::Texture debug("debug.png");
    sf::Texture digits("digits.png");
    sf::Texture win("face_win.png");
    sf::Texture lose ("face_lose.png");
    sf::Texture reset("face_happy.png");
    sf::Texture win("face_happy.png");
    sf::Texture flag("flag.png");
    sf::Texture mineMineMine("mine.png");
    sf::Texture number_1("number_1.png");
    sf::Texture number_2("number_2.png");
    sf::Texture number_3("number_3.png");
    sf::Texture number_4("number_4.png");
    sf::Texture number_5("number_5.png");
    sf::Texture number_6("number_6.png");
    sf::Texture number_7("number_7.png");
    sf::Texture number_8("number_8.png");
    sf::Texture test_1("test_1.png");
    sf::Texture test_2("test_2.png");
    sf::Texture test_3("test_3.png");
    sf::Texture notShown("tile_hidden.png");
    sf::Texture Shown("tile_revealed.png");
    */
    
    auto window = sf::RenderWindow(sf::VideoMode({800u, 800u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    std::cout << '\n';
    while (window.isOpen())
    {
        
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
            std::cout << localPosition.y << '\n';
            if (gameOn == "game") {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                if (localPosition.y <= 600) {

                }
                else {

                }
                // left mouse button is pressed: shoot
                
                
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        {

            // left mouse button is pressed: shoot
            sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
            std::cout << localPosition.y << '\n';
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            if (gameOn == "game") {
                
            }
        }
        
        for (int h = 0; h < gridX; h++) {
            for (int g = 0; g < gridY; g++) {

            }
        }
        
        
        
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

        }




        window.clear();

        // set a 10-pixel wide orange outline
        window.display();
        
    }
    
    
}

/*try {

    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }*/