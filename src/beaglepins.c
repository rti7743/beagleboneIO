/** @file beaglepins.c
 *
 * AUTOMATICALLY GENERATED - PLEASE DO NOT MODIFY
 */
#include "beaglepins.h"
#include "beaglegpio.h"
#include "beaglemem.h"

const PIN pins[] = {
/* P8_1 */
{"DGND"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P8_2 */
{"DGND"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P8_3 */
{"GPIO1_6"
		,38				//gpio
		,"gpmc_ad6"		//mux
		,26				//eeprom
		,GPIO_MEMORY_TO(38)		//gpio memory address
		,GPIO_BIT_TO(38)		//gpio memory mask
},
/* P8_4 */
{"GPIO1_7"
		,39				//gpio
		,"gpmc_ad7"		//mux
		,27				//eeprom
		,GPIO_MEMORY_TO(39)		//gpio memory address
		,GPIO_BIT_TO(39)		//gpio memory mask
},
/* P8_5 */
{"GPIO1_2"
		,34				//gpio
		,"gpmc_ad2"		//mux
		,22				//eeprom
		,GPIO_MEMORY_TO(34)		//gpio memory address
		,GPIO_BIT_TO(34)		//gpio memory mask
},
/* P8_6 */
{"GPIO1_3"
		,35				//gpio
		,"gpmc_ad3"		//mux
		,23				//eeprom
		,GPIO_MEMORY_TO(35)		//gpio memory address
		,GPIO_BIT_TO(35)		//gpio memory mask
},
/* P8_7 */
{"TIMER4"
		,66				//gpio
		,"gpmc_advn_ale"//mux
		,41				//eeprom
		,GPIO_MEMORY_TO(66)		//gpio memory address
		,GPIO_BIT_TO(66)		//gpio memory mask
},
/* P8_8 */
{"TIMER7"
		,67				//gpio
		,"gpmc_oen_ren"	//mux
		,44				//eeprom
		,GPIO_MEMORY_TO(67)		//gpio memory address
		,GPIO_BIT_TO(67)		//gpio memory mask
},
/* P8_9 */
{"TIMER5"
		,69				//gpio
		,"gpmc_ben0_cle"//mux
		,42				//eeprom
		,GPIO_MEMORY_TO(69)		//gpio memory address
		,GPIO_BIT_TO(69)		//gpio memory mask
},
/* P8_10 */
{"TIMER6"
		,68				//gpio
		,"gpmc_wen"		//mux
		,43				//eeprom
		,GPIO_MEMORY_TO(68)		//gpio memory address
		,GPIO_BIT_TO(68)		//gpio memory mask
},
/* P8_11 */
{"GPIO1_13"
		,45				//gpio
		,"gpmc_ad13"	//mux
		,29				//eeprom
		,GPIO_MEMORY_TO(45)		//gpio memory address
		,GPIO_BIT_TO(45)		//gpio memory mask
},
/* P8_12 */
{"GPIO1_12"
		,44				//gpio
		,"gpmc_ad12"	//mux
		,28				//eeprom
		,GPIO_MEMORY_TO(44)		//gpio memory address
		,GPIO_BIT_TO(44)		//gpio memory mask
},
/* P8_13 */
{"EHRPWM2B"
		,23				//gpio
		,"gpmc_ad9"		//mux
		,15				//eeprom
		,GPIO_MEMORY_TO(23)		//gpio memory address
		,GPIO_BIT_TO(23)		//gpio memory mask
},
/* P8_14 */
{"GPIO0_26"
		,26				//gpio
		,"gpmc_ad10"	//mux
		,16				//eeprom
		,GPIO_MEMORY_TO(26)		//gpio memory address
		,GPIO_BIT_TO(26)		//gpio memory mask
},
/* P8_15 */
{"GPIO1_15"
		,47				//gpio
		,"gpmc_ad15"	//mux
		,31				//eeprom
		,GPIO_MEMORY_TO(47)		//gpio memory address
		,GPIO_BIT_TO(47)		//gpio memory mask
},
/* P8_16 */
{"GPIO1_14"
		,46				//gpio
		,"gpmc_ad14"	//mux
		,30				//eeprom
		,GPIO_MEMORY_TO(46)		//gpio memory address
		,GPIO_BIT_TO(46)		//gpio memory mask
},
/* P8_17 */
{"GPIO0_27"
		,27				//gpio
		,"gpmc_ad11"	//mux
		,17				//eeprom
		,GPIO_MEMORY_TO(27)		//gpio memory address
		,GPIO_BIT_TO(27)		//gpio memory mask
},
/* P8_18 */
{"GPIO2_1"
		,65				//gpio
		,"gpmc_clk"		//mux
		,40				//eeprom
		,GPIO_MEMORY_TO(65)		//gpio memory address
		,GPIO_BIT_TO(65)		//gpio memory mask
},
/* P8_19 */
{"EHRPWM2A"
		,22				//gpio
		,"gpmc_ad8"		//mux
		,14				//eeprom
		,GPIO_MEMORY_TO(22)		//gpio memory address
		,GPIO_BIT_TO(22)		//gpio memory mask
},
/* P8_20 */
{"GPIO1_31"
		,63				//gpio
		,"gpmc_csn2"	//mux
		,39				//eeprom
		,GPIO_MEMORY_TO(63)		//gpio memory address
		,GPIO_BIT_TO(63)		//gpio memory mask
},
/* P8_21 */
{"GPIO1_30"
		,62				//gpio
		,"gpmc_csn1"	//mux
		,38				//eeprom
		,GPIO_MEMORY_TO(62)		//gpio memory address
		,GPIO_BIT_TO(62)		//gpio memory mask
},
/* P8_22 */
{"GPIO1_5"
		,37				//gpio
		,"gpmc_ad5"		//mux
		,25				//eeprom
		,GPIO_MEMORY_TO(37)		//gpio memory address
		,GPIO_BIT_TO(37)		//gpio memory mask
},
/* P8_23 */
{"GPIO1_4"
		,36				//gpio
		,"gpmc_ad4"		//mux
		,24				//eeprom
		,GPIO_MEMORY_TO(36)		//gpio memory address
		,GPIO_BIT_TO(36)		//gpio memory mask
},
/* P8_24 */
{"GPIO1_1"
		,33				//gpio
		,"gpmc_ad1"		//mux
		,21				//eeprom
		,GPIO_MEMORY_TO(33)		//gpio memory address
		,GPIO_BIT_TO(33)		//gpio memory mask
},
/* P8_25 */
{"GPIO1_0"
		,32				//gpio
		,"gpmc_ad0"		//mux
		,20				//eeprom
		,GPIO_MEMORY_TO(32)		//gpio memory address
		,GPIO_BIT_TO(32)		//gpio memory mask
},
/* P8_26 */
{"GPIO1_29"
		,61				//gpio
		,"gpmc_csn0"	//mux
		,37				//eeprom
		,GPIO_MEMORY_TO(61)		//gpio memory address
		,GPIO_BIT_TO(61)		//gpio memory mask
},
/* P8_27 */
{"GPIO2_22"
		,86				//gpio
		,"lcd_vsync"	//mux
		,57				//eeprom
		,GPIO_MEMORY_TO(86)		//gpio memory address
		,GPIO_BIT_TO(86)		//gpio memory mask
},
/* P8_28 */
{"GPIO2_24"
		,88				//gpio
		,"lcd_pclk"		//mux
		,59				//eeprom
		,GPIO_MEMORY_TO(88)		//gpio memory address
		,GPIO_BIT_TO(88)		//gpio memory mask
},
/* P8_29 */
{"GPIO2_23"
		,87				//gpio
		,"lcd_hsync"	//mux
		,58				//eeprom
		,GPIO_MEMORY_TO(87)		//gpio memory address
		,GPIO_BIT_TO(87)		//gpio memory mask
},
/* P8_30 */
{"GPIO2_25"
		,89				//gpio
		,"lcd_ac_bias_en"//mux
		,60				//eeprom
		,GPIO_MEMORY_TO(89)		//gpio memory address
		,GPIO_BIT_TO(89)		//gpio memory mask
},
/* P8_31 */
{"UART5_CTSN"
		,10				//gpio
		,"lcd_data14"	//mux
		,7				//eeprom
		,GPIO_MEMORY_TO(10)		//gpio memory address
		,GPIO_BIT_TO(10)		//gpio memory mask
},
/* P8_32 */
{"UART5_RTSN"
		,11				//gpio
		,"lcd_data15"	//mux
		,8				//eeprom
		,GPIO_MEMORY_TO(11)		//gpio memory address
		,GPIO_BIT_TO(11)		//gpio memory mask
},
/* P8_33 */
{"UART4_RTSN"
		,9				//gpio
		,"lcd_data13"	//mux
		,6				//eeprom
		,GPIO_MEMORY_TO(9)		//gpio memory address
		,GPIO_BIT_TO(9)		//gpio memory mask
},
/* P8_34 */
{"UART3_RTSN"
		,81				//gpio
		,"lcd_data11"	//mux
		,56				//eeprom
		,GPIO_MEMORY_TO(81)		//gpio memory address
		,GPIO_BIT_TO(81)		//gpio memory mask
},
/* P8_35 */
{"UART4_CTSN"
		,8				//gpio
		,"lcd_data12"	//mux
		,5				//eeprom
		,GPIO_MEMORY_TO(8)		//gpio memory address
		,GPIO_BIT_TO(8)		//gpio memory mask
},
/* P8_36 */
{"UART3_CTSN"
		,80				//gpio
		,"lcd_data10"	//mux
		,55				//eeprom
		,GPIO_MEMORY_TO(80)		//gpio memory address
		,GPIO_BIT_TO(80)		//gpio memory mask
},
/* P8_37 */
{"UART5_TXD"
		,78				//gpio
		,"lcd_data8"	//mux
		,53				//eeprom
		,GPIO_MEMORY_TO(78)		//gpio memory address
		,GPIO_BIT_TO(78)		//gpio memory mask
},
/* P8_38 */
{"UART5_RXD"
		,79				//gpio
		,"lcd_data9"	//mux
		,54				//eeprom
		,GPIO_MEMORY_TO(79)		//gpio memory address
		,GPIO_BIT_TO(79)		//gpio memory mask
},
/* P8_39 */
{"GPIO2_12"
		,76				//gpio
		,"lcd_data6"	//mux
		,51				//eeprom
		,GPIO_MEMORY_TO(76)		//gpio memory address
		,GPIO_BIT_TO(76)		//gpio memory mask
},
/* P8_40 */
{"GPIO2_13"
		,77				//gpio
		,"lcd_data7"	//mux
		,52				//eeprom
		,GPIO_MEMORY_TO(77)		//gpio memory address
		,GPIO_BIT_TO(77)		//gpio memory mask
},
/* P8_41 */
{"GPIO2_10"
		,74				//gpio
		,"lcd_data4"	//mux
		,49				//eeprom
		,GPIO_MEMORY_TO(74)		//gpio memory address
		,GPIO_BIT_TO(74)		//gpio memory mask
},
/* P8_42 */
{"GPIO2_11"
		,75				//gpio
		,"lcd_data5"	//mux
		,50				//eeprom
		,GPIO_MEMORY_TO(75)		//gpio memory address
		,GPIO_BIT_TO(75)		//gpio memory mask
},
/* P8_43 */
{"GPIO2_8"
		,72				//gpio
		,"lcd_data2"	//mux
		,47				//eeprom
		,GPIO_MEMORY_TO(72)		//gpio memory address
		,GPIO_BIT_TO(72)		//gpio memory mask
},
/* P8_44 */
{"GPIO2_9"
		,73				//gpio
		,"lcd_data3"	//mux
		,48				//eeprom
		,GPIO_MEMORY_TO(73)		//gpio memory address
		,GPIO_BIT_TO(73)		//gpio memory mask
},
/* P8_45 */
{"GPIO2_6"
		,70				//gpio
		,"lcd_data0"	//mux
		,45				//eeprom
		,GPIO_MEMORY_TO(70)		//gpio memory address
		,GPIO_BIT_TO(70)		//gpio memory mask
},
/* P8_46 */
{"GPIO2_7"
		,71				//gpio
		,"lcd_data1"	//mux
		,46				//eeprom
		,GPIO_MEMORY_TO(71)		//gpio memory address
		,GPIO_BIT_TO(71)		//gpio memory mask
},
/* P9_1 */
{"DGND"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_2 */
{"DGND"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_3 */
{"VDD_3V3"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_4 */
{"VDD_3V3"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_5 */
{"VDD_5V"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_6 */
{"VDD_5V"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_7 */
{"SYS_5V"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_8 */
{"SYS_5V"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_9 */
{"PWR_BUT"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_10 */
{"SYS_RESETn"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_11 */
{"UART4_RXD"
		,30				//gpio
		,"gpmc_wait0"	//mux
		,18				//eeprom
		,GPIO_MEMORY_TO(30)		//gpio memory address
		,GPIO_BIT_TO(30)		//gpio memory mask
},
/* P9_12 */
{"GPIO1_28"
		,60				//gpio
		,"gpmc_ben1"	//mux
		,36				//eeprom
		,GPIO_MEMORY_TO(60)		//gpio memory address
		,GPIO_BIT_TO(60)		//gpio memory mask
},
/* P9_13 */
{"UART4_TXD"
		,31				//gpio
		,"gpmc_wpn"		//mux
		,19				//eeprom
		,GPIO_MEMORY_TO(31)		//gpio memory address
		,GPIO_BIT_TO(31)		//gpio memory mask
},
/* P9_14 */
{"EHRPWM1A"
		,50				//gpio
		,"gpmc_a2"		//mux
		,34				//eeprom
		,GPIO_MEMORY_TO(50)		//gpio memory address
		,GPIO_BIT_TO(50)		//gpio memory mask
},
/* P9_15 */
{"GPIO1_16"
		,48				//gpio
		,"mii1_rxd3"	//mux
		,32				//eeprom
		,GPIO_MEMORY_TO(48)		//gpio memory address
		,GPIO_BIT_TO(48)		//gpio memory mask
},
/* P9_16 */
{"EHRPWM1B"
		,51				//gpio
		,"gpmc_a3"		//mux
		,35				//eeprom
		,GPIO_MEMORY_TO(51)		//gpio memory address
		,GPIO_BIT_TO(51)		//gpio memory mask
},
/* P9_17 */
{"I2C1_SCL"
		,5				//gpio
		,"spi0_cs0"		//mux
		,3				//eeprom
		,GPIO_MEMORY_TO(5)		//gpio memory address
		,GPIO_BIT_TO(5)		//gpio memory mask
},
/* P9_18 */
{"I2C1_SDA"
		,4				//gpio
		,"spi0_d1"		//mux
		,2				//eeprom
		,GPIO_MEMORY_TO(4)		//gpio memory address
		,GPIO_BIT_TO(4)		//gpio memory mask
},
/* P9_19 */
{"I2C2_SCL"
		,13				//gpio
		,"uart1_rtsn"	//mux
		,9				//eeprom
		,GPIO_MEMORY_TO(13)		//gpio memory address
		,GPIO_BIT_TO(13)		//gpio memory mask
},
/* P9_20 */
{"I2C2_SDA"
		,12				//gpio
		,"uart1_ctsn"	//mux
		,10				//eeprom
		,GPIO_MEMORY_TO(12)		//gpio memory address
		,GPIO_BIT_TO(12)		//gpio memory mask
},
/* P9_21 */
{"UART2_TXD"
		,3				//gpio
		,"spi0_d0"		//mux
		,1				//eeprom
		,GPIO_MEMORY_TO(3)		//gpio memory address
		,GPIO_BIT_TO(3)		//gpio memory mask
},
/* P9_22 */
{"UART2_RXD"
		,2				//gpio
		,"spi0_sclk"	//mux
		,0				//eeprom
		,GPIO_MEMORY_TO(2)		//gpio memory address
		,GPIO_BIT_TO(2)		//gpio memory mask
},
/* P9_23 */
{"GPIO1_17"
		,49				//gpio
		,"gpmc_a1"		//mux
		,33				//eeprom
		,GPIO_MEMORY_TO(49)		//gpio memory address
		,GPIO_BIT_TO(49)		//gpio memory mask
},
/* P9_24 */
{"UART1_TXD"
		,15				//gpio
		,"uart1_txd"	//mux
		,12				//eeprom
		,GPIO_MEMORY_TO(15)		//gpio memory address
		,GPIO_BIT_TO(15)		//gpio memory mask
},
/* P9_25 */
{"GPIO3_21"
		,117				//gpio
		,"mcasp0_ahclkx"//mux
		,66				//eeprom
		,GPIO_MEMORY_TO(117)		//gpio memory address
		,GPIO_BIT_TO(117)		//gpio memory mask
},
/* P9_26 */
{"UART1_RXD"
		,14				//gpio
		,"uart1_rxd"	//mux
		,11				//eeprom
		,GPIO_MEMORY_TO(14)		//gpio memory address
		,GPIO_BIT_TO(14)		//gpio memory mask
},
/* P9_27 */
{"GPIO3_19"
		,115				//gpio
		,"mcasp0_fsr"	//mux
		,64				//eeprom
		,GPIO_MEMORY_TO(115)		//gpio memory address
		,GPIO_BIT_TO(115)		//gpio memory mask
},
/* P9_28 */
{"SPI1_CS0"
		,113				//gpio
		,"mcasp0_ahclkr"//mux
		,63				//eeprom
		,GPIO_MEMORY_TO(113)		//gpio memory address
		,GPIO_BIT_TO(113)		//gpio memory mask
},
/* P9_29 */
{"SPI1_D0"
		,111				//gpio
		,"mcasp0_fsx"	//mux
		,61				//eeprom
		,GPIO_MEMORY_TO(111)		//gpio memory address
		,GPIO_BIT_TO(111)		//gpio memory mask
},
/* P9_30 */
{"SPI1_D1"
		,112				//gpio
		,"mcasp0_axr0"	//mux
		,62				//eeprom
		,GPIO_MEMORY_TO(112)		//gpio memory address
		,GPIO_BIT_TO(112)		//gpio memory mask
},
/* P9_31 */
{"SPI1_SCLK"
		,110				//gpio
		,"mcasp0_aclkx"	//mux
		,65				//eeprom
		,GPIO_MEMORY_TO(110)		//gpio memory address
		,GPIO_BIT_TO(110)		//gpio memory mask
},
/* P9_32 */
{"VDD_ADC"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_33 */
{"AIN4"
		,0				//gpio
		,""	//mux
		,71				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_34 */
{"GNDA_ADC"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_35 */
{"AIN6"
		,0				//gpio
		,""				//mux
		,73				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_36 */
{"AIN5"
		,0				//gpio
		,""				//mux
		,72				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_37 */
{"AIN2"
		,0				//gpio
		,""				//mux
		,69				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_38 */
{"AIN3"
		,0				//gpio
		,""				//mux
		,70				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_39 */
{"AIN0"
		,0				//gpio
		,""				//mux
		,67				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_40 */
{"AIN1"
		,0				//gpio
		,""				//mux
		,68				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_41 */
{"CLKOUT2"
		,20				//gpio
		,"xdma_event_intr1"//mux
		,13				//eeprom
		,GPIO_MEMORY_TO(20)		//gpio memory address
		,GPIO_BIT_TO(20)		//gpio memory mask
},
/* P9_42 */
{"GPIO0_7"
		,7				//gpio
		,"ecap0_in_pwm0_out"//mux
		,4				//eeprom
		,GPIO_MEMORY_TO(7)		//gpio memory address
		,GPIO_BIT_TO(7)		//gpio memory mask
},
/* P9_43 */
{"DGND"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_44 */
{"DGND"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_45 */
{"DGND"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* P9_46 */
{"DGND"
		,0				//gpio
		,""				//mux
		,0				//eeprom
		,0				//gpio memory address
		,0				//gpio memory mask
},
/* USR0 */
{"USR0"
		,53				//gpio
		,"gpmc_a5"		//mux
		,0				//eeprom
		,GPIO_MEMORY_TO(53)		//gpio memory address
		,GPIO_BIT_TO(53)		//gpio memory mask
},
/* USR1 */
{"USR1"
		,54				//gpio
		,"gpmc_a6"		//mux
		,0				//eeprom
		,GPIO_MEMORY_TO(54)		//gpio memory address
		,GPIO_BIT_TO(54)		//gpio memory mask
},
/* USR2 */
{"USR2"
		,55				//gpio
		,"gpmc_a7"		//mux
		,0				//eeprom
		,GPIO_MEMORY_TO(55)		//gpio memory address
		,GPIO_BIT_TO(55)		//gpio memory mask
},
/* USR3 */
{"USR3"
		,56				//gpio
		,"gpmc_a8"		//mux
		,0				//eeprom
		,GPIO_MEMORY_TO(56)		//gpio memory address
		,GPIO_BIT_TO(56)		//gpio memory mask
}
};
