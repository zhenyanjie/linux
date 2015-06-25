#ifndef __NVBIOS_RAMCFG_H__
#define __NVBIOS_RAMCFG_H__

struct nouveau_bios;

struct nvbios_ramcfg {
	unsigned rammap_11_08_01;
	unsigned rammap_11_08_0c;
	unsigned rammap_11_08_10;
	unsigned rammap_11_11_0c;

	unsigned ramcfg_11_01_01;
	unsigned ramcfg_11_01_02;
	unsigned ramcfg_11_01_04;
	unsigned ramcfg_11_01_08;
	unsigned ramcfg_11_01_10;
	unsigned ramcfg_11_01_20;
	unsigned ramcfg_11_01_40;
	unsigned ramcfg_11_01_80;
	unsigned ramcfg_11_02_03;
	unsigned ramcfg_11_02_04;
	unsigned ramcfg_11_02_08;
	unsigned ramcfg_11_02_10;
	unsigned ramcfg_11_02_40;
	unsigned ramcfg_11_02_80;
	unsigned ramcfg_11_03_0f;
	unsigned ramcfg_11_03_30;
	unsigned ramcfg_11_03_c0;
	unsigned ramcfg_11_03_f0;
	unsigned ramcfg_11_04;
	unsigned ramcfg_11_06;
	unsigned ramcfg_11_07_02;
	unsigned ramcfg_11_07_04;
	unsigned ramcfg_11_07_08;
	unsigned ramcfg_11_07_10;
	unsigned ramcfg_11_07_40;
	unsigned ramcfg_11_07_80;
	unsigned ramcfg_11_08_01;
	unsigned ramcfg_11_08_02;
	unsigned ramcfg_11_08_04;
	unsigned ramcfg_11_08_08;
	unsigned ramcfg_11_08_10;
	unsigned ramcfg_11_08_20;
	unsigned ramcfg_11_09;

	unsigned timing[11];
	unsigned timing_20_2e_03;
	unsigned timing_20_2e_30;
	unsigned timing_20_2e_c0;
	unsigned timing_20_2f_03;
	unsigned timing_20_2c_003f;
	unsigned timing_20_2c_1fc0;
	unsigned timing_20_30_f8;
	unsigned timing_20_30_07;
	unsigned timing_20_31_0007;
	unsigned timing_20_31_0078;
	unsigned timing_20_31_0780;
	unsigned timing_20_31_0800;
	unsigned timing_20_31_7000;
	unsigned timing_20_31_8000;
};

u8 nvbios_ramcfg_count(struct nouveau_bios *);
u8 nvbios_ramcfg_index(struct nouveau_subdev *);

#endif
