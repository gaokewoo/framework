AUTOMAKE_OPTIONS=foreign

INCLUDES=-I${top_srcdir}/3rd/gmock/gtest/include \
         -I${top_srcdir}/3rd/gmock/include \
         -I${top_srcdir}/src/tool \
         -I${top_srcdir}/src/utility

bin_PROGRAMS=BasicUnitTest

BasicUnitTest_SOURCES=testConfiguration.cpp ../main.cpp


BasicUnitTest_LDADD=-lgtest -lgmock -lsealutility

BasicUnitTest_LDFLAGS=-L${top_srcdir}/3rd/gmock/gtest/lib/ \
                      -L${top_srcdir}/3rd/gmock/lib/ \
                      -L${top_srcdir}/src/utility

