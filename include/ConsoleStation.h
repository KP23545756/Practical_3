#ifndef CONSOLESTATION_H
#define CONSOLESTATION_H

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
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        void update(const Notice&) override;
        void startSession();
        void endSession();
};
#endif // CONSOLESTATION_H
