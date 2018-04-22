/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exception.cpp
 * Author: mohit
 * 
 * Created on March 4, 2018, 1:00 PM
 */

#include "./headers/exception.h"
#include "./headers/bug.h"
Exception::Exception(const char* msg){
    reason = msg;
}
const char* Exception::what() const throw(){
    return reason;
}



