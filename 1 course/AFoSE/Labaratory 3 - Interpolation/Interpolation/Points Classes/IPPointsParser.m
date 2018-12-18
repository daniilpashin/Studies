//
//  IPPointsParser.m
//  Interpolation
//
//  Created by Даниил on 05/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import "IPPointsParser.h"
#import "IPPoint.h"
#import "NSString+Interpolation.h"

@implementation IPPointsParser

+ (NSMutableArray <IPPoint *> *)parsePointsFromFile:(NSString *)filePath
{
    NSError *localError = nil;
    NSString *pointsString = [NSString stringWithContentsOfFile:filePath
                                                       encoding:NSUTF8StringEncoding error:&localError];
    if (localError) {
        return nil;
    }
    
    return [self parsePointsFromString:pointsString];
}

+ (NSMutableArray <IPPoint *> *)parsePointsFromString:(NSString *)pointsString
{
    NSArray <NSString *> *allStringPoints = [pointsString componentsSeparatedByString:@"\n"];
    if (allStringPoints.count == 0) {
        return nil;
    }
    
    NSMutableArray <IPPoint *> *pointsDict = [NSMutableArray array];
    [allStringPoints enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if ([obj hasPrefix:@"#"] || obj.length == 0)
            return;
        
        IPPoint *point = [self processLine:obj];
        if (point) {
            [pointsDict addObject:point];
        }
    }];
    
    return pointsDict;
}

+ (IPPoint * _Nullable)processLine:(NSString * _Nonnull)line
{
    NSArray <NSString *> *points = [line componentsSeparatedByString:@" "];
    if (points.count != 2)
        return nil;
    
    @try {
        NSNumber *xValue = points[0].numberRepresentation;
        NSNumber *yValue = points[1].numberRepresentation;
        IPPoint *point = [IPPoint pointWithNumberedX:xValue y:yValue];
        return point;
    } @catch (NSException *exception) {
        error_log("%s",  exception.description.UTF8String);
    }
    
    return nil;
}

@end
