/*
 * ping_pong.h
 *
 *  Created on: 27 лип. 2018 р.
 *      Author: obychenko
 */

#ifndef __PINGPONG_H_
#define __PINGPONG_H_

#include "inttypes.h"

#define maxHeight 240
#define maxWidth 320
#define minHeight 0
#define minWidth 0
#define move 15
#define width 40
#define height 10

extern int16_t moveX;
extern int16_t moveY;
extern uint16_t boardX;
extern uint16_t boardY;
extern int16_t ballX;
extern int16_t ballY;
extern uint16_t radius;

void MoveBall(int16_t* ptr_ballX, int16_t* ptr_ballY, int16_t* ptr_moveX, int16_t* ptr_moveY);
void MoveRect(uint16_t* ptr_startX, uint16_t* ptr_startY, int16_t val_move);
void MoveRectClick(uint16_t* ptr_startX, uint16_t* ptr_startY);
void LooseGame(void);
uint8_t IsExit(int16_t* ptr_ballX, int16_t* ptr_ballY, int16_t* ptr_moveX, int16_t* ptr_moveY);

#endif /* __PINGPONG_H_ */
