#pragma once
#include "EventUnit.h"
#include <string>
using namespace std;
struct Notice;

/**
 * @brief The venue's information point and announcement board.
 */
class InfoDesk : public EventUnit {
private:
    /** @brief Whether the desk is fully staffed. */
    bool fullyStaffed;
    /** @brief Current text on the announcement board. */
    string announcement;
public:
    /**
     * @brief Constructs an InfoDesk.
     * @param name Display name for this desk.
     * @param capacity Maximum number of attendees it can assist at once.
     * @param initialAnnoucement Announcement shown before any notices arrive.
     */
    InfoDesk(string name, int capacity, string initialAnnoucement);

    /** @brief Brings the desk up to full staffing. */
    void open() override;

    /** @brief Reduces staffing to a skeleton crew. */
    void close() override;

    /** @brief Prints staffing level and the current announcement. */
    void reportStatus() const override;

    /** @return The desk's current effective capacity. */
    int getCapacity() const override;

    /**
     * @brief Reacts to a cascaded Notice by updating the announcement board.
     * @param notice The notice broadcast by this unit's parent EventGroup.
     */
    void update(const Notice& notice) override;
};
