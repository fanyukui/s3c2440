#include <common.h>
#include <s3c2410.h>

#define GSTATUS1        (*(volatile unsigned int *)0x560000B0)
#define BUSY            1

#define NAND_SECTOR_SIZE	512
#define NAND_BLOCK_MASK	(NAND_SECTOR_SIZE - 1)

#define NAND_SECTOR_SIZE_LP	2048
#define NAND_BLOCK_MASK_LP	(NAND_SECTOR_SIZE_LP - 1)

char bLARGEBLOCK;			//HJ_add 20090807
char b128MB;				//HJ_add 20090807

/* ���ⲿ���õĺ��� */
void nand_init_ll(void);
int nand_read_ll(unsigned char *buf, unsigned long start_addr, int size);
int nand_read_ll_lp(unsigned char *buf, unsigned long start_addr, int size);

/* NAND Flash�����������, ���ǽ�����S3C2410��S3C2440����Ӧ���� */
static void nand_reset(void);
static void wait_idle(void);
static void nand_select_chip(void);
static void nand_deselect_chip(void);
static void write_cmd(int cmd);
static void write_addr(unsigned int addr);
static void write_addr_lp(unsigned int addr);
static unsigned char read_data(void);
int NF_ReadID(void);				//HJ_add 20090807

/* S3C2440��NAND Flash������ */
static void s3c2440_nand_reset(void);
static void s3c2440_wait_idle(void);
static void s3c2440_nand_select_chip(void);
static void s3c2440_nand_deselect_chip(void);
static void s3c2440_write_cmd(int cmd);
static void s3c2440_write_addr(unsigned int addr);
static void s3c2440_write_addr_lp(unsigned int addr);
static unsigned char s3c2440_read_data(void);

/* S3C2440��NAND Flash�������� */

/* ��λ */
static void s3c2440_nand_reset(void)
{
	s3c2440_nand_select_chip();
	s3c2440_write_cmd(0xff);  // ��λ����
	s3c2440_wait_idle();
	s3c2440_nand_deselect_chip();
}

/* �ȴ�NAND Flash���� */
static void s3c2440_wait_idle(void)
{
	int i;
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;
	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFSTAT;

	while(!(*p & BUSY))
        for(i=0; i<10; i++);
}

/* ����Ƭѡ�ź� */
static void s3c2440_nand_select_chip(void)
{
	int i;
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;

	s3c2440nand->NFCONT &= ~(1<<1);
	for(i=0; i<10; i++);    
}

/* ȡ��Ƭѡ�ź� */
static void s3c2440_nand_deselect_chip(void)
{
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;

	s3c2440nand->NFCONT |= (1<<1);
}

/* �������� */
static void s3c2440_write_cmd(int cmd)
{
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;

	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFCMD;
	*p = cmd;
}

/* ������ַ */
static void s3c2440_write_addr(unsigned int addr)
{
	int i;
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;
	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFADDR;
    
	*p = addr & 0xff;
	for(i=0; i<10; i++);
	*p = (addr >> 9) & 0xff;
	for(i=0; i<10; i++);
	*p = (addr >> 17) & 0xff;
	for(i=0; i<10; i++);
	*p = (addr >> 25) & 0xff;
	for(i=0; i<10; i++);
}


/* ������ַ */
static void s3c2440_write_addr_lp(unsigned int addr)
{
	int i;
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;
	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFADDR;
	int col, page;

	col = addr & NAND_BLOCK_MASK_LP;
	page = addr / NAND_SECTOR_SIZE_LP;
	
	*p = col & 0xff;			/* Column Address A0~A7 */
	for(i=0; i<10; i++);		
	*p = (col >> 8) & 0x0f;		/* Column Address A8~A11 */
	for(i=0; i<10; i++);
	*p = page & 0xff;			/* Row Address A12~A19 */
	for(i=0; i<10; i++);
	*p = (page >> 8) & 0xff;	/* Row Address A20~A27 */
	for(i=0; i<10; i++);
if (b128MB == 0)
	*p = (page >> 16) & 0x03;	/* Row Address A28~A29 */
	for(i=0; i<10; i++);
}

