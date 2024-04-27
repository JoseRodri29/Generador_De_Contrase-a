#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>

//Jose Antonio Rodriguez Garcia 62211223

class PasswordGenerator {
private:
    std::vector<char> characters;

public:
    PasswordGenerator() {
        //Se inicializa el generador de números aleatorios
        srand(time(nullptr));
        
        //Aqui se aregan los caracteres ASCII entre 33 y 125 al vector de caracteres
        for (int i = 33; i <= 125; ++i) {
            characters.push_back(static_cast<char>(i));
        }
    }

    std::string generatePassword() {
        //Se mezcla los caracteres en el vector para mayor aleatoriedad
        std::shuffle(characters.begin(), characters.end(), std::mt19937{std::random_device{}()});

        //Crear la contraseña con los primeros 15 caracteres no repetidos
        std::string password;
        for (char c : characters) {
            if (password.size() == 15) {
                break;
            }
            if (password.find(c) == std::string::npos) {
                password.push_back(c);
            }
        }

        return password;
    }
};

int main() {
    PasswordGenerator generator;
    std::string password = generator.generatePassword();
    std::cout << "Contrasena generada: " << password << std::endl;
    return 0;
}
