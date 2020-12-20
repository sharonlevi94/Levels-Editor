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
#include "Controller.h"
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

   // drawExample();

   // auto mouseClickExample = MouseClickExample();
   // mouseClickExample.run();

    //DrawManyExample().run();

    //textureAndFontExample();

    //SetOriginExample().run();
    
    Controller controller = Controller();
    controller.run();
    
    return 0;
}
