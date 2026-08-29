#include "Notice.h"
    /**
     * @brief Constructs a Notice.
     *
     * @param type The type of notice.
     * @param message The descriptive message.
     * @param value The numerical value associated with the notice.
     */
Notice::Notice(NoticeType type, const std::string& message, int value){
    this->message = message;
    this->type = type;
    this->value = value;
}