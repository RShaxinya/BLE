
#ifndef ESTC_SERVICE_H__
#define ESTC_SERVICE_H__

#include <stdint.h>

#include "ble.h"
#include "sdk_errors.h"

#define ESTC_BASE_UUID { 0x89, 0xED, 0x3C, 0x19, 0x84, 0x1A, /* - */ 0x31, 0x97, /* - */ 0x09, 0x42, /* - */ 0x2E, 0x32, /* - */ 0x00, 0x00, 0xA3, 0x3D }

#define ESTC_SERVICE_UUID 0x6577


#define ESTC_GATT_CHAR_1_UUID 0x6578

typedef struct
{
    uint16_t service_handle;
    uint16_t connection_handle;
    uint8_t uuid_type;

   
    ble_gatts_char_handles_t char1_handles;
} ble_estc_service_t;

ret_code_t estc_ble_service_init(ble_estc_service_t *service);

void estc_ble_service_on_ble_event(const ble_evt_t *ble_evt, void *ctx);

void estc_update_characteristic_1_value(ble_estc_service_t *service, int32_t *value);


#endif /* ESTC_SERVICE_H__ */
