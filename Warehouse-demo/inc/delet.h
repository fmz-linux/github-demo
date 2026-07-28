#ifndef DELET_H
#define DELET_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include<stdbool.h>

#include "ruku.h"

bool deleteNode(Node *head, Node *delnode);
bool deleteByValue(Node *head, int id);
void delet();
#endif