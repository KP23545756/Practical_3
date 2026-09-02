#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"

class EventComponent;
struct Notice;

/**
 * @brief The event-level coordinator: a concrete Subject that issues
 * top-level notices into the tree.
 *
 * EventControl is deliberately not part of the Composite tree itself
 * - it is a client/collaborator that holds a reference to the root
 */
class EventControl:public Subject{
private:
    /// @brief Non-owning reference to the tree root, for reference only.
    EventComponent* root;

public:
    /**
     * @brief Construct a control point over a (non-owned) root component.
     * @param root Pointer to the root of the Composite tree. Not owned.
     */
    EventControl(EventComponent* root);

    /**
     * @brief Broadcast a notice to everything directly attached to
     * this control point.
     * @param notice The notice to issue.
     */
    void issueNotice(const Notice& notice);

    /**
     * @brief Virtual destructor.
     *
     * Does not delete root
     */
    ~EventControl();
};

#endif // EVENTCONTROL_H