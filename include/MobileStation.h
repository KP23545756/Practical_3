#pragma once
#include "EventUnit.h"


class MobileStation : public EventUnit {
private:
    
    bool isitopen;
    
    int queueLength;

public:
    
    MobileStation(string name, int capacity);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
    void joinQueue();
    void leaveQueue();
};
