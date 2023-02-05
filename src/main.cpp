#include "simp_cli/simp_cli.hpp"
#include <iostream>


using namespace mm1::simp_cli;

int main(int argc, char **argv)
{
    Callback *callback = new CallbackFunction(
        "test",
        [](std::vector<std::string> args) {
            std::cout << "test callback" << std::endl;
        },
        []() {
            std::cout << "test help";
        }
    );
    SimpCli cli("test", "0.1.0", "test description");
    cli.add_callback(callback);
    cli.run(argc, argv);
    return 0;
}