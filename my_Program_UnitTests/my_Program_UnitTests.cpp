#include "pch.h"
#include "CppUnitTest.h"
#include "..\Singleton\Singleton.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace myProgramUnitTests
{
	TEST_CLASS(myProgramUnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MetricRegister::getInstance()->add_metr(0, 1, 2);
			Assert::AreEqual(3, MetricRegister::getInstance()->count_cometr(0));
		}
		TEST_METHOD(TestMethod2)
		{
			MetricRegister::getInstance()->add_metr(1, 1000000, 845641651);
			Assert::AreEqual(846641651, MetricRegister::getInstance()->count_cometr(1));
		}
		TEST_METHOD(TestMethod3)
		{
			MetricRegister::getInstance()->add_metr(2, 990, 1000000);
			Assert::AreEqual(1000990, MetricRegister::getInstance()->count_cometr(2));
		}
		TEST_METHOD(TestMethod4)
		{
			MetricRegister::getInstance()->add_metr(3, 0, 0);
			Assert::AreEqual(0, MetricRegister::getInstance()->count_cometr(3));
		}
		TEST_METHOD(TestMethod5)
		{
			MetricRegister::getInstance()->add_metr(4, -1, 1);
			Assert::AreEqual(0, MetricRegister::getInstance()->count_cometr(4));
		}
		TEST_METHOD(TestMethod6)
		{
			MetricRegister::getInstance()->add_metr(5, 'a', 68);
			Assert::AreEqual(165, MetricRegister::getInstance()->count_cometr(5));
		}
		TEST_METHOD(TestMethod7)
		{
			MetricRegister::getInstance()->add_metr(6, 20, 20);
			Assert::AreEqual(40, MetricRegister::getInstance()->count_cometr(6));
		}
		TEST_METHOD(TestMethod8)
		{
			MetricRegister::getInstance()->add_metr(7, -985, -20);
			Assert::AreEqual(-1005, MetricRegister::getInstance()->count_cometr(7));
		}
		TEST_METHOD(TestMethod9)
		{
			MetricRegister::getInstance()->add_metr(8, 1024, 4096);
			Assert::AreEqual(5120, MetricRegister::getInstance()->count_cometr(8));
		}
		TEST_METHOD(TestMethod10)
		{
			MetricRegister::getInstance()->add_metr(9, INT32_MAX, INT32_MAX);
			Assert::AreEqual(INT32_MAX*2, MetricRegister::getInstance()->count_cometr(9));
		}
	};
}
