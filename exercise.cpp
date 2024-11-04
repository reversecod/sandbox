#include <iostream>
#include <string>

namespace log_line {

    std::string message(const std::string& line) {
        // Encontra a posição de ": " e retorna a substring após ela
        std::size_t pos = line.find(": ");
        return line.substr(pos + 2);
    }

    std::string log_level(const std::string& line) {
        // Encontra a posição de "[" e "]" e retorna o conteúdo em maiúsculas
        std::size_t start = line.find('[');
        std::size_t end = line.find(']');
        return line.substr(start + 1, end - start - 1);
    
    }

    std::string reformat(const std::string& line) {
        // Retorna a mensagem seguida do nível de log entre parênteses
        return message(line) + " (" + log_level(line) + ")";
    }

}

int main(){
    std::string line = "[ERROR]: Invalid operation";
    std::cout << log_line::message(line) << std::endl;      // Imprime "Invalid operation"
    std::cout << log_line::log_level(line) << std::endl;    // Imprime "ERROR"
    std::cout << log_line::reformat(line) << std::endl;     // Imprime "Invalid operation (ERROR)"
}