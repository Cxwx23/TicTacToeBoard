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

TEST(TicTacToeBoardTest, placePieceTestForOutOfBounds)
{
	TicTacToeBoard board;
	Piece turn;
	
	for( int i = -2; i < 5; i++)
	{
		for(int j = -2; j < 5; j++)
		{
			ASSERT_NE(turn, Invalid);	
		}
	}
}

