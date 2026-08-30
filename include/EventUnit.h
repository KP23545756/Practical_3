#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"
#include "Observer.h"

struct Notice;

/**
 * @brief Abstract Leaf role in Composite, and simultaneously an
 * abstract Observer.
 *
 * EventUnit is the common base for every concrete operational unit.
 */
class EventUnit:public EventComponent, public Observer{
public:
    /**
     * @brief Forward name/capacity to EventComponent.
     * @param name Display name of the unit.
     * @param capacity Starting capacity (headcount, stock, etc.
     * depending on the concrete unit).
     */
    EventUnit(std::string name, int capacity);

    // open(), close(), reportStatus(), getCapacity() remain pure
    // virtual, inherited unchanged from EventComponent - every
    // concrete leaf implements its own.

    /// Every concrete leaf must define its own reaction to a Notice.
    void update(const Notice& notice) override = 0;

    /**
     * @brief Virtual destructor.
     *
     * EventUnit still has no resources of its own to release - each
     * concrete leaf's own destructor handles anything it added.
     */
    virtual ~EventUnit();
};

#endif // EVENTUNIT_H