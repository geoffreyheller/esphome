import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins
from esphome.const import CONF_RATE, CONF_ID, CONF_WS, CONF_BCLK, CONF_DATA
from esphome.core import coroutine, coroutine_with_priority

i2s_input_ns = cg.esphome_ns.namespace('i2sInput')
I2SInputComponent = i2s_input_ns.class_('I2SInputComponent', cg.Component)

MULTI_CONF = True
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(I2SInputComponent),
    # cv.Optional(CONF_DATA, default='GPIO12'): pins.input_pin,
    # cv.Optional(CONF_BCLK, default='GPIO13'): pins.input_pin,
    # cv.Optional(CONF_WS, default='GPIO14'): pins.input_pin,
    cv.Optional(CONF_RATE, default='11025'):
        cv.All(cv.rate, cv.Range(min=0, min_included=False)),
}).extend(cv.COMPONENT_SCHEMA)


@coroutine_with_priority(1.0)
def to_code(config):
    cg.add_global(i2s_input_ns.using)
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)

    # cg.add(var.set_data_pin(config[CONF_DATA]))
    # cg.add(var.set_bclk_pin(config[CONF_BCLK]))
    # cg.add(var.set_ws_pin(config[CONF_WS]))
    cg.add(var.set_rate(int(config[CONF_RATE])))
    cg.add_library('i2s', None)
