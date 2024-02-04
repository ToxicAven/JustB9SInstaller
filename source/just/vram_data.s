@ Credit to: https://github.com/d0k3/GodMode9/blob/master/arm9/source/system/vram_data.s

.section .rodata.vram_data

.align 2
.global vram_data
vram_data:
	.incbin "../output/vram0.tar"
.global vram_data_end
vram_data_end: