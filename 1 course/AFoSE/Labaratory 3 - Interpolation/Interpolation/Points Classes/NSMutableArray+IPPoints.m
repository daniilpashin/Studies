//
//  NSMutableArray+IPPoints.m
//  Interpolation
//
//  Created by Даниил on 18/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import "NSMutableArray+IPPoints.h"
#import "IPPoint.h"

@implementation NSMutableArray (IPPoints)

- (void)sortPoints
{
    NSComparator comparator = ^NSComparisonResult(IPPoint * _Nonnull obj1, IPPoint * _Nonnull obj2) {
        
        if (obj1.xValue < obj2.xValue)
            return NSOrderedAscending;
        else if (obj1.xValue > obj2.xValue)
            return NSOrderedDescending;
        
        return NSOrderedSame;
    };
    
    quicksortInPlace(self, 0, self.count - 1, comparator);
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

@end
