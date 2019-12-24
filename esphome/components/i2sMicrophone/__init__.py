import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins
from esphome.const import CONF_RATE, CONF_ID, CONF_WS, CONF_BCLK, CONF_DATA
from esphome.core import coroutine, coroutine_with_priority

i2s_microphone_ns = cg.esphome_ns.namespace('i2sMicrophone')
I2SMicrophoneComponent = i2s_microphone_ns.class_('I2SMicrophoneComponent', cg.Component)

MULTI_CONF = True
CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(I2SMicrophoneComponent),
    cv.Optional(CONF_RATE, default='11025'):
        cv.All(cv.rate, cv.Range(min=0, min_included=False)),
}).extend(cv.COMPONENT_SCHEMA)


@coroutine_with_priority(1.0)
def to_code(config):
    cg.add_global(i2s_microphone_ns.using)
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)

    cg.add(var.set_rate(int(config[CONF_RATE])))
    cg.add_library('i2s', None)
