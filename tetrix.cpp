#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

int main()  {
    int i = 0;
    bool move = 1;
    constexpr unsigned int window_tall = 1000, window_large = 1000; //Size of the window
    sf::RenderWindow window (
    sf::VideoMode({window_large, window_tall}),
    "Nick Tetrix_SMLF");

    window.setFramerateLimit(60);
    struct Objects {
    float x = 500.f; 
    float y = 0.f;
    float side = 50;
    sf::RectangleShape rectangle_shape = sf::RectangleShape({side,side});
    };
    Objects object[1];
    object[0].rectangle_shape.setPosition({object[0].x,object[0].y});

        sf::RectangleShape partofbackgraund1 = sf::RectangleShape({(window_large/6), window_tall/6});
        partofbackgraund1.setPosition({20.f+(window_large - (window_large/6)), 15.f});

        sf::RectangleShape backgraund = sf::RectangleShape({(window_large/6),window_tall});
        backgraund.setPosition({window_large - (window_large/6), 0});
        backgraund.setFillColor(sf::Color::Blue);
            

    while (window.isOpen()) {
    
    i++;









        while (const auto event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()) window.close();
            if (move) {
                if (const auto* press_key = event->getIf<sf::Event::KeyPressed>()) {
                    if (press_key->code == sf::Keyboard::Key::A) {object[0].x -= 50.f;move=0;}
                    if (press_key->code == sf::Keyboard::Key::S) {object[0].y += 50.f;move=0;}
                    if (press_key->code == sf::Keyboard::Key::D) {object[0].x += 50.f;move=0;}
                }
            }
        }
        if (i>=60) {object[0].y += object[0].side; i = 0; move = 1;}
        
        
                if (object[0].y+ (object[0].side) >= window_tall){ object[0].y = window_tall - (object[0].side);}
                if (object[0].x < 0) object[0].x = 0;
                if (object[0].x + (object[0].side) > window_large-(window_large/6)) object[0].x = window_large-(window_large/6) - (object[0].side);
                object[0].rectangle_shape.setPosition({object[0].x,object[0].y});  
    
            window.clear();
            window.draw(partofbackgraund1);
            window.draw(backgraund);
            window.draw(object[0].rectangle_shape);
            window.display();
    }
}
