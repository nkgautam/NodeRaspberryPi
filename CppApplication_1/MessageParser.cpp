/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MessageParser.cpp
 * Author: mvondermey
 * 
 * Created on March 6, 2017, 2:13 PM
 */

#include "MessageParser.h"

using namespace rapidjson;

MessageParser::MessageParser() {
}

MessageParser::MessageParser(const MessageParser& orig) {
}

MessageParser::~MessageParser() {
}

void  MessageParser::ParseMessage(std::string MessageToParse){
    //
    std::string json(MessageToParse);
    //
    //
    json.erase(json.find("<BOF>"),5);
    json.erase(json.find("<EOF>"),5);
    //
    printf("After erase: \n %s \n",json.c_str());
    //
    Document document;
    document.Parse(json.c_str());
    //
    if ( document.HasParseError() ) {
        printf("ParseError \n");
        printf("Failed parsing json %s Offset: %d \n",GetParseError_En(document.GetParseError()),document.GetErrorOffset());
    }
        //
    raspidjson:Value & results = document["Message"];
    std::string message = results.GetString();
    printf(" Message: %s \n",message.c_str());
    //
}