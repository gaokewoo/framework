export SEAL_HOME=/opt-seal/
export PATH=/usr/local/bin:/usr/sbin:$PATH
export PATH=$SEAL_HOME/thrift/bin/:$PATH

export LD_LIBRARY_PATH=$SEAL_HOME/thrift/lib:.:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=$SEAL_HOME/zeromq/lib:.:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=$SEAL_HOME/glog/lib:.:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH=~/dev/framework/lib:.:$LD_LIBRARY_PATH