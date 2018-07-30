/*
 * ping_pong.h
 *
 *  Created on: 27 лип. 2018 р.
 *      Author: obychenko
 */

#ifndef __PINGPONG_H_
#define __PINGPONG_H_

#include "inttypes.h"

#define maxWidth 320
#define height 10

const uint16_t maxHeight = 240;
/*const uint16_t maxWidth = 320;*/
const uint16_t minHeight = 0;
const uint16_t minWidth = 0;
const uint16_t move = 15;

int16_t moveX = 10;
int16_t moveY = 10;
uint16_t width = 40;
//uint16_t height = 10;
uint16_t boardX = 100;
uint16_t boardY = maxWidth - height;
int16_t ballX = 118;
int16_t ballY = 158;
uint16_t radius = 2;

void MoveBall(int16_t* ptr_ballX, int16_t* ptr_ballY, int16_t* ptr_moveX, int16_t* ptr_moveY);
void MoveRect(uint16_t* ptr_startX, uint16_t* ptr_startY, int16_t val_move);
void LooseGame(void);
uint8_t IsExit(int16_t* ptr_ballX, int16_t* ptr_ballY, int16_t* ptr_moveX, int16_t* ptr_moveY);

#endif /* __PINGPONG_H_ */
