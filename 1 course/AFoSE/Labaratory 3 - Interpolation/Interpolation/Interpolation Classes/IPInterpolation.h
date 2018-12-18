//
//  IPInterpolation.h
//  Interpolation
//
//  Created by Даниил on 06/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import <Foundation/Foundation.h>
@class IPPoint;

NS_ASSUME_NONNULL_BEGIN

@interface IPInterpolation : NSObject

+ (NSArray <IPPoint *> *)interpolatePoints:(NSArray <IPPoint *> *)points
                   withExtraPointsCount:(NSInteger)extraPointsCount __attribute__((warn_unused_result));

@end

NS_ASSUME_NONNULL_END
