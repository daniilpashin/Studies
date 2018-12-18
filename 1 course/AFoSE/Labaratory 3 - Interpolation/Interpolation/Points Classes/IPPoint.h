//
//  IPPoint.h
//  Interpolation
//
//  Created by Даниил on 05/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface IPPoint : NSObject

+ (instancetype)pointWithNumberedX:(NSNumber *)xValue y:(NSNumber *)yValue __attribute__((warn_unused_result));

@property (assign, nonatomic, readonly) long double xValue;
@property (assign, nonatomic, readonly) long double yValue;

- (instancetype)initWithX:(long double)xValue y:(long double)yValue __attribute__((warn_unused_result));

@end

NS_ASSUME_NONNULL_END