/* ��ȡ���� */
static unsigned char s3c2440_read_data(void)
{
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;
	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFDATA;
	return *p;
}


/* �ڵ�һ��ʹ��NAND Flashǰ����λһ��NAND Flash */
static void nand_reset(void)
{
	s3c2440_nand_reset();
}

static void wait_idle(void)
{
	s3c2440_wait_idle();
}

static void nand_select_chip(void)
{
	int i;
	
	s3c2440_nand_select_chip();
	
	for(i=0; i<10; i++);
}

static void nand_deselect_chip(void)
{
	s3c2440_nand_deselect_chip();
}

static void write_cmd(int cmd)
{
	s3c2440_write_cmd(cmd);
}
static void write_addr(unsigned int addr)
{
	s3c2440_write_addr(addr);
}

static void write_addr_lp(unsigned int addr)
{
	s3c2440_write_addr_lp(addr);
}

static unsigned char read_data(void)
{
	return s3c2440_read_data();
}

/* ��ʼ��NAND Flash */
void nand_init_ll(void)
{
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;

	#define TACLS   0
	#define TWRPH0  3
	#define TWRPH1  0

	/* ����ʱ�� */
	s3c2440nand->NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4);
	/* ʹ��NAND Flash������, ��ʼ��ECC, ��ֹƬѡ */
	s3c2440nand->NFCONT = (1<<4)|(1<<1)|(1<<0);

	/* ��λNAND Flash */
	nand_reset();
}
#if 1
int NF_ReadID(void)
{
	char pMID;
	char pDID;
	int  nBuff;
	char   n4thcycle;
	int i;
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;
	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFADDR;

	b128MB = 1;
	n4thcycle = nBuff = 0;

	nand_init_ll();
	nand_select_chip();
	write_cmd(0x90);	// read id command
	*p=0x00 & 0xff;
	for ( i = 0; i < 100; i++ );

	pMID = read_data();
	pDID =  read_data();
	nBuff =  read_data();
	n4thcycle = read_data();

	nand_deselect_chip();
	
	if (pDID >= 0xA0)
	{
		b128MB = 0;
	}

	return (pDID);
}
#endif

/* ������ */
int nand_read_ll(unsigned char *buf, unsigned long start_addr, int size)
{
	int i, j;
	char dat;
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;
	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFADDR;

    
	if ((start_addr & NAND_BLOCK_MASK) || (size & NAND_BLOCK_MASK))
	{
		return -1;    /* ��ַ�򳤶Ȳ����� */
	}

	/* ѡ��оƬ */
	nand_select_chip();

	for(i=start_addr; i < (start_addr + size);)
	{
/* Check Bad Block */
if(1){
		/* ����READ0���� */
		write_cmd(0x50);

		*p = 5;
		for(j=0; j<10; j++);
		*p = (i >> 9) & 0xff;
		for(j=0; j<10; j++);
		*p = (i >> 17) & 0xff;
		for(j=0; j<10; j++);
		*p = (i >> 25) & 0xff;
		for(j=0; j<10; j++);
		wait_idle();
		dat = read_data();
		write_cmd(0);
		
		/* ȡ��Ƭѡ�ź� */
		nand_deselect_chip();
		if(dat != 0xff)
			i += 16384;		// 1 Block = 512*32= 16384
/* Read Page */
		/* ѡ��оƬ */
		nand_select_chip();
}
		/* ����READ0���� */
		write_cmd(0);

		/* Write Address */
		write_addr(i);
		wait_idle();

		for(j=0; j < NAND_SECTOR_SIZE; j++, i++)
		{
			*buf = read_data();
			buf++;
		}
	}

	/* ȡ��Ƭѡ�ź� */
	nand_deselect_chip();

	return 0;
}

/* ������ 
  * Large Page
  */
