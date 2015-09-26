//
//  MyDriver.c
//  MyDriver
//
//  Created by panda zheng on 15/9/26.
//  Copyright © 2015年 pandazheng. All rights reserved.
//

#include <mach/mach_types.h>
#include <libkern/libkern.h>

kern_return_t MyDriver_start(kmod_info_t * ki, void *d);
kern_return_t MyDriver_stop(kmod_info_t *ki, void *d);

kern_return_t MyDriver_start(kmod_info_t * ki, void *d)
{
    printf("Hello World!\n");
    return KERN_SUCCESS;
}

kern_return_t MyDriver_stop(kmod_info_t *ki, void *d)
{
    printf("Goodbye World!\n");
    return KERN_SUCCESS;
}
