#pragma once
#include "EventUnit.h"


class TournamentDesk : public EventUnit{
private:
    
    bool isOpen;
    int currentRound;

public:
    
    TournamentDesk(string name, int capacity, int startingRound);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
    void advanceRound();
};
