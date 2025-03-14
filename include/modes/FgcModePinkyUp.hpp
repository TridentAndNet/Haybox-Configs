#ifndef _MODES_FGCMODEPINKYUP_HPP
#define _MODES_FGCMODEPINKYUP_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

class FgcModePinkyUp : public ControllerMode {
  public:
    FgcModePinkyUp(socd::SocdType horizontal_socd, socd::SocdType vertical_socd);

  private:
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
};

#endif
