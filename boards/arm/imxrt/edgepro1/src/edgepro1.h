/****************************************************************************
 * boards/arm/imxrt/edgepro1/src/edgepro1.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __BOARDS_ARM_IMXRT_EDGEPRO1_H
#define __BOARDS_ARM_IMXRT_EDGEPRO1_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

#include <arch/irq.h>
#include <nuttx/irq.h>

#include "imxrt_gpio.h"
#include "imxrt_iomuxc.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* EdgePro1 GPIO Pin Definitions ********************************************/

/* LPSPI1 CS:  GPIO_AD_B0_15 */
#define IOMUX_LPSPI1_CS       (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                               IOMUX_SPEED_MEDIUM | IOMUX_PULL_UP_100K | \
                               _IOMUX_PULL_ENABLE)
#define GPIO_LPSPI1_CS        (GPIO_OUTPUT | GPIO_OUTPUT_ONE | \
                               GPIO_PORT1 | GPIO_PIN15 | IOMUX_LPSPI1_CS)

/* LPSPI4 CS:  GPIO_B0_00 */
#define IOMUX_LPSPI4_CS       (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                               IOMUX_SPEED_MEDIUM | IOMUX_PULL_UP_100K | \
                               _IOMUX_PULL_ENABLE)
#define GPIO_LPSPI4_CS        (GPIO_OUTPUT | GPIO_OUTPUT_ONE | \
                               GPIO_PORT2 | GPIO_PIN0 | IOMUX_LPSPI4_CS)

/* NINA NRST:  GPIO_AD_B0_00 */
#define IOMUX_NINA_NRST       (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                               IOMUX_SPEED_MEDIUM | IOMUX_PULL_UP_100K | \
                               _IOMUX_PULL_ENABLE)
#define GPIO_NINA_NRST        (GPIO_OUTPUT | GPIO_OUTPUT_ONE | \
                               GPIO_PORT1 | GPIO_PIN0 | IOMUX_NINA_NRST)

/* NINA BOOT:  GPIO_AD_B0_02 */
#define IOMUX_NINA_NRST       (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                               IOMUX_SPEED_MEDIUM | IOMUX_PULL_UP_100K | \
                               _IOMUX_PULL_ENABLE)
#define GPIO_NINA_BOOT        (GPIO_OUTPUT | GPIO_OUTPUT_ONE | \
                               GPIO_PORT1 | GPIO_PIN2 | IOMUX_NINA_BOOT)

/* NINA GPIO:  GPIO_SD_B1_04 */
#define IOMUX_NINA_GPIO       (IOMUX_SLEW_FAST | IOMUX_DRIVE_50OHM | \
                               IOMUX_SPEED_MEDIUM | IOMUX_PULL_UP_100K | \
                               _IOMUX_PULL_ENABLE)
#define GPIO_NINA_GPIO        (GPIO_OUTPUT | GPIO_OUTPUT_ONE | \
                               GPIO_PORT3 | GPIO_PIN4 | IOMUX_NINA_GPIO)


/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public data
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Name: imxrt_bringup
 *
 * Description:
 *   Bring up board features
 *
 ****************************************************************************/

#if defined(CONFIG_BOARDCTL) || defined(CONFIG_BOARD_LATE_INITIALIZE)
int imxrt_bringup(void);
#endif

/****************************************************************************
 * Name: imxrt_spidev_initialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the EdgePro1.
 *
 ****************************************************************************/

void imxrt_spidev_initialize(void);

/****************************************************************************
 * Name: imxrt_gpio_initialize
 *
 * Description:
 *   Initialize GPIO drivers for use with /apps/examples/gpio
 *
 ****************************************************************************/

#ifdef CONFIG_DEV_GPIO
int imxrt_gpio_initialize(void);
#endif

/****************************************************************************
 * Name: imxrt_adc_initialize
 *
 * Description:
 *   Initialize ADC drivers
 *
 ****************************************************************************/

#ifdef CONFIG_IMXRT_ADC
int imxrt_adc_initialize(void);
#endif


#ifdef CONFIG_IMXRT_FLEXSPI
int imxrt_flexspi_nor_initialize(void);
#endif


/****************************************************************************
 * Name: imxrt_rgbled_setup
 *
 * Description:
 *   This function is called by board initialization logic to configure the
 *   RGB LED driver.  This function will register the driver as /dev/rgbled0.
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   Zero is returned on success.  Otherwise, a negated errno value is
 *   returned to indicate the nature of the failure.
 *
 ****************************************************************************/

#ifdef CONFIG_RGBLED
int imxrt_rgbled_setup(void);
#endif

#endif /* __ASSEMBLY__ */
#endif /* __BOARDS_ARM_IMXRT_EDGEPRO1_H */
