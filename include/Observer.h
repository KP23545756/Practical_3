#ifndef OBSERVER_H
#define OBSERVER_H
#include "Notice.h"
struct Notice;
/**
 * @brief GoF Observer role.
 *
 * Anything that needs to react to a Notice implements this. EventFlow
 * uses a Push model
 * observer never has to call back into the subject for state.
 */

class Observer{
    public:
        /**
         * @brief Called by a Subject when it notifies its observers.
         * @param notice The event data being pushed to this observer.
         */
        virtual void update(const Notice& notice) = 0;
         /// Virtual destructor: Observer is a polymorphic base.
        virtual ~Observer();
};


#endif //OBSERVER_H