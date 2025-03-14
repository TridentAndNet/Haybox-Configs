#include "modes/FgcMode2Neutral.hpp"

FgcMode2Neutral::FgcMode2Neutral(socd::SocdType horizontal_socd, socd::SocdType vertical_socd) {
    // _socd_pair_count = 4;
    _socd_pair_count = 9;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
 /* Mod X override C-Up input if both are pressed. Without this, neutral SOCD doesn't work
  properly if Down and both Up buttons are pressed, because it first resolves Down + Mod X
  to set both as unpressed, and then it sees C-Up as pressed but not Down, so you get an up                         
  input instead of neutral. */
        socd::SocdPair{ &InputState::a, &InputState::wasd_up,  socd::SOCD_DIR1_PRIORITY},
        socd::SocdPair{ &InputState::a, &InputState::c_up,  socd::SOCD_DIR1_PRIORITY},
        socd::SocdPair{ &InputState::c_up, &InputState::wasd_up,  socd::SOCD_DIR1_PRIORITY},
        socd::SocdPair{ &InputState::left, &InputState::l,  socd::SOCD_DIR1_PRIORITY},
        socd::SocdPair{&InputState::left,   &InputState::right, horizontal_socd         },
        socd::SocdPair{ &InputState::down,  &InputState::a,  vertical_socd           },
        socd::SocdPair{ &InputState::down,  &InputState::wasd_up,  vertical_socd  },
        socd::SocdPair{ &InputState::down,  &InputState::c_up,  vertical_socd  },
        socd::SocdPair{&InputState::l,   &InputState::right, horizontal_socd         }
    }; 
}

void FgcMode2Neutral::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left || inputs.l;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.a || inputs.wasd_up || inputs.c_up; //changed RHS up and added WASD up

    // Menu keys
    outputs.start = inputs.start;
    outputs.select = inputs.c_right; // "Steam/XBox button"
    outputs.home = inputs.mod_y; 
    outputs.rightStickClick = inputs.c_left || inputs.c_down;
    outputs.leftStickClick =  inputs.mod_x;

    // Right hand bottom row
    outputs.a = inputs.b;
    outputs.b = inputs.x;
    outputs.triggerRDigital = inputs.z;
    outputs.triggerLDigital = inputs.up;

    // Right hand top row
    outputs.x = inputs.r;
    outputs.y = inputs.y;
    outputs.buttonR = inputs.lightshield;
    outputs.buttonL = inputs.midshield;
}

void FgcMode2Neutral::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
    outputs.triggerLAnalog = outputs.triggerLDigital ? 255 : 0;
    outputs.triggerRAnalog = outputs.triggerRDigital ? 255 : 0;
}
