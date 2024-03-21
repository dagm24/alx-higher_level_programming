#!/usr/bin/python3
def uniq_add(my_list=[]):
    num = 0
    for element in set(my_list):
        num += element
    return num
