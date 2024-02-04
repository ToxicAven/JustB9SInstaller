#pragma once

// Credit to: https://github.com/d0k3/GodMode9/blob/master/arm9/source/system/vram0.h

#include "common.h"
#include "tar.h"

#define VRAM0_B9S_FIRM        "boot9strap.firm"
#define VRAM0_B9S_SHA         "boot9strap.firm.sha"

extern const char vram_data[];
extern const char vram_data_end[];

#define VRAM0_OFFSET    (uintptr_t)(vram_data)
#define VRAM0_LIMIT     (uintptr_t)(vram_data_end - vram_data)

#define TARDATA         ((void*) VRAM0_OFFSET)
#define TARDATA_(off)   ((void*) (u32) (VRAM0_OFFSET + (off)))
#define TARDATA_END     TARDATA_(VRAM0_LIMIT)

#define CheckVram0Tar() \
    (ValidateTarHeader(TARDATA, TARDATA_END) == 0)

#define FirstVTarEntry() \
    TARDATA

#define OffsetVTarEntry(off) \
    TARDATA_(off)

#define NextVTarEntry(tardata) \
    NextTarEntry(tardata, TARDATA_END)

#define GetVTarFileInfo(tardata, fname, fsize, is_dir) \
    GetTarFileInfo(tardata, fname, fsize, is_dir)

#define FindVTarFileInfo(fname, fsize) \
    FindTarFileInfo(TARDATA, TARDATA_END, fname, fsize)