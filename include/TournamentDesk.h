#pragma once
#include "EventUnit.h"
#include <string>
using namespace std;
struct Notice;

/**
 * @brief Desk coordinating bracket progression inside the Tournament Zone.
 */
class TournamentDesk : public EventUnit{
private:
    /** @brief Whether the desk is currently accepting/running matches. */
    bool isOpen;
    /** @brief The bracket round currently in play. */
    int currentRound;
public:
    /**
     * @brief Constructs a TournamentDesk.
     * @param name Display name for this desk.
     * @param capacity Maximum number of players/spectators it can host.
     * @param startingRound The bracket round to begin at.
     */
    TournamentDesk(string name, int capacity, int startingRound);

    /** @brief Opens the desk. */
    void open() override;

    /** @brief Closes the desk. */
    void close() override;

    /** @brief Prints the current round number and status. */
    void reportStatus() const override;

    /** @return The desk's current effective capacity. */
    int getCapacity() const override;

    /**
     * @brief Reacts to a cascaded Notice.
     * @param notice The notice broadcast by the Tournament Zone EventGroup.
     */
    void update(const Notice& notice) override;

    /** @brief Advances the bracket to the next round. */
    void advanceRound();
};
