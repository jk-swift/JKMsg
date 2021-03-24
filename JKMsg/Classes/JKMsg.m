//
//  JKMsg.m
//  JKMsg
//
//  Created by Long on 2021/3/24.
//

#import "JKMsg.h"

@implementation JKMsg

+ (NSString *)hello:(NSString *)name
{
    return [NSString stringWithFormat:@"hello, %@", name];
}

@end
