#ifndef _MODES_MELEETHUMBY_HPP
#define _MODES_MELEETHUMBY_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

typedef struct {
    bool crouch_walk_os = false;
} MeleeThumbYOptions;

class MeleeThumbY : public ControllerMode {
  public:
    MeleeThumbY(socd::SocdType socd_type, MeleeThumbYOptions options = {});

  protected:
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);

  private:
    MeleeThumbYOptions _options;
    bool _horizontal_socd;

    void HandleSocd(InputState &inputs);
};

#endif
