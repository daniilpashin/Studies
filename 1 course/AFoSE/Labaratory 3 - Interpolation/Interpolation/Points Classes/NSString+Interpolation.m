//
//  NSString+Interpolation.m
//  Interpolation
//
//  Created by Даниил on 05/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import "NSString+Interpolation.h"

@implementation NSString (Interpolation)

- (NSNumber *)numberRepresentation
{
    NSNumberFormatter *numerFormatter = [NSNumberFormatter new];
    NSNumber *number = [numerFormatter numberFromString:self];
    if (number == nil) {
        NSString *description = [NSString stringWithFormat:@"Passed string '%@' is not numeric.", self];
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:description userInfo:nil];
    }
    
    return number;
}

@end
