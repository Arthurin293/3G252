#pragma once
#include <vector>
#include "Dibujo.hpp"

class Avion {
public:
    int x, y, ancho, alto;
    Dibujo dibujo_avion;
    std::vector<Dibujo> nubes;
    
    Avion(int x, int y, int ancho, int alto, ftxui::Color color = ftxui::Color::Cyan)
        : x(x), y(y), ancho(ancho), alto(alto),
          dibujo_avion(x, y, GenerarFiguraAvion(), color) {}
    
    static std::vector<std::u32string> GenerarFiguraAvion() {
        // Tu arte ASCII del avión
        std::vector<std::u32string> figura = {
            U"                _                                  ",
            U"              (`  ).                   _           ",
            U"             (     ).              .:(`  )`.       ",
            U")           _(       '`.          :(   .    )      ",
            U"        .=(`(      .   )     .--  `.  (    ) )      ",
            U"       ((    (..__.:'-'   .+(   )   ` _`  ) )                 ",
            U"`.     `(       ) )       (   .  )     (   )  ._   ",
            U"  )      ` __.:'   )     (   (   ))     `-'.-(`  ) ",
            U")  )  ( )       --'       `- __.'         :(      )) ",
            U".-'  (_.'          .')                    `(    )  ))",
            U"                  (_  )                     ` __.:'          "
        };
        return figura;
    }
    
    void AgregarNube(const Dibujo& nube) {
        nubes.push_back(nube);
    }
    
    void Dibujar(ftxui::Screen& screen) const {
        // Dibuja las nubes primero (fondo)
        for (const auto& nube : nubes) {
            nube.Dibujar(screen);
        }
        // Dibuja el avión encima
        dibujo_avion.Dibujar(screen);
    }
};