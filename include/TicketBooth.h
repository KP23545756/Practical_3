#pragma once
#include "EventUnit.h"

class TicketBooth : public EventUnit{
private:
    bool salesOpen;
    bool lockedByEvacuation;

public:
    TicketBooth(string name, int capacity);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
};
