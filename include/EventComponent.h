#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H
#include <string>
/**
 * @brief Abstract Component role in the Composite pattern
 * Interface used by every operatioal unit in eventflow.
 * Abstract class, do not instatiate.
 */
class EventComponent{
    protected:
        /// @brief Name of component like PC station 1
        std::string name;
        /** @brief Capacity size of component
         *  leaf will store own value. 
        */
        int capacity;
    public:
        /**
         * @brief Construct a component with a name and a starting capacity.
         * Base constructor, as in no validation is done
         * @param name Display name for this component
         * @param capacity Starting capacity value
         */
        EventComponent(std::string name, int capacity);
        /**
         * @brief Open this component.
         * A leaf opens itself. A composite is expected to open its
         * children.
         */
        virtual void open() = 0;
        /// @brief Close this component. Opposite of open
        virtual void close() = 0;
        /**
         * @brief Print a human-readable status line for this component.
         * A composite is expected to also report its children's status
         * beneath its own
         */
        virtual void reportStatus() const = 0;
        /// @brief Get this component's effective capacity.
        /// @return Current capacity value
        virtual int getCapacity() const = 0;
        /// @brief Virtual destructor
        /// @brief Virtual destructor   
        virtual ~EventComponent();
};

#endif //EVENTCOMPONENT_H