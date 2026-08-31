#pragma once
#include "EventUnit.h"
#include <string>
using namespace std;
struct Notice;

class InfoDesk : public EventUnit {
private:
    bool fullyStaffed;
    string announcement;

public:
    InfoDesk(string name, int capacity, string initialAnnoucement);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
};
