#pragma once
#include "EventUnit.h"
#include <string>
struct Notice;
using namespace std;

/**
 * @brief A single-session virtual-reality demo booth.
 */
class VRBooth : public EventUnit {
private:
    /** @brief Whether a VR session is currently running. */
    bool isOpen;
    /** @brief True while the booth is unavailable to new sessions (cooldown/pause). */
    bool inCooldown;
public:
    /**
     * @brief Constructs a VRBooth.
     * @param name Display name for this booth.
     * @param capacity Number of simultaneous participants a session supports.
     */
    VRBooth(string name, int capacity);

    /** @brief Starts a new session, unless the booth is in cooldown. */
    void open() override;

    /** @brief Ends the current session and enters cooldown for cleaning. */
    void close() override;

    /** @brief Prints whether a session is running, closed, or in cooldown. */
    void reportStatus() const override;

    /** @return The booth's current effective capacity. */
    int getCapacity() const override;

    /**
     * @brief Reacts to a cascaded Notice.
     * @param notice The notice broadcast by this unit's parent EventGroup.
     */
    void update(const Notice& notice) override;
};
