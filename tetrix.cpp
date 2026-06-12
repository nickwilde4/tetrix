#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <utility>
int main()  {
    int i = 0;
    int block = 0;
    bool move = 1;
    constexpr unsigned int window_tall = 1000, window_large = 1000; //Size of the window
    sf::RenderWindow window (
    sf::VideoMode({window_large, window_tall}),
    "Nick Tetrix_SMLF");

    window.setFramerateLimit(60);
    struct Objects {
    float x = 500.f; 
    float y = 0.f;
    float side = 100.f;
    std::pair<int,int>coordenates = {6,1};
    sf::RectangleShape rectangle_shape = sf::RectangleShape({side,side});};
    Objects object[100];

    unsigned int grid_tall = 12;
    unsigned int grid_large = 12;
    bool grid [grid_tall][grid_large]{};
    for (int a = 0; a<grid_large;++a){grid[a][11] = 1; grid[a][0] = 1;}
    for (int a = 0; a<grid_tall;++a){grid[0][a] = 1; grid[11][a] = 1;}

    /*
         0   1   2   3   4   5   6   7   8   9   10  11
      0  1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1
      1  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
      2  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
      3  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
      4  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
      5  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
      6  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
      7  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
      8  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
      9  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
     10  1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1
     11  1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1
    */
    
    
    object[block].rectangle_shape.setPosition({object[block].x,object[block].y});
    while (window.isOpen()) {
    
    i++;
        while (const auto event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()) window.close();
            if (move) {
                if (const auto* press_key = event->getIf<sf::Event::KeyPressed>()) {
                    if (press_key->code == sf::Keyboard::Key::A && (grid[object[block].coordenates.second][object[block].coordenates.first-1] == 0)) {
                        object[block].x -= object[block].side;
                        move=0;
                        object[block].coordenates.first -=1;}
                    if (press_key->code == sf::Keyboard::Key::S && (grid[object[block].coordenates.second+1][object[block].coordenates.first] == 0)) {
                        object[block].y += object[block].side;
                        move=0;
                        object[block].coordenates.second +=1;}
                    if (press_key->code == sf::Keyboard::Key::D && (grid[object[block].coordenates.second][object[block].coordenates.first+1] == 0)) {
                        object[block].x += object[block].side;
                        move=0;
                        object[block].coordenates.first +=1;}
                }
            }
        }
        if (i>=60) {
            if (grid[object[block].coordenates.second+1][object[block].coordenates.first] == 0 ){
                object[block].y += object[block].side;  object[block].coordenates.second += 1;}
            i = 0;  move = 1;}
        
        
                object[block].rectangle_shape.setPosition({object[block].x,object[block].y}); 
                if (object[block].coordenates.second + 1 < grid_tall &&
                    grid[object[block].coordenates.second + 1][object[block].coordenates.first] == 1){

                    grid[object[block].coordenates.second][object[block].coordenates.first] = 1;
                    ++block;
                    object[block].y = 0;
                    object[block].x = 500;
                    object[block].coordenates.first = 6;
                    object[block].coordenates.second = 1;
                    object[block].rectangle_shape.setPosition({object[block].x,object[block].y});

                }
            window.clear();
            for (int j = 0;j <= block; ++j) window.draw(object[j].rectangle_shape);
            window.display();
    }
}
