#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

namespace esphome {
namespace i2sInput {

class I2SInputComponent : public Component {
public:
    I2SInputComponent();
   
    // void set_data_pin(uint8_t data_pin) { data_pin_ = data_pin; }  // I2S DATA / DOUT
    // void set_bclk_pin(uint8_t bclk_pin) { bclk_pin_ = bclk_pin; }  // I2S BCK / BCLK / CLOCK
    // void set_ws_pin(uint8_t ws_pin) { ws_pin_ = ws_pin; } // I2S WS / LRCLK
    void set_rate(uint16_t i2s_rate) { i2s_rate_ = i2s_rate; }   // I2S samping rate

    /// Setup the i2s bus
    void setup() override;

    /// Returns one sample from the RX buffer
    bool raw_read_sample(int16_t *left_data, int16_t *right_data, bool blocking);

protected:
    // uint8_t     data_pin_; 
    // uint8_t     bclk_pin_;
    // uint8_t     ws_pin_;
    uint16_t    i2s_rate_;
};

}  // namespace i2sInput
}  // namespace esphome
