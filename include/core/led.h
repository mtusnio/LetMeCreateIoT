/**
 * @file led.h
 * @author Francois Berder
 * @date 2017
 * @copyright 3-clause BSD
 */

#ifndef H_CORE_LED
#define H_CORE_LED

#include <stdint.h>

/** Index of LED's */
enum LED_INDEX {
 LED_0 = 0x01,
 LED_1 = 0x02,
 ALL_LEDS = 0x03
};

/** Mode of LED's */
enum LED_MODE {
 ON_OFF_MODE,
 TIMER_MODE
};

/** Number of LEDS */
#define LED_CNT   (2)

/**
 * @brief Switch off all LEDs.
 *
 * @return 0 if successful, -1 otherwise
 */
int led_init(void);

/**
 * @brief Switch on some LEDs.
 *
 * @param[in] mask
 * @return 0 if successful, -1 otherwise
 */
int led_switch_on(uint8_t mask);

/**
 * @brief Switch off some LEDs.
 *
 * @param[in] mask
 * @return 0 if successful, -1 otherwise
 */
int led_switch_off(uint8_t mask);

/**
 * @brief Switch on/off each LED depending on corresponding bit in @p led_value
 *
 * Each bit of the mask represents a LED. Only LED's whose corresponding bit in mask is set to 1
 * will be switched on or off by this function depending on corresponding bit .
 *
 * For instance, to turn on LED_1 you have to set bit 1 of mask to 1 and bit 1 of value to 1. So,
 * mask = LED_1 (= 0x02)
 * value = 0x02
 *
 * @param[in] mask bit string to access LED'S
 * @param[in] value bit string to set LED's value
 * @return 0 if successful, -1 otherwise
 */
int led_set(uint8_t mask, uint8_t value);

/**
 * @brief Configure all LEDS from mask in on/off mode.
 *
 * This function is only there for compatibility reasons with LetMeCreate, it does not
 * do anything apart from returing 0.
 *
 * @param[in] mask bit string to access LED'S
 * @return 0 if successful, -1 otherwise
 */
int led_configure_on_off_mode(uint8_t mask);

/**
 * @brief Configure all LEDS from mask in timer mode. led_init must have been called before.
 *
 * This function is only there for compatibility reasons with LetMeCreate, it does not
 * do anything apart from returing -1.
 *
 * @param[in] mask bit string to access LED'S
 * @return 0 if successful, -1 otherwise
 */
int led_configure_timer_mode(uint8_t mask);

/**
 * @brief Get the mode of a LED.
 *
 * Since LED's on clickers only support ON_OFF_MODE, this function always set
 * led_mode to ON_OFF_MODE.
 *
 * @param[in] led_index
 * @param[out] led_mode Current mode of the LED (see #LED_MODE)
 * @return 0 if successful, -1 otherwise
 */
int led_get_mode(uint8_t led_index, uint8_t *led_mode);

/**
 * @brief Configure delays for LEDS. LEDS must have been configured in timer mode before.
 *
 * This function is only there for compatibility reasons with LetMeCreate, it does not
 * do anything apart from returing -1.
 *
 * @param[in] mask bit string to access LED'S
 * @param[in] delay_on Defines how long the LED will stay on (in milliseconds)
 * @param[in] delay_off Defines how long the LED will stay on (in milliseconds)
 * @return -1
 */
int led_set_delay(uint8_t mask, uint32_t delay_on, uint32_t delay_off);

/**
 * @brief Switch off all LED's.
 *
 * @return 0 if successful, -1 otherwise
 */
int led_release(void);

#endif
