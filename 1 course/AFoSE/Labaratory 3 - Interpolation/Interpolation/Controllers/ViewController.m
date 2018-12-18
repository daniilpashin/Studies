//
//  ViewController.m
//  Interpolation-App
//
//  Created by Даниил on 06/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import "ViewController.h"
#import "IPGraphViewController.h"

#import "LinearInterpolation.h"
#import "IPPointsParser.h"
#import "NSMutableArray+IPPoints.h"


@implementation ViewController

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    if (indexPath.section == 0 && indexPath.row == 0) {
        [self presentFileLinearInterpolationController];
    }
}

- (void)presentFileLinearInterpolationController
{
    IPGraphViewController *graphController = [IPGraphViewController new];
    [self.navigationController pushViewController:graphController animated:YES];
    
    [graphController updatePoints:^NSArray<IPPoint *> * _Nonnull{
        NSString *path = [[NSBundle mainBundle] pathForResource:@"points" ofType:@""];
        NSMutableArray *points = [IPPointsParser parsePointsFromFile:path];
        [points sortPoints];
        
        NSArray *interpolatedPoints = [LinearInterpolation interpolatePoints:points withExtraPointsCount:2];
        [points addObjectsFromArray:interpolatedPoints];
        [points sortPoints];
        
        NSLog(@"Points count is: %lu, points: %@", (unsigned long)points.count, points);
        return points;
    }];
}

@end
