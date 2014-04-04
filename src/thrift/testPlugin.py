#!/usr/bin/env python  
import sys
import ConfigParser
sys.path.append('./gen-py/PluginServant')
import PluginServant
from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

# Make socket
transport = TSocket.TSocket('localhost', 9090)
# Buffering is critical. Raw sockets are very slow
transport = TTransport.TBufferedTransport(transport)
# Wrap in a protocol
protocol = TBinaryProtocol.TBinaryProtocol(transport)
# Create a client to use the protocol encoder
client = PluginServant.Client(protocol)
# Connect!
transport.open()
# Call Server services
client.initialize(1,'123')
client.prepareForStart()
client.start()
client.active()
client.passive()
client.stop()
client.prepareForUnload()
client.destroy(1)

