framework
=========

=====thrift install=====
sudo apt-get install libboost-dev libboost-test-dev libboost-program-options-dev libevent-dev automake libtool flex bison pkg-config g++ libssl-dev
sudo apt-get install openjdk-6-jdk

cd thrift-0.9.1
./bootstrap.sh
./configure --prefix=/opt-seal/thrift/
make
make install


=====zeromq install=====
cd zeromq-4.0.4
./configure --prefix=/opt-seal/zeromq/
make
make install


======glog install=====
cd glog-0.3.3
./configure --prefix=/opt-seal/glog/
make
make install


Besides the above 3pp, below list also have been used:
googlemock
tinyxml2
libconfparser
