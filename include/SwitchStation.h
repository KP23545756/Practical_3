#ifndef SWITCHSTATION_H
#define SWITCHSTATION_H
#include <string>
#include "EventUnit.h"

class SwitchStation: public EventUnit{
    private:
        bool isOpen;
        bool portableMode;
    public:
        SwitchStation(std::string name, int capacity);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        void update(const Notice&) override;
        void dock();
        void undock();
};

#endif // SWITCHSTATION_H
