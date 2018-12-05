/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"


using namespace std;
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

// check the change turn function
TEST(TicTacToeBoardTest, ToggleTurnTest)
{
	TicTacToeBoard board;
	Piece turn;
	Piece nextTurn;
	
	for( int i = 0; i < 10; i++)
	{
		nextTurn = board.toggleTurn();
		ASSERT_NE(turn, Invalid);
		ASSERT_NE(turn, nextTurn);	
		
	}
	
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundsRow)
{
	TicTacToeBoard board;
	Piece turn;
	
	turn = board.placePiece(3, 2);
	ASSERT_EQ(turn, Invalid);
}

TEST(TicTacToeBoardTest, placePieceOutOfBoundsCol)
{
	TicTacToeBoard board;
	Piece turn;
	
	turn = board.placePiece(2, 3);
	ASSERT_EQ(turn, Invalid);
}


TEST(TicTacToeBoardTest, placePieceOutOfBoundsNegative)
{
	TicTacToeBoard board;
	Piece turn;
	
	turn = board.placePiece(-1, -1);
	ASSERT_EQ(turn, Invalid);
}


TEST(TicTacToeBoardTest, placePieceInBounds)
{
	TicTacToeBoard board;
	Piece turn;
	
	turn = board.placePiece(2, 2);
	ASSERT_NE(turn, Invalid);
}

TEST(TicTacToeBoardTest, getPieceOutOfBoundsRow)
{
	TicTacToeBoard board;
	//Piece turn;
	Piece gotten;
	
	//turn = board.placePiece(3, 2);
	gotten = board.getPiece(3, 2);
	ASSERT_EQ(gotten, Invalid);
}

TEST(TicTacToeBoardTest, getPieceOutOfBoundsCol)
{
	TicTacToeBoard board;
	//Piece turn;
	Piece gotten;
	
	
	//turn = board.placePiece(2, 3);
	gotten = board.getPiece(2, 3);
	ASSERT_EQ(gotten, Invalid);
}


TEST(TicTacToeBoardTest, getPieceInBounds)
{
	TicTacToeBoard board;
	Piece turn;
	Piece gotten;
	
	turn = board.placePiece(2, 2);
	gotten = board.getPiece(2, 2);
	ASSERT_EQ(turn, gotten);
}

TEST(TicTacToeBoardTest, getWinnerXrow)
{
	TicTacToeBoard board;
	Piece turn;
	Piece winner;
	
	turn = board.placePiece(0, 0);
	turn = board.placePiece(0, 1);
	turn = board.placePiece(0, 2);
	
	winner = board.getWinner();
	ASSERT_EQ(turn, winner);
}

TEST(TicTacToeBoardTest, getWinnerXcol)
{
	TicTacToeBoard board;
	Piece turn;
	Piece winner;
	
	turn = board.placePiece(0, 0);
	turn = board.placePiece(1, 0);
	turn = board.placePiece(2, 0);
	
	winner = board.getWinner();
	ASSERT_EQ(turn, winner);
}

TEST(TicTacToeBoardTest, getWinnerXdiag)
{
	TicTacToeBoard board;
	Piece turn;
	Piece winner;
	
	turn = board.placePiece(0, 0);
	turn = board.placePiece(1, 1);
	turn = board.placePiece(2, 2);
	
	winner = board.getWinner();
	ASSERT_EQ(turn, winner);
}


TEST(TicTacToeBoardTest, getWinnerXdiag2)
{
	TicTacToeBoard board;
	Piece turn;
	Piece winner;
	
	turn = board.placePiece(0, 2);
	turn = board.placePiece(1, 1);
	turn = board.placePiece(2, 0);
	
	winner = board.getWinner();
	ASSERT_EQ(turn, winner);
}


TEST(TicTacToeBoardTest, getWinnerOrow)
{
	TicTacToeBoard board;
	Piece turn;
	Piece winner;
	
	turn = board.toggleTurn();
	turn = board.placePiece(0, 0);
	turn = board.placePiece(0, 1);
	turn = board.placePiece(0, 2);
	
	winner = board.getWinner();
	ASSERT_EQ(turn, winner);
}

TEST(TicTacToeBoardTest, getWinnerOcol)
{
	TicTacToeBoard board;
	Piece turn;
	Piece winner;
	
	turn = board.toggleTurn();
	turn = board.placePiece(0, 0);
	turn = board.placePiece(1, 0);
	turn = board.placePiece(2, 0);
	
	winner = board.getWinner();
	ASSERT_EQ(turn, winner);
}


TEST(TicTacToeBoardTest, getWinnerOdiag)
{
	TicTacToeBoard board;
	Piece turn;
	Piece winner;
	
	turn = board.toggleTurn();
	turn = board.placePiece(0, 0);
	turn = board.placePiece(1, 1);
	turn = board.placePiece(2, 2);
	
	winner = board.getWinner();
	ASSERT_EQ(turn, winner);
}

TEST(TicTacToeBoardTest, getWinnerOdiag2)
{
	TicTacToeBoard board;
	Piece turn;
	Piece winner;
	
	turn = board.toggleTurn();
	turn = board.placePiece(0, 2);
	turn = board.placePiece(1, 1);
	turn = board.placePiece(2, 0);
	
	winner = board.getWinner();
	ASSERT_EQ(turn, winner);
}