/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

// PT1000 with TPMCP6022 amp 

#define REVERSE_TEMP_SENSOR_RANGE_1050 1

constexpr temp_entry_t temptable_1050[] PROGMEM = {
  { OV( 49),   0 },
  { OV( 79),  10 },
  { OV(108),  20 },
  { OV(137),  30 },
  { OV(165),  40 },
  { OV(194),  50 },
  { OV(222),  60 },
  { OV(251),  70 },
  { OV(306),  90 },
  { OV(362), 110 },
  { OV(416), 130 },
  { OV(470), 150 },
  { OV(523), 170 },
  { OV(576), 190 },
  { OV(627), 210 },
  { OV(679), 230 },
  { OV(729), 250 },
  { OV(779), 270 },
  { OV(829), 290 },
  { OV(877), 310 },
  { OV(926), 330 },
  { OV(973), 350 },
  {OV(1019), 370 },
};

