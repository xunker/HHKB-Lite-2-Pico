// Copyright 2024 Matthew Nielsen (@xunker)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef RP_I2C_USE_I2C0
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C0 FALSE
#define RP_I2C_USE_I2C1 FALSE

#undef RP_SPI_USE_SPI0
#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI0 FALSE
#define RP_SPI_USE_SPI1 FALSE

#undef RP_SIO_USE_UART0
#undef RP_SIO_USE_UART1
#define RP_SIO_USE_UART0 FALSE
#define RP_SIO_USE_UART1 FALSE

#undef RP_ADC_USE_ADC1
#define RP_ADC_USE_ADC1 FALSE

#undef RP_PWM_USE_PWM0
#undef RP_PWM_USE_PWM1
#undef RP_PWM_USE_PWM2
#undef RP_PWM_USE_PWM3
#undef RP_PWM_USE_PWM4
#undef RP_PWM_USE_PWM5
#undef RP_PWM_USE_PWM6
#undef RP_PWM_USE_PWM7
#define RP_PWM_USE_PWM0 FALSE
#define RP_PWM_USE_PWM1 FALSE
#define RP_PWM_USE_PWM2 FALSE
#define RP_PWM_USE_PWM3 FALSE
#define RP_PWM_USE_PWM4 FALSE
#define RP_PWM_USE_PWM5 FALSE
#define RP_PWM_USE_PWM6 FALSE
#define RP_PWM_USE_PWM7 FALSE
