
#include <iostream>
using namespace std;
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;

int main(int argc, char const *argv[])
{
    auto pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10)
    );
    
    auto& pixel = pantalla.PixelAt(1,1);
    pixel.blink = true;
    pixel.background_color = Color::Green1;
    pixel.foreground_color = Color::Red;
    pixel.character = "A";

     cout<<pantalla.ToString()<<endl;
   
    return 0;
}
