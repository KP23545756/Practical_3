#ifndef EVENTGROUP_H
#define EVENTGROUP_H
#include <vector>
#include "EventComponent.h"
#include "Subject.h"
#include "Observer.h"


/**
 * @brief GoF Composite role, and simultaneously both Subject and Observer.
 *
 * EventGroup plays three roles for three different reasons:
 *  - Composite: it owns a list of child EventComponent* (Leaves and/or
 *    further EventGroups) and implements open/close/reportStatus/
 *    getCapacity recursively over that tree.
 *  - Subject: it can have its own observers (typically its children,
 *    if they are also registered) attached to it, and notify() pushes
 *    a Notice down to them.
 *  - Observer: it can itself be attach()ed to a parent EventGroup or to
 *    EventControl, so that a notice issued above cascades down to it
 *    and, via its own notify(), further down again.
 *
 */

class EventGroup: public Subject, public Observer,public EventComponent{
    private:
        /// @brief Owned children
        std::vector<EventComponent*> children;
    public:
        /**
         * @brief Construct a named group.
         * @param name Display name of this group
         */
        EventGroup(std::string name);
        /**
         * @brief Add a child to this group's ownership tree.
         *
         * Does NOT call attach(), Composite membership and Observer
         * @param child Component to add. This group takes ownership of it.
         */
        void addChildren(EventComponent*);
        /**
         * @brief Remove a child from this group's ownership tree.
         *
         * If the child was also registered as this group's observer, it is
         * detach()ed.
         * method never deletes the child, so it can be re-parented elsewhere.
         * @param child Component to remove (matched by pointer).
         * @return The removed component, or nullptr if not found.
         */
        EventComponent* removeChildren(EventComponent*);
        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;
        /**
         * @brief React to a notice pushed from above, then cascade it down.
         *
         * @param notice The notice pushed from above.
         */

        void update(const Notice& notice) override;
        ~EventGroup();
};

#endif // EVENTGROUP_H
