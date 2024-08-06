a LAN is the local area network, switches are on the LAN, in fact a LAN finish with the routers. for example here we can see when finish a LAN. [[LAN_example]] 
# Parts of the frame
```
|eth header|Packet|eth trailer| -> how is composed a frame

|eth header| is composed by:
|Preamble|SFD|MAC destination|Mac source|Type|

|eth trailer| is composed by:
|FCS|

```
1. preamble -> length is 7 bytes, \[10101010] * 4 allow devices to synchronize their  receiver clocks.
   
2. SFD -> stands for start frame delimiter, and is used for separate the preamble form the rest, is 1 byte length, \[10101011]
   
3. destination -> indicate who have to receive the message
4. source -> indicate who sent the message
   
5. type or length -> is 2 bytes, is used to represent the length of the encapsulation packet if is 1500 or less, is also used for represent  the type of encapsulation if is 1536 or more, usual IPv4 or IPv6, length is calculated via other ways.
   
6. FCS -> stands for frame check sequence, is 4 bytes in length and detect corrupted data by running CRC algorithm over the data
## Ethernet frame
usually the preamble + SFD isn't considerate part of the Ethernet header; in fact the size is header + trailer = 18 bytes (6 + 6 + 2 + 4).
### minimum size
(header + payload \[Packet] + trailer) is 64 bytes. therefore the minimum payload (packet) size is 46 bytes. Padding bits will be added if is lower than 46.
# MAC address
6-bytes physical address assigned to the device when it is made. it is burned-in-address, is global unique.
the first 3 bytes are OUI -> organization unique identifier.
the last 3 bytes are for identify the device itself
# frame
in this representation we can see the part of this communication -> [[cast_unicast]]
## unicast frame
is a frame destination a single target.
## unknown unicast frame
is a frame that know the position of the source MAC but don't know the position of the destination MAC, for this reason flood and sent to every machine in the network the frame, so the source replay.
## dynamical learning
when switches match a frame memorize use his source for populate the MAC address table.
## know unicast frame
is a frame that know where is his destination because is memorized inside the switch, for this reason don't flood
# ARP request 
Address resolution protocol, used for discover MAC address with IP address, because pc know the ip of the pc in the network, but not the MAC.
Consist in 2 request:
1. ARP request -> sent to all hosts on the network, but to who sent, is broadcast.           The destination is `FFFF.FFFF.FFFF`
2. ARP reply -> sent to one host, the ones that sent the request, is unicast
# Ping 
is a network utility that is used for test reachability, measures round-trip time; uses two messages: 
1. ICMP Echo request
2. ICMP echo replay