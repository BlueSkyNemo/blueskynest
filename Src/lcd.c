//#include "stm32f4xx_hal.h"
#include "lcd.h"
//#include "spi.h"

void deley(uint16_t val)
{
	uint8_t i,j=200;
	for(i=0;i<val;i++)
	{
		while(j)
		{
			j--;
		}
	}
	
	
}

void lcd_writeCommand(uint8_t dat)
{
	LCD_SCL_LOW();
	deley(1);
	LCD_CS_LOW();
//	spi_write(0x00);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
//	HAL_Delay(1);
//	spi_write(dat);
	LCD_SDA_0();
	LCD_SCL_HIGH();
	for(uint8_t i=0;i<8;i++)
	{
		LCD_SCL_LOW();
		deley(1);
		if(dat & 0x80)
		{
			LCD_SDA_1();
		}
		else
		{
			LCD_SDA_0();
		}
		LCD_SCL_HIGH();
		deley(1);
		dat = dat<<1;
	}
	LCD_SDA_0();
	LCD_CS_HIGH();
	deley(1);
}

void lcd_writeData(uint8_t dat)
{
	LCD_SCL_LOW();
	deley(1);
	LCD_CS_LOW();
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
//	spi_write(0x01);
//	HAL_Delay(1);
//	spi_write(dat);
	LCD_SDA_1();
	LCD_SCL_HIGH();
	for(uint8_t i=0;i<8;i++)
	{
		LCD_SCL_LOW();
		if(dat & 0x80)
		{
			LCD_SDA_1();
		}
		else
		{
			LCD_SDA_0();
		}
		LCD_SCL_HIGH();
		deley(1);
		dat = dat<<1;
	}
	LCD_SDA_0();
	LCD_CS_HIGH();
	deley(1);
}
void ST7789V_init(void)
{
//	lcd_reset();
//	lcd_writeCommand(0xCB); //AP[2:0] 
//	lcd_writeData(0x01); 
//-----------------------------------ST7789S reset sequence------------------------------------// 
//	LCD_RESET_LOW();
	LCD_RESET_HIGH();
	HAL_Delay(20);
	__nop();
	LCD_RESET_LOW();
	HAL_Delay(100);
	LCD_RESET_HIGH();
	HAL_Delay(520);

	
//---------------------------------------------------------------------------------------------------//
//	lcd_writeCommand(0x1);
//	lcd_writeCommand(0x11);
//	HAL_Delay(120);
//--------------------------------Display and color format setting----------------------------// 	
	lcd_writeCommand(0x36);
	lcd_writeData(0xC8);
	lcd_writeCommand(0x3a);
	lcd_writeData(0x66);		//IF 0X06 WILL WRONG
//--------------------------------ST7789S Frame rate setting----------------------------------// 
	lcd_writeCommand(0xb2);
	lcd_writeData(0x0c);
	lcd_writeData(0x0c);
	lcd_writeData(0x00);
	lcd_writeData(0x33);
	lcd_writeData(0x33);
	lcd_writeCommand(0xb7);
	lcd_writeData(0x35);
	
//	lcd_writeCommand(0xb3);////////////////
//	lcd_writeData(0x10);
//	lcd_writeData(0x0b);
//	lcd_writeData(0x0b);

//---------------------------------ST7789S Power setting--------------------------------------// 		
	lcd_writeCommand(0xbb); 
	lcd_writeData(0x1f); 

	lcd_writeCommand(0xC0); 
	lcd_writeData(0x2c);  
	
	lcd_writeCommand(0xC2);     
	lcd_writeData(0x01);  
	
	lcd_writeCommand(0xC3);  
	lcd_writeData(0x17);
//	lcd_writeData(0x13);
	
	lcd_writeCommand(0xC4); 
	lcd_writeData(0x20); 	
	
	lcd_writeCommand(0xC6); 
	lcd_writeData(0x0f); 
	
//	lcd_writeCommand(0xC5);     //VCM control 
//	lcd_writeData(0x31); 			//0x31
//	lcd_writeData(0x3C); 			//0x3c

	lcd_writeCommand(0xca);			//
	lcd_writeData(0x0f);				//
	
	lcd_writeCommand(0xc8);			//
	lcd_writeData(0x08);				//
	
	lcd_writeCommand(0x55);			//
	lcd_writeData(0x90);				//
	
	lcd_writeCommand(0xd0); 
	lcd_writeData(0xa4);
	lcd_writeData(0xa1);

	lcd_writeCommand(0x26);     //Gamma curve selected 
	lcd_writeData(0x01); 



//		lcd_writeCommand(0x36); 
//	lcd_writeData(0x68); //0x48 //
//	lcd_writeData(0xc8); //0x48
//		lcd_writeData(0xc0); //0x48
//		lcd_writeData(0x0); //0x48
//		lcd_writeData(0xa0); //0x48
//		lcd_writeData(0x60); //0x48
//		lcd_writeData(0xe0); 
//		lcd_writeCommand(0x3A); 
//	lcd_writeData(0x55); 
//	lcd_writeCommand(0xC7); 
//	lcd_writeData(0xa8); 
//		lcd_writeCommand(0x35); 
//		lcd_writeCommand(0x38);
//--------------------------------ST7789S gamma setting---------------------------------------// 	

	lcd_writeCommand(0xE0);     //Set Gamma 
	lcd_writeData(0xd0); 
	lcd_writeData(0x00); 
	lcd_writeData(0x14); 
	lcd_writeData(0x15); 
	lcd_writeData(0x13); 
	lcd_writeData(0x2c); 
	lcd_writeData(0x42); 
	lcd_writeData(0x43); 
	lcd_writeData(0x4e); 
	lcd_writeData(0x09);
	lcd_writeData(0x16); 
	lcd_writeData(0x14); 
	lcd_writeData(0x18); 
	lcd_writeData(0x21); 

	lcd_writeCommand(0XE1);     //Set Gamma 
	lcd_writeData(0xd0); 
	lcd_writeData(0x00); 
	lcd_writeData(0x14); 
	lcd_writeData(0x15); 
	lcd_writeData(0x13); 
	lcd_writeData(0x0b); 
	lcd_writeData(0x43); 
	lcd_writeData(0x55); 
	lcd_writeData(0x53); 
	lcd_writeData(0x0c); 
	lcd_writeData(0x17); 
	lcd_writeData(0x14); 
	lcd_writeData(0x23); 
	lcd_writeData(0x20); 
//	lcd_writeData(0x0F); 
	
	lcd_writeCommand(0xB0); ////////////
//	lcd_writeData(0x00);
//	lcd_writeData(0x1b);
	lcd_writeData(0x11);
	lcd_writeData(0xc0);

	lcd_writeCommand(0xB1); 
	lcd_writeData(0x42);
	lcd_writeData(0x04);
	lcd_writeData(0x14);


	lcd_writeCommand (0x2A);  
	lcd_writeData(0x00); 
	lcd_writeData(0x00); 
	lcd_writeData(0x00); 
	lcd_writeData(0xEF); 
	lcd_writeCommand(0x2B);  
	lcd_writeData(0x00); 
	lcd_writeData(0x00); 
	lcd_writeData(0x01); 
	lcd_writeData(0x3F);
//	lcd_writeCommand (0x21); 
	lcd_writeCommand (0x11);     //Exit Sleep 
	HAL_Delay(120); 
//	lcd_writeCommand(0x20);
	lcd_writeCommand(0x29); //display on 
	lcd_writeData(0x2C); 

}





