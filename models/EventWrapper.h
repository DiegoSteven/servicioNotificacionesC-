#pragma once
#include <memory>
#include "../clientmodels/EventDTO.h"
#include "../clientmodels/DeviceDTO.h"
#include "../clientmodels/PositionDTO.h"

struct EventWrapper {
    std::shared_ptr<EventDTO> event;
    std::shared_ptr<DeviceDTO> device;
    std::shared_ptr<PositionDTO> position;
};
