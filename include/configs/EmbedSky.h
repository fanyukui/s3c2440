/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <gj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the EmbedSky TQ2440 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM920T			1	/* This is an ARM920T Core	*/
#define	CONFIG_S3C2440			1	/* in a SAMSUNG S3C2440 SoC     */
#define CONFIG_TQ2440			1	/* on a EmbedSky TQ2440 Board  */

/* input clock of PLL */
#define CONFIG_SYS_CLK_FREQ		12000000/* the TQ2440 has 12MHz input clock */
//#define CONFIG_SYS_CLK_FREQ		16934400 /* the TQ2440 has 16.9344MHz input clock */

#define USE_920T_MMU			1
#define CONFIG_USE_MMU

#define CONFIG_USB_DEVICE		1

#ifdef CONFIG_USB_DEVICE
#define CONFIG_USE_IRQ			1
#endif

/* enable EmbedSky Logo	*/
#define CONFIG_EMBEDSKY_LOGO			1

/* set LCD params */
#ifdef CONFIG_EMBEDSKY_LOGO

#define S35					1	//S35
#define W35					2	//W35=Q35
#define TFT240320				3	//T35
#define TFT480272				4	//W43 or Q43
#define VGA640480				5	//VGA 640*480
#define TFT800480				6	//A70
#define TFT800600				7	//A104
#define VGA1024768				8	//VGA 1024*768

#define LCD_TFT					W35

#if(LCD_TFT == W35)
#define	CONFIG_EMBEDSKY_LCD_VBPD		12
#define	CONFIG_EMBEDSKY_LCD_VFPD		4
#define	CONFIG_EMBEDSKY_LCD_VSPW		5
#define	CONFIG_EMBEDSKY_LCD_HBPD		21
#define	CONFIG_EMBEDSKY_LCD_HFPD		32
#define	CONFIG_EMBEDSKY_LCD_HSPW		44
#define	CONFIG_EMBEDSKY_LCD_CLKVAL		6

#elif(LCD_TFT == S35)
#define	CONFIG_EMBEDSKY_LCD_VBPD		3
#define	CONFIG_EMBEDSKY_LCD_VFPD		5
#define	CONFIG_EMBEDSKY_LCD_VSPW		15
#define	CONFIG_EMBEDSKY_LCD_HBPD		5
#define	CONFIG_EMBEDSKY_LCD_HFPD		15
#define	CONFIG_EMBEDSKY_LCD_HSPW		8
#define	CONFIG_EMBEDSKY_LCD_CLKVAL		7

#elif(LCD_TFT == TFT240320)
#define	CONFIG_EMBEDSKY_LCD_VBPD		1
#define	CONFIG_EMBEDSKY_LCD_VFPD		2
#define	CONFIG_EMBEDSKY_LCD_VSPW		1
#define	CONFIG_EMBEDSKY_LCD_HBPD		6
#define	CONFIG_EMBEDSKY_LCD_HFPD		3
#define	CONFIG_EMBEDSKY_LCD_HSPW		1
#define	CONFIG_EMBEDSKY_LCD_CLKVAL		2

#elif(LCD_TFT == TFT480272)
#define	CONFIG_EMBEDSKY_LCD_VBPD		2
#define	CONFIG_EMBEDSKY_LCD_VFPD		4
#define	CONFIG_EMBEDSKY_LCD_VSPW		8
#define	CONFIG_EMBEDSKY_LCD_HBPD		10
#define	CONFIG_EMBEDSKY_LCD_HFPD		19
#define	CONFIG_EMBEDSKY_LCD_HSPW		30
#define	CONFIG_EMBEDSKY_LCD_CLKVAL		4

#elif(LCD_TFT == VGA640480)
#define	CONFIG_EMBEDSKY_LCD_VBPD		29
#define	CONFIG_EMBEDSKY_LCD_VFPD		5
#define	CONFIG_EMBEDSKY_LCD_VSPW		4
#define	CONFIG_EMBEDSKY_LCD_HBPD		71
#define	CONFIG_EMBEDSKY_LCD_HFPD		40
#define	CONFIG_EMBEDSKY_LCD_HSPW		31
#define	CONFIG_EMBEDSKY_LCD_CLKVAL		1

#elif(LCD_TFT == TFT800480)
#define	CONFIG_EMBEDSKY_LCD_VBPD		4
#define	CONFIG_EMBEDSKY_LCD_VFPD		2
#define	CONFIG_EMBEDSKY_LCD_VSPW		2
#define	CONFIG_EMBEDSKY_LCD_HBPD		27
#define	CONFIG_EMBEDSKY_LCD_HFPD		14
#define	CONFIG_EMBEDSKY_LCD_HSPW		8
#define	CONFIG_EMBEDSKY_LCD_CLKVAL		2

