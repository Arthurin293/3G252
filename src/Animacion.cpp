#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"

using namespace ftxui;

int main()
{
    
    auto screen = Screen::Create(
        Dimension::Fixed(120),
        Dimension::Fixed(40));
    
    
    const std::vector<std::u32string> avion = {
        U"__  _",
        U"\\ `/ |",
        U" \\__`!",
        U" / ,' `-.__________________",
        U"'-'\\_____                LI`-.",
        U"   <____()-=O=O=O=O=O=[]====-)",
        U"     `.___ ,-----,_______...-'",
        U"          /    .'",
        U"         /   .'",
        U"        /  .'",
        U"        `-'"
    };
    
    
    const std::vector<std::u32string> nube = {
        U"          .-~~~-.",
        U"  .- ~ ~-(       )_ _",
        U" /                     ~ -.",
        U"|                           \\",
        U" \\                         .'",
        U"   ~- . _____________ . -~ "
    };
    
    
    const std::vector<std::u32string> pajaro = {
        U"                   /^v^\\",
        U"         /^v^\\                      /^v^\\",
        U"                /^v^\\",
        U"",
        U"       /^v^\\"
    };
    
    GestorDibujos gestor;
    
    
    gestor.Agregar(Dibujo(5, 5, nube, ftxui::Color::GrayLight));
    gestor.Agregar(Dibujo(40, 8, nube, ftxui::Color::White));
    gestor.Agregar(Dibujo(75, 6, nube, ftxui::Color::GrayLight));
    gestor.Agregar(Dibujo(20, 20, nube, ftxui::Color::White));
    gestor.Agregar(Dibujo(85, 18, nube, ftxui::Color::GrayLight));
    gestor.Agregar(Dibujo(55, 25, nube, ftxui::Color::White));
    
    
    gestor.Agregar(Dibujo(25, 8, pajaro, ftxui::Color::Green));
    gestor.Agregar(Dibujo(70, 15, pajaro, ftxui::Color::Green));
    gestor.Agregar(Dibujo(50, 22, pajaro, ftxui::Color::Green));
    
    
    gestor.Agregar(Dibujo(0, 15, avion, ftxui::Color::Yellow));
    
    int frames = 250;
    for (int frame = 0; frame < frames; ++frame)
    {
        
        screen.Clear();
        
        gestor.dibujos[9].x = -30 + frame;  
        
        
        int vuelo_ondulante = (frame / 5) % 4;
        if (vuelo_ondulante == 0 || vuelo_ondulante == 2) {
            gestor.dibujos[9].y = 15;
        } else if (vuelo_ondulante == 1) {
            gestor.dibujos[9].y = 14;
        } else {
            gestor.dibujos[9].y = 16;
        }
        
        
        gestor.dibujos[6].x = 25 + ((frame / 2) % 15);
        gestor.dibujos[6].y = 8 + ((frame / 4) % 3);
        
        
        gestor.dibujos[7].x = 70 - ((frame / 3) % 12);
        gestor.dibujos[7].y = 15 + ((frame / 5) % 2);
        
        
        gestor.dibujos[8].x = 50 + ((frame / 2) % 10);
        gestor.dibujos[8].y = 22 + ((frame / 6) % 3);
        
        
        gestor.dibujos[0].x = 5 + (frame / 15) % 3;   
        gestor.dibujos[1].x = 40 - (frame / 20) % 2;   
        gestor.dibujos[2].x = 75 + (frame / 18) % 3;   
       
        
        
        gestor.DibujarTodos(screen);
        
       
        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    
    std::cout << "\n\n¡Animación completada! El avión atravesó a los pájaros.\n";
    
    return 0;
}