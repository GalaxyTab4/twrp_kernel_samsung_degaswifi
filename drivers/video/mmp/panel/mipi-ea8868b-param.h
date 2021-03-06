/* drivers/video/mmp/panel/mipi-ea8868b-param.h
 *
 * Copyright (C) 2014 Samsung Electronics Co, Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MIPI_EA8868B_PARAM_H
#define __MIPI_EA8868B_PARAM_H

#include <video/mipi_display.h>

#define EA8868B_SMART_DIMMING
#define EA8868B_SLEEP_IN_DELAY 210
#define EA8868B_SLEEP_OUT_DELAY 100
#define EA8868B_DISP_ON_DELAY 120
#define EA8868B_DISP_OFF_DELAY 50

#define HS_MODE 0
#define LP_MODE 1

enum {
	GAMMA_30CD,
	GAMMA_40CD,
	GAMMA_50CD,
	GAMMA_60CD,
	GAMMA_70CD,
	GAMMA_80CD,
	GAMMA_90CD,
	GAMMA_100CD,
	GAMMA_110CD,
	GAMMA_120CD,
	GAMMA_130CD,
	GAMMA_140CD,
	GAMMA_150CD,
	GAMMA_160CD,
	GAMMA_170CD,
	GAMMA_180CD,
	GAMMA_190CD,
	GAMMA_200CD,
	GAMMA_210CD,
	GAMMA_220CD,
	GAMMA_230CD,
	GAMMA_240CD,
	GAMMA_250CD,
	GAMMA_260CD,
	GAMMA_270CD,
	GAMMA_280CD,
	GAMMA_290CD,
	GAMMA_300CD,
};

static int lux_tbl_acl[] = {
	30, 40, 50, 60, 70, 80,
	90, 100, 110, 120, 130, 140,
	150, 160, 170, 180, 190, 200,
	210, 220, 230, 240, 250, 260,
	270, 280, 290, 300,
};

static char pkt_size_cmd[] = {0x1};

static char pkt_size_cmd_4[] = {0x4};

static char read_id[] = {0x04};
static char read_id1[] = {0xda};
static char read_id2[] = {0xdb};
static char read_id3[] = {0xdc};


static u8 ea8868b_exit_sleep[] = {0x11, 0x00};
static u8 ea8868b_display_on[] = {0x29, 0x00};
static u8 ea8868b_display_off[] = {0x28, 0x00};
static char ea8868b_sleep_in[] = {0x10};


static struct mmp_dsi_cmd_desc read_id_cmds[] = {
	{MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE, HS_MODE, 0,
		sizeof(pkt_size_cmd_4), pkt_size_cmd_4},
	{MIPI_DSI_DCS_READ, HS_MODE, 0, sizeof(read_id), read_id},
};

static struct mmp_dsi_cmd_desc read_id1_cmds[] = {
	{MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE, HS_MODE, 0,
		sizeof(pkt_size_cmd), pkt_size_cmd},
	{MIPI_DSI_DCS_READ, HS_MODE, 0, sizeof(read_id1), read_id1},
};

static struct mmp_dsi_cmd_desc read_id2_cmds[] = {
	{MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE, HS_MODE, 0,
		sizeof(pkt_size_cmd), pkt_size_cmd},
	{MIPI_DSI_DCS_READ, HS_MODE, 0, sizeof(read_id2), read_id2},
};

static struct mmp_dsi_cmd_desc read_id3_cmds[] = {
	{MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE, HS_MODE, 0,
		sizeof(pkt_size_cmd), pkt_size_cmd},
	{MIPI_DSI_DCS_READ, HS_MODE, 0, sizeof(read_id3), read_id3},
};

static char level2_comma_set[] = {
	0xF0,
	0x5A, 0x5A,
};

static char nvm_refresh_off[] = {
	0xB3, 0x00,
};

static char global_parameter_access[] = {
	0xB0, 0x06,
};

static char eot_check_disable[] = {
	0xE0, 0x41,
};

static char display_control_set[] = {
	0xF2,
	0x02, 0x03, 0x1C, 0x10, 0x10,
};
static char gtcon_control[] = {
	0xF7,
	0x09,
};
static char ltps_timing_set[] = {
	0xF8,
	0x05, 0x71, 0xAC, 0x80, 0x8F,
	0x0F, 0x48, 0x00, 0x00, 0x3A,
	0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x07, 0x06, 0x24, 0x24,
	0x24, 0x00, 0x00
};

static char level3_comma_set[] = {
	0xFC,
	0x5A, 0x5A,
};

static char key_command_set[] = {
	0xF1,
	0x5A, 0x5A
};

static char power_ctrl_set[] = {
	0xF4,
	0xAB, 0x6A, 0x00, 0x55, 0x03,
};

static char gamma_flag_set[] = {
	0xFB,
	0x00, 0x5A
};

static char gamma_set[] = {
	0xF9,
	/* default gamma : 300cd */
	0x00, 0xC0, 0xBA, 0xA5, 0xCF, 0xC0, 0xC8, 0x55,
	0x00, 0xE0, 0xB8, 0xA3, 0xCD, 0xBE, 0xC9, 0x55,
	0x00, 0xE7, 0xB8, 0xA3, 0xCD, 0xBE, 0xCF, 0x55,
};

