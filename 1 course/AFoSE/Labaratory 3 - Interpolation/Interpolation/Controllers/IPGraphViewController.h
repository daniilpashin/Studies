//
//  IPGraphViewController.h
//  Interpolation-App
//
//  Created by Даниил on 06/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import <UIKit/UIKit.h>
@class IPPoint;

NS_ASSUME_NONNULL_BEGIN

@interface IPGraphViewController : UIViewController

- (void)updatePoints:( NSArray <IPPoint *> *(^)(void) )pointBlock;

@end

NS_ASSUME_NONNULL_END
