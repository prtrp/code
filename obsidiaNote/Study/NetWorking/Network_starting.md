# what is Networking
networking is the way that machines can talk each outer, for do this they have to follow standards and protocols, as Tcp/ip, or osi.
# OSI model
osi stands for open system interconnection, is a old system used for control communication between the network. Have 7 layers:

7. Application -> like HTTP or HTTPS,  interacts with software applications. Is used for identify communication partners, synchronizing communication.
   
6. Presentation -> data in application is application format, translate for sent over network in network format, for example the encryption and decryption 
   
5. Session -> controls session between communicating hosts
4. Transport -> is used for segment and reassemble data for communication. Provide host-to-host communication or end-to-end communication.
   
3. network  -> provides connectivity between end hosts on different networks (out the LAN),provides logical addressing IP, and provides path selection between source and destination. ROUTERS operate here
   
2. data link -> provides node-to-node communication, defines how data is formatted for transmission between physical layer. Use MAC address to determinate where to send data. SWITCH work here.
1. physical 
## encapsulation
for communicate have to encapsulate, where each layer add something, and de-encapsulate the data, the opposite process.
both this interaction are an example for adjacent-layer interaction
## PDU' S
stands for Process data units, and is used for the encapsulation, the Application, presentation and session is used for prepare the data, after that:
1. Transport layer add a header -> ==segment==
2. Network layer add a header -> ==packet==
3. data link layer add a header and trailer -> ==frame==
4. physical layer convert all in ==binary physical signal.==
```
|L2 trailer|Data|L4 header|l3 header|l2 header|
```
## same layer interaction
the communication between the application layer. For avoid the process between.
```
layer 7 <-> layer 7
```

# TCP/IP
is the conceptual model and set of communication protocols used int the internet and other networks today, developed by DARPA, is like the OSI but with fewer layers, in fact have only 4 layers:

4. Application -> is layer 7 + layer 6 + layer 5.
3. Transport -> is the same of the OSI
2. internet -> is the same of OSI
1. link -> layer 2 + layer 1
