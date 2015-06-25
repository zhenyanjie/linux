#ifndef __DRM_I2C_TDA998X_H__
#define __DRM_I2C_TDA998X_H__

struct tda998x_encoder_params {
	u8 swap_b;
	u8 mirr_b;
	u8 swap_a;
	u8 mirr_a;
	u8 swap_d;
	u8 mirr_d;
	u8 swap_c;
	u8 mirr_c;
	u8 swap_f;
	u8 mirr_f;
	u8 swap_e;
	u8 mirr_e;

	u8 audio_cfg;
	u8 audio_clk_cfg;
	u8 audio_frame[6];

	enum {
		AFMT_SPDIF,
		AFMT_I2S
	} audio_format;

	unsigned audio_sample_rate;
};

#endif