#elif(LCD_TFT == TFT800600)
#define	CONFIG_EMBEDSKY_LCD_VBPD		4
#define	CONFIG_EMBEDSKY_LCD_VFPD		2
#define	CONFIG_EMBEDSKY_LCD_VSPW		2
#define	CONFIG_EMBEDSKY_LCD_HBPD		27
#define	CONFIG_EMBEDSKY_LCD_HFPD		14
#define	CONFIG_EMBEDSKY_LCD_HSPW		8
#define	CONFIG_EMBEDSKY_LCD_CLKVAL		2

#elif(LCD_TFT == VGA1024768)
#define	CONFIG_EMBEDSKY_LCD_VBPD		1
#define	CONFIG_EMBEDSKY_LCD_VFPD		1
#define	CONFIG_EMBEDSKY_LCD_VSPW		1
#define	CONFIG_EMBEDSKY_LCD_HBPD		15
#define	CONFIG_EMBEDSKY_LCD_HFPD		199
#define	CONFIG_EMBEDSKY_LCD_HSPW		15
#define	CONFIG_EMBEDSKY_LCD_CLKVAL		3

#endif
#endif

#define CONFIG_64MB_Nand		0		//添加了对64MB Nand Flash支持
#define CONFIG_128MB_Nand		0		//添加了对128MB Nand Flash支持，当为1时就是128MB的Nand Flash

/* enable 128MB SDRAM */
#define CONFIG_128MB_SDRAM		0

/* enable SDRAM 133MHz */
#define CONFIG_133MHZ_SDRAM		0

#define CONFIG_JFFS2_CMDLINE		1
#define CONFIG_JFFS2_NAND		1

#define MTDIDS_DEFAULT			"nand0=nandflash0"

#if(CONFIG_64MB_Nand == 1)
#define MTDPARTS_DEFAULT		"mtdparts=nandflash0:256k@0(bios)," \
					"48k(params)," \
					"144k(eboot)," \
					"1536k(logo)," \
					"2m(kernel)," \
					"-(root)"

#else
#if( LCD_TFT == VGA1024768 )
#define MTDPARTS_DEFAULT		"mtdparts=nandflash0:256k@0(bios)," \
                           		 "128k(params)," \
                           		 "128k(toc)," \
                           		 "256k(eboot)," \
                           		 "1792k(logo)," \
                           		 "3m(kernel)," \
                           		 "-(root)"
#else
#define MTDPARTS_DEFAULT		"mtdparts=nandflash0:256k@0(bios)," \
                           		 "128k(params)," \
                           		 "128k(toc)," \
                           		 "512k(eboot)," \
                           		 "1024k(logo)," \
                           		 "3m(kernel)," \
                           		 "-(root)"
#endif

#endif

/*
 * Size of malloc() pool
 */
#define CFG_MALLOC_LEN				(CFG_ENV_SIZE + 128*1024)
#define CFG_GBL_DATA_SIZE			128	/* size in bytes reserved for initial data */

/*
 * Hardware drivers
 */
#define CONFIG_DRIVER_DM9000			1
#define CONFIG_DM9000_BASE			0x20000300
#define DM9000_IO				CONFIG_DM9000_BASE
#define DM9000_DATA				(CONFIG_DM9000_BASE + 4)
#define CONFIG_DM9000_USE_16BIT

/*
 * select serial console configuration
 */
#define CONFIG_SERIAL1				1	/* we use SERIAL 1 on TQ2440 */

/************************************************************
 * RTC
 ************************************************************/
#define	CONFIG_RTC_S3C24X0			1

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE				115200

/* for tag(s) to transfer message to kernel, www.embedsky.net */
#define CONFIG_SETUP_MEMORY_TAGS		1
#define CONFIG_CMDLINE_TAG			1

/***********************************************************
 * Command definition
 ***********************************************************/
#define CONFIG_COMMANDS \
			(CONFIG_CMD_DFL	 | \
			CFG_CMD_CACHE	 | \
		    /* Start: by www.embedsky.net */ \
			CFG_CMD_PING     | \
			CFG_CMD_JFFS2    | \
			CFG_CMD_NAND	 | \
		    /* End: by www.embedsky.net */  \
			/*CFG_CMD_EEPROM |*/ \
			/*CFG_CMD_I2C	 |*/ \
			/*CFG_CMD_USB	 |*/ \
			CFG_CMD_REGINFO  | \
		    	CFG_CMD_ELF		 | \
			CFG_CMD_DATE)

/* this must be included AFTER the definition of CONFIG_COMMANDS (if any) */
#include <cmd_confdefs.h>

#define CONFIG_BOOTDELAY		3

