from __future__ import print_function
import socket
from contextlib import closing

def main():
  #host = '127.0.0.1'
  #host = '192.168.11.7'
  host = ''
  port = 9750
  bufsize = 4096

  sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  with closing(sock):
    sock.bind((host, port))
    while True:
      r = sock.recvfrom(bufsize)
      rMsg = str(r[0])
      rSrc = r[1]
      rAddr = rSrc[0]
      rPort = rSrc[1]
      print('--- receive data !! ---')
      print('addr:'+ str(rAddr))
      print('port:'+ str(rPort))
      print('msg:' + rMsg)
#      print(sock.recvfrom(bufsize))
  return

if __name__ == '__main__':
  main()

