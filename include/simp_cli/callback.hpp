#ifndef SIMP_CLI_CALLBACK_HPP
#define SIMP_CLI_CALLBACK_HPP

#include <string>
#include <vector>
#include <functional>

namespace mm1
{
    namespace simp_cli
    {
        /**
         * @brief Callback interface
         * @property run: Run the callback
         * @property print_help: Print the help message
         * @property get_name: Get the name of the callback
        */
        class Callback {
            public:
                virtual void run(std::vector<std::string>) = 0;
                virtual void print_help() = 0;
                virtual std::string get_name() = 0;
        };

        /**
         * @brief Callback in functional form
         * @property name: Name of the callback
         * @property callback: Callback function
         * @property help: Help message function
        */
        class CallbackFunction : public Callback
        {
        private:
            std::string name;
            std::function<void(std::vector<std::string>)> callback;
            std::function<void()> help;
        public:
            CallbackFunction(std::string name, std::function<void(std::vector<std::string>)> callback, std::function<void()> help);
            ~CallbackFunction();
            void run(std::vector<std::string>);
            void print_help();
            std::string get_name();
        };
    }
}

#endif