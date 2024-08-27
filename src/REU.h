/*
 *  REU.h - 17xx REU emulation
 *
 *  Frodo Copyright (C) Christian Bauer
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _REU_H
#define _REU_H


class MOS6510;
class Prefs;

class REU {
public:
	REU(MOS6510 *CPU);
	~REU();

	void NewPrefs(const Prefs *prefs);
	void Reset();
	uint8_t ReadRegister(uint16_t adr);
	void WriteRegister(uint16_t adr, uint8_t byte);
	void FF00Trigger();

private:
	void open_close_reu(int old_size, int new_size);
	void execute_dma();

	MOS6510 *the_cpu;	// Pointer to 6510

	uint8_t *ex_ram;	// REU expansion RAM

	uint32_t ram_size;	// Size of expansion RAM
	uint32_t ram_mask;	// Expansion RAM address bit mask

	uint8_t regs[16];	// REU registers
};

#endif
