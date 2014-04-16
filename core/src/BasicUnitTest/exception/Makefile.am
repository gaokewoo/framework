AUTOMAKE_OPTIONS=foreign

INCLUDES=-I../${top_srcdir}/gmock/gtest/include \
         -I../${top_srcdir}/gmock/include \
         -I${SEAL_HOME}/thrift/include \
         -I${top_srcdir}/src/exception

bin_PROGRAMS=BasicUnitTest

BasicUnitTest_SOURCES=testStandardException.cpp ../main.cpp


BasicUnitTest_LDADD=-lgtest -lgmock -lthrift -lsealstandardexception

BasicUnitTest_LDFLAGS=-L../${top_srcdir}/gmock/gtest/lib/ \
                      -L../${top_srcdir}/gmock/lib/ \
                      -L${SEAL_HOME}/thrift/lib \
                      -L${top_srcdir}/src/exception

