#ifndef PCSTATION_H
#define PCSTATION_H
#include "EventUnit.h"
struct Notice;
/**
 * @brief Concrete Leaf: a PC gaming station.
 *
 * Indoor unit,ignores weather alerts entirely, but a
 * evacuation forces an immediate close.
 */
class PCStation:public EventUnit{
private:
    bool isOpen;
    bool sessionsSuspended;
    std::string currentGame;
public:
    /**
     * @brief Construct a PC station.
     * @param name Display name.
     * @param capacity Number of PC seats.
     * @param startingGame Game loaded before the station has been opened.
     */
    PCStation(std::string name, int capacity, std::string startingGame = "None");
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
    /**
     * @brief Swap the game currently running on this station.
     * @param gameName Name of the game to load. Ignored if the station
     * is not currently open.
     */
    void setGame(std::string gameName);
};

#endif // PCSTATION_H