#ifndef EA8868B_SMART_DIMMING
static char gamma_set_default[][24] = {
	{0x00, 0x6E, 0xCB, 0xB1, 0xCE, 0xBA, 0x85, 0x55, 0x00, 0x7F, 0xC9, 0xAF,
	0xCF, 0xBB, 0x85, 0x55, 0x00, 0x83, 0xC9, 0xAF, 0xD2, 0xBF, 0x85, 0x55},
	{0x00, 0x6E, 0xCB, 0xB1, 0xCE, 0xBA, 0x85, 0x55, 0x00, 0x7F, 0xC9, 0xAF,
	0xCF, 0xBB, 0x85, 0x55, 0x00, 0x83, 0xC9, 0xAF, 0xD2, 0xBF, 0x85, 0x55},
	{0x00, 0x74, 0xCB, 0xB0, 0xCD, 0xBA, 0x9D, 0x55, 0x00, 0x86, 0xCA, 0xAD,
	0xCD, 0xBB, 0x9D, 0x55, 0x00, 0x8A, 0xCA, 0xAD, 0xCF, 0xC0, 0x9D, 0x55},
	{0x00, 0x79, 0xC9, 0xAF, 0xCE, 0xBF, 0x94, 0x55, 0x00, 0x8C, 0xC8, 0xAC,
	0xCD, 0xC0, 0x95, 0x55, 0x00, 0x91, 0xC8, 0xAC, 0xCF, 0xC4, 0x95, 0x55},
	{0x00, 0x7E, 0xC9, 0xAE, 0xCE, 0xBE, 0xA6, 0x55, 0x00, 0x92, 0xC7, 0xAB,
	0xCD, 0xBE, 0xA7, 0x55, 0x00, 0x97, 0xC7, 0xAB, 0xCE, 0xC3, 0xA8, 0x55},
	{0x00, 0x82, 0xC8, 0xAE, 0xCE, 0xBD, 0xA2, 0x55, 0x00, 0x97, 0xC6, 0xAB,
	0xCD, 0xBD, 0xA2, 0x55, 0x00, 0x9C, 0xC6, 0xAB, 0xCE, 0xC1, 0xA4, 0x55},
	{0x00, 0x87, 0xC6, 0xAD, 0xD1, 0xBB, 0xB3, 0x55, 0x00, 0x9C, 0xC5, 0xAA,
	0xCF, 0xBC, 0xB3, 0x55, 0x00, 0xA1, 0xC5, 0xAA, 0xCF, 0xC0, 0xB5, 0x55},
	{0x00, 0x8B, 0xC5, 0xAE, 0xD0, 0xBB, 0xAE, 0x55, 0x00, 0xA1, 0xC4, 0xAB,
	0xCE, 0xBC, 0xAF, 0x55, 0x00, 0xA6, 0xC4, 0xAB, 0xCE, 0xC0, 0xB1, 0x55},
	{0x00, 0x8E, 0xC3, 0xAE, 0xCE, 0xBE, 0xAA, 0x55, 0x00, 0xA5, 0xC2, 0xAB,
	0xCC, 0xBF, 0xAA, 0x55, 0x00, 0xAA, 0xC2, 0xAB, 0xCC, 0xC2, 0xAD, 0x55},
	{0x00, 0x91, 0xC3, 0xAD, 0xCF, 0xBF, 0xBA, 0x55, 0x00, 0xA9, 0xC2, 0xAA,
	0xCD, 0xBF, 0xBA, 0x55, 0x00, 0xAE, 0xC2, 0xAA, 0xCD, 0xC2, 0xBD, 0x55},
	{0x00, 0x95, 0xC2, 0xAD, 0xCD, 0xC1, 0xB6, 0x55, 0x00, 0xAD, 0xC1, 0xAA,
	0xCB, 0xC1, 0xB6, 0x55, 0x00, 0xB2, 0xC1, 0xAA, 0xCB, 0xC4, 0xBA, 0x55},
	{0x00, 0x98, 0xC2, 0xAD, 0xCD, 0xC0, 0xC5, 0x55, 0x00, 0xB0, 0xC0, 0xAB,
	0xCB, 0xC0, 0xC6, 0x55, 0x00, 0xB6, 0xC0, 0xAB, 0xCB, 0xC3, 0xC9, 0x55},
	{0x00, 0x9B, 0xC1, 0xAB, 0xCE, 0xC3, 0xC1, 0x55, 0x00, 0xB4, 0xBF, 0xA9,
	0xCC, 0xC2, 0xC2, 0x55, 0x00, 0xBA, 0xBF, 0xA9, 0xCC, 0xC4, 0xC6, 0x55},
	{0x00, 0x9E, 0xBF, 0xAB, 0xCD, 0xC0, 0xC1, 0x55, 0x00, 0xB8, 0xBD, 0xA9,
	0xCB, 0xC0, 0xC2, 0x55, 0x00, 0xBE, 0xBD, 0xA9, 0xCB, 0xC2, 0xC6, 0x55},
	{0x00, 0xA1, 0xBF, 0xAA, 0xCF, 0xC0, 0xC7, 0x55, 0x00, 0xBB, 0xBD, 0xA8,
	0xCD, 0xBF, 0xC7, 0x55, 0x00, 0xC1, 0xBD, 0xA8, 0xCD, 0xC1, 0xCC, 0x55},
	{0x00, 0xA3, 0xBF, 0xAA, 0xCE, 0xC1, 0xC3, 0x55, 0x00, 0xBE, 0xBE, 0xA7,
	0xCC, 0xC0, 0xC4, 0x55, 0x00, 0xC4, 0xBE, 0xA7, 0xCC, 0xC2, 0xC9, 0x55},
	{0x00, 0xA6, 0xBE, 0xAA, 0xCD, 0xBF, 0xC3, 0x55, 0x00, 0xC1, 0xBD, 0xA8,
	0xCB, 0xBE, 0xC4, 0x55, 0x00, 0xC7, 0xBD, 0xA8, 0xCB, 0xC0, 0xC9, 0x55},
	{0x00, 0xA9, 0xBD, 0xA9, 0xCE, 0xC0, 0xC0, 0x55, 0x00, 0xC4, 0xBC, 0xA6,
	0xCC, 0xBF, 0xC1, 0x55, 0x00, 0xCB, 0xBC, 0xA6, 0xCC, 0xC1, 0xC6, 0x55},
	{0x00, 0xAB, 0xBD, 0xA9, 0xCD, 0xC2, 0xC6, 0x55, 0x00, 0xC8, 0xBB, 0xA6,
	0xCC, 0xC1, 0xC7, 0x55, 0x00, 0xCE, 0xBB, 0xA6, 0xCC, 0xC2, 0xCC, 0x55},
	{0x00, 0xAE, 0xBD, 0xA8, 0xCD, 0xBF, 0xC6, 0x55, 0x00, 0xCA, 0xBC, 0xA6,
	0xCB, 0xBE, 0xC7, 0x55, 0x00, 0xD0, 0xBC, 0xA6, 0xCB, 0xBF, 0xCC, 0x55},
	{0x00, 0xB0, 0xBD, 0xA7, 0xCD, 0xC1, 0xC3, 0x55, 0x00, 0xCD, 0xBB, 0xA5,
	0xCC, 0xBF, 0xC4, 0x55, 0x00, 0xD4, 0xBB, 0xA5, 0xCC, 0xC0, 0xC9, 0x55},
	{0x00, 0xB2, 0xBC, 0xA7, 0xCD, 0xC2, 0xC8, 0x55, 0x00, 0xD0, 0xBB, 0xA5,
	0xCB, 0xC1, 0xC9, 0x55, 0x00, 0xD6, 0xBB, 0xA5, 0xCB, 0xC1, 0xCF, 0x55},
	{0x00, 0xB5, 0xBB, 0xA7, 0xCE, 0xC0, 0xC8, 0x55, 0x00, 0xD3, 0xB9, 0xA5,
	0xCC, 0xBE, 0xC9, 0x55, 0x00, 0xDA, 0xB9, 0xA5, 0xCC, 0xBF, 0xCF, 0x55},
	{0x00, 0xB7, 0xBB, 0xA7, 0xCD, 0xC1, 0xC5, 0x55, 0x00, 0xD5, 0xB9, 0xA5,
	0xCB, 0xC0, 0xC6, 0x55, 0x00, 0xDC, 0xB9, 0xA5, 0xCB, 0xC0, 0xCC, 0x55},
	{0x00, 0xB9, 0xBB, 0xA6, 0xCE, 0xBF, 0xC5, 0x55, 0x00, 0xD8, 0xB9, 0xA4,
	0xCC, 0xBD, 0xC6, 0x55, 0x00, 0xDF, 0xB9, 0xA4, 0xCC, 0xBE, 0xCC, 0x55},
	{0x00, 0xBB, 0xBA, 0xA5, 0xCE, 0xC0, 0xCA, 0x55, 0x00, 0xDA, 0xB9, 0xA3,
	0xCC, 0xBF, 0xCB, 0x55, 0x00, 0xE1, 0xB9, 0xA3, 0xCC, 0xBF, 0xD1, 0x55},
	{0x00, 0xBD, 0xBA, 0xA6, 0xCE, 0xBE, 0xCA, 0x55, 0x00, 0xDD, 0xB8, 0xA4,
	0xCC, 0xBC, 0xCB, 0x55, 0x00, 0xE4, 0xB8, 0xA4, 0xCC, 0xBD, 0xD1, 0x55},
	{0x00, 0xC0, 0xBA, 0xA5, 0xCF, 0xC0, 0xC8, 0x55, 0x00, 0xE0, 0xB8, 0xA3,
	0xCD, 0xBE, 0xC9, 0x55, 0x00, 0xE7, 0xB8, 0xA3, 0xCD, 0xBE, 0xCF, 0x55},
};
#endif

