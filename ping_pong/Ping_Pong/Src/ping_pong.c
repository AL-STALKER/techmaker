/*
 * ping_pong.c
 *
 *  Created on: 27 лип. 2018 р.
 *      Author: obychenko
 */

#include "ping_pong.h"
#include "lcd.h"

int16_t moveX = 10;
int16_t moveY = 10;
uint16_t boardX = 100;
uint16_t boardY = maxWidth - height;
int16_t ballX = 118;
int16_t ballY = 158;
uint16_t radius = 2;

uint8_t IsExit(int16_t* ptr_ballX, int16_t* ptr_ballY, int16_t* ptr_moveX, int16_t* ptr_moveY)
{
	uint8_t result = 0;

	if (*ptr_ballX >= maxHeight)
	{
		*ptr_ballX = maxHeight - 2 * radius;
		*ptr_moveX *= -1;
	}

	if (*ptr_ballX <= minHeight)
	{
		*ptr_ballX = minHeight;
		*ptr_moveX *= -1;
	}

	if (*ptr_ballY <= minWidth)
	{
		*ptr_ballY = minWidth;
		*ptr_moveY *= -1;
	}

	if ( ((*ptr_ballX == (boardX + width)) || ((*ptr_ballX + 2 * radius) == boardX)) && ((*ptr_ballY + 2 * radius) >= boardY) )
	{
		*ptr_moveX *= -1;
		*ptr_moveY *= -1;
	} else if ( (*ptr_ballX + 2 * radius) > boardX && *ptr_ballX < (boardX + width) && (*ptr_ballY + 2 * radius) >= boardY )
	{
		*ptr_ballY = boardY - 2 * radius;
		*ptr_moveY *= -1;
	}

	if (*ptr_ballY >= maxWidth)
		result = 1;

	LCD_FillCircle(*ptr_ballX, *ptr_ballY, radius, RED);

	return result;
}

void MoveBall(int16_t* ptr_ballX, int16_t* ptr_ballY, int16_t* ptr_moveX, int16_t* ptr_moveY)
{
	LCD_FillCircle(*ptr_ballX, *ptr_ballY, radius, BLACK);
	*ptr_ballX += *ptr_moveX;
	*ptr_ballY += *ptr_moveY;
}

void MoveRect(uint16_t* ptr_startX, uint16_t* ptr_startY, int16_t val_move)
{
	LCD_FillRect(*ptr_startX, *ptr_startY, width, height, BLACK);
	*ptr_startX += val_move;

	if (*ptr_startX > maxHeight - width)
		*ptr_startX = maxHeight - width;
	if (*ptr_startX < minHeight)
		*ptr_startX = minHeight;

	LCD_FillRect(*ptr_startX, *ptr_startY, width, height, BLUE);
	//HAL_Delay(100);
}

void MoveRectClick(uint16_t* ptr_startX, uint16_t* ptr_startY)
{
  GPIO_PinState btn2 = GPIO_PIN_RESET;
  GPIO_PinState btn1 = GPIO_PIN_RESET;

  btn2 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3);
  btn1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2);

	if ( btn1 == GPIO_PIN_SET )
	{
	  LCD_FillRect(*ptr_startX, *ptr_startY, width, height, BLACK);
	  *ptr_startX += move;
	  if ( *ptr_startX > maxHeight - width )
		  *ptr_startX = maxHeight - width;

	  LCD_FillRect(*ptr_startX, *ptr_startY, width, height, BLUE);
	  HAL_Delay(100);
	  btn1 = GPIO_PIN_RESET;
	}

	if ( btn2 == GPIO_PIN_SET )
	{
	  LCD_FillRect(*ptr_startX, *ptr_startY, width, height, BLACK);

	  //if ( *startX < move )
	  if ( *ptr_startX < minHeight )
		  *ptr_startX = minHeight;
		  //*startX = maxHeight - width;
	  else
		  *ptr_startX -= move;

	  LCD_FillRect(*ptr_startX, *ptr_startY, width, height, BLUE);
	  HAL_Delay(100);
	  btn2 = GPIO_PIN_RESET;
	}
}

void LooseGame(void)
{
	LCD_FillScreen(BLACK);
	LCD_SetCursor(100, 160);
	LCD_Printf("Looser!!!");
}
