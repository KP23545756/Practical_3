#ifndef CONSOLESTATION_H
#define CONSOLESTATION_H
#include <string>
#include "EventUnit.h"
class ConsoleStation: public EventUnit{
    private:
        /// @brief Checks if place is open
        bool isOpen;
        /// @brief Checks if signups have been paused, yes = true
        bool sigUpsCapped;
        /// @brief Number of active sessions
        int activeSessions;
    public:
        ConsoleStation(std::string name, int capacity);
        void open();
        void close();
        void reportStatus() const;
        int getCapacity() const;
        void update(const Notice&);
        void startSession();
        void endSession();
};
#endif // CONSOLESTATION_H