static char gamma_flag_set_2[] = {
	0xFB,
	0x00, 0xa5,
};

static char elvss_cond_set[] = {
	0xB2,
	0x06, 0x06, 0x06, 0x06
};

static char elvss_on[] = {
	0xB1,
	0x0B, 0x16
};

/********************* ACL *******************/
static char acl_on[] = {
	0xC0,
	0x01
};

static char acl_off[] = {
	0xC0,
	0x00
};

static char acl_cond_set_40[] = {
	0xC1,
	0x4D, 0x96, 0x1D, 0x00, 0x00,
	0x01, 0xDF, 0x00, 0x00, 0x03,
	0x1F, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x06, 0x11, 0x1A,
	0x20, 0x25, 0x29, 0x2D, 0x30,
	0x33, 0x35
};
static char acl_cond_set_50[] = {
	0xC1,
	0x4D, 0x96, 0x1D, 0x00, 0x00,
	0x01, 0xDF, 0x00, 0x00, 0x03,
	0x1F, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x08, 0x16, 0x22,
	0x2B, 0x31, 0x37, 0x3B, 0x3F,
	0x43, 0x46
};

static struct mmp_dsi_cmd_desc ea8868b_acl_on_cmds[] = {
	{MIPI_DSI_DCS_SHORT_WRITE_PARAM, HS_MODE, 0, sizeof(acl_on),
		acl_on},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(acl_cond_set_40),
		acl_cond_set_40},
};

