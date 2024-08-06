/dev contains the device files. if we execute ls -l in, we can see that the permission starts with b, c, p or s. It means that the file is a device. these letters stand for block, character, pipe and socket. they are a way for get input in and out of the linux system.

1. block device:
   programs can access data form a block device in fixed chunks. for example sda1, the size is fixed. like hard drive
2. character device:
   one character at time, like a string. there is no buffer involve, is in real time.
   dev0 is just a constant stream of null character. dev/null, is like a write only file system, nothing came out. dev/Urandom. are just a stream of random character, rather there will be enough.

