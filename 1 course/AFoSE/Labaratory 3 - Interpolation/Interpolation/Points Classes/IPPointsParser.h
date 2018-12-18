//
//  IPPointsParser.h
//  Interpolation
//
//  Created by Даниил on 05/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

@import Foundation;
@class IPPoint;

NS_ASSUME_NONNULL_BEGIN

@interface IPPointsParser : NSObject

+ (NSMutableArray <IPPoint *> *)parsePointsFromFile:(NSString *)filePath __attribute__((warn_unused_result));

@end

NS_ASSUME_NONNULL_END
