#include "simp_cli/callback.hpp"

mm1::simp_cli::CallbackFunction::CallbackFunction(
    std::string name,
    std::function<void(std::vector<std::string>)> callback,
    std::function<void()> help)
{
    this->name = name;
    this->callback = callback;
    this->help = help;
}

mm1::simp_cli::CallbackFunction::~CallbackFunction()
{
}

void mm1::simp_cli::CallbackFunction::run(std::vector<std::string> args)
{
    this->callback(args);
}

void mm1::simp_cli::CallbackFunction::print_help()
{
    this->help();
}

std::string mm1::simp_cli::CallbackFunction::get_name()
{
    return this->name;
}