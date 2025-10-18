
#include <iostream>

using namespace std;
#include<string>
#include<sstream>
#include<thread>
#include<chrono>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace ftxui;

string nave = 

string("        ___      \n")+
string("    ___/   \\___  \n")+
string("   /   '---'   \\  \n")+
string("   '--_______--' \n")+
string("        /  \\     \n")+
string("       /    \\   \n")+ 
string("      /  \\O/ \\    \n")+ 
string("      /    |  \\  \n")+ 
string("      /   / \\  \n"); 
int main(int argc, char const *argv[])
{
    auto pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10)
    );
    
    int x=0;
    int y=0;

    while(true)
    {
    
        x++;
        stringstream ss(nave);
        string linea;
        int notlinea = 0;
        while (getline(ss,linea))
        {

            int columna = 0;
            for (auto&&letra : linea)
            {

    auto &pixel = pantalla.PixelAt(x,y + notlinea);
    //pixel.blink = true;
    //pixel.background_color = Color::Green1;
    //pixel.foreground_color = Color::Red;
    pixel.character = letra;
    columna ++;
}
notlinea++;
        }
    pantalla.Print();
    pantalla.Clear();
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<pantalla.ResetPosition();
    }
   
    return 0;
}

