bin/programa : src/main.cpp include/Foco.hpp include/EstadoFoco.hpp c++ src/main.cpp -o bin/programa -I include

run : bin/programa
	./bin/programa


bin/memoria : src/memoria.cpp 
	c++ src/memoria.cpp -o bin/memoria

runMemoria : bin/memoria	
	./bin/memoria	

bin/ejemplo : src/ejemplo.cpp
	c++ src/ejemplo.cpp -o bin/ejemplo -l ftxui-screen -l ftxui-dom -l ftxui-component

runEjemplo : bin/ejemplo
	./bin/ejemplo

bin/Animacion : src/Animacion.cpp include/Avion.hpp include/Dibujo.hpp include/GestorDibujos.hpp 
	c++ src/Animacion.cpp -o bin/Animacion -I include -l ftxui-screen -l ftxui-dom -l ftxui-component

runAnimacion : bin/Animacion
	./bin/Animacion



