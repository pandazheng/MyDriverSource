//
//  main.c
//  EnumUsbDriver
//
//  Created by panda zheng on 15/9/27.
//  Copyright © 2015年 pandazheng. All rights reserved.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>

int main(int argc, const char * argv[]) {
    CFDictionaryRef matchingDict = NULL;
    io_iterator_t iter = 0;
    io_service_t service = 0;
    kern_return_t kr;
    
    //创建一个匹配字典，查找任意的USB设备
    matchingDict = IOServiceMatching("IOUSBDevice");
    
    //为匹配该字典的所有I/O Registry对象创建一个迭代器
    kr = IOServiceGetMatchingServices(kIOMasterPortDefault, matchingDict, &iter);
    if (kr != KERN_SUCCESS)
        return -1;
    
    //迭代所有的匹配对象
    while ((service = IOIteratorNext(iter)) != 0) {
        CFStringRef className;
        io_name_t name;
        
        //列出所有的IOUSBDevice对象
        className = IOObjectCopyClass(service);
        if (CFEqual(className, CFSTR("IOUSBDevice")) == true)
        {
            IORegistryEntryGetName(service, name);
            printf("Found device with name: %s\n",name);
        }
        CFRelease(className);
        IOObjectRelease(service);
    }
    
    //释放迭代器
    IOObjectRelease(iter);
    return 0;
}
