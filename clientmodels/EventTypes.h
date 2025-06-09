#pragma once
#include <string>

namespace EventTypes {
    inline static const std::string COMMAND_RESULT       = "commandResult";
    inline static const std::string DEVICE_ONLINE        = "deviceOnline";
    inline static const std::string DEVICE_UNKNOWN       = "deviceUnknown";
    inline static const std::string DEVICE_OFFLINE       = "deviceOffline";
    inline static const std::string DEVICE_INACTIVE      = "deviceInactive";
    inline static const std::string QUEUED_COMMAND_SENT  = "queuedCommandSent";
    inline static const std::string DEVICE_MOVING        = "deviceMoving";
    inline static const std::string DEVICE_STOPPED       = "deviceStopped";
    inline static const std::string DEVICE_OVERSPEED     = "deviceOverspeed";
    inline static const std::string DEVICE_FUEL_DROP     = "deviceFuelDrop";
    inline static const std::string DEVICE_FUEL_INCREASE = "deviceFuelIncrease";
    inline static const std::string GEOFENCE_ENTER       = "geofenceEnter";
    inline static const std::string GEOFENCE_EXIT        = "geofenceExit";
    inline static const std::string ALARM                = "alarm";
    inline static const std::string IGNITION_ON          = "ignitionOn";
    inline static const std::string IGNITION_OFF         = "ignitionOff";
    inline static const std::string MAINTENANCE          = "maintenance";
    inline static const std::string TEXT_MESSAGE         = "textMessage";
    inline static const std::string DRIVER_CHANGED       = "driverChanged";
    inline static const std::string MEDIA                = "media";
}
