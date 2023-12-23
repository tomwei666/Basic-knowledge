01-xxx

02-xxx

03-xxx


04-socket:
4.1 概述:
TCP服务器端依次调用socket()、bind()、listen()之后，就会监听指定的socket地址了。
TCP客户端依次调用socket()、connect()之后就想TCP服务器发送了一个连接请求。
TCP服务器监听到这个请求之后，就会调用accept()函数取接收请求，这样连接就建立好了。
之后就可以开始网络I/O操作了，即类同于普通文件的读写I/O操作。

4.2 Server端:
在server端调用api的流程: socket->listen->accept

4.2.1 listen:
	服务端调用listen()后，让套接字进入被动监听状态（并不是说调用listen的过程中进入这个状态，而是调用返回后一直处于这个状态），所谓被动监听，
是指当没有客户端请求时，套接字处于“睡眠”状态，只有当接收到客户端请求时，套接字才会被“唤醒”来响应请求。
	执行accept的是被动套接字，执行connect的是主动套接字。
4.2.2 accept:
	accept会阻塞服务器，直到socket监听到连接请求后，accept将连接请求加入半连接队列，3次握手后再将连接从半连接队列放到全连接队列。

4.3 Client端:
4.3.1 connect
	客户端调用connect()函数，向指定服务端发起连接请求。
源码有客户端和服务端的demo，一个是互相发送一次数据，另外一个demo互相发送多次数据。





