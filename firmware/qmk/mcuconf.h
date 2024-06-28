// Copyright 2024 Matthew Nielsen (@xunker)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 FALSE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 FALSE

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 FALSE

#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 FALSE

#undef RP_SIO_USE_UART0
#define RP_SIO_USE_UART0 FALSE

#undef RP_SIO_USE_UART1
#define RP_SIO_USE_UART1 FALSE