int nand_read_ll_lp(unsigned char *buf, unsigned long start_addr, int size)
{
	int i, j;
	char dat;
	S3C2440_NAND * s3c2440nand = (S3C2440_NAND *)0x4e000000;
	volatile unsigned char *p = (volatile unsigned char *)&s3c2440nand->NFADDR;

	if ((start_addr & NAND_BLOCK_MASK_LP) || (size & NAND_BLOCK_MASK_LP))
	{
		return -1;    /* ��ַ�򳤶Ȳ����� */
	}

	/* ѡ��оƬ */
	nand_select_chip();

	for(i=start_addr; i < (start_addr + size);)
	{
/* Check Bad Block */
if(1){
		int col, page;

		col = i & NAND_BLOCK_MASK_LP;
		page = i / NAND_SECTOR_SIZE_LP;
		/* ����READ0���� */
		write_cmd(0x00);

		*p = 5;
		for(j=0; j<10; j++);
		*p = 8;
		for(j=0; j<10; j++);
		*p = page & 0xff;		/* Row Address A12~A19 */
		for(j=0; j<10; j++);
		*p = (page >> 8) & 0xff;		/* Row Address A20~A27 */
		for(j=0; j<10; j++);
if (b128MB == 0)
		*p = (page >> 16) & 0x03;		/* Row Address A28~A29 */
		for(j=0; j<10; j++);

		write_cmd(0x30);
		wait_idle();
		dat = read_data();
		
		/* ȡ��Ƭѡ�ź� */
		nand_deselect_chip();
		if(dat != 0xff)
			i += 131072;		// 1 Block = 2048*64= 131072
/* Read Page */
		/* ѡ��оƬ */
		nand_select_chip();
}
		/* ����READ0���� */
		write_cmd(0);

		/* Write Address */
		write_addr_lp(i);
		write_cmd(0x30);
		wait_idle();

		for(j=0; j < NAND_SECTOR_SIZE_LP; j++, i++)
		{
			*buf = read_data();
			buf++;
		}
	}

	/* ȡ��Ƭѡ�ź� */
	nand_deselect_chip();

	return 0;
}

int bBootFrmNORFlash(void)
{
	volatile unsigned int *pdw = (volatile unsigned int *)0;
	unsigned int dwVal;

	/*
	 * �����Ǵ�NOR Flash���Ǵ�NAND Flash������
	 * ��ַ0��Ϊָ��"b	Reset", ������Ϊ0xEA00000B��
	 * ���ڴ�NAND Flash������������俪ʼ4KB�Ĵ���Ḵ�Ƶ�CPU�ڲ�4K�ڴ��У�
	 * ���ڴ�NOR Flash�����������NOR Flash�Ŀ�ʼ��ַ��Ϊ0��
	 * ����NOR Flash������ͨ��һ�����������в���д���ݣ�
	 * ���Կ��Ը�����������ֱ��Ǵ�NAND Flash����NOR Flash����:
	 * ���ַ0д��һ�����ݣ�Ȼ������������û�иı�Ļ�����NOR Flash
	 */

	dwVal = *pdw;       
	*pdw = 0x12345678;
	if (*pdw != 0x12345678)
	{
		return 1;
	}
	else
	{
		*pdw = dwVal;
		return 0;
	}
}

int CopyCode2Ram(unsigned long start_addr, unsigned char *buf, int size)
{
	unsigned int *pdwDest;
	unsigned int *pdwSrc;
	int i;

	if (bBootFrmNORFlash())
	{
		pdwDest = (unsigned int *)buf;
		pdwSrc  = (unsigned int *)start_addr;
		/* �� NOR Flash���� */
		for (i = 0; i < size / 4; i++)
		{
			pdwDest[i] = pdwSrc[i];
		}
		return 0;
	}
	else
	{
		/* ��ʼ��NAND Flash */
		nand_init_ll();

		/* �� NAND Flash���� */
		if (NF_ReadID() == 0x76 )
			nand_read_ll(buf, start_addr, (size + NAND_BLOCK_MASK)&~(NAND_BLOCK_MASK));
		else
			nand_read_ll_lp(buf, start_addr, (size + NAND_BLOCK_MASK_LP)&~(NAND_BLOCK_MASK_LP));
		return 0;
	}
}

