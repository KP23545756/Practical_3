#ifndef CONSOLESTATION_H
#define CONSOLESTATION_H
#include "EventUnit.h"
struct Notice;
/**
 * @brief Concrete Leaf: a console gaming station.
 *
 * On close(), saves active sessions before shutting down rather than
 * dropping them instantly.
 */
class ConsoleStation:public EventUnit{
private:
    bool isOpen;
    bool signUpsCapped;
    int activeSessions;
public:
    /**
     * @brief Construct a console station.
     * @param name Display name.
     * @param capacity Number of console seats.
     */
    ConsoleStation(std::string name, int capacity);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
    /**
     * @brief Begin tracking one more active session.
     */
    void startSession();
    /**
     * @brief A session finished normally (not via close()).
     */
    void endSession();
};
#endif // CONSOLESTATION_H
