#ifndef __FLASH_H
#define __FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "generic.h"

#define FLASH_STORAGE_BANK FLASH_BANK_1
#define FLASH_STORAGE_PAGE (FLASH_PAGE_NB - 1)
#define FLASH_START_ADDR 0x8000000UL
#define FLASH_STORAGE_BASE_ADDR (FLASH_START_ADDR + (FLASH_PAGE_SIZE * FLASH_STORAGE_PAGE))

/* Exported functions ------------------------------------------------------*/
extern Bool_t Flash_Store(uint64_t *data, uint16_t chunks);
extern void Flash_Restore(uint64_t *data, uint16_t chunks);
extern Bool_t Flash_Erase(void);

#ifdef __cplusplus
}
#endif

#endif