static struct mmp_dsi_cmd_desc ea8868b_acl_off_cmds[] = {
	{MIPI_DSI_DCS_SHORT_WRITE_PARAM, HS_MODE, 0, sizeof(acl_off),
		acl_off},
};

static struct mmp_dsi_cmd_desc ea8868b_gamma_update_cmds[] = {
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 5, sizeof(gamma_flag_set),
		gamma_flag_set},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 5, sizeof(gamma_set),
		gamma_set},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 5, sizeof(gamma_flag_set_2),
		gamma_flag_set_2},
};

static struct mmp_dsi_cmd_desc ea8868b_elvss_update_cmds[] = {
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(elvss_on),
		elvss_on},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(elvss_cond_set),
		elvss_cond_set},
};
static struct mmp_dsi_cmd_desc ea8868b_video_init_cmds[] = {
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(key_command_set),
		key_command_set},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(level2_comma_set),
		level2_comma_set},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(level3_comma_set),
		level3_comma_set},

	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 10, sizeof(display_control_set),
		display_control_set},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(gtcon_control),
		gtcon_control},

	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(ltps_timing_set),
		ltps_timing_set},

	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(gamma_flag_set),
		gamma_flag_set},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(gamma_flag_set_2),
		gamma_flag_set_2},

	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(elvss_on),
		elvss_on},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(elvss_cond_set),
		elvss_cond_set},

	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(power_ctrl_set),
		power_ctrl_set},

	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(nvm_refresh_off),
		nvm_refresh_off},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(global_parameter_access),
		global_parameter_access},
	{MIPI_DSI_DCS_LONG_WRITE, HS_MODE, 0, sizeof(eot_check_disable),
		eot_check_disable},

};

static struct mmp_dsi_cmd_desc ea8868b_video_display_off_cmds[] = {
	{MIPI_DSI_DCS_SHORT_WRITE, HS_MODE, EA8868B_DISP_OFF_DELAY,
		sizeof(ea8868b_display_off), ea8868b_display_off},
};

static struct mmp_dsi_cmd_desc ea8868b_video_sleep_in_cmds[] = {
	{MIPI_DSI_DCS_SHORT_WRITE, HS_MODE, EA8868B_SLEEP_IN_DELAY,
		sizeof(ea8868b_sleep_in), ea8868b_sleep_in},
};

static struct mmp_dsi_cmd_desc ea8868b_video_power_on_cmds[] = {
	{MIPI_DSI_DCS_SHORT_WRITE, HS_MODE, EA8868B_SLEEP_OUT_DELAY,
		sizeof(ea8868b_exit_sleep), ea8868b_exit_sleep},
	{MIPI_DSI_DCS_SHORT_WRITE, HS_MODE, EA8868B_DISP_ON_DELAY,
		sizeof(ea8868b_display_on), ea8868b_display_on},
};
#endif /* __MIPI_EA8868B_PARAM_H */
