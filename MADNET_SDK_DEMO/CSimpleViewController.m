//
//  CSimpleViewController.m
//  MADNET_SDK_DEMO
//
//  Created by AndreyIvanov on 23.07.13.
//  Copyright (c) 2013 AndreyIvanov. All rights reserved.
//

#import "CSimpleViewController.h"
#import "MADRotationView.h"

@interface CSimpleViewController ()<IMADRotationViewDelegate>
{
  @private
    MADRotationView *_madnetView;
    
}
@end

@implementation CSimpleViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (UIViewController *) MADViewController
{
    return (self);
}

- (void) loadView
{
    [super loadView];
    
    _madnetView = [[MADRotationView alloc] initWithAdSize: kmAdSize_320x50
                                                  spaceId: @"SPACE_ID" // !Replace with your ad-placemenet id! 
                                                partnerId: nil];
    
    _madnetView.origin = CGPointMake(0.0f, 40.0f);
    _madnetView.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin;
    _madnetView.transitionMask = etoAnimationOptionTransitionFlipFromLeft | etoAnimationOptionTransitionRevealFromBottom;
    
    _madnetView.delegate = self;
    [self.view addSubview: _madnetView];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
	// Do any additional setup after loading the view.
    
    MADExternalValuesForTargeting *values = [[MADExternalValuesForTargeting alloc] init];
    [values setValue: [CmAdTargetParameters params].gender.male];
    [values setValue: [CmAdTargetParameters params].education.university];
    [values setValue: [CmAdTargetParameters params].income.from15to24];
    
    values.dob = [NSDate date];
    values.age = [NSNumber numberWithUnsignedInt: 0];
    
    [_madnetView loadWithExternalValues: values];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
	return YES;
}

- (BOOL) shouldAutorotate
{
    return YES;
}

- (void) dealloc
{
    [_madnetView invalidate];
    [_madnetView release]; _madnetView = nil;
    
    [super dealloc];
}

@end
