#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Message {
    string _text;
    string _sender;
    string _receiver;
public:
    Message(string text, string sender, string receiver);

    friend fstream& operator >>(fstream& is, Message& obj1);
    friend ostream& operator <<(ostream& os, const Message& obj1);
};
