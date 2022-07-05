#include "flash.h"

/* Exported functions ------------------------------------------------------*/
Bool_t Flash_Store(uint64_t *data, uint16_t chunks)
{
    Bool_t result = TRUE;
    HAL_FLASH_Unlock();

    for (uint16_t index = 0; index < chunks; index++)
    {
        if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD,
                              (FLASH_STORAGE_BASE_ADDR + (index << 3)),
                              data[index]) != HAL_OK)
        {
            result = FALSE;
            break;
        }
    }

    HAL_FLASH_Lock();

    return result;
}

void Flash_Restore(uint64_t *data, uint16_t chunks)
{
    HAL_FLASH_Unlock();

    for (uint16_t index = 0; index < chunks; index++)
    {
        data[index] = *((volatile uint64_t *)(FLASH_STORAGE_BASE_ADDR + (index << 3)));
    }

    HAL_FLASH_Lock();
}

Bool_t Flash_Erase(void)
{
    FLASH_EraseInitTypeDef erase;
    uint32_t page_error;
    Bool_t result = TRUE;

    erase.Banks = FLASH_STORAGE_BANK;
    erase.NbPages = 1;
    erase.Page = FLASH_STORAGE_PAGE;
    erase.TypeErase = FLASH_TYPEERASE_PAGES;

    HAL_FLASH_Unlock();

    if (HAL_FLASHEx_Erase(&erase, &page_error) != HAL_OK)
    {
        result = FALSE;   
    }

    HAL_FLASH_Lock();

    return result;
}