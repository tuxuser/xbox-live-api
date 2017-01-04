#pragma once

namespace xbox { namespace services { namespace player_state_writer {

/// <summary> 
/// Event type
/// </summary>
enum class player_state_event_type
{
    local_user_added,
    local_user_removed
};

/// <summary> 
/// Represents a player state
/// Player state is a set
/// </summary>
class player_state_value
{
public:
    player_state_value(
        _In_ const string_t& value
        );

    player_state_value(
        _In_ double value
        );

    player_state_value(
        _In_ int64_t value
        );

    player_state_value(
        _In_ bool value
        );

    /// <summary> 
    /// Gets the value as a string
    /// </summary>
    string_t as_string() const;

    /// <summary> 
    /// Gets the value as a boolean
    /// </summary>
    bool as_bool() const;

    /// <summary> 
    /// Gets the value as a boolean
    /// </summary>
    double as_number() const;

    /// <summary> 
    /// Gets the value as a boolean
    /// </summary>
    int64_t as_integer() const;
};

/// <summary> 
/// Player state event
/// </summary>
class player_state_event
{
public:
    /// <summary> 
    /// Represents error code and error message
    /// </summary>
    /// <return>The returned xbox live result</return>
    const xbox_live_result<void>& error_info() const;

    /// <summary> 
    /// The type of event the statistic is
    /// </summary>
    /// <return>The event type</return>
    player_state_event_type event_type() const;

    /// <summary> 
    /// Local user the event is for
    /// </summary>
    /// <return>The returned user</return>
    const xbox_live_user_t& local_user() const;

    /// Internal function
    player_state_event(
        player_state_event_type eventType,
        xbox_live_user_t user,
        xbox_live_result<void> errorInfo
        );
};

/// <summary> 
/// The player state writer expects information for various player state information
/// This information is used for various services like stats_manager, contextual search information, and presence
/// </summary>
class player_state_writer
{
public:
    /// <summary> 
    /// Instantiates and returns an instance of the player state writer
    /// </summary>
    static player_state_writer get_singleton_instance();

    /// <summary> 
    /// Sets player state. Immediately applies.
    /// </summary>
    /// <return>A list of events that have happened since previous do_work</return>
    xbox_live_result<void> set_player_state(_In_ xbox_live_user_t user, const std::unordered_map<string_t, player_state_value>& playerStateList);

    /// <summary> 
    /// Removes a player state object from the internal list
    /// </summary>
    xbox_live_result<void> clear_player_state(_In_ xbox_live_user_t user, _In_ const string_t& name);

    /// <summary> 
    /// Gets the player state list
    /// </summary>
    xbox_live_result<void> get_player_states(_In_ xbox_live_user_t user, _Inout_ std::unordered_map<string_t, player_state_value>& playerStateList);
};
    
}}}