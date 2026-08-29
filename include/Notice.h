#ifndef NOTICE_H
#define NOTICE_H
#include <string>

/**
 * @brief Types of notices that can be sent to observers.
 */
enum NoticeType{
    OPEN,
    CLOSED,
    SCHEDULE_CHANGE,
    CAPACITY_ALERT,
    WEATHER_ALERT,
    PAUSE,
    RESUME,
    EVACUATE
};
/**
 * @brief Represents a notice/event sent to observers.
 * 
 * A Notice contains the type of event, a descriptive message,
 * and an optional numerical value associated with the event.
 */
struct Notice{
    NoticeType type;
    std::string message;
    int value;
    /**
     * @brief Constructs a Notice.
     *
     * @param type The type of notice.
     * @param message The descriptive message.
     * @param value The numerical value associated with the notice.
     */
    Notice(NoticeType type, const std::string& message, int value);
};

#endif // NOTICE_H
