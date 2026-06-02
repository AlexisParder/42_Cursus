# NetPractice
![42 Cursus](https://img.shields.io/badge/42-Cursus-blue?style=for-the-badge)
![Projects](https://img.shields.io/badge/Projects-Common_Core-success?style=for-the-badge)
<!-- ![Score](https://img.shields.io/badge/score-100%20%2F%20100-success?style=for-the-badge)<br> -->
[🇫🇷 French](./README.md)
- [NetPractice](#netpractice)
  - [Description](#description)
  - [Instructions](#instructions)
  - [Resources](#resources)
    - [TCP/IP Addressing](#tcpip-addressing)
    - [Subnet Masks](#subnet-masks)
    - [Default Gateway](#default-gateway)
    - [Routers and Switches](#routers-and-switches)
    - [OSI Model](#osi-model)
    - [Static IP Routing](#static-ip-routing)
    - [Useful Links](#useful-links)

## Description
A networking-focused project designed to develop a practical understanding of TCP/IP addressing and network configuration. Through a series of progressively complex exercises, the goal is to correctly configure small network infrastructures by working with IP addresses, subnet masks, routing, and connectivity rules. The project emphasizes troubleshooting logical networking issues, understanding how devices communicate across subnets, and applying fundamental networking concepts without relying on automated tools. This project strengthens knowledge of computer networks, addressing schemes, routing logic, subnetting, and low-level network architecture fundamentals.

## Instructions
- Run the script provided by the school (`run.sh`)
- Two modes are available:
  - The `training` mode will give you access to 10 levels with increasing difficulty.
  - The `exam` mode will give you 3 random exercises from exercises 6 - 10 of the training mode.
- During an exercise, there are 2 main buttons:
  - `Check Again`: Allows you to verify if the exercise is correct after a modification.
  - `Get my config`: Downloads a `json` file containing the configuration of your exercise with the data you entered.
  - A last button appears once the exercise is completed to move on to the next one.
- For the submission of exercises, the 10 `json` configuration files (1 per level) must be placed at the root of the git repository for grading.

## Resources
### TCP/IP Addressing
`TCP/IP` is the common language of the Internet.
- IP (`Internet Protocol`) handles addressing — every machine on a network has a unique IP address (e.g. `192.168.1.10`), like a postal address.
- TCP (`Transmission Control Protocol`) handles delivery — it splits data into packets, sends them, and ensures they all arrive at their destination in the correct order.

### Subnet Masks
A `subnet mask` (e.g. `255.255.255.0` or `/24`) is used to divide a network into several smaller subnetworks. It indicates which part of the IP address identifies the network, and which part identifies the machine. For example, two machines with addresses `192.168.1.10` and `192.168.1.20` on a `/24` are on the same network and can communicate directly. On a `/30`, they could end up in two different subnetworks.

### Default Gateway
The `default gateway` is the address of the router to which a machine sends its packets when the destination is outside its local network. It is the "exit door" of the network. Without it configured correctly, a machine can talk to its neighbors, but not to the rest of the world.

### Routers and Switches
- A `switch` connects machines within the same local network (`LAN — Local Area Network`). It knows the `MAC address` of each connected device and forwards frames to the correct recipient.
- A `router` connects multiple different networks together. It reads `IP` addresses and decides which path a packet should take to reach its destination, using a routing table.

### OSI Model
The `OSI model` breaks down network communication into 7 layers, each with a specific role:

- `Layer 1 — Physical`: Handles the raw transmission of bits over a physical medium (Ethernet cable, fiber optic, Wi-Fi).
- `Layer 2 — Data Link`: Organizes bits into frames and manages communication between two directly connected machines. This is where MAC addresses and switches come in.
- `Layer 3 — Network`: Manages IP addressing and the routing of packets from one network to another. This is the domain of routers and the IP protocol.
- `Layer 4 — Transport`: Ensures reliable end-to-end delivery of data.
- `Layer 5 — Session`: Opens, maintains, and closes communication sessions between two applications. It handles things like resuming an interrupted connection.
- `Layer 6 — Presentation`: Handles data formatting: encryption (SSL/TLS), compression, encoding. It ensures that data sent by one machine is understandable by another.
- `Layer 7 — Application`: Contains the protocols that applications use directly: HTTP, FTP, DNS, SMTP, etc.

> Each layer only communicates with the layer directly above or below it, making the system modular and universal.

### Static IP Routing
`Static routing` consists of manually configuring in a router the paths to take to reach a given network. Unlike dynamic routing (where routers communicate with each other to update themselves), here each route is written by hand.

### Useful Links
- [TCP/IP - IT Connect](https://www.it-connect.fr/modules/protocole-tcp-ip/)
- [OSI Model](https://www.cloudflare.com/learning/ddos/glossary/open-systems-interconnection-model-osi/)
- [Subnet Calculator](https://www.subnet-calculator.com/)