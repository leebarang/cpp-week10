#include "link.h"
#include "node.h"
#include <iostream>

// 패킷을 반대편으로 보낸다.
void Link::sendPacket(Node* sender, Packet* packet){
    std::string message1 = "packet in: " + packet->toString() + " from " + sender->toString();
    log(message1);
    Node* receiver = other(sender);
    //std::cout << "Link: forwarding packet from node #" << sender->id() << ", to node #" << receiver->id() << std::endl;
    std::string message2 = "packet out: " + packet->toString() + " to " + receiver->toString();
    log(message2);
    receiver->onReceive(packet);
}