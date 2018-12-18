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
#import "IPPoint.h"


@interface ViewController () <UITableViewDelegate>
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.tableView.delegate = self;
}

- (void)pushSafe:(UIViewController *)viewController
{
    if (NSThread.mainThread) {
        [self.navigationController pushViewController:viewController animated:YES];
    } else {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.navigationController pushViewController:viewController animated:YES];
        });
    }
}

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
    [self pushSafe:graphController];
    
    
    __weak typeof(self) weakSelf = self;
    [graphController updatePoints:^NSArray<IPPoint *> * _Nonnull{
        NSString *path = [[NSBundle mainBundle] pathForResource:@"points" ofType:@""];
        NSMutableArray *points = [IPPointsParser parsePointsFromFile:path];
        
        
        NSComparisonResult (^comparisonBlock)(IPPoint * _Nonnull obj1, IPPoint * _Nonnull obj2) = ^NSComparisonResult(IPPoint * _Nonnull obj1, IPPoint * _Nonnull obj2) {
            
            if (obj1.xValue < obj2.xValue)
                return NSOrderedAscending;
            else if (obj1.xValue > obj2.xValue)
                return NSOrderedDescending;
            
            return NSOrderedSame;
        };
        
        [weakSelf sortArray:points usingComparator:comparisonBlock];
        
        NSArray *interpolatedPoints = [LinearInterpolation interpolatePoints:points withExtraPointsCount:2];
        [points addObjectsFromArray:interpolatedPoints];
        
        [weakSelf sortArray:points usingComparator:comparisonBlock];
        
        NSLog(@"%@", points);
        
        NSLog(@"%@", @(points.count));
        return points;
    }];
}

void quicksortInPlace(NSMutableArray *array, NSInteger first, NSInteger last, NSComparator comparator)
{
    if (first >= last)
        return;
    
    id pivot = array[(first + last) / 2];
    NSInteger left = first;
    NSInteger right = last;
    while (left <= right) {
        while (comparator(array[left], pivot) == NSOrderedAscending)
            left++;
        while (comparator(array[right], pivot) == NSOrderedDescending)
            right--;
        if (left <= right)
            [array exchangeObjectAtIndex:left++ withObjectAtIndex:right--];
    }
    
    quicksortInPlace(array, first, right, comparator);
    quicksortInPlace(array, left, last, comparator);
}

- (void)sortArray:(NSMutableArray *)array usingComparator:(NSComparator)comparator
{
    quicksortInPlace(array, 0, array.count - 1, comparator);
}

@end
