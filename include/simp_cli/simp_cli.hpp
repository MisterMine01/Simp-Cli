#ifndef SIMP_CLI_HPP
#define SIMP_CLI_HPP
#define SIMP_CLI_VERSION "0.1.0"

#include <string>
#include <vector>
#include <functional>
#include "./callback.hpp"

namespace mm1
{
    namespace simp_cli
    {
        /**
         * @brief Simple CLI
         * @property name: Name of the CLI
         * @property callbacks: List of callbacks
         * @property add_callback: Add a callback to the list
         * @property run: Run the CLI
        */
        class SimpCli
        {
        private:
            std::string name;
            std::string version;
            std::string description;
            std::vector<Callback *> callbacks;
        public:
            SimpCli(std::string name, std::string version, std::string description);
            ~SimpCli();
            void add_callback(Callback *callback);
            void run(int argc, char **argv);
        };
    } // namespace simp_cli

} // namespace mm1

#endif