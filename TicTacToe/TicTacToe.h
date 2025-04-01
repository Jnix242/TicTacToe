#pragma once

#include "Game.h"

#include <iostream>

class TicTacToe : public Game {

private:
	char m_board[9];
	int m_playerTurn;
	static const int winningMoves[8][3];

public:
	TicTacToe();

	bool IsGameOver() const override;
	
	void TakeTurn() override;

	void Display() const override;

	bool CheckWin(char mark) const;
	
	bool IsBoardFull() const;

};
