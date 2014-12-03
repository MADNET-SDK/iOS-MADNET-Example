//
//  CMADFreeFormAdViewController.m
//  MADNET_SDK_DEMO
//
//  Created by AndreyIvanov on 18.11.14.
//  Copyright (c) 2014 AndreyIvanov. All rights reserved.
//

#import "CMADFreeFormAdViewController.h"
#import "MADRotationView.h"

@interface CMADFreeFormAdViewController ()<IMADRotationViewDelegate>
@property (nonatomic, retain) IBOutlet MADRotationView *adView;
@end

@implementation CMADFreeFormAdViewController

- (void) viewDidLoad
{
    self.adView.delegate = self;
#warning replace SPACE_ID with you MADNET placement id
    self.adView.spaceId = SPACE_ID;
    self.adView.transitionMask = etoAnimationOptionTransitionCrossDissolve;
    self.adView.allowLocation = YES;
}

- (void) viewWillAppear:(BOOL)animated
{
    [self.adView load];
}

- (void) didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
    [self.adView load];
}

#pragma mark - MADNET-AD

- (UIViewController *) MADViewController
{
    return (self);
}

- (BOOL) rotationViewTestingMode: (MADRotationView *)aRotationView
{
#warning change to NO before deploy to AppStore
    return (TESTMODE);
}

- (void) dealloc
{
    [self.adView invalidate];
    self.adView = nil;
    [super dealloc];
}

@end
