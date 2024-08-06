is a protocol that provides connectivity between LAN, between different networks. Providing logical addressing (IP address) for source and destination.
## characteristics
IP address are 4 bytes in length.
`192.168.1.254` -> is 4 octanes of doted decimal.
`192.168.1.256/24` -> 24 represent the portion for the network portion, the remain part represent the device ports. but we can also have `/16` or `/8` for indicate the portion of network.
## Address classes
| class | first octet | first octet numeric range | prefix length |    netmask    |    example of ip     |
|:-----:| ----------- |:-------------------------:|:-------------:|:-------------:|:--------------------:|
|   A   | 0xxxxxxx    |           0-127           |      /8       |   255.0.0.0   | ==12.==128.251.23/8  |
|   B   | 10xxxxxx    |          128-191          |      /16      |  255.255.0.0  | ==154.78==.111.32/16 |
|   C   | 110xxxxx    |          192-223          |      /24      | 255.255.255.0 | ==192.168.1==.254/24 |
|   D   | 1110xxxx    |          224-39           |     ....      |               |                      |
|   E   | 1111xxxx    |          240-255          |     ....      |               |                      |
is determinate with the first octet
## loop-back addresses
address range 125.0.0.0 - 125.255.255.255 are used to test the `network stack` on the local device
### network address
host portion of the address is all 0's = Network Address, identifier of the network itself