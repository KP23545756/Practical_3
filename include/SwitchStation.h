#ifndef SWITCHSTATION_H
#define SWITCHSTATION_H
#include "EventUnit.h"
struct Notice;
/**
 * @brief Concrete Leaf: a portable Switch station.
 *
 * Reduced effective capacity while running in portable/battery mode.
 * Ignores most notices.
 */
class SwitchStation:public EventUnit{
private:
    bool isOpen;
    bool portableMode;
public:
    /**
     * @brief Construct a Switch station.
     * @param name Display name.
     * @param capacity Number of Switch seats.
     * @param startsPortable Whether the station starts in portable/battery mode.
     */
    SwitchStation(std::string name, int capacity, bool startsPortable = true);
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void update(const Notice& notice) override;
    /**
     * @brief Switch into docked mode.
     */
    void dock();
    /**
     * @brief Switch into portable/battery mode.
     */
    void undock();
};
#endif // SWITCHSTATION_H
