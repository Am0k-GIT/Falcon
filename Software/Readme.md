## Конфигурирование Marlin для работы с платой Falcon_v1

Рекомендуется использовать модицикацию последней стабильной версии оригинальной прошивки.
Готовая прошивка предлагается как пример. Для добавления поддержки платы
в оригинальную прошивку выполните следующие пункты:

1.	Добавляем файл определения пинов: `..\ Marlin\src\pins\stm32f4\pins_FALCON_V1.h`

2.  Добавляем папку с файлами определения кастомного варианта платы: `..\buildroot\share\PlatformIO\variants\MARLIN_FALCON\..`

3.	Добавляем в файл `..\Marlin\src\pins\pins.h`:

```C
#elif MB(FALCON_V1)
  #include "stm32f4/pins_FALCON_V1.h"               // STM32F4                              env:Falcon_v1 env:Falcon_v1_dfu env:Falcon_v1_stlink
```

Важно: в закомментированной части строки есть информация о необходимом окружении, она парсится скриптом во время подготовки 
к компиляции, поэтому должна соответствовать имени вашего окружения на шаге 5.

4.	Добавляем в файл `..\Marlin\src\core\boards.h`:

```C
#define BOARD_FALCON_V1               5245  // Falcon_v1 (STM32F407VE)
```

Номер после названия платы может быть любым (при выходе свежих версий система нумерации периодически изменяется, а уже 
существующие номера сдвигаются), главное чтобы он был уникальным.

5.	В файл `..\ini\stm32f4.ini` добавляем определение окружения:

```C
#
# Falcon_v1 board
# STM32F407VET6 ARM Cortex-M4
#
[env:Falcon_v1]
extends                     = stm32_variant
platform_packages           = ${stm_flash_drive.platform_packages}
board                       = genericSTM32F407VET6
board_build.variant         = MARLIN_FALCON
board_build.offset          = 0x8000
board_upload.offset_address = 0x08000000
build_flags                 = ${stm32_variant.build_flags} ${stm32f4_I2C1.build_flags}
                               -Os -DHAL_PCD_MODULE_ENABLED
                               -DHAL_UART_MODULE_ENABLED
                               -DSERIAL_RX_BUFFER_SIZE=1024 -DSERIAL_TX_BUFFER_SIZE=1024
                               -DSTEP_TIMER_IRQ_PRIO=0
monitor_speed               = 250000

[env:Falcon_v1_dfu]
extends                     = env:Falcon_v1
upload_protocol             = dfu

[env:Falcon_v1_stlink]
extends                     = env:Falcon_v1
upload_protocol             = stlink
```

6.  Добавляем header-файл с калибровкой датчика температуры PT1000: `.. \Marlin\src\module\thermistor\thermistor_1050.h`.

7. 	В файл `..\Marlin\src\module\thermistor\thermistors.h` добавляем строки:

```C
#if ANY_THERMISTOR_IS(1050)   // Pt1000 with MCP6022 amp
  #include "thermistor_1050.h"
#endif
```

8.	В файлe `..\Marlin\Configuration.h` производим необходимые изменения 

- указываем нашу плату:
```C
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_FALCON_V1
#endif
```
- устанавливаем номер порта для USB:
```C
#define SERIAL_PORT -1
```
- устанавливаем скорость обмена:
```C
#define BAUDRATE 250000
```
- при использовании датчиков температуры PT1000 (при их подключении к соответствующим разъемам)
указываем это:
```C
#define TEMP_SENSOR_0 1050
```

9.	Первоначально необходимо залить сам загрузчик. Используйте файл BOOTLOADER_FALCON_SPI_SD.hex из репозитория. 
Предварительно выполните полную очистку FLASH. После загрузите файл bootloader’а при помощи ST-Link и 
STM32CubeProgrammer. 

10. Соберите файл прошивки используя окружение `env:Falcon_v1`. Затем вы можете заливать/обновлять 
прошивку просто записывая файл прошивки Marlin с именем firmware.bin на SD карту. При включении принтера 
bootloader проверит SD карту на наличие файла firmware.bin и в случае его обнаружения запишет его во 
FLASH память МК, а после удачной верификации переименует файл в firmware.cur и запустит основную прошивку.
Так же вы можете использовать окружение `env:Falcon_v1_dfu` для прошивки по USB (для этого необходимо 
перезагрузить плату кнопкой RST с зажатой кнопкой BOOT0), либо `env:Falcon_v1_stlink` для прошивки 
с помощью ST-LINK через специальный разъем программирования на плате.

11. После прошивки не забываем сбросить настройки EEPROM командой `M502` и сохранить их вновь командой `M500`.
