#include "gtest/gtest.h"
#include "StandardException.h"

class StandardExceptionTest : public ::testing::Test
{
    protected:
        virtual void SetUp() 
        {
        }

        virtual void TearDown()
        {
        }

};

TEST_F(StandardExceptionTest, what) 
{
    StandardException myException;

    const char * resp="Error Code: Unknow\nError Reason: Default StandardException";
    EXPECT_STREQ(resp,myException.what());

    myException=StandardException("TEST01","Test Exception");
    resp="Error Code: TEST01\nError Reason: Test Exception";
    EXPECT_STREQ(resp,myException.what());
}

