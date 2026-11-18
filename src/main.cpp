#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <vector>
#include <string>
#include <random>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        // Tu lista de mensajes aleatorios
        std::vector<std::string> mensajes = {
            "Hello",
            "Miaw",
            "Grief",
            "Doggie",
            "Roptob",
            "Roptob is love",
            "The challenge"
        };

        // Selección aleatoria
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, mensajes.size() - 1);

        std::string mensajeElegido = mensajes[distrib(gen)];

        // Muestra la ventana emergente con el mensaje elegido
        FLAlertLayer::create(
            "Mensaje", 
            mensajeElegido, 
            "OK"
        )->show();

        return true;
    }
};

