/*
 MIT License

 Copyright (c) 2019 SAE Institute Switzerland AG

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <gtest/gtest.h>
#include <engine/engine.h>
#include <engine/log.h>
#include <City/city_function_map.h>

class FunctionMapTest : public ::testing::Test, public neko::BasicEngine
{
protected:
	void SetUp() override 
	{
		Init();
	}

	void TearDown() override
	{
		Destroy();
	}

	neko::FunctionMap funcMap_ = neko::FunctionMap(0xdeadbeef);
};

TEST_F(FunctionMapTest, FunctionDoesntRespondInCaseDoesntExist)
{
	EXPECT_FALSE(funcMap_.CallFunction("doesntExist", 0.0));
}

TEST_F(FunctionMapTest, FunctionRespondInCaseExist)
{
	// Register a new function (under exist).
	funcMap_.SetFunction(
		"exist", 
		[](neko::Index comp, const std::vector<double>& values)
	{
		EXPECT_EQ(0xdeadbeef, comp);
		EXPECT_TRUE(values.size() == 1 || values.size() == 4);
		EXPECT_EQ(values[0], 0.0);
		if (values.size() == 4) 
		{
			EXPECT_EQ(values[1], 1.0);
			EXPECT_EQ(values[2], 2.0);
			EXPECT_EQ(values[3], 3.0);
		}
		return true;
	});
	// Try to execute it!
	EXPECT_TRUE(funcMap_.CallFunction("exist", 0.0));
	EXPECT_TRUE(funcMap_.CallFunction("exist", { 0.0, 1.0, 2.0, 3.0 }));
}