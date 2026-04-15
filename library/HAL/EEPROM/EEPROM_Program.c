#include <avr/io.h>
#include <util/delay.h>
#include "LIB/STD_TYPES.h"

#define F_CPU 8000000UL
#define F_SCL 100000UL // 100kHz I2C
#define TWBR_VALUE ((((F_CPU / F_SCL) / 1) - 16) / 2)

// EEPROM Config
#define EEPROM_FIXED_ADDRESS 0xA0 // AT24Cxx base address
#define A2_CONNECTION 0           // A2 pin grounded

/* ======================= LOW LEVEL I2C ======================= */
static void I2C_Init(void)
{
    TWBR = (uint8_t)TWBR_VALUE;
    TWSR = 0x00; // Prescaler = 1
}

static void I2C_Start(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

static void I2C_RepeatedStart(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

static void I2C_Stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

static void I2C_Write(u8 data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

static u8 I2C_ReadACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

static u8 I2C_ReadNACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

/* ACK polling: Wait until EEPROM ready */
static void EEPROM_WaitReady(u8 devAddr)
{
    while (1)
    {
        I2C_Start();
        I2C_Write(devAddr | 0); // Write mode
        if ((TWSR & 0xF8) == 0x18) // SLA+W ACK
        {
            I2C_Stop();
            break;
        }
        I2C_Stop();
        _delay_ms(1);
    }
}

/* ======================= EEPROM FUNCTIONS ======================= */

void EEPROM_Init(void)
{
    I2C_Init();
}

void EEPROM_WriteByte(u16 memAddr, u8 data)
{
    u8 devAddr = EEPROM_FIXED_ADDRESS
               | (A2_CONNECTION << 2)
               | (u8)(memAddr >> 8);

    I2C_Start();
    I2C_Write(devAddr | 0); // Write mode
    I2C_Write((u8)memAddr); // Low byte address
    I2C_Write(data);
    I2C_Stop();

    EEPROM_WaitReady(devAddr);
}

u8 EEPROM_ReadByte(u16 memAddr)
{
    u8 data;
    u8 devAddr = EEPROM_FIXED_ADDRESS
               | (A2_CONNECTION << 2)
               | (u8)(memAddr >> 8);

    EEPROM_WaitReady(devAddr);

    I2C_Start();
    I2C_Write(devAddr | 0); // Write mode
    I2C_Write((u8)memAddr);

    I2C_RepeatedStart();
    I2C_Write(devAddr | 1); // Read mode
    data = I2C_ReadNACK();
    I2C_Stop();

    return data;
}

void EEPROM_ReadBytes(u16 startAddr, u8 *buffer, u16 length)
{
    u8 devAddr = EEPROM_FIXED_ADDRESS
               | (A2_CONNECTION << 2)
               | (u8)(startAddr >> 8);
    u16 i;

    EEPROM_WaitReady(devAddr);

    I2C_Start();
    I2C_Write(devAddr | 0); // Write mode
    I2C_Write((u8)startAddr);

    I2C_RepeatedStart();
    I2C_Write(devAddr | 1); // Read mode

    for (i = 0; i < length; i++)
    {
        if (i < (length - 1))
            buffer[i] = I2C_ReadACK();
        else
            buffer[i] = I2C_ReadNACK();
    }
    I2C_Stop();
}
