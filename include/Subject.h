#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "Observer.h"

struct Notice;
/**
 * @brief GoF Subject role: something that can be observed.
 *
 * Subject stores non-owning raw pointers to its observers. 
 * Whoever created an Observer is responsible for its lifetime and must detach() it before it is destroyed
 */

class Subject{
    protected:
        /// @brief Non-owning pointers to registered observers.
        std::vector<Observer*> observers;
    public:
        /**
         * @brief Register an observer to receive future notices.
         *
         * if the same pointer is already registered, attach() cannot be done.
         *
         * @param observer Observer to register. Must not be nullptr.
         */
        virtual void attach(Observer* observer);
        /**
         * @brief Remove a previously registered observer.
         *
         * If the pointer is not currently registered, detach() does
         * nothing.
         *
         * @param observer Observer to remove.
         */
        virtual void detach(Observer* observer);
        /**
         * @brief Push a notice to every currently registered observer.
         *
         * Implementation must copy the observer list before iterating
         *
         * @param notice The notice to broadcast.
         */
        virtual void notify(const Notice& notice);
        /**
         * @brief Clears the observer list. Never deletes the observers
         * themselves - Subject does not own them.
         */
        virtual ~Subject();
};

#endif // SUBJECT_H
