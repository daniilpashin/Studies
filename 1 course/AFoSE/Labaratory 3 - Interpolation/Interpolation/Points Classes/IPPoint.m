//
//  IPPoint.m
//  Interpolation
//
//  Created by Даниил on 05/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import "IPPoint.h"

@implementation IPPoint

+ (instancetype)pointWithNumberedX:(NSNumber *)xValue y:(NSNumber *)yValue
{
    return [[self alloc] initWithX:xValue.doubleValue y:yValue.doubleValue];
}

- (instancetype)initWithX:(long double)xValue y:(long double)yValue
{
    self = [super init];
    if (self) {
        _xValue = xValue;
        _yValue = yValue;
    }
    return self;
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"%@ (%Lf, %Lf)",
            NSStringFromClass([self class]), self.xValue, self.yValue];
}

- (BOOL)isEqual:(id)object
{
    if (![object isKindOfClass:[self class]])
        return NO;
    
    IPPoint *point = (IPPoint *)object;
    return (point.xValue == self.xValue) && (point.yValue == self.yValue);
}

@end
