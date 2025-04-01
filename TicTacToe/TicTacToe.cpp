#include "TicTacToe.h"

const int TicTacToe::winningMoves[8][3] = {

    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
    {0, 4, 8}, {2, 4, 6}

};

TicTacToe::TicTacToe() : m_playerTurn(0){

    for(int i = 0; i < 9; ++i) {
        m_board[i] = ' ';
    }

}

bool TicTacToe::IsGameOver() const {

    return CheckWin('X') || CheckWin('O') || IsBoardFull();
}

void TicTacToe::TakeTurn() 
{
    int position;
    while (true) {
        std::cin >> position;
        position--;

        if (position < 0 || position >= 9 || m_board[position] != ' ') {
            std::cout << "Invalid move. Try again: ";
        }
        else {
            break;
        }
    }

    
    m_board[position] = (m_playerTurn == 0) ? 'X' : 'O';

   
    m_playerTurn = 1 - m_playerTurn;
}

void TicTacToe::Display() const {

    std::cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        std::cout << " " << m_board[i] << " | " << m_board[i + 1] << " | " << m_board[i + 2] << "\n";
        if (i < 6) std::cout << "---+---+---\n";
    }
    std::cout << "\nPlayer " << (m_playerTurn == 0 ? "X" : "O") << "'s turn. Enter a number (1-9): ";
}

bool TicTacToe::CheckWin(char mark) const {

    for (const auto& combo : winningMoves) {
        if (m_board[combo[0]] == mark && m_board[combo[1]] == mark && m_board[combo[2]] == mark) {
            return true;
        }
    }
    return false;

}

bool TicTacToe::IsBoardFull() const {

    for (char cell : m_board) {
        if (cell ==' ') return false;



    }
    return true;
}