#if CONFIG_128MB_SDRAM
#define CONFIG_BOOTARGS			"noinitrd root=/dev/mtdblock2 init=/linuxrc console=ttySAC0 mem=128M"
#else
#define CONFIG_BOOTARGS			"noinitrd root=/dev/mtdblock2 init=/linuxrc console=ttySAC0"
#endif
#define CONFIG_ETHADDR			0a:1b:2c:3d:4e:5f
#define CONFIG_NETMASK			255.255.255.0
#define CONFIG_IPADDR			192.168.1.6
#define CONFIG_SERVERIP			192.168.1.8
/*#define CONFIG_BOOTFILE		"elinos-lart" */
#define CONFIG_BOOTCOMMAND		"nand read 0x32000000 0x200000 0x300000;bootm 0x32000000;"

#if (CONFIG_COMMANDS & CFG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE		115200		/* speed to run kgdb serial port */
/* what's this ? it's not used anywhere */
#define CONFIG_KGDB_SER_INDEX		1		/* which serial port to use */
#endif

/*
 * Miscellaneous configurable options
 */
#define	CFG_LONGHELP				/* undef to save memory		*/
#define	CFG_PROMPT			"EmbedSky> "	/* Monitor Command Prompt	*/
#define	CFG_CBSIZE			256		/* Console I/O Buffer Size	*/
#define	CFG_PBSIZE			(CFG_CBSIZE+sizeof(CFG_PROMPT)+16) /* Print Buffer Size */
#define	CFG_MAXARGS			16		/* max number of command args	*/
#define	CFG_BARGSIZE			CFG_CBSIZE	/* Boot Argument Buffer Size	*/

#define	CFG_MEMTEST_START		0x30000000	/* memtest works on	*/
#ifdef	CONFIG_128MB_SDRAM
#define	CFG_MEMTEST_END			0x37F00000	/* 127 MB in DRAM	*/
#else
#define	CFG_MEMTEST_END			0x33F00000	/* 63 MB in DRAM	*/
#endif

#undef  CFG_CLKS_IN_HZ				/* everything, incl board info, in Hz */

#ifdef CONFIG_128MB_SDRAM
#define CFG_LOAD_ADDR			0x37000000	/* default load address	*/
#else
#define	CFG_LOAD_ADDR			0x33000000	/* default load address	*/
#endif

/* the PWM TImer 4 uses a counter of 15625 for 10 ms, so we need */
/* it to wrap 100 times (total 1562500) to get 1 sec. */
#define	CFG_HZ				1562500

/* valid baudrates */
#define CFG_BAUDRATE_TABLE		{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE		(128*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ		(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ		(4*1024)	/* FIQ stack */
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS		1	   /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1			0x30000000 /* SDRAM Bank #1 */
#if CONFIG_128MB_SDRAM
#define PHYS_SDRAM_1_SIZE		0x08000000 /* 128 MB */
#else
#define PHYS_SDRAM_1_SIZE		0x04000000 /* 64 MB */
#endif

#define PHYS_FLASH_1			0x00000000 /* Flash Bank #1 */

#define CFG_FLASH_BASE			PHYS_FLASH_1

#if(CONFIG_64MB_Nand == 1)
#define CONFIG_SURPORT_WINCE		1			//因为现在还不支持2K页面的wince
#endif

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */

#if 0
#define CONFIG_AMD_LV400		1	/* uncomment this if you have a LV400 flash */
#endif
#define CONFIG_AMD_LV800		1	/* uncomment this if you have a LV800 flash */

#define CFG_MAX_FLASH_BANKS		1	/* max number of memory banks */
#ifdef CONFIG_AMD_LV800
#define PHYS_FLASH_SIZE			0x00200000 /* 1MB */
#define CFG_MAX_FLASH_SECT		(19)	/* max number of sectors on one chip */
#define CFG_ENV_ADDR			(CFG_FLASH_BASE + 0x1F0000) /* addr of environment */
#endif
#ifdef CONFIG_AMD_LV400
#define PHYS_FLASH_SIZE			0x00080000 /* 512KB */
#define CFG_MAX_FLASH_SECT		(11)	/* max number of sectors on one chip */
#define CFG_ENV_ADDR			(CFG_FLASH_BASE + 0x070000) /* addr of environment */
#endif

/* timeout values are in ticks */
#define CFG_FLASH_ERASE_TOUT		(5*CFG_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT		(5*CFG_HZ) /* Timeout for Flash Write */

//#define	CFG_ENV_IS_IN_FLASH		1
#define CFG_ENV_IS_IN_NAND		1
#define CFG_ENV_OFFSET			0x40000
#define CFG_ENV_SIZE64			0xc000	/* Total Size of Environment Sector */
#if(CONFIG_64MB_Nand == 1)
#define CFG_ENV_SIZE			0xc000	/* Total Size of Environment Sector */
#else
#define CFG_ENV_SIZE			0x20000	/* Total Size of Environment Sector */
#endif

/*-----------------------------------------------------------------------
 * NAND flash settings
 */
#define CFG_NAND_BASE			0
#define CFG_MAX_NAND_DEVICE		1
#define NAND_MAX_CHIPS			1

#endif	/* __CONFIG_H */
