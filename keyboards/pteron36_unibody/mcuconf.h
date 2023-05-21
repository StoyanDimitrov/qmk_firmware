#pragma once

#include_next <mcuconf.h>
// Enable I2C2
#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE