#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
  {
    turn = O;
    return turn;
  }
  else if(turn == O)
  {
    turn = X;
    return turn;
  }
  
  return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  int i = column;
  int j = row;
  
  if(i >= BOARDSIZE || i < 0 || j >= BOARDSIZE || j < 0)
  {
    return Invalid;
  }
  else if(board[i][j] == X || board[i][j] == O)
  {
    return board[i][j];
  }
  else
  {
    if(board[i][j] == Blank)
    {
      board[i][j] = turn;
      
    }
    return turn; 
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  int i = column;
  int j = row;
  
  if(i >= BOARDSIZE || i < 0 || j >= BOARDSIZE || j < 0)
  {
    return Invalid;
  }
  else
  {
    return board[i][j]; 
  }
  
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  int oCount = 0;
  int xCount = 0;
  int oCountD = 0;
  int xCountD = 0;
  
  //  check for rows
  for(int i = 0; i < BOARDSIZE; i++)
  {
    for(int j = 0; j < BOARDSIZE; j++)
    {
      if(board[i][j] == O)
        oCount++;
      if(board[i][j] == X)
        xCount++;
    }
    
    if(oCount >= 2)
      return O;
    if(xCount >= 2)
      return X;
      
    oCount = 0;
    xCount = 0;
  }
  
  //  check for columns
  for(int j = 0; j < BOARDSIZE; j++)
  {
    for(int i = 0; i < BOARDSIZE; i++)
    {
      if(board[i][j] == O)
        oCount++;
      if(board[i][j] == X)
        xCount++;
    }
    
    if(oCount >= 2)
      return O;
    if(xCount >= 2)
      return X;
      
    oCount = 0;
    xCount = 0;
  }
  
  
  // check diagonals
  for(int i=0; i<BOARDSIZE; i++)
  {
    for(int j=0; j<BOARDSIZE; j++)
    {
      if(i == j)
      {
        if(board[i][j] == O)
          oCount++;
        if(board[i][j] == X)
          xCount++;
      }
      
      if(i + j == 2)
      {
        if(board[i][j] == O)
          oCountD++;
        if(board[i][j] == X)
          xCountD++;
      }
    }
  }
  
  if(oCount >= 2 || oCountD >=2)
    return O;
  if(xCount >= 2 || xCountD >=2)
    return X;
    
}

