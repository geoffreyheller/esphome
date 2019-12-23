#include "i2sInput.h"
#include <i2s.h>
#include "esphome/core/log.h"
#include "esphome/core/helpers.h"
#include "esphome/core/application.h"

namespace esphome {
namespace i2sInput {

static const char *TAG = "i2sInput";

I2SInputComponent::I2SInputComponent() {
}

// see https://github.com/esp8266/Arduino/blob/19d09eae2b5ff9ed7cc48b5fa2c912d1297462b9/cores/esp8266/core_esp8266_i2s.cpp
// see https://github.com/esp8266/Arduino/blob/19d09eae2b5ff9ed7cc48b5fa2c912d1297462b9/cores/esp8266/i2s.h
// see https://github.com/esp8266/Arduino/blob/master/libraries/esp8266/examples/I2SInput/I2SInput.ino


void I2SInputComponent::setup() {
    const bool enable_rx = true;
    const bool enable_tx = false;
    i2s_rxtx_begin(enable_rx, enable_tx);
    i2s_set_rate(this->rate_);
}

bool I2SInputComponent::raw_read_sample(int16_t *left_data, int16_t *right_data, bool blocking) {
    return i2s_read_sample(left_data, right_data, blocking);
}



}  // namespace i2sInput
}  // namespace esphome
