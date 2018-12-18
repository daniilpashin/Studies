//
//  IPInterpolation.m
//  Interpolation
//
//  Created by Даниил on 06/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import "IPInterpolation.h"
#import "IPPoint.h"

@implementation IPInterpolation

+ (NSArray <IPPoint *> *)interpolatePoints:(NSArray <IPPoint *> *)points  withExtraPointsCount:(NSInteger)extraPointsCount
{
    NSMutableArray <IPPoint *> *interpolatedPoints = [NSMutableArray array];
    
    if (points.count == 0) {
        error_log("Points array does not contain any point. Returning...");
        
        return interpolatedPoints;
    }
    
    if (extraPointsCount <= 0) {
        error_log("Extra points count must be more than zero. Returning...");
        return interpolatedPoints;
    }
    
    NSUInteger pointsCount = points.count - 1;
    for (NSUInteger index = 0; index < pointsCount; index++) {
        IPPoint *mainPoint = points[index];
        IPPoint *nextPoint = points[index + 1];
        
        long double xDelta = (nextPoint.xValue - mainPoint.xValue) / (long double)(extraPointsCount + 1);
        
        long double currentX = mainPoint.xValue;
        for (NSInteger i = 0; i < extraPointsCount; i++) {
            currentX += xDelta;
            
            IPPoint *interpolatedPoint = [self interpolatedPointWith:mainPoint secondPoint:nextPoint
                                                              xValue:currentX];
            [interpolatedPoints addObject:interpolatedPoint];
        }
    }
    
    return interpolatedPoints;
}

+ (IPPoint *)interpolatedPointWith:(IPPoint *)firstPoint secondPoint:(IPPoint *)secondPoint xValue:(long double)xValue
{
    NSString *reason = [NSString stringWithFormat:@"%s was not implemented in root class. Please, consider using children interpolation classes.", __FUNCTION__];
    @throw [NSException exceptionWithName:NSGenericException reason:reason userInfo:nil];
    
    return nil;
}

@end
