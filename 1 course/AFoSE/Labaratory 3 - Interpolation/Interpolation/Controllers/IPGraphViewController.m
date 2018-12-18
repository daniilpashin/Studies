//
//  IPGraphViewController.m
//  Interpolation-App
//
//  Created by Даниил on 06/12/2018.
//  Copyright © 2018 Даниил. All rights reserved.
//

#import "IPGraphViewController.h"
#import "Charts-Swift.h"
#import "IPPoint.h"

@interface IPGraphViewController ()
@property (nonatomic, strong) LineChartView *chartView;
@end

@implementation IPGraphViewController

- (void)viewDidLoad
{
    self.view.backgroundColor = [UIColor whiteColor];
    [super viewDidLoad];
    
    self.chartView = [LineChartView new];
    self.chartView.pinchZoomEnabled = YES;
    [self.view addSubview:self.chartView];
    
    self.chartView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-[view]-|" options:0
                                                                      metrics:nil views:@{@"view": self.chartView}]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-[view]-|" options:0
                                                                      metrics:nil views:@{@"view": self.chartView}]];
}

- (void)updatePoints:( NSArray <IPPoint *> *(^)(void) )pointBlock
{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^{
        NSArray *points = pointBlock();
        
        NSMutableArray <ChartDataEntry *> *chartEntries = [NSMutableArray array];
        [points enumerateObjectsUsingBlock:^(IPPoint * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [chartEntries addObject:[[ChartDataEntry alloc] initWithX:obj.xValue y:obj.yValue]];
        }];
        
        LineChartDataSet *chartDataSet = [[LineChartDataSet alloc] initWithValues:chartEntries];
        dispatch_async(dispatch_get_main_queue(), ^{
            self.chartView.data = [[LineChartData alloc] initWithDataSet:chartDataSet];
        });
    });
}

@end
