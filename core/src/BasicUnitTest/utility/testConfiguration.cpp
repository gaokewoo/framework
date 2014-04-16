#include "gtest/gtest.h"
#include "Configuration.h"

class ConfigurationTest : public ::testing::Test
{
    protected:
        virtual void SetUp() 
        {
        }

        virtual void TearDown()
        {
        }
};

TEST_F(ConfigurationTest, what) 
{
    Configuration & myCfg=Configuration::getInstance();

    const char * resp="world";
    EXPECT_STREQ(resp,myCfg.getStringValue("test","hello").c_str());

    int iresp=1;
    EXPECT_EQ(iresp,myCfg.getIntValue("test","value"));
}

