//
//  LinearInterpolation.m
//  Interpolation
//
//  Created by Даниил on 04/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import "LinearInterpolation.h"
#import "IPPoint.h"

@implementation LinearInterpolation

+ (IPPoint *)interpolatedPointWith:(IPPoint *)firstPoint secondPoint:(IPPoint *)secondPoint xValue:(long double)xValue
{
    long double t = (xValue - firstPoint.xValue) / (secondPoint.xValue - firstPoint.xValue);
    long double interpolatedY = firstPoint.yValue + (secondPoint.yValue - firstPoint.yValue) * t;
    
    return [[IPPoint alloc] initWithX:xValue y:interpolatedY];
}

@end
