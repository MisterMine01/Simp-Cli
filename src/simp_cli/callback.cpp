#include "simp_cli/callback.hpp"

/**
 * @brief Construct CallbackFunction object
 * @param name Name of the callback
 * @param callback Callback function
 * @param help Help message function
 * @return
*/
mm1::simp_cli::CallbackFunction::CallbackFunction(
    std::string name,
    std::function<void(std::vector<std::string>)> callback,
    std::function<void()> help)
{
    this->name = name;
    this->callback = callback;
    this->help = help;
}


/**
 * @brief Destroy CallbackFunction object
 * @return
*/
mm1::simp_cli::CallbackFunction::~CallbackFunction()
{
}

/**
 * @brief Run the callback
 * @param args Arguments
 * @return
*/
void mm1::simp_cli::CallbackFunction::run(std::vector<std::string> args)
{
    this->callback(args);
}

/**
 * @brief Print the help message
 * @return
*/
void mm1::simp_cli::CallbackFunction::print_help()
{
    this->help();
}

/**
 * @brief Get the name of the callback
 * @return
*/
std::string mm1::simp_cli::CallbackFunction::get_name()
{
    return this->name;
}