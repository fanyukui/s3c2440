#ifdef CONFIG_EMBEDSKY_LOGO
#define MVAL			(13)
#define MVAL_USED 		(0)						//0=each frame   1=rate by MVAL
#define INVVDEN			(1)						//0=normal       1=inverted
#define BSWP			(0)						//Byte swap control
#define HWSWP			(1)						//Half word swap control


#if ( LCD_TFT == TFT800480 )
//TFT 800480
#define LCD_XSIZE_TFT	 	(800)	
#define LCD_YSIZE_TFT	 	(480)

//Timing parameter for LCD LTP700WV-F01

#define VBPD			(4)						//��ֱͬ���źŵĺ��
#define VFPD			(2)						//��ֱͬ���źŵ�ǰ��
#define VSPW			(2)						//��ֱͬ���źŵ�����

#define HBPD			(27)						//ˮƽͬ���źŵĺ��
#define HFPD			(14)						//ˮƽͬ���źŵ�ǰ��
#define HSPW			(8)						//ˮƽͬ���źŵ�����

#define CLKVAL_TFT		(2)

#elif ( LCD_TFT == VGA640480 )
//VGA
#define LCD_XSIZE_TFT	 	(640)	
#define LCD_YSIZE_TFT	 	(480)

//Timing parameter for VGA
#define VBPD			(29)						//��ֱͬ���źŵĺ��
#define VFPD			(5)						//��ֱͬ���źŵ�ǰ��
#define VSPW			(4)						//��ֱͬ���źŵ�����

#define HBPD			(71)						//ˮƽͬ���źŵĺ��
#define HFPD			(40)						//ˮƽͬ���źŵ�ǰ��
#define HSPW			(31)						//ˮƽͬ���źŵ�����

#define CLKVAL_TFT		(1)

#elif ( LCD_TFT == TFT480272 )
//TFT 480272
#define LCD_XSIZE_TFT	 	(480)	
#define LCD_YSIZE_TFT	 	(272)

//Timing parameter for LCD
#define VBPD			(3)						//��ֱͬ���źŵĺ��
#define VFPD			(5)						//��ֱͬ���źŵ�ǰ��
#define VSPW			(15)						//��ֱͬ���źŵ�����

#define HBPD			(5)						//ˮƽͬ���źŵĺ��
#define HFPD			(15)						//ˮƽͬ���źŵ�ǰ��
#define HSPW			(8)						//ˮƽͬ���źŵ�����

#define CLKVAL_TFT		(7)

#elif ( LCD_TFT == TFT240320 )
//TFT 240320
#define LCD_XSIZE_TFT	 	(240)	
#define LCD_YSIZE_TFT	 	(320)

//Timing parameter for LCD ��֥��
#define VBPD			(1)						//��ֱͬ���źŵĺ��
#define VFPD			(2)						//��ֱͬ���źŵ�ǰ��
#define VSPW			(1)						//��ֱͬ���źŵ�����

#define HBPD			(6)						//ˮƽͬ���źŵĺ��
#define HFPD			(3)						//ˮƽͬ���źŵ�ǰ��
#define HSPW			(1)						//ˮƽͬ���źŵ�����

#define CLKVAL_TFT		(4)

#elif ( LCD_TFT == W35 )
//TFT 320240
#define LCD_XSIZE_TFT	 	(320)	
#define LCD_YSIZE_TFT	 	(240)

//Timing parameter for LCD
#define VBPD			(12)						//��ֱͬ���źŵĺ��
#define VFPD			(4)						//��ֱͬ���źŵ�ǰ��
#define VSPW			(5)						//��ֱͬ���źŵ�����

#define HBPD			(21)						//ˮƽͬ���źŵĺ��
#define HFPD			(32)						//ˮƽͬ���źŵ�ǰ��
#define HSPW			(44)						//ˮƽͬ���źŵ�����

#define CLKVAL_TFT		(6)

#elif ( LCD_TFT == S35 )
//TFT 320240
#define LCD_XSIZE_TFT	 	(320)	
#define LCD_YSIZE_TFT	 	(240)

//Timing parameter for LCD
#define VBPD			(3)						//��ֱͬ���źŵĺ��
#define VFPD			(5)						//��ֱͬ���źŵ�ǰ��
#define VSPW			(15)						//��ֱͬ���źŵ�����

#define HBPD			(5)						//ˮƽͬ���źŵĺ��
#define HFPD			(15)						//ˮƽͬ���źŵ�ǰ��
#define HSPW			(8)						//ˮƽͬ���źŵ�����

#define CLKVAL_TFT		(7)

#elif ( LCD_TFT == TFT800600 )
//TFT 800600
#define LCD_XSIZE_TFT	 	(800)	
#define LCD_YSIZE_TFT	 	(600)

//Timing parameter for LCD
#define VBPD			(22)						//��ֱͬ���źŵĺ��
#define VFPD			(36)						//��ֱͬ���źŵ�ǰ��
#define VSPW			(5)						//��ֱͬ���źŵ�����

#define HBPD			(63)						//ˮƽͬ���źŵĺ��
#define HFPD			(55)						//ˮƽͬ���źŵ�ǰ��
#define HSPW			(119)						//ˮƽͬ���źŵ�����

#define CLKVAL_TFT		(0)

#elif ( LCD_TFT == VGA1024768 )
//VGA 1024768
#define LCD_XSIZE_TFT	 	(1024)	
#define LCD_YSIZE_TFT	 	(768)

//Timing parameter for LCD
#define VBPD			(1)						//��ֱͬ���źŵĺ��
#define VFPD			(1)						//��ֱͬ���źŵ�ǰ��
#define VSPW			(1)						//��ֱͬ���źŵ�����

#define HBPD			(15)						//ˮƽͬ���źŵĺ��
#define HFPD			(199)						//ˮƽͬ���źŵ�ǰ��
#define HSPW			(15)						//ˮƽͬ���źŵ�����

#define CLKVAL_TFT		(3)

#endif

#endif
