#pragma once
#include "EventUnit.h"
#include <string>
struct Notice;
using namespace std;
class VRBooth : public EventUnit {
private:
    bool isOpen;
    bool inCooldown;

public:
    VRBooth(string name, int capacity);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
};