static inline void delay (unsigned long loops)
{
	__asm__ volatile ("1:\n"
			"subs %0, %1, #1\n"
			"bne 1b":"=r" (loops):"0" (loops));
}

/* S3C2440: Mpll = (2*m * Fin) / (p * 2^s), UPLL = (m * Fin) / (p * 2^s)
 * m = M (the value for divider M)+ 8, p = P (the value for divider P) + 2
 */
/* Fin = 12.0000MHz */
#define S3C2440_MPLL_400MHZ	((0x5c<<12)|(0x01<<4)|(0x01))						//HJ 400MHz
#define S3C2440_MPLL_405MHZ	((0x7f<<12)|(0x02<<4)|(0x01))						//HJ 405MHz
#define S3C2440_MPLL_440MHZ	((0x66<<12)|(0x01<<4)|(0x01))						//HJ 440MHz
#define S3C2440_MPLL_480MHZ	((0x98<<12)|(0x02<<4)|(0x01))						//HJ 480MHz
#define S3C2440_MPLL_200MHZ	((0x5c<<12)|(0x01<<4)|(0x02))
#define S3C2440_MPLL_100MHZ	((0x5c<<12)|(0x01<<4)|(0x03))

#define S3C2440_UPLL_48MHZ	((0x38<<12)|(0x02<<4)|(0x02))						//HJ 100MHz

#define S3C2440_CLKDIV		0x05    /* FCLK:HCLK:PCLK = 1:4:8, UCLK = UPLL */		//HJ 100MHz
#define S3C2440_CLKDIV136	0x07    /* FCLK:HCLK:PCLK = 1:3:6, UCLK = UPLL */		//HJ 133MHz
#define S3C2440_CLKDIV188	0x04    /* FCLK:HCLK:PCLK = 1:8:8 */
#define S3C2440_CAMDIVN188	((0<<8)|(1<<9)) /* FCLK:HCLK:PCLK = 1:8:8 */

/* Fin = 16.9344MHz */
#define S3C2440_MPLL_399MHz     		((0x6e<<12)|(0x03<<4)|(0x01))
#define S3C2440_UPLL_48MHZ_Fin16MHz		((60<<12)|(4<<4)|(2))

void clock_init(void)
{
	S3C24X0_CLOCK_POWER *clk_power = (S3C24X0_CLOCK_POWER *)0x4C000000;

	/* FCLK:HCLK:PCLK = ?:?:? */
#if CONFIG_133MHZ_SDRAM
	clk_power->CLKDIVN = S3C2440_CLKDIV136;			//HJ 1:3:6
#else
	clk_power->CLKDIVN = S3C2440_CLKDIV;				//HJ 1:4:8
#endif
	/* change to asynchronous bus mod */
	__asm__(    "mrc    p15, 0, r1, c1, c0, 0\n"    /* read ctrl register   */  
                    "orr    r1, r1, #0xc0000000\n"      /* Asynchronous         */  
                    "mcr    p15, 0, r1, c1, c0, 0\n"    /* write ctrl register  */  
                    :::"r1"
                    );

	/* to reduce PLL lock time, adjust the LOCKTIME register */
	clk_power->LOCKTIME = 0xFFFFFF;

	/* configure UPLL */
	clk_power->UPLLCON = S3C2440_UPLL_48MHZ;		//fin=12.000MHz
//	clk_power->UPLLCON = S3C2440_UPLL_48MHZ_Fin16MHz;	//fin=16.934MHz

	/* some delay between MPLL and UPLL */
	delay (4000);

	/* configure MPLL */
	clk_power->MPLLCON = S3C2440_MPLL_400MHZ;		//fin=12.000MHz
//	clk_power->MPLLCON = S3C2440_MPLL_405MHZ;				//HJ 405MHz
//	clk_power->MPLLCON = S3C2440_MPLL_440MHZ;				//HJ 440MHz
//	clk_power->MPLLCON = S3C2440_MPLL_480MHZ;				//HJ 480MHz
//	clk_power->MPLLCON = S3C2440_MPLL_399MHz;		//fin=16.934MHz
	/* some delay between MPLL and UPLL */
	delay (8000);
}

