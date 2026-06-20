#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
int what_square(int x, int y, unsigned int xmax)
{
    return y * xmax + x;
}
int main()  {
    unsigned int i = 0;
    bool move = 1;
    constexpr unsigned int window_tall = 1000, window_large = 1200; //Size of the window 
    sf::RenderWindow window (
    sf::VideoMode({window_large, window_tall}),
    "Nick Tetrix_SMLF");


    constexpr int side_of_squares = 50.f;


    int x=0,y=window_tall-side_of_squares;
    window.setFramerateLimit(90);
    struct Square {
        sf::RectangleShape square_shape;

        Square (){
            square_shape.setSize({static_cast<float>(side_of_squares),static_cast<float>(side_of_squares)});
            square_shape.setFillColor(sf::Color::Black);
            square_shape.setOutlineThickness(1.f);
            square_shape.setOutlineColor(sf::Color(30,30,30));
        }
    };

    sf::RectangleShape side_shape;
    side_shape.setSize({static_cast<float>(100.f)*2,window_tall});
    side_shape.setFillColor(sf::Color::White);
    side_shape.setPosition({window_large - static_cast<float>(100.f)*2,0});;

    const unsigned int grid_tall = static_cast<unsigned int>(1000/side_of_squares+2);
    const unsigned int grid_large = static_cast<unsigned int>(1000/side_of_squares+2);
    bool grid [grid_tall][grid_large]{};
    for (int a = 0; a<grid_large;++a) grid[grid_tall-1][a]= 1;
    for (int a = 0; a<grid_tall;++a){grid[a][0] = 1; grid[a][grid_large-1] = 1;}
    Square square[(grid_large-2)*(grid_tall-2)];

    for(Square& n: square){
        if(x>=(grid_large-2)*side_of_squares){y-=side_of_squares;x=0;}
        n.square_shape.setPosition({static_cast<float>(x),static_cast<float>(y)});
        x+=side_of_squares;}

    square[what_square(10,grid_tall-3,grid_large-3)].square_shape.setFillColor(sf::Color::White);

    std::cout << grid_tall-3 << ' ' << grid_large-3;
    x = 10;
    y = grid_tall-3;

while (window.isOpen()) {

    i++;

    if (i>=60){move=1;y-=1;i=0;}
        while (const auto event = window.pollEvent()){
            

            if (event->is<sf::Event::Closed>()) window.close();
            if (move) {
                if (const auto* press_key = event->getIf<sf::Event::KeyPressed>()) {
                    if (press_key->code == sf::Keyboard::Key::A){x-=1;}
                    if (press_key->code == sf::Keyboard::Key::D){x+=1;}
                    if (press_key->code == sf::Keyboard::Key::S){y-=1;}


                }
            }
        }

    square[what_square(x,y,grid_large-2)].square_shape.setFillColor(sf::Color::White);

            window.clear();
            //window.draw();
            window.draw(side_shape);
            for (Square& n : square) window.draw(n.square_shape);
            window.display();
    }
}
