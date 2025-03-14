#ifndef _MODES_FGCMODE2NEUTRAL_HPP
#define _MODES_FGCMODE2NEUTRAL_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

class FgcMode2Neutral : public ControllerMode {
  public:
    FgcMode2Neutral(socd::SocdType horizontal_socd, socd::SocdType vertical_socd);

  private:
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
};

#endif
