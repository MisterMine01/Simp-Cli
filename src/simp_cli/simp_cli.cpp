#include "simp_cli/simp_cli.hpp"
#include <iostream>

/**
 * @brief Construct SimpCli object
 * @param name Name of the CLI
 * @param version Version of the CLI
 * @param description Description of the CLI
*/
mm1::simp_cli::SimpCli::SimpCli(std::string name, std::string version, std::string description)
{
    this->name = name;
    this->version = version;
    this->description = description;
    this->callbacks = std::vector<mm1::simp_cli::Callback *>();
}

/**
 * @brief Destroy SimpCli object
 * @return
*/
mm1::simp_cli::SimpCli::~SimpCli()
{
}

/**
 * @brief Add a callback to the list
 * @param callback Callback
 * @return
*/
void mm1::simp_cli::SimpCli::add_callback(mm1::simp_cli::Callback *callback)
{
    this->callbacks.push_back(callback);
}

/**
 * @brief Run the CLI
 * @param argc Number of arguments
 * @param argv Arguments
 * @return
*/
void mm1::simp_cli::SimpCli::run(int argc, char **argv)
{
    std::vector<std::string> args;
    for (int i = 1; i < argc; i++)
    {
        args.push_back(argv[i]);
    }
    if (args.size() == 0 || args[0] == "help")
    {
        std::cout << this->name << "-" << this->version;
        std::cout << " Powered by simp_cli-" << SIMP_CLI_VERSION << std::endl;
        std::cout << this->description << std::endl;
        std::cout << std::endl;
        std::cout << "Available commands:" << std::endl;
        std::cout << "help: View available commands" << std::endl;
        for (auto callback : this->callbacks)
        {
            std::cout << callback->get_name() << ": ";
            callback->print_help();
            std::cout << std::endl;
        }
        return;
    }
    for (auto callback : this->callbacks)
    {
        if (callback->get_name() == args[0])
        {
            std::vector<std::string> args_copy = args;
            args_copy.erase(args_copy.begin());
            callback->run(args_copy);
        }
    }
}