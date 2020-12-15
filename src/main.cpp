#include "00-WindowExample.h"
#include "01-CloseEventExample.h"
#include "02-ClearDisplayExample.h"
#include "03-DrawExample.h"
#include "04-MouseClickExample.h"
#include "05-DrawManyExample.h"
#include "06-TextureAndFontExample.h"
#include "07-SetOriginExample.h"

#include <thread>


#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
int main()
{
   /* {
        // if we just open a window, nothing happens with it
        // and it's closed when it's destructed
        auto example = WindowExample();

        // wait a bit before destruction so we can see what happens (or doesn't)
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(30s); // 30 seconds
    }*/

    //closeEventExample();

    //clearDisplayExample();

    //drawExample();

   // auto mouseClickExample = MouseClickExample();
   // mouseClickExample.run();

    DrawManyExample().run();

    //textureAndFontExample();

    //SetOriginExample().run();
    
    sf::RenderWindow window(sf::VideoMode(600, 600), "ex4_sharon_levi_eliad_karni");
    Menu menu(window.getSize().x, window.getSize().y);
    
    while (window.isOpen()) {
        
        sf::Event evnt;
       
        while (window.pollEvent(evnt)) {
            switch (evnt.type) {
            case sf::Event::KeyReleased:{
                switch (evnt.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                }
                break;
                }
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }
}
