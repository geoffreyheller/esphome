#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

namespace esphome {
namespace i2sMicrophone {

class I2SMicrophoneComponent : public Component {
public:
    I2SMicrophoneComponent();

    void set_rate(uint16_t i2s_rate) { i2s_rate_ = i2s_rate; }   // I2S samping rate

    /// Setup the i2s bus
    void setup() override;

    /// Returns one sample from the RX buffer
    bool raw_read_sample(int16_t *left_data, int16_t *right_data, bool blocking);

protected:
    uint16_t    i2s_rate_;
};

}  // namespace i2sMicrophone
}  // namespace esphome
