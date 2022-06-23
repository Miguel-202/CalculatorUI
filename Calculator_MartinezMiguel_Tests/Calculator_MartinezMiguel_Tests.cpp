#include "pch.h"
#include "CppUnitTest.h"
#include "wx/wx.h"
#include "ButtonFactoryTests.h"
#include "CalculatorProcessorTests.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorMartinezMiguelTests
{
	TEST_CLASS(CalculatorMartinezMiguelTests)
	{
	private:
		ButtonFactoryTests bt;
		CalculatorProcessorTests ct;
	public:
		//BUTTONS TEST 1
		TEST_METHOD(TestGetDecimalButtonID)
		{
			int answer = bt.GetIDButton(1);
			Assert::AreEqual(30, answer);
		}
		//BUTTONS TEST 2
		TEST_METHOD(TestGetMultiplyButtonID)
		{
			int answer = bt.GetIDButton(2);
			Assert::AreEqual(42, answer);
		}
		//BUTTONS TEST 3
		TEST_METHOD(TestGetDivideButtonID)
		{
			int answer = bt.GetIDButton(3);
			Assert::AreEqual(47, answer);
		}
		//BUTTONS TEST 4
		TEST_METHOD(TestGetSubstractButtonID)
		{
			int answer = bt.GetIDButton(4);
			Assert::AreEqual(45, answer);
		}
		//BUTTONS TEST 5
		TEST_METHOD(TestGetAddButtonID)
		{
			int answer = bt.GetIDButton(5);
			Assert::AreEqual(43, answer);
		}
		//BUTTONS TEST 6
		TEST_METHOD(TestGetBinaryButtonID)
		{
			int answer = bt.GetIDButton(6);
			Assert::AreEqual(31, answer);
		}
		//BUTTONS TEST 7
		TEST_METHOD(TestGetDecimalButtonLabel) 
		{
			wxString answer = bt.GetLabelDecimalButton();
			Assert::AreNotEqual("MOD", answer);
		}
		//BUTTONS TEST 8
		TEST_METHOD(TestGetClearButtonColor)
		{
			bool isEqual = bt.GetClearButtonColor() == *wxRED;
			Assert::IsTrue(isEqual);
		}
		//BUTTONS TEST 9
		TEST_METHOD(TestGetEqualsButtonColor)
		{
			bool isEqual = bt.GetEqualsButtonColor() == *wxRED;
			Assert::IsTrue(isEqual);
		}
		//BUTTONS TEST 10
		TEST_METHOD(TestGetNegativeButtonColor)
		{
			bool isEqual = bt.GetNegativeButtonColor() == *wxLIGHT_GREY;
			Assert::IsTrue(isEqual);
		}



		//			PROCESSOR TESTS



		//PROCESSOR TEST 1
		TEST_METHOD(TestThreePlusSixTimesSix)
		{
			float answer = ct.SolveOperationAdditionThenMultiplications("3+6*6");
			float correct = 3.0f + 6.0f * 6.0f;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 2
		TEST_METHOD(TestFourPlusNineTimesTen)
		{
			float answer = ct.SolveOperationAdditionThenMultiplications("4+9*10");
			float correct = 4.0f + 9.0f * 10.0f;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 3
		TEST_METHOD(TestTenMinusTwenty)
		{
			float answer = ct.SolveOperationSubstraction("10-20");
			float correct = 10.0f - 20.0f;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 4
		TEST_METHOD(TestTenMinusFive)
		{
			float answer = ct.SolveOperationSubstraction("10-5");
			float correct = 10.0f - 5.0f;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 5
		TEST_METHOD(SeventyFourToBinary)
		{
			int answer = ct.SolveOperationDecimalToBinary(74);
			int correct = 1001010;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 6
		TEST_METHOD(SeventyFourToHex)
		{
			std::string answer = ct.SolveOperationDecimalToHex(74);
			std::string correct = "0x4A";
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 7
		TEST_METHOD(TwentyFourToBinaryAndBackToDecimal)
		{
			int answer = ct.SolveOperationDecimalToBinaryAndBackToDecimal(24);
			int correct = 24;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 8
		TEST_METHOD(TwentyNineModTen)
		{
			int answer = ct.SolveOperationModulus("29%10");
			int correct = 29 % 10;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 9
		TEST_METHOD(FiftyModTen)
		{
			int answer = ct.SolveOperationModulus("50%10");
			int correct = 50 % 10;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 10
		TEST_METHOD(SixtyEightMinusTwentyEightDotFive)
		{
			float answer = ct.SolveOperationSubstraction("68-28.5");
			float correct = 68.0f - 28.5f;
			Assert::AreEqual(correct, answer);
		}
		//PROCESSOR TEST 11 (BONUS)
		TEST_METHOD(NineToNegative)
		{
			float answer = ct.OperationToNegative(9);
			float correct = -9.0f;
			Assert::AreEqual(correct, answer);
		}
	};
}
