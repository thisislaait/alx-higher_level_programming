HTTP Protocol
As mentioned, whenever you enter a URL in the address box of the browser, the browser translates the URL into a request message according to the specified protocol; and sends the request message to the server.

For example, the browser translated the URL http://www.nowhere123.com/doc/index.html into the following request message:

GET /docs/index.html HTTP/1.1
Host: www.nowhere123.com
Accept: image/gif, image/jpeg, */*
Accept-Language: en-us
Accept-Encoding: gzip, deflate
User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)
(blank line)
When this request message reaches the server, the server can take either one of these actions:

The server interprets the request received, maps the request into a file under the server's document directory, and returns the file requested to the client.
The server interprets the request received, maps the request into a program kept in the server, executes the program, and returns the output of the program to the client.
The request cannot be satisfied, the server returns an error message.
An example of the HTTP response message is as shown:

HTTP/1.1 200 OK
Date: Sun, 18 Oct 2009 08:56:53 GMT
Server: Apache/2.2.14 (Win32)
Last-Modified: Sat, 20 Nov 2004 07:16:26 GMT
ETag: "10000000565a5-2c-3e94b66c2e680"
Accept-Ranges: bytes
Content-Length: 44
Connection: close
