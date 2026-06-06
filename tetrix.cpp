#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

int main()  {


    constexpr unsigned int window_tall = 750, window_large = 1000; //Size of the window
    sf::RenderWindow window (
    sf::VideoMode({window_large, window_tall}),
    "Nick Tetrix_SMLF");
    struct Balls {
    float x = 500.f; 
    float y = 500.f;
    float radius = 50;
    sf::CircleShape circle_shape = sf::CircleShape(radius);
    };
    Balls ball[1];
    ball[0].circle_shape.setPosition({ball[0].x,ball[0].y});

    while (window.isOpen()){
        while (const auto event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()) window.close();
             
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) ball[0].y -= 5.f;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) ball[0].x -= 5.f;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) ball[0].y += 5.f;
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) ball[0].x += 5.f;
                    ball[0].circle_shape.setPosition({ball[0].x,ball[0].y});
        }
    
            window.clear();
            window.draw(ball[0].circle_shape);
            window.display();
    }        
}
