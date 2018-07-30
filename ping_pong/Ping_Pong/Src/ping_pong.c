/*
 * ping_pong.c
 *
 *  Created on: 27 лип. 2018 р.
 *      Author: obychenko
 */

#include "ping_pong.h"
#include "lcd.h"

uint8_t IsExit(int16_t* ptr_ballX, int16_t* ptr_ballY, int16_t* ptr_moveX, int16_t* ptr_moveY)
{
	//uint16_t width = 40;
	//uint16_t height = 10;
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

	if (*ptr_ballX <= minWidth)
	{
		*ptr_ballX = minWidth;
		*ptr_moveY *= -1;
	}

	if ( ((*ptr_ballX == (boardX + width)) || ((*ptr_ballX + 2 * radius) == boardX)) && ((*ptr_ballX + 2 * radius) >= boardY) )
	{
		*ptr_moveX *= -1;
		*ptr_moveY *= -1;
	} else if ( (*ptr_ballX + 2 * radius) > boardX && *ptr_ballX < (boardX + width) && (*ptr_ballX + 2 * radius) >= boardY )
	{
		*ptr_ballX = boardY - 2 * radius;
		*ptr_moveY *= -1;
	}

	if (*ptr_ballX >= maxWidth)
		result = 1;

	LCD_FillCircle(*ptr_ballX, *ptr_ballX, radius, RED);
	HAL_Delay(200);

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
	HAL_Delay(100);
}

void LooseGame(void)
{
	LCD_FillScreen(BLACK);
	LCD_SetCursor(100, 160);
	LCD_Printf("Looser!!!");
}
