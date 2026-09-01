#pragma once
#include "EventUnit.h"
#include <string>
using namespace std;
struct Notice;

/**
 * @brief Sells entry/upgrade tickets at a fixed point in the venue.
 */
class TicketBooth : public EventUnit{
private:
    /** @brief Whether the booth is actively selling tickets. */
    bool salesOpen;
    /** @brief True once an evacuation has locked the booth against reopening. */
    bool lockedByEvacuation;
public:
    /**
     * @brief Constructs a TicketBooth.
     * @param name Display name for this booth.
     * @param capacity Maximum queue/service capacity.
     */
    TicketBooth(string name, int capacity);

    /** @brief Opens sales, unless the booth is locked by an evacuation. */
    void open() override;

    /** @brief Stops selling tickets. */
    void close() override;

    /** @brief Prints sales status and evacuation-lock status. */
    void reportStatus() const override;

    /** @return The booth's current effective capacity. */
    int getCapacity() const override;

    /**
     * @brief Reacts to a cascaded Notice.
     * @param notice The notice broadcast by this unit's parent EventGroup.
     */
    void update(const Notice& notice) override;
};
