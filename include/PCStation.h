#ifndef PCSTATION_H
#define PCSTATION_H
#include <string>
#include "EventUnit.h"

class PCStation: public EventUnit{
    private:
        bool isOpen;
        bool sessionsSuspended;
        std::string currentGame;
    public:
        PCStation(std::string name, int capacity, std::string startGame);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        void update(const Notice&) override;
        void setGame(string gameName);

};
#endif // PCSTATION_H
